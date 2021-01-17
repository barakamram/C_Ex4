#ifndef FREQUENCY_H
#define FREQUENCY_H
#include <stdlib.h>
#define NUM_LETTERS 26
typedef enum { FALSE = 0, TRUE = 1 } boolean;

typedef struct node {
	boolean isItWord;
	char letter;
	long unsigned int count;
	struct node* children[NUM_LETTERS];
} node;

struct node* new_node();
void chenge_letters(char str[]);
void remove_char(char* s);
void add_word(node* head, char* word);
void free_node(node* n);

void print_words(node* head,char* c);
void print_words_help(node* node, char* c,int level);

void print_words_reverse(node* head, char* c);
void print_words_reverse_help(node* node, char* c, int level);

#endif
