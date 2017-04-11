CC = gcc
CFLAGS = -g
PKG_FLAGS = `pkg-config --cflags --libs glib-2.0`

ex_compile: ex_compile.c
	$(CC) $^ -o $@ $(CFLAGS) $(PKG_FLAGS)

word_count: word_count.c
	$(CC) $^ -o $@ $(CFLAGS) $(PKG_FLAGS)