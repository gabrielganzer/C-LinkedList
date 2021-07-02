/*
 ============================================================================
 Name        : prompt
 Author      : Gabriel Ganzer
 Version     : v1.0
 Copyright   : Gabriel Ganzer, 2021
 Description : Linked list manipulation in C, Ansi-style
 ============================================================================
 */

#include "lib/list.h"

int main(int argc, char *argv[]) {
	
	/* ------------------- Local Variables ------------------- */
    char input[32];

	/* ------------------- Initialization -------------------- */
    head = tail = NULL;
	count = 0;

	/* ------------------- Main Procedure -------------------- */
	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		} else if ((strncmp(input, "put", 3) == 0)) {
            put(find_number(input));
			list();
		} else if ((strncmp(input, "get", 3) == 0)) {
			get(find_number(input));
		} else if ((strncmp(input, "delete", 6) == 0)) {
			delete(find_number(input));
		} else if ((strncmp(input, "list", 4) == 0)) {
			list();
		} else if ((strncmp(input, "first", 5) == 0)) {
			first();
		} else if ((strncmp(input, "last", 4) == 0)) {
			last();
		} else if ((strncmp(input, "sort", 4) == 0)) {
			sort();
		} else if ((strncmp(input, "clean", 5) == 0)) {
			clean();
			list();
		} else if (strncmp(input, "exit", 4) == 0) {
			printf("Good bye!\n");
			break;
		} else {
			print_entry(input);
		}
	}

	return EXIT_SUCCESS;
}
