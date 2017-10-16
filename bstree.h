#ifndef bstree_included
#define bstree_included

typedef struct BNode{
  struct BNode *right, *left;
  char *name;
}BNode;


BNode *bsAlloc(char *eName);
/* add new name to the tree*/

struct BNode addNode(BNode *node, char *eName);

/* removes a name from tree*/

void removeNode(BNode *node, char *eName);

/* Prints the values of the tree in order*/

void printTree(BNode *node);

void writeInFile(char *eName);

void readFile();


#endif


  
