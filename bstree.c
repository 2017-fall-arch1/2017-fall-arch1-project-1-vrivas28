#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"
//Creates a new node
BNode* bsAlloc(char *eName)
{
  BNode *nb = (BNode *)malloc(sizeof(BNode));
  nb->name = malloc(strlen(eName)+1);
  nb->right = NULL;
  nb->left = NULL;
  
  return nb;
}
// Adds a new node to the ninary serach tree.
BNode* addNode(BNode *node, char *eName)
{
  if(node == NULL)
     node = bsAlloc(eName);
  if(strcmp(node->name,eName)<0)
    {
      node->right = addNode(node->right, eName);
    }
  if(strcmp(node->name,eName)>0){
    node->left = addNode(node->left, eName);
  }
  return node;
}
/* Finds the node with the smallest value of the tree*/
BNode* minNode(BNode *node)
{
  if(node->left == NULL)
    return node;
  return minNode(node->left);
}
/* this method removes a given node from the tree*/
/* This piece of code was referenced from https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/*/
BNode* removeNode(BNode *node, char *eName)
{
  if(node == NULL)
    return node;
  if(strcmp(node->name, eName) < 0){
    node->right = removeNode(node, eName);
  }
  else if(strcmp(node->name, eName) > 0){
    node->left = removeNode(node,eName);
  }
  else{
    /*node had no children*/
    if(node->left == NULL && node->right == NULL){
      free(node);
      return NULL;
    }
    /*Removes a node that has one child*/ 
    else if(node->left == NULL){
      BNode *temp1 = (BNode *)malloc(sizeof(BNode));
      temp1 = node->right;
      free(node);
      return temp1;
    }
    else if(node->right == NULL){
      BNode *temp2 = (BNode *)malloc(sizeof(BNode));
      temp2 = node->left;
      free(node);
      return temp2;
    }
    else{
      //Has both children and raises the right child as a new root
      BNode *temp3 = (BNode *)malloc(sizeof(BNode));
      temp3 = minNode(node->right);
      node->name = temp3->name;
      node->right = removeNode(node->right,temp3->name);
    }
  }
  return node;
}
/* Will open the file and extract each name and add it to the tree.*/
BNode* readFile(BNode *node, char *fileName)
{
  FILE *fp;
  fp = fopen(fileName,"r");
  char *name = (char *)malloc(sizeof(char));
  while(!feof(fp))
    {
      fscanf(fp,"%s", name);
      node = addNode(node,name);
    }
  fclose(fp);
  return node;
}//Opens a file and write the tree inoder
void writeToFile(BNode *node, char *fileName)
{
  FILE *fp;
  fp = fopen(fileName, "w");
  if(fp == NULL){
    printf("File does not Exist!!");
    return;}
  if(node == NULL)
    return;
  writeToFile(node->left,fileName);
  fprintf(fp,"%s\n",node->name);
  writeToFile(node->right,fileName);
}
//Prints the nodes of tree inorder 
void printTree(BNode *node)
{
  if(node == NULL)
    return;
  printTree(node->left);
  printf("%s\n",node->name);
  printTree(node->right);
}
int main()
{
  BNode *node;
  node = NULL;
  int command = 0;
  char *name;
  printf("Welcome to the Personnel Management System!\n");

  while(command !=6)
    {
      printf("Please enter one of these commands.\n (1) Add new employee.\n"
	    " (2) Remove employee.\n (3) Display list of employees.\n"
	    " (4) Add employees from file.\n"
	    " (5) Write employees' names to file.\n (6) EXIT \n");
      scanf("%d",&command);
      if(command == 1)
	{
	  printf("Please Enter employee's name.\n");
	  scanf("%s",name);
	  node=addNode(node,name);
	}
      else if(command == 2)
	{
	  printf("Please enter the employee's name that you wish to delete.\n");
	  scanf("%s",name);
	  node=removeNode(node,name);
	}
      else if(command == 3)
	{
	  printTree(node);
	}
      else if(command == 4)
	{
	  printf("Please enter name of File.\n");
	  scanf("%s",name);
	  node=readFile(node,name);
	}
      else if(command == 5)
	{
	  printf("Please enter name of File.\n");
	  scanf("%s",name);
	  writeToFile(node, name);
	}
      else
	printf("Not a valid command. Please try again.\n");
    }
  printf("BYE!!\n");
  return 0;
}

	
