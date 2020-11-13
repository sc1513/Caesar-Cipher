#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary_hashtable.h"
#include "shift_matrix.h"
#include "file_handler.h"

/*
Author Steven Carpenter
Date: 9/5/2020
Name: Decryption C program
Function: Allows user to decrypt a ceasar cypher encription.
*/

int main(int argc, char *argv[]){

//My Key
int sizeKey = 0;
int key = 0;

//initial memory allocation
char* string = malloc(1);
char c = 0;
int count = 0;

//file handling
FILE *fp;
FILE *fp_write;
FILE *fp_write2;
int tf = 0;

//Open dictionary file
create_dictionary(key, fp);

//Loop for getting user input
while((c = getchar()) != EOF){
    
    if(c == '\n' || c == 0){
        
        // shift matrix returns the key for the sentance input
        sizeKey = shift_matrix(string, count);
       
        // Condition for writing the file, either false for write to a file and true to append to the same file.
        if(tf){
            write_to_solutions(sizeKey, fp_write);
        } else {
            write_to_solutions2(sizeKey, fp_write2);
            tf++;
        }

	    free(string);
        string = calloc(1, sizeof(char));
        count = 0;

    } else {

        string = realloc(string, count + 1);
        string[count] = c;   
        count += 1;
        
    }
}

return 0;

}