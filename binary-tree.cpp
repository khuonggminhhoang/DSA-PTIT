#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

typedef Node* node;

node makeNode(int data){
    node newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void makeRoot(node root, int u, int v, char c){
    if( c == 'L') root->left = makeNode(v);
    else root->right = makeNode(v);
}

void insertNode(node root, int u, int v, char c){
    if(root == NULL) return;
    if(root->data == u) {
        makeRoot(root,u,v,c);
    }
    else{
        insertNode(root->left,u,v,c);
        insertNode(root->right,u,v,c);
    }
}

// các hàm duyệt cây:

// 1. duyệt giữa - left-root-right
void inorder(node root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

// 2. duyệt trước - root-left-right
void preorder(node root){
    if(root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

//3. duyệt sau - left-right-root
void postorder(node root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

// 4. duyệt theo mức
void levelOrder( node root){
    queue <node> q;
    q.push(root);
    cout<<root->data<<" ";
    while( !q.empty() ){
        node tmp = q.front();
        q.pop();
        if(tmp->left != NULL){
            cout<<tmp->left->data<<" ";
            q.push(tmp->left);
        }
        if(tmp->right != NULL){
            cout<<tmp->right->data<<" ";
            q.push(tmp->right);
        }
    }
}

// 5. duyệt xoắn ốc - spiral
void spiralOrder(node root){
    stack <node> stk1, stk2;
    stk1.push(root);
    while(!stk1.empty() || !stk2.empty()){
        while(!stk1.empty()){
            node top = stk1.top(); stk1.pop();
            cout<<top->data<<" ";
            if(top->right != NULL){
                stk2.push(top->right);
            }
            if(top->left != NULL){
                stk2.push(top->left);
            }
        }

        while (!stk2.empty()){
            node top = stk2.top(); stk2.pop();
            cout<<top->data<<" ";
            if(top->left != NULL){
                stk1.push(top->left);
            }
            if(top->right != NULL){
                stk1.push(top->right);
            }
        }
        
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
            int u,v;
            char c;
            cin>>u>>v>>c;
            if(root == NULL){
                root = makeNode(u);
                makeRoot(root,u,v,c);
            }
            else{
                insertNode(root,u,v,c);
            }
        }

        inorder(root); cout<<endl;
        preorder(root); cout<<endl;
        postorder(root); cout<<endl;
        levelOrder(root); cout<<endl;
        spiralOrder(root); cout<<endl;
    }

    system("pause");
    return 0;
}

/*

3
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
6
10 3 L 10 4 R 4 6 L 4 2 R 6 5 L 6 9 R
*/