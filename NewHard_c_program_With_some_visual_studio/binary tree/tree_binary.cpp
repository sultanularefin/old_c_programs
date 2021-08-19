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
    void DeleteNode(node *,node *,int);
    int Searchnode(node*,int);
    void DisplayTree(node*,int);
    int mini(node *);
    void max(node*);
    void successor(node *);
    
};  

void btree::successor(node *tree)
{
    if(tree->right != NULL)
    {
        cout<<mini(tree->right);
    }
    else
    {
        node *x,*y;
        
    }
}

void btree::max(node *tree)
{
    while(tree->right !=NULL)
    {
        tree = tree->right;
    }
    cout<<"Maximum="<<tree->info<<" ";
}
int btree::mini(node* tree)
{
    while(tree->left!=NULL)
    {
        tree = tree->left;
    }
    cout<<"Minimum="<<tree->info<<" ";
    return tree->info;
}

btree::btree()
{
    char create='Y';
    root = new node;
    cout<<"Enter a number which will become a root"<<endl;
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

int btree::Searchnode(node *current,int num)
{
    if(num<current->info && current->left!=NULL)
        Searchnode(current->left,num);
    else if(num>current->info && current->right!=NULL)
        Searchnode(current->right,num);
    else
    {
        if(num==current->info)
            return TRUE;
        else
            return FALSE;
    }
    return FALSE;
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
        cout<<"3. search a node\n";
        cout<<"4. display the tree\n";
        cout<<"5. Minimum Value\n";
        cout<<"6. Maximum Value\n";
        cout<<"7. postorder traversal\n";
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
            cout<<"\nEnter a number to search in the tree\n";
            cin>>num;
            if(bt.Searchnode(bt.GetRoot(),num))
                cout<<"The number is present"<<endl;
            else
                cout<<"The number is not present"<<endl;
            break;
        case 4:
            bt.DisplayTree(bt.GetRoot(),1);
            break;
        case 5:
            bt.mini(bt.GetRoot());
            break;
        case 6:
            bt.max(bt.GetRoot());
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
