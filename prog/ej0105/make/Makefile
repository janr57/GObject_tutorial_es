# Makefile para los ejemplos

CC = gcc
CFLAGS=`pkg-config --cflags glib-2.0 gobject-2.0`
LDFLAGS=`pkg-config --libs glib-2.0 gobject-2.0`

EJEMPLOS=ejemplo01 ejemplo02 ejemplo03 ejemplo04 ejemplo05

ALL: $(EJEMPLOS)

%: ../src/%.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)

.PHONY: clean run

clean:
	rm -f $(EJEMPLOS)
