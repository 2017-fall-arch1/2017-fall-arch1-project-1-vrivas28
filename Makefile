all: bstree

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

bstree: bstree.o
	cc -o $@ $^

bstree.o: bstree.c bstree.h
	cc -c $(CFLAGS) bstree.c

clean:
	rm -f *.o bstree

demo: bstree
	(echo first; echo "second line"; echo "third and last") | ./bstree

