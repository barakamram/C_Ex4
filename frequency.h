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
void remove_letters(char* s);
void add_word(node* head, char* word);
void free_node(node* n);

void print_frequency(node* head,char* c);
void freq(node* node, char* c,int level);

void print_frequency_reverse(node* head, char* c);
void freq_rev(node* node, char* c, int level);

#endif
