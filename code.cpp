#include<iostream>
#include <fstream>
using namespace std;
struct node
{
    string data;
    struct node *left;
    struct node *right;
};
struct node *head;

struct info
{
    int level;
    struct node *loc;
};


int nlev;
string nname;
info s[100];
int top=-1;

info push(info c)
{
    top++;
    s[top]=c;

return s[top];
}

void pop()
{
    top--;
}

info peek()
{
    return s[top];
}

void preorder(node *root)
{
    if(root!=NULL)
    {
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
}
void inorder(node *root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    }
}

ifstream fin;

void readConvert();

void whoIsTheFather();
void whoAreAllTheSons();
void
int main(){

    fin.open("data.txt");
    readConvert();
    cout<<"\nBinary Tree\nPreorder:";
    preorder(head);
    cout<<"\ninorder:";
    inorder(head);
    return 0;
}


void readConvert(){

    int i=0;
    //cout<<"\nGENERAL TREE TO BINARY TREE\n Note: Input must be the preorder sequence of the general tree";
    node *newnode = new node;
    head=newnode;
    head->left=NULL;
    head->right=NULL;
    info a;
    a.level=-1;
    a.loc=head;
    push(a);
    do{
        fin>>nlev;
        fin>>nname;
        node* newnode=new node;
        newnode->left=newnode->right=NULL;
        newnode->data=nname;
        info Pred=peek();

        if(Pred.level< nlev)         //if different levels add to left -1<0,0<1,1<2
            { Pred.loc->left=newnode;}
        else
        {               //if levels match or lesser  2<1,1<1
            while(Pred.level>nlev){
                 pop();               //popped until we get a sibling
                 Pred=peek();
                 }
                if(Pred.level<nlev)
                {
                //cout<<"\nError in input.Mixed Level numbers\n";
                return;
                }
               Pred.loc->right=newnode;   //sibling added to the right
               pop(); //pop added node
        }

        a.level=nlev;
        a.loc=newnode;
        push(a);

    }while(fin);
}

