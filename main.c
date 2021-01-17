
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"frequency.h"

int main(int argc, char* argv[]) {
	char* r = "r";
	node* head = new_node();
	char c[100];
	char word[100];

	// while it is not end of file  keep reading
	while (scanf("%s", word) != EOF)
		add_word(head, word);

	// if the second word of the commend it is 'r'
	// turns on print_words_reverse
	if (argv[1] != NULL) {
		if (strcmp(r, argv[1]) == 0)
			print_words_reverse(head, c);
	}
	// turns on print_words
	else {
		print_words(head, c);
	}
	//releases the memory
	free_node(head);
	return 0;
}
