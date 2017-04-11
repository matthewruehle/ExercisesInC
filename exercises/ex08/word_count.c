/*
Word count implementation using GLib.
-Matt, SoftSys 2017.
*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <ctype.h>
#include <string.h>

char* DEFAULT_FILE = "wonderland_carroll.txt";

void make_lower_alpha(char* source, char* target){
	// currently unused; not working. will try to fix later,
	// but i'm already a little late with submitting this
	// so it will wait a bit.
	int i;
	int j = 0;
	for (i=0; source[i]; i++) {
		if (isalpha(source[i])) {
			target[j] = tolower(source[i]);
			j++;
		}
	}
}

void make_counts_table (GHashTable* wc, char* filename) {
  FILE* fp;
  char wordbuf[80];
  char word_processed[80]; // unused currently.
  int oldval, newval;
  fp = fopen(filename, "r");

  while (fscanf(fp, "%79s", wordbuf) != EOF) {
  	oldval = (int) g_hash_table_lookup(wc, wordbuf);
  	if (oldval) {
  		newval = oldval + 1;
  		g_hash_table_replace(wc, strdup(wordbuf), GINT_TO_POINTER(newval));
  	} else {
  		newval = 1;
  		g_hash_table_insert(wc, strdup(wordbuf), GINT_TO_POINTER(newval));
  	}
  }
  fclose(fp);
}

// trying this with more glib stuff, but it's garbling the
// file right now for some reason. will look at more, later!

// void make_counts_table(GHashTable* wc, char* filename) {
// 	int i;
// 	int old_val, new_val;
// 	gchar* file_as_str;
// 	g_file_get_contents(filename, &file_as_str, NULL, NULL);
// 	g_strdelimit(file_as_str, "’!�@#$\"'()-+?=.,", " ");
// 	gchar** all_words = g_strsplit(file_as_str, " ", -1);

// 	for (i = 0; all_words[i] != NULL; i++) {
// 		old_val = GPOINTER_TO_INT(g_hash_table_lookup(wc, all_words[i]));
// 		new_val = old_val + 1;
// 		g_hash_table_replace(wc, strdup(all_words[i]), GINT_TO_POINTER(new_val));
// 	}
// }

void print_count (gpointer key, gpointer value, gpointer data) {
	printf("%s : %d\n", key, (int) value);
}

int main(int argc, char* argv[]) {
	GHashTable* wc = g_hash_table_new(g_str_hash, g_str_equal);

	if (argc >= 2) {
		make_counts_table(wc, argv[1]);
	}
	else {
		make_counts_table(wc, DEFAULT_FILE);
	}

	g_hash_table_foreach(wc, print_count, NULL);

	return 0;
}











