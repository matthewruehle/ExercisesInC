// Alternate implementation of 'tee' command
// SoftSys 17 			Matt


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>


int main(int argc, char *argv[]) {
	int i, j, k;
	int append_flag = 0;
	char this_line[80];
	char this_arg;

	while ((this_arg = getopt(argc, argv, "ah?")) != EOF) {
		switch (this_arg) {
			case 'a':
				append_flag = 1;
				break;
			case '?':
			case 'h':
				fprintf(stdout, "works like 'tee' hopefully i guess?");
				exit(1);
			default:
				fprintf(stderr, "i have no idea what '%c' is", this_arg);
				exit(1);
		}
	}

	argc -= optind;
	argv += optind;

	FILE *fps[argc];

	for (i = 0; i < argc; i++) {
		if (append_flag) {
			fps[i] = fopen(argv[i], "a");
		} else {
			fps[i] = fopen(argv[i], "w");
		}
	}

	while ((fscanf(stdin, "%79[^\n]\n", this_line)) == 1) {
		fprintf(stdout, "%s\n", this_line);
		fflush(stdout);

		for (i = 0; i < argc; i++) {
			fprintf(fps[i], "%s\n", this_line);
			fflush(fps[i]);
		}
	}  // maxlen of 80; \n terminated.

	for (i = 0; i < argc; i++) {
		fclose(fps[i]);
	}

	return 0;
}