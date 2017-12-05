#include <iostream>
#include <fstream>
#include <stack>
using namespace std;


struct BinaryTree{
	string data;
	BinaryTree *left, *right;	
	BinaryTree(){left=NULL;right=NULL;}
};



struct GeneralTree{
	string data;
	GeneralTree *firstChild,*sibling;
	GeneralTree(){firstChild=NULL;sibling=NULL;}
	void newNode(string data);
};

GeneralTree GeneralTree::newNode(string data){
	GeneralTree node = new GeneralTree;
	this->data = data;
	return node;
}


ifstream fin;
BinaryTree *bintree = NULL;
GeneralTree *gentree = NULL;


void readFile(GeneralTree *&);
void newNode(BinaryTree *&bintree,string data);
void freeTree();
void insert(BinaryTree *&bintree,string data);
void inorder(BinaryTree *bintree);
void preorder(BinaryTree *bintree);


int main(){


	// GeneralTree gentreeroot;
	

	fin.open("data.txt");
	readFile(bintree);
	// //get root;
	// gentreeroot = gentreeroot->newNode("Jones");
	cout<<endl;

	//cout<<bintree->left->left->right->left->right->data;
	inorder(bintree);

	return 0;
}


void readFile(GeneralTree *&gentree){
	string name,childrenph;
	int children;

	if(!fin.eof()){

		fin>>name>>childrenph;
		cout<<name<<childrenph;
		children = stoi(childrenph);
		gen
	}
}





// void insert(BinaryTree *&bintree,string data){
// 	if()
// 	cout<<"Inserting Node..."<<endl;
// 	newNode(bintree,data);
	

// }

// void inorder(BinaryTree *bintree){
// 	if(bintree == NULL){
// 	    return;
// 	}
// 	else{
// 		inorder(bintree->left);
// 		//if (tree->data != EMPTY)
// 			cout<<bintree->data<<", ";
// 		inorder(bintree->right);
// 	}

// }


// void preorder(BinaryTree* tree){
// 	if(tree == NULL){
// 	    return;
// 	}
// 	else{
// 		//if(tree->data != EMPTY)
// 			cout<<tree->data<<", ";
// 		inorder(tree->left);
// 		inorder(tree->right);
// 	}

// }



// // void genToBin(binroot,genroot){
// // 	if(genroot->firstChild == NULL && genroot->sibling == NULL || genroot == NULL) return;
// // 	binroot->left = genroot->firstChild;
// // 	genToBin(binroot->left,genroot->firstChild)

// // 	if(genroot->sibling != NULL){
// // 		binroot-right = genroot->sibling;
// // 		genToBin(binroot->right,genroot->sibling);

// // 	}
// // }



// /*
// 	Next three Functions
// 	are for binarybintree
// */
// void newNode(BinaryTree *&bintree,string data){
// 	bintree = new BinaryTree;
// 	bintree->data = data;
// }

// void freeTree(){
// 	delete bintree;
// 	bintree = NULL;
// 	cout<<"Tree Freed"<<endl;
// }

