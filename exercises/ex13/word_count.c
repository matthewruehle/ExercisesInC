/* Example code for Exercises in C

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

Started with ex-ghashtable-3.c from
http://www.ibm.com/developerworks/linux/tutorials/l-glib/section5.html

Note: this version leaks memory.

*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <glib/gstdio.h>


/* Represents a word-frequency pair. */
typedef struct {
    gint freq;
    gchar *word;
} Pair;


/* Compares two key-value pairs by frequency. */
gint compare_pair (gpointer v1, gpointer v2, gpointer user_data)
{
    Pair *p1 = (Pair *) v1;
    Pair *p2 = (Pair *) v2;
    return p1->freq - p2->freq;
}


/* Iterator that prints pairs. */
void pair_printor (gpointer value, gpointer user_data)
{
    Pair *pair = (Pair *) value;
    printf ("%d\t %s\n", pair->freq, pair->word);
}


/* Iterator that prints keys and values. */
void printor (gpointer key, gpointer value, gpointer user_data)
{
    printf (user_data, key, * (gint *) value);
}


/* Iterator that add key-value pairs to a sequence. */
void accumulator (gpointer key, gpointer value, gpointer user_data)
{
    GSequence *seq = (GSequence *) user_data;
    Pair *pair = g_new(Pair, 1);
    pair->word = (gchar *) key;
    pair->freq = * (gint *) value;

    g_sequence_insert_sorted (seq, 
			      (gpointer) pair, 
			      (GCompareDataFunc) compare_pair,
			      NULL);
}

/* Increments the frequency associated with key. */
void incr (GHashTable* hash, gchar *key)
{
    gint *val = (gint *) g_hash_table_lookup (hash, key);

    if (val == NULL) {
        gchar* key_1 = g_strdup(key);
    	gint *val1 = g_new (gint, 1);
    	*val1 = 1;
    	g_hash_table_insert (hash, key_1, val1);
    } else {
	*val += 1;
    }
}

// void free_kvp(gchar* key, gint* value) { // kvp : key value pair
//     g_free(key);
//     g_free(value);
// }

void free_kvp_wrapper(gpointer key, gpointer value, gpointer user_data) {
    // could probably just directly free the casts? todo: try that out.
    // just, not now because it is nighttime.
    g_free( (gchar *) key);
    g_free( (gint *) value);
    // free_kvp( (gchar *) key, (gint *) value);
}

// void free_pair(Pair* p) {
//     g_free(p);
// }

void free_pair_wrapper(gpointer value, gpointer user_data) {
    // free_pair as a GFunc
    g_free( (Pair*) value);
    // free_pair((Pair *) value);
}



int main (int argc, char** argv)
{
    gchar *filename;

    // open the file
    if (argc > 1) {
	filename = argv[1];
    } else {
	filename = "emma.txt";
    }

    FILE *fp = g_fopen(filename, "r");
    if (fp == NULL) {
	perror (filename);
	exit (-10);
    }

    /* string array is a (two-L) NULL terminated array of pointers to
       (one-L) NUL terminated strings */
    gchar **array;
    gchar line[128];
    GHashTable* hash = g_hash_table_new (g_str_hash, g_str_equal);
    int i;

    // read lines from the file and build the hash table
    while (1) {
	gchar *res = fgets (line, sizeof(line), fp);
	if (res == NULL) break;

	array = g_strsplit(line, " ", 0);
	for (i=0; array[i] != NULL; i++) {
	    incr(hash, array[i]);
        // g_free(array[i]);
	}
    g_strfreev(array);
    }
    fclose (fp);

    // print the hash table
    // g_hash_table_foreach (hash,  (GHFunc) printor, "Word %s freq %d\n");

    // iterate the hash table and build the sequence
    GSequence *seq = g_sequence_new (NULL);
    g_hash_table_foreach (hash,  (GHFunc) accumulator, (gpointer) seq);

    // iterate the sequence and print the pairs
    g_sequence_foreach (seq,  (GFunc) pair_printor, NULL);

    // try (unsuccessfully) to free everything
    // (in a future exercise, we will fix the memory leaks)
    
    g_hash_table_foreach(hash, (GHFunc) free_kvp_wrapper, NULL);
    g_hash_table_destroy (hash);

    g_sequence_foreach(seq, (GFunc) free_pair_wrapper, NULL);
    g_sequence_free (seq);

    return 0;
}

/*

==16473== LEAK SUMMARY:
==16473==    definitely lost: 1,890,348 bytes in 59,300 blocks
==16473==    indirectly lost: 931,607 bytes in 166,438 blocks
==16473==      possibly lost: 0 bytes in 0 blocks
==16473==    still reachable: 2,076 bytes in 3 blocks
==16473==         suppressed: 0 bytes in 0 blocks
==16473== Reachable blocks (those to which a pointer was found) are not shown.
==16473== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==16473== 
==16473== For counts of detected and suppressed errors, rerun with: -v
==16473== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)

*/
