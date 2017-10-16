#ifndef bstree_included
#define bstree_included

typedef struct BNode{
  struct BNode *right, *left;
  char *value;
}BNode;

BNode *bsAlloc();
/* add new name to the tree*/

void addNode(BNode *nb, char *name);

/* removes a name from tree*/

void removeNode(BNode *nb, char *name);

/* Prints the values of the tree in order*/

void printTree(BNode *root);

void writeInFile(char *namw);

void readFile();


#endif

  
