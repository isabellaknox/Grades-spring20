/*
 * ECE/CS 250.
 * 
 * Grades assignment starter code.
 */

// Include useful standard libraries.
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// TODO: Implement
typedef struct student{
    int student_id;
    int exam1_score;
    int exam2_score;
    char name[16];
    struct student* next;
}student_t;

student_t *hashtable[13];


/*
 * Simple hash function.
 */
int hash(int i)
{
    // creates hash codes to know which bucket to place item in 

    // return the number of the bucket the student id is in 
    return (i%13);
}

/*
 * Initialize the hash table.
 */
void init_hash_table()
{
    for (int i; i <=13;i++){
        hashtable[i]== NULL;
    }
}

/*
 * Deallocate the hash table.
 */
void dealloc_hash_table(){

    student_t *currentstudent;
    student_t *paststudent;
    for (int i; i<= 13; i++){
        currentstudent = hashtable[i];
        student_t *forward =hashtable[i]->next;
        while (currentstudent != NULL){
            paststudent = currentstudent;
            free(paststudent);
            currentstudent = currentstudent->next;

        }
    }

}

/*
 * Insert the record unless a record with the same ID already exists in the hash table.
 * If the record already exists, print "INSERT (<ID>) cannot insert because record exists".
 * If the record does not exist, print "INSERT (<ID>) <Exam 1 Score> <Exam 2 Score> <Name>".
 */
void insert_student(int student_id, int exam1_score, int exam2_score, char name[])
{
     // get hash code
    int studenthash = hash(student_id);
    student_t* temp;
    
    // temp points at the first node in the linked list (the index of the array)
    temp = hashtable[studenthash];

     // if bucket is completely empty 
     if (temp == NULL){
        student_t* newstudent = (struct student*)malloc(sizeof(struct student));
        newstudent->student_id = student_id;
        newstudent->exam1_score = exam1_score;
        newstudent->exam2_score = exam2_score;
        strcpy(newstudent->name, name);
        printf("INSERT (%d) %d %d %s\n", student_id, exam1_score, exam2_score, name);
        newstudent->next= NULL;
        //set first node in empty bucket to student
        hashtable[studenthash]= newstudent;
        return;
        }

     // otherwise
     student_t* behind = NULL; 
     while (temp != NULL){
        if (student_id == temp->student_id){
            printf("INSERT (%d) cannot insert because record exists\n", student_id); 
            return;
        }
        behind = temp;
        temp = temp-> next;
    }    
    
                 //allocate space for new node
                student_t* newstudent = (struct student*)malloc(sizeof(struct student));
                 // get info from struct fields
                newstudent->student_id = student_id;
                newstudent->exam1_score = exam1_score; 
                newstudent->exam2_score = exam2_score;
                strcpy(newstudent->name, name);
                printf("INSERT (%d) %d %d %s\n", student_id, exam1_score, exam2_score, name);
                newstudent->next= NULL;
                //set temp in empty bucket to student
                behind->next = newstudent;
                return;
}

/*
 * Delete the record for the specified ID, if it exists in the hash table.
 * If the record already exists, print "DELETE (<ID>) <Exam 1 Score> <Exam 2 Score> <Name>".
 * If the record does not exist, print "DELETE (<ID>) cannot delete because record does not exist".
 */
void delete_student(int student_id)
{
    int studenthash = hash(student_id);
    student_t* temp;
    student_t* behind;
    temp = hashtable[studenthash];
    behind = NULL;

    //bucket is empty
    if (temp == NULL){
        printf("DELETE (%d) cannot delete because record does not exist\n", student_id);
        return;
    }
    //bucket has students
    else{
        while (temp!= NULL){
        //if first item
        if (student_id == temp->student_id){
            hashtable[studenthash]=temp->next;
        }
        else{

            behind = temp;
            temp = temp-> next;
        }
        
        int exam2_score = temp->exam2_score;
        char name[16];
        printf("DELETE (%d) %d %d %s\n", student_id, temp->exam1_score, temp->exam2_score, temp->name);
        free(temp);
        return;
        }
    }

 
}

/*
 * Print all the member variables for the record with the specified ID, if it exists in the hash table.
 * If the record already exists, print "LOOKUP (<ID>) <Exam 1 Score> <Exam 2 Score> <Name>".
 * If the record does not exist, print "LOOKUP (<ID>) record does not exist".
 */
void lookup_student(int student_id)
{
    // get hash code
    int studenthash = hash(student_id);
    int exam2_score;
    int exam1_score;
    char name[16];
    // pointer
    student_t* temp;
     temp = hashtable[studenthash];
         while (temp != NULL){
            if (student_id == temp->student_id){
                exam1_score = temp->exam1_score;
                exam2_score = temp->exam2_score;
                 printf("LOOKUP (%d) %d %d %s\n", student_id, exam1_score, exam2_score, temp->name); 
                 return;
                 }
        
            temp = temp->next;
         
         
         }
         printf("LOOKUP (%d) record does not exist\n", student_id);
         return;
}

/*
 * main:
 *   - Reads in a filename from the command line arguments.
 *   - Opens and parses the file.
 *   - Calls the appropriate hash table functions.
 */
int main(int argc, char *argv[]){
    init_hash_table();

    FILE *fptr;

    if (argc != 2)
    {
        printf("Expected one argument but got %d", argc - 1);
        return EXIT_FAILURE;
    }

    if ((fptr = fopen(argv[1], "r")) == NULL)
    {
        printf("Error opening file `%s`!", argv[1]);
        return EXIT_FAILURE;
    }

    char command_type;
    int student_id, exam1_score, exam2_score;
    char name[16];

    while (fscanf(fptr, "%c %d %d %d %s\n", &command_type, &student_id, &exam1_score, &exam2_score, name) != EOF)
    {
        if (command_type == 'i')
        {
            insert_student(student_id, exam1_score, exam2_score, name);
        }
        else if (command_type == 'd')
        {
            delete_student(student_id);
        }
        else if (command_type == 'l')
        {
            lookup_student(student_id);
        }
        else
        {
            printf("Invalid command type `%c`!", command_type);
            return EXIT_FAILURE;
        }
    }

    fclose(fptr);

    dealloc_hash_table();

    return EXIT_SUCCESS;
}