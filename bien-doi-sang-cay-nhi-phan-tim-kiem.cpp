#include<iostream>
#include<set>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set <int> st;
        while (n--)
        {
            int x,y;
            char c;
            cin>>x>>y>>c;
            st.insert(x);
            st.insert(y);
        }
        for(auto x : st) cout<<x<<" ";
        cout<<endl;
        
    }


    system("pause");
    return 0;
}