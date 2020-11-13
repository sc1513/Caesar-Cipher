//Hash table function for my dictionary

#ifndef HASH_T

#define SIZE 3000
#define INCREMENT 2
struct DictionaryWord {
	char word[25];
	int wordLength;
	int key;
};

struct DictionaryWord* hashArray[SIZE];
struct DictionaryWord* initialWord;
struct DictionaryWord* word;


extern struct DictionaryWord *defaultWord();

//formula for hashing the key
extern int hashCode(int key);

//function used to search the table
extern struct DictionaryWord *search(int key, char *string, int length);

//function used to insert values into the hashtable
extern void insert(int key, char string[], int length);

#endif