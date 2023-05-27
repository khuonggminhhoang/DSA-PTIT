#include<iostream>
#include<queue>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

typedef Node* node;

node makeNode(int x){
	node p = new Node();
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void makeRoot(node root, int u, int v, char c){
	if(c == 'L'){
		root->left = makeNode(v);
	}
	else{
		root->right = makeNode(v);
	}
}

void insertNode(node root, int u, int v, char c){
	if(root == NULL) return;
	if(root->data == u){
		makeRoot(root,u,v,c);
	}
	else{
		insertNode(root->left, u, v, c);
		insertNode(root->right, u, v, c);
	}
}

void levelOrder(node root){
	queue <node> q;
	q.push(root);
	while(!q.empty()){
		node tmp = q.front();
		q.pop();
		cout<<tmp->data<<" ";
		if(tmp->left != NULL){
			q.push(tmp->left);
		}
		if(tmp->right != NULL){
			q.push(tmp->right);
		}
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		node root = NULL;
		while(n--){
			int u,v;
			char c;
			cin>>u>>v>>c;
			if(root == NULL){
				root = makeNode(u);
				makeRoot(root, u, v, c);
			}
			else{
				insertNode(root, u, v, c);
			}
		}
		levelOrder(root);
		
		cout<<endl;
	}
}
