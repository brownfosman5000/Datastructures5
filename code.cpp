#include<iostream>
#include <fstream>
using namespace std;

//Binary Tree
struct node
{
    string data;
    struct node *left;
    struct node *right;
};
struct node *head;




/*
    This is all for the
    conversion subprogram
*/
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


ifstream fin;

void readConvert();

void whoIsTheFather(node*,node*);
void whoAreTheSons(node*);
void whoIsTheYoungestBrother(node*p);
void whoIsTheOldestSon(node *p);
void whoIsTheYoungestSon(node*p);


node* search(string name,node *root);
node* searchForFather(string name,node *root);




int main(){

    string names[5] = {"Bob","Max","Liam","Carter","Aaron"};
    fin.open("data.txt");
    readConvert();
    node* p = search(names[0],head);
    for(int i = 1;i<6;i++){
        //whoIsTheFather(p,head->left);
        whoAreTheSons(p);

        whoIsTheOldestSon(p);
        whoIsTheYoungestSon(p);

        whoIsTheYoungestBrother(p);


        readConvert();
        p = search(names[i],head);

        cout<<endl<<endl<<"Next Tree"<<endl;
    }
    return 0;
}
node* search(string name,node *root){
    if(root == NULL) return NULL;
    if(root->data == name) return root;

    else{
        node *leftresutlt = search(name,root->left);
        if(leftresutlt != NULL) return leftresutlt;
        node *rightresult = search(name,root->right);
        if(rightresult != NULL) return rightresult;
    }
    return NULL;

}
void whoIsTheFather(node *p,node* root){
    node* temp = root;
    node* father = temp;
    if(temp == NULL) return;
    if(temp->left->data == p->data){
        cout<<"The father is "<< temp->data<<endl;
        return;
    }



    else{
        temp = temp->left;
        while(temp->right != NULL){
            if(temp->right->data == p->data){
                cout<<"The Father is "<<father->data<<endl;
                return;
            }
            temp = temp->right;

        }
    }
    whoIsTheFather(p,root->left);

}
void whoAreTheSons(node *p){
    if(p->left == NULL){cout<<p->data<<" has no sons"<<endl; return;}
    cout<<"Sons of " <<p->data<<": "<<p->left->data;
    p=p->left;
    while(p->right != NULL){
        cout<<", "<<p->right->data;
        p = p->right;
    }
    cout<<endl;

}
void whoIsTheOldestSon(node *p){
    if(p->left == NULL){cout<<p->data<<" has no sons"<<endl; return;}
    cout<<"The Oldest Son of "<<p->left->data<<endl;
}
void whoIsTheYoungestSon(node *p){
    if(p->left == NULL){cout<<p->data<<" has no sons"<<endl; return;}
    p=p->left;
    while(p->right != NULL){
        p = p->right;
    }
    cout<<"The Youngest Son is "<<p->data<<endl;
}
void whoIsTheYoungestBrother(node *p){
    if(p->right == NULL){cout<<p->data<<" has no brothers"<<endl; return;}
    if(p->right == NULL && p->left != NULL){ cout<<p->data <<" is the youngest "<<endl; return;}
    while(p->right != NULL){
        p = p->right;
    }

    cout<<"The Youngest Brother is "<<p->data<<endl;
}
void readConvert(){

    int i=0;
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
        if(nlev == 999) break;
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

