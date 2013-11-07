#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 100

struct{
	char *content;
	int count;
} typedef Word_S;

Word_S *read_word_from_file(char *word);

int main(int argc, char const *argv[]){
	FILE *fp_in, *fp_out;
	Word_S *words_array[10 * MAX_ROWS * sizeof(Word_S)] = {NULL};
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
	while(!feof(fp_in) && fscanf(fp_in, "%s", word) && counter < 10*MAX_ROWS){
		words_array[counter] = read_word_from_file(word);
		printf("el: %d content: %s\n", counter-1, words_array[counter-1]->content);
		counter++;
	}
	
	for (counter = 0; counter < 10*MAX_ROWS; ++counter){
		if(words_array[counter] != NULL)
			printf("el: %d content: %s\n", counter, words_array[counter]->content);
	}

	return 0;
}

Word_S *read_word_from_file(char *word){
	Word_S *word_s = malloc(sizeof(Word_S));

	word_s->content = word;
	word_s->count = 1;

	return word_s;
}
/*
	while(!feof(fp_in) && fscanf(fp_in, "%s", word) && counter < MAX_ROWS){
		words = read_word(word);
		printf("word : %s\t", words.content);
		printf("total: %d\n", words.count);
		counter++;
	}
*/