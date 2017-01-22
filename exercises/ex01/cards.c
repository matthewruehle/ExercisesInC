/* 
 * Excercise 1, Software Systems s17.
 * Matt Ruehle.
 */

#include <stdio.h>
#include <stdlib.h>

void get_input(char * destination) {
	puts("Enter the card_name: ");
	scanf("%2s", destination);
	return;
}

void process_count(int * count, int val) {
	if ((val > 2) && (val < 7)) {
		*count = *count + 1;
	} else if (val == 10) {
		*count = *count - 1;
	}
	printf("Current count: %i\n", *count);
	return;
}

void card_to_value(char *card_name, int * val) {
	switch (toupper(card_name[0])) {
		case 'K':
		case 'Q':
		case 'J':
			*val = 10;
			break;
		case 'A':
			*val = 11;
			break;
		case 'X':
			puts("Closing...");
			*val = -1;
			break;
		default:
			*val = atoi(card_name);
			if ((*val < 1) || (*val > 10)) {
				puts("I don't understand that value!");
			}
			break;
		}
}

int main()
{
	char card_name[3];
	int count = 0;
	int val;
	while (card_name[0] != 'X' && card_name[0] != 'x') {
		get_input(card_name);
		card_to_value(card_name, &val);
		process_count(&count, val);
	}
	return 0;
}

