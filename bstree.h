#ifndef bstree_included
#define bstree_included

typedef struct BNode{
  struct BNode *right, *left;
  char *name;
}BNode;

BNode* bsAlloc(char *eName);
/* add new name to the tree*/
BNode* addNode(BNode *node, char *eName);

/* removes a name from tree*/
BNode* removeNode(BNode *node, char *eName);

/* Will find the minimum node of the tree*/
BNode* minNode(BNode *node);

/* Prints the values of the tree in order*/

void printTree(BNode *node);

void writeInFile(char *eName);

BNode* readFile(BNode *node, char *eName);


#endif
