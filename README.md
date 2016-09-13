# arch1-linked-list-demo

This directory contains:
* code that implements a linked list of strings 
* a demo program that uses it

The demo program reads lines from stdin.
Each line is appended onto a linked list.
After end-of-file is read, the lines are printed out.

This demo contains the following files:
 llist.h: header file of llist structure & "public" interface functions
 llist.c: implementation of linked list
 listDemo.c: a demonstration program that uses the linked list
 

To compile:
$ make

To test it, try:
$ make demo

To delete binaries:
$ make clean

Things to figure out
0. Examine llist.h.  It defines llist's structures and declares llist's interface.
  - seriously, look at the comments too.
  - notice how the #ifndef/endif at the top/botom prevents multiple inclusion
1. Peek at llist.c to see how llist's functions are implemented
2. Peek at llistDemo to see how llist is used.
3. Be sure you understand how these codes use malloc() and free().
3. Notice how the Makefile specifies the dependencies 
4. Try extending llist.  Perhaps
 A   - adding an llCheck() method to llist.c and llist.h that checks that the llist consistent
     - and modifying llDemo to use it
 B.  - adding llGet() method to llist.c and llist.h
     - that discards the first item and returns the string it contained
     - writing another demo (probably starting with ours) that tests llGet().
     - be sure to use llCheck
     - and adding Makefile productions to compile & test it
 C. the same as #1, but now add llReverse that reverses list order to llist.c

