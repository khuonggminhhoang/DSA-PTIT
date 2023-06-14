#include<iostream>
#include<stack>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

typedef Node* node;

bool isSig(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

node makeNode(char c){
    node newNode = new Node();
    newNode->data = c;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void inOrder( node root){
    if(root != NULL){
        inOrder(root->left);
        cout<<root->data;
        inOrder(root->right);
    }
}

node solve(string s){
    stack <node> stk;
    node temp, tmp1, tmp2;
    for(int i=0; i<s.size(); ++i){
        if(!isSig(s[i])){
            temp = makeNode(s[i]);
            stk.push(temp);
        }
        else{
            tmp1 = stk.top(); stk.pop();
            tmp2 = stk.top(); stk.pop();

            temp = makeNode(s[i]);
            temp->right = tmp1;
            temp->left = tmp2;

            stk.push(temp);
        }
    }
    return stk.top();
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        node root = solve(s);
        
        inOrder(root);
        cout<<endl;
    }
    system("pause");
    return 0;
}

/*

2
ab+ef*g*-
wlrb+-*

*/