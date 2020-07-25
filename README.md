# 250 Homework 1


------ Section 1----- 
Write a C program called bySeventeen.c that prints out the first N positive numbers that are
divisible by 17, where N is an integer that is input to the program on the command line. Since your
binary executable is called bySeventeen.o, then you’d run it on an input of 3
with: ./bySeventeen.o 3. Your output in this case should look like:
17
34
51
Be sure that your main function returns EXIT_SUCCESS (i.e. 0) on a successful run. 


------ Section 2----- 

recurse.c
A C program called recurse.c that computes f(N), where N is an integer greater than zero
that is input to the program on the command line. f(N) = 3*f(N-1)+4*f(N-2)+2. The base case
is f(0)=1 and f(1)=2. Your code must be recursive. The key aspect of this program is to teach you
how to use recursion; code that is not recursive will be severely penalized! 

Your program should output a single integer and should be executed using the
command./recurse.o N for some number N.

Be sure that your main function returns EXIT_SUCCESS (i.e. 0) on a successful run. 

------ Section 3----- 
Grades.c

A C program that implements a hash table (hashmap). The basic data structure you will use to
implement your hash table is an array of linked lists. Keys map to buckets (array elements) and are then
stored in linked lists associated with that bucket.

Each element in the array is a pointer to a linked list node structure. The initial array is just a collection
of NULL pointers. Nodes are added to the linked list when new information is inserted into the
hashtable. Keys that map to the same bucket (called collisions) are simply added to the linked list
associated with the bucket. See the example hash table below.

Your hash table should have 13 elements/buckets (i.e. pointers) in the array and use the linked lists to
store an arbitrary number of records. Each record (i.e. struct) represents a student.
The members of the struct should be:
• An integer representing the student’s ID
• An integer for exam1 score.
• An integer for exam2 score.
• A character array to hold a string guaranteed not to exceed 16 characters, representing the
student’s name. The 16 characters includes the terminating null character.

The ID should be used as the hash table key (i.e., to compute an array index in a consistent manner, the
same ID should always provide the same array index).
You must implement functions to (see below for function specifications):
• Insert a record (i.e. structs) to the hash table
• Delete a record from the hash table based on ID
• Lookup a record in the hash table based on ID

You must use malloc within insert and free within delete, failure to use free leads to all kinds of memory
allocation problems in runtime and thus will be penalized.
Using these functions you should write a program that reads commands to insert, delete, and lookup
records in the hash table from a file given as a function argument. The general form for commands is
operation ID exam1 exam2 name where operation is a single character i for insert, d for
delete, and l for lookup; ID, exam1 and exam2 are integers; name is a string.
The grades.c program should be executed using the command
./grades.o FILE_NAME
where FILE_NAME is the name of the file which contains the commands to be executed.


NOTE: All commands will be valid. Nothing should be printed if an empty file is provided. IDs will be in
the range [0, 2^31 - 1], inclusive. Exam scores will be in the range [0, 100], inclusive. The name will
include ASCII upper and lowercase characters and will be at least one character long (not exceeding 16
including the string termination character).



