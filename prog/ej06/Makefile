# Makefile para los ejemplos

CC = gcc
CFLAGS=`pkg-config --cflags glib-2.0 gobject-2.0`
LDFLAGS=`pkg-config --libs glib-2.0 gobject-2.0`

PROG=ejemplo06

OBJ=main.o tdoble.o

ALL: $(PROG)

%.o: %.c %.h
	$(CC) -c $^ $(CFLAGS)

$(PROG): main.o tdoble.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf _build build
	rm -f $(PROG) $(OBJ) *.h.gch

