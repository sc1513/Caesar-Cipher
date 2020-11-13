#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shift_matrix.h"
#include "dictionary_hashtable.h"

char* shift(char* x, char* y, int size, int shift_amount){
        
    for (int i = 0; i < size; i++){
        y[i] = x[i];
    }

    for (int i = 0; i < size; i++){
        y[i] -= shift_amount;
        if(y[i] < 65){
            y[i] += 26;
        }
    }
    return y;
}

int check_dictionary(char* x, int size){
    int tf = 0;
    int key = 0;
    for (int i = 0; i < size; i++){

        key += (int)x[i];

    }
    
    if(search(key, x, size) != NULL){
        tf += 1;
        return tf;
    }

    return tf;

}

int shift_matrix(char* x, int size){

int count = 0;
int count_shifts = 0;
int count2 = 0;
char *string = malloc(1);
int *shifts = malloc(sizeof(int));
int *total_shifts = malloc(sizeof(int));
int s = 0;
char *y = malloc(1);

for (int i = 0; i <= size; i++){
	if(x[i] == 32 || x[i] == '\0'){
		
		if(count_shifts == 0){
			
			for(int j = 0; j < 26; j++){
                
                y = shift(string, y, count, j);
				if(check_dictionary(y, count) != 0){
                    
                    shifts[count_shifts] = j;

                    count_shifts++;

                    shifts = realloc(shifts, count_shifts * sizeof(int) + sizeof(int));
							
				}
			}

		} else {
			        
			s = count_shifts - count2;
			for(int j = 0; j < s; j++){

				//y = realloc(y, count * sizeof(int));
                y = shift(string, y, count, shifts[j]);
				if(check_dictionary(y,count) != 0){
                    
                total_shifts[count2] = shifts[j];

                    count2++;

                    total_shifts = realloc(total_shifts, count2  * sizeof(int) + sizeof(int));
					
				}
                
			}
		
        }
		free(string);
		string = calloc(1, sizeof(int));
		count = 0;
        free(y);
        y = calloc(1, sizeof(int));

	} else {
	
		string = realloc(string, count + 1);
        string[count] = x[i];
		count += 1;
        y = realloc(y, count + 1);
        	
	}

}
int key1 = 0;

if(count_shifts > 1){
    key1 = total_shifts[0];
} else {
    key1 = shifts[0];
}

free(string);
string = calloc(1, sizeof(int));

free(shifts);
shifts = calloc(1, sizeof(int));

free(y);
y = calloc(1, sizeof(int));

free(total_shifts);
total_shifts = calloc(1, sizeof(int));

return key1;

}
