
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary_hashtable.h"
#include "file_handler.h"


void create_dictionary(int key, FILE *fp){
//initial memory allocation
char* string = malloc(1);
char* string2 = malloc(1);
int count = 0;
int count2 = 0;

//char variable used to parse through txt document
int ch;

//initializing the data structure 
initialWord = (struct DictionaryWord*) malloc(sizeof(struct DictionaryWord));
initialWord->key = -1;

initialWord = defaultWord();

//Open dictionary file
if((fp = fopen("./dictionary2.txt", "r")) == NULL) {
    printf("Cant open %s\n", "dictionary.txt");
    exit(1);
}
while ((ch = getc(fp)) != EOF){
    if(ch == '\n'){
		
	    for(int i = 0; i < count2; i++){

	        key += (int)string2[i];
 
	    }
		
	    //Insert key and word into the hashtable
	    insert(key, string2, count2);
	

	    free(string2);
	    string2 = calloc(1 ,sizeof(char));
	    count2 = 0;
	    key = 0;

	} else {
	    string2 = realloc(string2, count2 + 1);
	
	    string2[count2] = ch;
	    count2 += 1;
	}

}

fclose(fp);
}

void write_to_solutions(int sizeKey, FILE *fp_write){

    if((fp_write = fopen("./solutions.txt", "a/")) == NULL) {
        printf("Cant open %s\n", "solutions.txt");
        exit(1);
    }

    fprintf(fp_write, "%d\n", sizeKey);
    fclose(fp_write);
}

        
void write_to_solutions2(int sizeKey, FILE *fp_write2){

    if((fp_write2 = fopen("./solutions.txt", "w")) == NULL) {
        printf("Cant open %s\n", "solutions.txt");
        exit(1);
    }

    fprintf(fp_write2, "%d\n", sizeKey);
    fclose(fp_write2);

}
      
