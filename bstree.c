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
void removeNode(BNode *node, char *eName)
{
  if(node == NULL)
    return node;
  if(strncmp(node->name, eName) < 0){
  }
}
/* Will open the file and extract each name and add it to the tree.*/
BNode readFile(BNode *node, char *fileName)
{
  FILE *fp;
  fp = fopen(fileName,"r");
  int line  = getc(fp);
  char *name = (char *)malloc(sizeof(char));
  while(line != EOF)
    {
      fscanf(fp, %s, name);
      node = addNode(node,name);
      line = getc(fp);
    }
  fclose(fp);
  return node;
}
void writeToFile(BNode *node, char *fileName)
{
  FILE *fp;
  fp = fopen(fileName, "w");
  if(fp == NULL){
    print("File does not Exist!!");
    return;}
  if(node == NULL)
    return;
  writeToFile(node->left,fileName);
  fprintf(fp,%s\n,node->name);
  writeToFile(node->right,fileName);
}
void printTree(BNode *node)
{
  if(node == NULL)
    return;
  printTree(node->left);
  printf(%s\n,node->name);
  printTree(node->right);
}
main()
{
  BNode *node;
  node = NULL;
  int cont = 1;
  int command = 0;
  char *name;
  printf("Welcome to the Personnel Management System!\n");

  while(cont == 1)
    {
      prinf("Please enter one of these commands.\n (1) Add new employee.\n"
	    "(2) Remove employee.\n (3) Display list of employees.\n"
	    "(4) Add employees from file.\n"
	    "(5) Write employees' names to file.\n (6) EXIT \n");
      scanf("%d",command);
      if(command == 1)
	{
	  printf("Please Enter employee's name.\n");
	  scanf("%s",name);
	  addNode(node,name);
	}
      else if(command == 2)
	{
	  printf("Please enter the employee's name that you wish to delete.\n");
	  scanf("%s",name);
	  removeNode(node,name);
	}
      else if(command == 3)
	{
	  printTree(node);
	}
      else if(command == 4)
	{
	  printf("Please enter name of File.\n");
	  scanf("%s",name);
	  readFile(node,name);
	}
      else if(command == 5)
	{
	  printf("Please enter name of File.\n");
	  scanf("%s",name);
	  writeToFile(node, name);
	}
      else if(command == 6)
	{
	  cont = 0;
	  return;
	}
      else
	printf("Not a valid command. Please try again.\n");
    }
  printf("BYE!!\n");
}

	
