#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    int level;
    Node* left;
    Node* right;
};

typedef Node* node;

node makeNode(int data, int level){
    node temp = new Node();
    temp->data = data;
    temp->level = level+1;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void makeRoot(node root, int u, int v, char c){
    if(c == 'L') root->left = makeNode(v, root->level);
    else root->right = makeNode(v,root->level);
}

void insertNode(node root, int u, int v, char c ){
    if(root == NULL) return;
    if(root->data == u) {
        makeRoot(root, u, v, c);
    }
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

void inorder(node root ){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<"->"<<root->level<<endl;
        inorder(root->right);
    }
}

vector <node> v;
void Search(node root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        v.push_back(root);
        return;
    }
    Search(root->left);
    Search(root->right);
}

bool check(){
    for(int i=0; i<v.size()-1; ++i){
        if(v[i]->level != v[i+1]->level) return false;
    }
    return true;
}

int main(){
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
                root = makeNode(u,-1);
                makeRoot(root,u,v,c);
            }
            else{
                insertNode(root,u,v,c);
            }
        }
        Search(root);
        cout<<check()<<endl;
        // inorder(root);
        v.clear();
    }

    system("pause");
    return 0;
}


/*

2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

*/
