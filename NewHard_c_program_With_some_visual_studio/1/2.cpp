#include <iostream>
using namespace std;
#include <stdlib.h>
#include<conio.h>

enum {TRUE = 1,FALSE = 0};

typedef struct _node
{
    int info;
    struct _node *left;
    struct _node *right;
    struct _node *p;
}node;
class btree
{
private:
    node *root;
    void InsertLeft(node* & ,node*);
    void InsertRight(node* &,node*);
    void deltree(node*);
public:
    btree();
    ~btree();
    node* GetRoot(void);
    void MakeTree(void);
    void DisplayTree(node*,int);
    void DeleteNode(node *,node *,int);
    int mini(node*);
    int maxi(node*);
    node* Searchnode(node*,int);
    void successor(node*);
    void predi(node*);
};  
int btree:: mini(node* tree)
{
   while(tree->left!=NULL)
   {
     tree = tree->left;
   }
   return tree->info;
}
void btree::successor(node* t)
{
   if(t->right!=NULL) cout<<mini(t->right);
   else
   {
       node *y;
       y = t->p;
       while(y!=NULL&&t==y->right)   
       {
          t = y;
          y = y->p;
       }   
       cout<<y->info;                                                                           
   }
}

int btree:: maxi(node* tree)
{
   while(tree->right!=NULL)
   {
     tree = tree->right;
   }
   return tree->info;
}
void btree::predi(node* t)
{
   if(t->left!=NULL) cout<<maxi(t->left);
   else
   {
       node *y;
       y = t->p;
       while(y!=NULL&&t==y->left)   
       {
          t = y;
          y = y->p;
       }   
       cout<<y->info;                                                                           
   }
}
btree::btree()
{
    char create='Y';
    root = new node;
    cout<<"create a root >>> enter info : ";
    cin>>root->info;
    root->left = NULL;
    root->right = NULL;
}

btree::~btree()
{
    deltree(root);
}

void btree::deltree(node *root)
{
    if(root)
    {
        deltree(root->left);
        deltree(root->right);
        delete root;
    }
}

node* btree::GetRoot(void)
{
    return(root);
}

void btree::MakeTree(void)
{  
    node *newnode;
    char create;

    do
    {
        newnode = new node;
        cout<<"Enter a number"<<endl;
        cin>>newnode->info;

        newnode->left=NULL;
        newnode->right=NULL;
        if(newnode->info < root->info)
            InsertLeft(newnode,root);
        else
            InsertRight(newnode,root);
        cout<<"Create another node[y/n]"<<endl;
        cin>>create;
    }while(create=='Y' || create=='y');
}
node* btree::Searchnode(node *current,int num)
{
    while(current!=NULL&&num!=current->info)
    {
       if(num<current->info) current=current->left;
       else current=current->right;
    }
    return current;
}
void btree::InsertLeft(node* &newnode,node* current)
{
    if(current->left==NULL)
    {
        current->left=newnode;
        newnode->p = current;
        }
    else
    {
        current = current->left;
        if(newnode->info < current->info)
            InsertLeft(newnode,current);
        else
            InsertRight(newnode,current);
    }
}

void btree::InsertRight(node* &newnode,node* current)
{
    if(current->right==NULL)
    {
        current->right=newnode;
        newnode->p=current;
        }
    else
    {
        current = current->right;
        if(newnode->info < current->info)
            InsertLeft(newnode,current);
        else
            InsertRight(newnode,current);
    }
}

void btree::DeleteNode(node *current,node *parent,int delnode)
{
    if(delnode < current->info)
        DeleteNode(current->left,current,delnode);
    else if(delnode > current->info)
        DeleteNode(current->right,current,delnode);
    else if(delnode == current->info)
    {
        if(current->left == NULL)
        {
            if(parent->info > current->info)
                parent->left = current->right;
            else
                parent->right = current->right;
        }
        else if(current->right == NULL)
        {
            if(parent->info > current->info)
                parent->left = current->left;
            else
                parent->right = current->left;
        }
        else
        {
            node *temp;
            int flag = 0;

            parent = current;
            current = current->left;
            temp = current;
            while(current->right != NULL)
            {
                current = current->right;
                if(flag == 0)
                    flag = 1;
                else
                    temp = temp->right;
            }
            parent->info = current->info;
            if(flag == 0)
                // No right child
                parent->left = current->left;
            else
                temp->right = current->left;
        }
        delete current;
    }
}

void btree::DisplayTree(node *current,int Level)
{
    if(current)
    {
        DisplayTree(current->right,Level+1);
        cout<<endl;
        for(int i=0;i<Level;i++)
            cout<<"  ";
        cout<<current->info;
        DisplayTree(current->left,Level+1);
    }
}
int main()
{
    int opt;
    int num;
    char ch='y';
    btree bt;
    do
    {
        cout<<"\nEnter your option\n";
        cout<<"1. Make a Tree\n";
        cout<<"2. Delete a node\n";
        cout<<"3. Display tree\n";
        cout<<"4. search minimum\n";
        cout<<"5. search maximum\n";
        cout<<"6. search successor\n";
        cout<<"7. search predecisor\n";
        cout<<"8. Exit\n";
        cin>>opt;
        switch(opt)
        {
        case 1:
            bt.MakeTree();
            break;
        case 2:
            int delnode;
            cout<<"\nEnter an information to be deleted\n";
            cin>>delnode;
            bt.DeleteNode(bt.GetRoot(),NULL,delnode);
            break;
        case 3:
            bt.DisplayTree(bt.GetRoot(),1);
            break;
        case 4:
             cout<<bt.mini(bt.GetRoot());
             break;
        case 5:
             bt.maxi(bt.GetRoot());
             break;
        case 6:
             cout<<"Enter a value\n";
             int n;
             cin>>n;
             bt.successor(bt.Searchnode(bt.GetRoot(),n));
             break;
        case 7:
             cout<<"Enter a value\n";
             int m;
             cin>>m;
             bt.predi(bt.Searchnode(bt.GetRoot(),m));
             break;
        case 8:
            exit(0);
        default:
            cout<<"\nInvalid Entry\n";
        }
    }while(ch=='Y' || ch=='y');
    getch();
    return 0;
}
