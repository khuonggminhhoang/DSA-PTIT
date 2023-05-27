#include<iostream>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

typedef Node* node;

node makeNode(int data){
	node p = new Node;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}

node makeRoot(int data){
	return makeNode(data);
}

void insertLeft(node root, int data){
	if(root->data == data) {
		if(root->left == NULL){
			node p = makeNode(data);
			root->left = p;
		}
	}
	insertLeft(root->left,data);
	insertLeft(root->right,data);
}



main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		node root=NULL;
		
	}
}
