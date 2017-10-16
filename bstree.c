#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bstree.h>

BNode *bsAlloc(char *eName)
{
  BNode *nb = (BTree *)malloc(sizeof(BTree));
  nb->malloc(strlen(eName)+1);
  nb->right = NULL;
  nb->left = NULL;
  
  return nb;
}

BNode addNode(BNode *node, char *eName)
{
  if(node == NULL)
    return node = *bsAlloc(eName);
  if(strcmp(node->name,eName)<0)
    {
      node->right = addNode(node->right, eName);
    }
  if(strcmp(node->name,eName)>0){
    node->left = addNode(node->left, eName);
  }
  return node;
}

