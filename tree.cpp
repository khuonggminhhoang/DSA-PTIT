#include<iostream>

using namespace std;

struct Node{
	int infor;
	Node* left;
	Node* right;
};

typedef Node* Tree;

Tree makeNode(int infor){
	Tree p;
	p = new Node;
	p->infor = infor;
	p->left = nullptr;
	p->right=nullptr;
	return p;
}

void freeNode(Tree p){
	delete p;
}

int isEmpty(Tree p){
	if(p== nullptr) return 1;
	return 0;
}

// tim kiem tren cay node co data la x
Tree Search( Tree T, int x){
	Tree p ;
	if( T->infor == x){
		return T;
	}
	if( T == nullptr){
		return nullptr;
	}
	p = Search(T->left, x);
	if(p == nullptr) 
		p = Search(T->right,x);
	return p;
}

// tao not goc
Tree makeRoot(Tree T, int x){
	if(T == nullptr){
		T = makeNode(x);
	}
	return T;
}

// them vao node la ben trai node p
void addLeft(Tree T, int x, int y){
	Tree p,q;
	p = Search(T,x);
	if(p==nullptr) {
		cout<<"not found\n";
		return ;
	}
	else if( p->left != nullptr){
		cout<<"available\n";
		return;
	}
	else {
		q = makeNode(y);
		p->left = q;
	}
}

// them vao node la ben phai node p
void addRight( Tree T, int x, int y){
	Tree p,q;
	p = Search(T,x);
	if( p == nullptr){
		cout<<"not found\n";
		return;
	}
	else if( p->right != nullptr){
		cout<<"available\n";
		return ;
	}
	else{
		q = makeNode(y);
		p->right = q;
	}
}

// loai bo node la ben trai node co noi dung là x
void removeLeft(Tree T, int x){
	Tree p, q;
	p = Search(T,x);
	if( p == nullptr) {
		cout<<"not found\n";
		return;
	}
	else if( (p->left)->left != nullptr || (p->left)->right != nullptr){
		cout<<"exist\n";
	} 
	else {
		q = p->left;
		p->left = NULL;
		delete q;
	}
}

// loai bo node la ben phai node co noi dung x
void removeRight(Tree T, int x){
	Tree p,q;
	p = Search(T,x);
	if(p== nullptr) {
		cout<<"not found\n";
		return;
	}
	else if((p->right)->left != nullptr || (p->right)->right != nullptr){
		cout<<"exist\n";
	}
	else {
		q = p->right;
		p->right = NULL;
		delete q;
	}
}

// loai bo cay
void clearTree(Tree T){
	if(T != NULL){
		clearTree(T->left);
		clearTree(T->right);
		delete T;
	}
}

// duyet cay theo thu tu truoc
void NLR( Tree T){
	if( T != NULL){
		cout<< T->infor<<" ";
		NLR(T->left);
		NLR(T->right);
	}
}

// duyet cay theo thu tu sau
void LRN( Tree T){
	if(T != NULL){
		LRN(T->left);
		LRN(T->right);
		cout<< T->infor<<" ";
	}
}

//duyet cay theo thu tu giua
void LNR( Tree T){
	if( T != NULL){
		LNR(T->left);
		cout<<T->infor<<" ";
		LNR( T->right);
	}
}

main(){
	Tree p = NULL;
	p = makeRoot(p,40);
//	addLeft(p,40,60);
	addRight(p,40,30);
	cout<< p->infor <<endl;
//	cout<< (p->left)->infor <<endl;	
	cout<< (p->right)->infor <<endl;	
	Tree q = Search(p,60);
	if(q == NULL) cout<<"NULL\n";
	cout<<q->infor;
}

//	NLR(p);
//	addLeft(p,30, 25); addRight(p,30,35);
//	addLeft(p,60,50); addRight(p,60,70);
