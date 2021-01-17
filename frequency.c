
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include"frequency.h"

// a new node is ready to use
node* new_node() {
	node* n = (node*)malloc(sizeof(node));
	if (n == NULL)
		printf("malloc not work, please try again");
	n-> count = 0;
	for (int i = 0; i < NUM_LETTERS; i++)
		n-> children[i] = NULL;
	return n;
}

// changes all the upper-case to lower-case
void chenge_letters(char str []){
	for (int i = 0; str[i]!='\0'; i++)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
}

// after change_letters the method remove all the chars
// that are not between 'a' to 'z'
void remove_char(char* s) {
	int writer = 0, reader = 0;
	while (s[reader]) {
		if (s[reader] >= 'a' && s[reader] <= 'z')
			s[writer++] = s[reader];
		reader++;
	}
	s[writer] = 0;
}

// checks if the node doesnt exist in the trie
// if not create a new node else reads the char until their
// is no more chars to read and add the new chars to the trie
// a pointer point to the address of the word
void add_word(node* head,char* word) {
	chenge_letters(word);
	remove_char(word);
	node* pointer = head;
	int i = 0;
	while (i<strlen(word)) {
		if (pointer-> children[*(word + i) - 97] == NULL) {
			pointer-> children[*(word + i) - 97] = new_node();
			pointer = pointer-> children[*(word + i) - 97];
			pointer-> letter = *(word + i);
			i++;
		}
		else {
			pointer = pointer-> children[*(word + i) - 97];
			i++;
		}
	}
	pointer-> count++;
	pointer-> isItWord = TRUE;
}

// checks if the node is NULL if not releases memory
// passing the function by recursion
void free_node(node* node) {
	if (node == NULL)
		return;
	else
		for (int i = 0; i < NUM_LETTERS; ++i)
			free_node((node-> children)[i]);
	free(node);
	return;
}

// reads the first word and updates the level of the trie and sends it
// to print_words_help method to continue printing and reading
void print_words(node* head,char* c) {
	for (int i = 0; i < NUM_LETTERS; i++)
		if (head-> children[i] != NULL) {
			int level=1;
			print_words_help(head-> children[i],c,level);
		}
}

// this method helps to the print_words method
// passing the function by recursion
void print_words_help(node* node, char* c,int level) {
	if (level <= strlen(c))
		c[level-1] = '\0';

	strncat(c, &node->letter, 1);
	if (node-> isItWord == TRUE)
		printf("%s %ld\n", c, node-> count);

	for (int i = 0; i < NUM_LETTERS; i++)
		if (node-> children[i] != NULL)
			print_words_help(node-> children[i], c,level+1);
}

// reads the last word and updates the level of the trie and sends it
// to print_words_reverse_help method to continue printing and reading
void print_words_reverse(node* head, char* c) {
	for (int i = NUM_LETTERS-1; i >= 0; i--)
		if (head-> children[i] != NULL) {
			int level = 1;
			print_words_reverse_help(head-> children[i], c, level);
		}
}

// this method helps to the print_words_reverse method
// passing the function by recursion
void print_words_reverse_help(node* node, char* c, int level) {
	if (level <= strlen(c))
		c[level - 1] = '\0';

	strncat(c, &node-> letter, 1);
	if (node-> isItWord == TRUE)
		printf("%s %ld\n", c, node-> count);

	for (int i = NUM_LETTERS-1; i>=0; i--)
		if (node-> children[i] != NULL)
			print_words_reverse_help(node-> children[i], c, level + 1);
}
