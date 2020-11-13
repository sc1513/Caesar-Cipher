//Hash table function for my dictionary

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dictionary_hashtable.h"


//initialize to defualt variables
struct DictionaryWord *defaultWord(){
	struct DictionaryWord *word = (struct DictionaryWord*) malloc(sizeof(struct DictionaryWord));
	word->wordLength = 0;
	word->key = -1;
	word->word[0] = 32;
	
	return word;
}


//formula for hashing the key
int hashCode(int key) {
	return ((key * 7) % SIZE);
}

//function used to search the table
struct DictionaryWord *search(int key, char *string, int length){
	
	//get hash of the key
	int hashIndex = hashCode(key);
	
	// match bool variable to see if the contents of the array matches
	int match = 0;
	
	while(hashArray[hashIndex] != NULL) {

		//checking the contents of the array
		for(int i = 0; i < length || i < hashArray[hashIndex]->wordLength; i++){
			
			if(hashArray[hashIndex]->word[i] == string[i]){
		       	match += 1;
			}
		}
		
			if(hashArray[hashIndex]->key == key && match == length){
				return hashArray[hashIndex];
			}
		
			// go to next 4 cells, in order to spread out hashtable results
			hashIndex += INCREMENT;

			// set match back to 0
			match = 0;

			// wrap around the table
			hashIndex %= SIZE;
	}

	return NULL;
}

//function used to insert values into the hashtable
void insert(int key, char string[], int length){

	if(search(key, string, length) == NULL){

		struct DictionaryWord *word = (struct DictionaryWord*) malloc(sizeof(struct DictionaryWord));
		
		for (int i = 0; i < length; i++){

			word->word[i] = string[i];
		
		}

		word->key = key;
		word->wordLength = length;

		//printf("%s\n", word->word);
		//get the hash
		int hashIndex = hashCode(key);
	
		//move in array until there is an empty cell
		while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){
	
			//purposefully done to prevent bunching in the array
			hashIndex += INCREMENT;	

			//wraps around the enitre table
			hashIndex %= SIZE;
		}

		hashArray[hashIndex] = word;

	}

}


