
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"frequency.h"

int main(int argc, char* argv[]) {
	char* r = "r";
	node* head = new_node();
	char c[100];
	char word[100];

	while (scanf("%s", word) != EOF)
		add_word(head, word);

	if (argv[1] != NULL) {
		if (strcmp(r, argv[1]) == 0)
			print_frequency_reverse(head, c);
	}
	else
		print_frequency(head, c);

	free_node(head);
	return 0;
}
