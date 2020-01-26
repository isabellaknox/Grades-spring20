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
struct student{
    int student_id;
    int exam1_score;
    int exam2_score;
    char name[16];
    struct student* next;
}

struct student* hashtable[13];


/*
 * Simple hash function.
 */
int hash(int i)
{
    // creates hash codes to know which bucket to place item in 
    return (i % 13);
}

/*
 * Initialize the hash table.
 */
void init_hash_table()
{
    for (int i; i <=13;i++){
        //hastable[i]= (student*)malloc(sizeof(student)); // allocate memory for each node
        hashtable[i]== NULL;
    }
}

/*
 * Deallocate the hash table.
 */
void dealloc_hash_table(){

    // TODO: Implement
    for (int i; i<= 13; i++){
        if (hashtable[i]==NULL){
            free(hashtable[i];)
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
    // TODO: Implement
}

/*
 * Delete the record for the specified ID, if it exists in the hash table.
 * If the record already exists, print "DELETE (<ID>) <Exam 1 Score> <Exam 2 Score> <Name>".
 * If the record does not exist, print "DELETE (<ID>) cannot delete because record does not exist".
 */
void delete_student(int student_id)
{
    // TODO: Implement
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
    // pointer
    struct student* temp;
    struct student* next;
    // go through array 
    for (int i=0; i<=13; i++){
        if (hashtable[i] == studenthash){
                temp = hashtable[i];
                next = hashtable[i+1]
                   while (temp != NULL){
                       if (next != NULL){
                          if (student_id== temp){
                         printf("LOOKUP (%d) %d %d %s\n", student_id, exam1_score, exam2_score, name);  
                       }
                       
                       
                       temp-> next;
                       temp = temp->next;
                       
                }
                   }
            
        }
        else{

        }

    }

}

/*
 * main:
 *   - Reads in a filename from the command line arguments.
 *   - Opens and parses the file.
 *   - Calls the appropriate hash table functions.
 */
int main(int argc, char *argv[])
{
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
