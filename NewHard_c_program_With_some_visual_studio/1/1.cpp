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
    node* Searchnode(node*,int);
    void DisplayTree(node*,int);
    void Inorder(node* );
    void Preorder(node*);
    void Postorder(node*);
};  

btree::btree()
{
    char create='Y';
    root = new node;
    cout<<"Create root >>> enter info :  " ;
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

void btree::InsertLeft(node* &newnode,node* current)
{
    if(current->left==NULL)
        current->left=newnode;
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
        current->right=newnode;
    else
    {
        current = current->right;
        if(newnode->info < current->info)
            InsertLeft(newnode,current);
        else
            InsertRight(newnode,current);
    }
}
node *btree::Searchnode(node *current,int num)
{
    
    while(current!=NULL && num!=current->info)
    {
       if(num<current->info) current=current->left;
       else current=current->right;
    }
    return current;
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

void btree::Inorder(node *current)
{
    if(current!=NULL)
    {
        Inorder(current->left);
        cout<<current->info<<" ";
        Inorder(current->right);
    }
}

void btree::Preorder(node *current)
{
    if(current!=NULL)
    {
        cout<<current->info<<" ";
        Preorder(current->left);
        Preorder(current->right);
    }
}

void btree::Postorder(node *current)
{
    if(current!=NULL)
    {
        Postorder(current->left);
        Postorder(current->right);
        cout<<current->info<<" ";
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
        cout<<"1.... insert....\n";
        cout<<"2.... search....\n";
        cout<<"3.... display...\n";
        cout<<"4.... Inorder...\n";
        cout<<"5.... preorder..\n";
        cout<<"6.... postorder.\n";
        cout<<"7.... Exit\n";
        cin>>opt;
        switch(opt)
        {
        case 1:
            bt.MakeTree();
            break;
        case 2:
            cout<<"\nEnter a number to search in the tree\n";
            cin>>num;
            if(bt.Searchnode(bt.GetRoot(),num))
                cout<<"The number is present"<<endl;
            else
                cout<<"The number is not present"<<endl;
            break;
        case 3:
            bt.DisplayTree(bt.GetRoot(),1);
            break;
        case 4:
            bt.Inorder(bt.GetRoot());
            break;
        case 5:
            bt.Preorder(bt.GetRoot());
            break;
        case 6:
            bt.Postorder(bt.GetRoot());
            break;
        case 7:
            exit(0);
        default:
            cout<<"\nInvalid Entry\n";
        }
    }while(ch=='Y' || ch=='y');
    getch();
    return 0;
}
