
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include"frequency.h"

node* new_node() {
	node* n = (node*)malloc(sizeof(node));
	if (n == NULL)
		printf("malloc not work, please try again");
	n-> count = 0;
	for (int i = 0; i < NUM_LETTERS; i++)
		n-> children[i] = NULL;
	return n;
}

void chenge_letters(char str []){
	for (int i = 0; str[i]!='\0'; i++)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
}

void remove_letters(char* s) {
	int writer = 0, reader = 0;
	while (s[reader]) {
		if (s[reader] >= 'a' && s[reader] <= 'z')
			s[writer++] = s[reader];
		reader++;
	}
	s[writer] = 0;
}

void add_word(node* head,char* word) {
	chenge_letters(word);
	remove_letters(word);
	node* temp = head;
	int i = 0;
	while (i<strlen(word)) {
		if (temp-> children[*(word + i) - 97] == NULL) {
			temp-> children[*(word + i) - 97] = new_node();
			temp = temp-> children[*(word + i) - 97];
			temp-> letter = *(word + i);
			i++;
		}
		else {
			temp = temp-> children[*(word + i) - 97];
			i++;
		}
	}
	temp-> count++;
	temp-> isItWord = TRUE;
}

void free_node(node* node) {
	if (node == NULL)
		return;
	else
		for (int i = 0; i < NUM_LETTERS; ++i)
			free_node((node-> children)[i]);
	free(node);
	return;
}

void print_frequency(node* head,char* c) {
	for (int i = 0; i < NUM_LETTERS; i++)
		if (head-> children[i] != NULL) {
			int level=1;
			freq(head-> children[i],c,level);
		}
}

void freq(node* node, char* c,int level) {
	if (level <= strlen(c))
		c[level-1] = '\0';

	strncat(c, &node->letter, 1);
	if (node-> isItWord == TRUE)
		printf("%s %ld\n", c, node-> count);

	for (int i = 0; i < NUM_LETTERS; i++)
		if (node-> children[i] != NULL)
			freq(node-> children[i], c,level+1);
}

void print_frequency_reverse(node* head, char* c) {
	for (int i = NUM_LETTERS-1; i >= 0; i--)
		if (head-> children[i] != NULL) {
			int level = 1;
			freq_rev(head-> children[i], c, level);
		}
}

void freq_rev(node* node, char* c, int level) {
	if (level <= strlen(c))
		c[level - 1] = '\0';

	strncat(c, &node-> letter, 1);
	if (node-> isItWord == TRUE)
		printf("%s %ld\n", c, node-> count);

	for (int i = NUM_LETTERS-1; i>=0; i--)
		if (node-> children[i] != NULL)
			freq_rev(node-> children[i], c, level + 1);
}
