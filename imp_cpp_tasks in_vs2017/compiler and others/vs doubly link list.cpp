// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//  the glut file for windows operations 
// it also includes g1.h and g1u.h for the OpenGL library  calls 

#include<stdio.h>
#include<stdlib.h>

/*struct NODE
{
int val;
struct NODE * left;
struct NODE * right;
}
struct NODE *root =NULL;
*/
struct NODE
{
	int val;
	struct NODE * left;
	struct NODE * right;
} *root = NULL;
// node is the type and root is the variable
int nodes;

void insert(int value){
	struct NODE *anode, *parent;
	struct NODE *newnode;
	parent = NULL;
	anode = root;		// for (anode = root ; anode!= NULL; anode= anode->left | anode =anode -> right)	{     }
	
	while (anode != NULL){	// for the 1st time anode = root = null , so it will not execute.
				parent = anode;				// parent changes , it is father of left and right childs.
		if (value <= anode->val)
			anode = anode->left;
		else anode = anode->right;

	}
	newnode = new NODE;
	newnode->val = value;
	newnode->right = newnode->left = NULL;
	if (parent == NULL) // insert the root if it is empty. In first case parent == NULL .
		root = newnode;
	else {
		if (value <= parent->val)			// parent changes , it is father of left and right childs.
			parent->left = newnode;
		else parent->right = newnode;

	}

}



void shownode_inorder(struct NODE *anode)	//watch it by visual studio debugger
{
	if (anode != NULL)
	{
		shownode_inorder(anode->left);
		printf("%d  ", anode->val);		// put break points in each 4 lines, it works by recursion. 
											//In recursion calls are saved in stack or some where else , those calls
										// are invoked momentarily
		shownode_inorder(anode->right);
	}
}


void shownode_preorder(struct NODE *anode)		//watch it by visual studio debugger
{
	if (anode != NULL){
		printf("%d  ", anode->val);// put break points in each 4 lines, it works by recursion. 
											//In recursion calls are saved in stack or some where else , those calls
										// are invoked momentarily
		shownode_preorder(anode->left);
		shownode_preorder(anode->right);
	}
}
void shownode_postorder(struct NODE *anode)		//watch it by visual studio debugger
{
	if (anode != NULL){						// put break points in each 4 lines, it works by recursion. 
											//In recursion calls are saved in stack or some where else , those calls
										// are invoked momentarily
		shownode_postorder(anode->left);
		shownode_postorder(anode->right);
		printf("%d  ", anode->val);
	}
}



NODE *find(int value)
{
	struct NODE *anode;
	anode = root;				// root is DECLARED global
	while ((anode != NULL) && (anode->val != value))
						
		// YOU CAN SKIP CURLY BRASE SINCE IT IS A SINGLE COMMAND 
	{
		if (value <= anode->val)
			anode = anode->left;
		else anode = anode->right;
	}
	return anode;
}

void remove(int value){
	
		NODE *parent=NULL;   //required to store the parent of a deleted leaf node. 
	if (root == NULL){
		printf("The list is empty!");
		printf("\n");
	}
	else {
		NODE *temp = root;
		while (temp != NULL)
		{
			
			printf(" %d ", temp->val);


			if (value == temp->val)
			{
				printf("Data verified");
				printf("\n");
				//DELETE ROOT
				if (temp->left && temp->right) //If it has two children
				{
					printf("Root with two children");
					printf("\n");

					// going to the left node and then right most node.
					NODE * temporary;
				 /* deleted node has two children */
				{
					/* find where to reattach right subtree */
					for (temporary = temp->left; temporary->right != NULL;
						temporary = temporary->right)
						continue;
					temporary->right = temp->right;
					// temporary->left= temp->left;

					temporary = temp;
					temp = temp->left;
					delete(temporary);
					root = temp;
				}
					

					return;


				}
				if (temp->left || temp->right)
				{
					printf("Root with a single child");
					printf("\n");
					
					// deletion of node with single child.

					if (parent->left->val == value)
					{
						if (temp->left)
						parent->left = temp->left;

						if (temp->right)
							parent->left = temp->right;

						delete temp;
					}

					if (parent->right->val == value)
					{
						if (temp->left)
							parent->left = temp->left;

						if (temp->right)
							parent->left = temp->right;

						delete temp;
					}



					return;
				}
						// see if leaf node , then remove
				else {
					
					printf("Leaf node");
					printf("\n");
					
					if ((parent->left->val) == value)
					{ //then
						parent->left = NULL;
					}
					else parent->right = NULL;

					// you need to NULL the  temp node like parent's left or right =NULL;
					//temp = NULL;
					delete temp;		// this code have a problem you have to make the parent's child(leaf node) pointing to the deleted item =NULL
					// parent's left = NULL
					// or parent's right =NULL  
					//which was not performed
					
					return;
				}
			}

			
			else if (value<temp->val){
				parent = temp;
				if (temp->left)			// if (temp-> left == true , meaning not null
					temp = temp->left;
				else
					return;
			}
			else{
				parent = temp;
				if (temp->right)
					temp = temp->right;
				else
					return;
			}


		}
	}
}

void destroy_tree(NODE *anode)
{
	if (anode != NULL)
	{
		destroy_tree(anode->left);
		destroy_tree(anode->right);
		printf(" Deleting node:  %d", anode->val);
		delete anode;
	}
}


int main()
{
	int a, b, i, c;
	NODE * arefin;
	// insertion starts here.
	printf("Enter value to be inserted \n");
	printf("Enter number of values you want to give ==> ");
	scanf_s("%d", &a);
	for (i = 0; i < a; i++)
	{
		printf("Enter values ==>");
		scanf_s("%d", &b);
		insert(b);
	}
	


	// traversing starts here
	printf("\nINORDER     ==>    ");
	shownode_inorder(root);
	printf("\n\nPOSTORDER     ==>    ");
	shownode_postorder(root);
	printf("\n\nPREORDER     ==>    ");
	shownode_preorder(root);
	printf("\n\n\n Enter value to find    :  ");
	scanf_s("%d", &c);

	arefin = find(c);
	if (arefin == NULL) printf("\n\nNot found\n\n\n\n");
	else
	{
		printf("\n\nfound\n\n\n");
		printf("   %d   FOUND   .", arefin->val);

	}
		
	// remove starts here
	int r;
	printf("Enter number to remove : \n");
	scanf_s("%d", &r);

	remove(r);

	//checking purpose
	printf("\nINORDER     ==>    ");
	shownode_inorder(root);


	destroy_tree(root);
	

	//checking purpose
	printf("\n\nPREORDER     ==>    ");
	shownode_preorder(root);



	return 0;
}