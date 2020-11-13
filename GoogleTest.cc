// Google Test Suite
// Test Caeser Cipher Program
#include <gtest/gtest.h>
#include "dictionary_hashtable.hh"
#include "shift_matrix.hh"
#include "file_handler.hh"
#include <string.h>
#include <stdio.h>

TEST(DictionaryTest, WordLength_Is_Zero){
	DictionaryWord *TestDictionary = defaultWord();

	ASSERT_TRUE(0 == TestDictionary->wordLength);
}

TEST(DictionaryTest, defaultWord_Is_Not_Null){
	DictionaryWord *TestDictionary = defaultWord();

	ASSERT_FALSE(NULL == TestDictionary);
}

TEST(DictionaryTest, key_Is_Negative_One){
	DictionaryWord *TestDictionary = defaultWord();

	ASSERT_TRUE(-1 == TestDictionary->key);
}

TEST(DictionaryTest, Total_amount_of_inserts){
	FILE *fp;
	create_dictionary(0,fp);
	int NumEntries = 0;

	for (int i = 0; i < SIZE; i++){
		if(hashArray[i] != NULL)
			NumEntries++;
	}

	ASSERT_TRUE(NumEntries < SIZE);
	ASSERT_EQ(NumEntries, 2183);
}

TEST(DictionaryTest, Check_For_Duplicates_In_Hash_Table){
	
	//initialize data structures
	FILE *fp;
	create_dictionary(0,fp);
	
	//check for duplicates in data structures
	int NumberOfDuplicates = 0;
	for (int i = 0; i < SIZE; i++){
		for (int j = i + 1; j < SIZE; j++){
			if(hashArray[i] != NULL && hashArray[j] != NULL){
				if(!strcmp(hashArray[i]->word, hashArray[j]->word)){
					NumberOfDuplicates++;
				}
			}
		}
	}
	
	ASSERT_EQ(0, NumberOfDuplicates);
}

TEST(DictionaryTest, shift_Function){

	char myString [] = {'H','E','L','L','O'};
	char *myNewString;
	char array[5];
	myNewString = array;
	myNewString = shift(myString,myString,5,1);

	ASSERT_TRUE(myNewString[0] == 'G');
	ASSERT_TRUE(myNewString[1] == 'D');
	ASSERT_TRUE(myNewString[2] == 'K');
	ASSERT_TRUE(myNewString[3] == 'K');
	ASSERT_TRUE(myNewString[4] == 'N');
}

TEST(DictionaryTest, shift_Function2){


	char myString [] = {'W','O','R','L','D'};
	char *myNewString;
	char array[5];
	myNewString = array;
	myNewString = shift(myString,myString,5,10);

	ASSERT_TRUE(myNewString[0] == 'M');
	ASSERT_TRUE(myNewString[1] == 'E');
	ASSERT_TRUE(myNewString[2] == 'H');
	ASSERT_TRUE(myNewString[3] == 'B');
	ASSERT_TRUE(myNewString[4] == 'T');
}

TEST(DictionaryTest, check_dictionary){
	char myString [] = {'H','E','L','L','O'};
	FILE *fp;
	
	create_dictionary(0,fp);

	EXPECT_EQ(1 ,check_dictionary(myString, 5));
	
}

TEST(DictionaryTest, check_hashKey){
	
	//check key
	int key = 5983;

	EXPECT_EQ(2881 ,hashCode(key));
	
}

TEST(DictionaryTest, search_dictionary){
	
	//Create Dictionary
	FILE *fp1;
	create_dictionary(0,fp1);

	//Set pointer
	char myString [] = {'H','E','L','L','O'};
	char *ptr = &myString[0];
	
	//Create Key
	int key = 0;
	for (int i = 0; i < 5; i++){
		key += (int)ptr[i];
	}

	ASSERT_TRUE(search(key,ptr,5) != NULL);
	
}

TEST(DictionaryTest, search_dictionary_check_for_same_result){
	//Making sure that every search is consistent in the hashtable
	//Create Dictionary
	FILE *fp1;
	create_dictionary(0,fp1);

	//Set pointer
	char myString [] = {'H','E','L','L','O'};
	char *ptr = &myString[0];
	
	//Create Key
	int key = 0;
	for (int i = 0; i < 5; i++){
		key += (int)ptr[i];
	}

	char myString2 [] = {'H','E','L','L','O'};
	char *ptr2 = &myString2[0];
	
	//Create Key
	int key2 = 0;
	for (int i = 0; i < 5; i++){
		key2 += (int)ptr2[i];
	}

	ASSERT_EQ(search(key,ptr,5), search(key2,ptr2,5));
	
}

TEST(DictionaryTest, insert_dictionary){
	
	FILE *fp1;
	create_dictionary(0,fp1);
	char myString [] = {'S','T','E','V','E'};
	char *ptr = &myString[0];
	int key = 0;
	for (int i = 0; i < 5; i++){
		key += (int)ptr[i];
	}

	insert(key,ptr,5);

	ASSERT_TRUE(search(key,ptr,5) != NULL);

}

TEST(DictionaryTest, insert_test_word_length){
	
	FILE *fp1;
	create_dictionary(0,fp1);
	char myString [] = {'H','E','L','L','O'};
	char *ptr = &myString[0];
	int key = 0;
	for (int i = 0; i < 5; i++){
		key += (int)ptr[i];
	}

	insert(key,ptr,1);

	EXPECT_EQ(search(key,ptr,5)->wordLength, 5);

}

TEST(DictionaryTest, TestShift_Matrix){
	//initialize data structures
	FILE *fp;
	create_dictionary(0,fp);

	//taken from encrypted_text.txt
	char myString [] = {'C',' ','F','I','P','Y',' ','N','L','C','J','M'};

	ASSERT_TRUE(20 == shift_matrix(myString,13));
}


TEST(DictionaryTest, TestShift_Matrix2){
	//initialize data structures
	FILE *fp;
	create_dictionary(0,fp);

	//taken from encrypted_text.txt
	char myString [] = {'A','F','E',' ','J','Z','F','C',' ','S','L','Y','O','D',' ','O','Z','H','Y'};

	ASSERT_TRUE(11 == shift_matrix(myString,19));
}

int main(int argc, char* argv[]){

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	return 0;

}
