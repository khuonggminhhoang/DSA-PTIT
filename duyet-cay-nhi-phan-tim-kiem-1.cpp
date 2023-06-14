#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

typedef Node* node;

node makeNode(int data){
    node newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(node &root, int data){
    if(root == NULL){
        root = makeNode(data);
        return;
    }
    if(root->data < data){
        insertNode(root->right,data);
    }
    else if(root->data > data){
        insertNode(root->left,data);
    }
}

void postOrder(node root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        node root = NULL;
        while(n--){
            int x;
            cin>>x;
            if(root == NULL){
                root = makeNode(x);
            }
            else{
                insertNode(root,x);
            }
        }
        postOrder(root);
        cout<<endl;
    }

    system("pause");
    return 0;
}

/*

2
5
40 30 35 80 100
8
40 30 32 35 80 90 100 120

*/