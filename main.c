#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 100

struct{
	char *content;
	int count;
} typedef Word_S;

Word_S *create_struct_from_word(char *word);
void print_word(Word_S *word_s);

int main(int argc, char const *argv[]){
	FILE *fp_in, *fp_out;
	Word_S *words_array[10 * MAX_ROWS] = {NULL};
	char word[20];
	int counter;

	fp_in = fopen(argv[1], "r");
	fp_out = fopen(argv[2], "w");

	if(argc != 3){
		printf("You\'ve to pass three inputs!\n");
		exit(EXIT_FAILURE);
	}

	if(fp_in == NULL || fp_out == NULL){
		printf("couldn't open input or output file!\n");
		exit(EXIT_FAILURE);
	}

	counter = 0;
	while(!feof(fp_in) && fscanf(fp_in, "%s", word)){
		words_array[counter] = create_struct_from_word(word);
		counter++;
	}
	
	for (counter = 0; counter < 10*MAX_ROWS; ++counter){
		print_word(words_array[counter]);
	}

	return 0;
}

Word_S *create_struct_from_word(char *word){
	Word_S *word_s = malloc(sizeof(Word_S));
	int i;

	//allocate memory for the word
	word_s->content = malloc(strlen(word+1) * sizeof(char));

	//turn the string into lower case
	//loop through each element of the word and turn each of them into lower case
	for (i = 0; i < strlen(word); ++i){
		word[i] = (char)tolower(word[i]);
	}

	//copy the string into struct content
	strcpy(word_s->content, word);

	word_s->count = 1;

	return word_s;
}

void print_word(Word_S *word_s){
	if(word_s != NULL)
		printf("Word: %s Total: %d\n", word_s->content, word_s->count);
}