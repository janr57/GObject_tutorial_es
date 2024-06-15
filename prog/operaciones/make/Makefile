# Makefile para los ejemplos

CC = gcc
CFLAGS=`pkg-config --cflags glib-2.0 gobject-2.0`
LDFLAGS=`pkg-config --libs glib-2.0 gobject-2.0`

PROG = operaciones
FILE1 = main
FILE2 = tdouble

ALL: $(PROG)

$(FILE2).o: ../src/$(FILE2).c ../src/$(FILE2).h
	$(CC) -c -o $@ $< $(CFLAGS)

$(FILE1).o: ../src/$(FILE1).c ../src/$(FILE2).c
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROG): $(FILE1).o $(FILE2).o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf _build build
	rm -f $(PROG) $(FILE1).o $(FILE2).o *.h.gch

