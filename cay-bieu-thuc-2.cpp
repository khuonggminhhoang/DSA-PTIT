#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;
};

typedef Node* node;

bool isSig(string c){
    return c == "+" || c == "-" || c == "/" || c == "*";
}

node makeNode(string c){
    node newNode = new Node();
    newNode->data = c;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int so(string s){
    int res = 0;
    if(s[0] == '-'){
        for(int i=1; i<s.size(); ++i){
            res = res*10 + (s[i] - '0');
        }
        res*=-1;
    }
    else
        for(int i=0; i<s.size(); ++i){
            res = res*10 + (s[i] - '0');
        }
    return res;
}

string cal(string s1, string s2, string sig){
    int num1 = so(s1);
    int num2 = so(s2);
    int num;
    if(sig == "+") num = num1 + num2;
    if(sig == "-") num = num1 - num2;
    if(sig == "/") num = num1/num2;
    if(sig == "*") num = num1 * num2;
    return to_string(num);
}

int solve(int n){
    stack <node> stkSig,stkNum;
    node tmp1, tmp2, temp;
    vector <node> vct;
    while (n--){
        string x;
        cin>>x;
        if(isSig(x)) {
            temp = makeNode(x);
            stkSig.push(temp);
        }
        else{
            temp = makeNode(x);
            stkNum.push(temp);
        }
    }
    while(!stkSig.empty()){
        while (!stkNum.empty())
        {
            node sig = stkSig.top();
            stkSig.pop();
            tmp1 = stkNum.top(); stkNum.pop();
            tmp2 = stkNum.top(); stkNum.pop();

            temp = makeNode(cal(tmp2->data, tmp1->data, sig->data));
            vct.push_back(temp);
        }
        for(int i=vct.size()-1; i>=0; --i){
        	stkNum.push(vct[i]);
        	vct.erase(vct.begin()+i);
		}
    }
    return so(stkNum.top()->data);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;;
    }

    system("pause");
    return 0;
}
