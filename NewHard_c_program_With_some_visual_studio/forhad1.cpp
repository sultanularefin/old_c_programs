#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct searchtree{
       int element;
       struct searchtree *left,*right;
       }*root;
       typedef struct searchtree *node;
       typedef int ElementType;
       node insert(ElementType, node);
       node find(ElementType, node);
       void display(node, int);
       void preorder(node);
       void inorder(node);
       void postorder(node);
int main(){
            int ch;
            ElementType a;
            node temp;
            while(1){
                     printf("\n1. Insert\n2. Find\n3.Display\n4. pre-order\n5.in-order\n6.post-order\n7. Exit\nEnter Your Choice : ");
                     scanf("%d",&ch);
                     switch(ch){
                                case 1:printf("Enter an element : ");
                                scanf("%d", &a);
                                root = insert(a, root);
                                break;
                                case 2:printf("\nEnter the element to search : ");
                                scanf("%d",&a);
                                temp = find(a, root);
                                if (temp != NULL)
                                printf("Element found");
                                else
                                printf("Element not found");
                                break;
                                case 3:
                                     if(root==NULL)
                                printf("\nEmpty tree");
                                else
                                display(root, 1);
                                break;
                                case 4:
                                printf("\nPre-Order : ");
                                preorder(root);
                                break;
                                case 5:
                                printf("\nIn-Order : ");
                                inorder(root);
                                break;
                                case 6:
                                printf("\nPost-Order : ");
                                postorder(root);
                                break;
                                case 7:
                                     exit(0);
                                default:printf("Invalid Choice");
                                }
                                }
                                return 0;
                                }
node insert(ElementType x,node t){
                          if(t==NULL)
                          {
                                     t = (node)malloc(sizeof(node));
                                     t->element = x;
                                     t->left = t->right = NULL;
                          }
                          else
                          {
                               if(x < t->element)
                               t->left = insert(x, t->left);
                               else if(x > t->element)
                               t->right = insert(x, t->right);
                          }
                               return t;
                               }

node find(ElementType x, node t)
{
                 if(t==NULL) 
                 return NULL;
                 if(x<t->element)
                 return find(x,t->left);
                 if(x>t->element) 
                 return find(x,t->right);
                 return t;
}    
void display(node t,int level){
         int i;
         if(t){
               display(t->right, level+1);
         printf("\n");
         for(i=0;i<level;i++)
         printf(" ");
         printf("%d", t->element);
         display(t->left, level+1);
         }  
         }                   
void preorder(node t)
          {
               if(t!=NULL)
               {
                    printf("%d", t->element);
                    preorder(t->left);
                    preorder(t->right);
               }
          }
void inorder(node t)
          {
               if(t!=NULL)
               {
                    inorder(t->left);
                    printf("%d", t->element);
                    inorder(t->right);
               }
          }

void postorder(node t)
          {
               if(t!=NULL)
               {
                    postorder(t->left);
                    postorder(t->right);
                    printf("%d", t->element);
               }
          }
