#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], dp[n], len = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] > a[len - 1]) {
            dp[i] = ++len;
        } else {
            int pos = lower_bound(a, a + len, a[i]) - a;
            dp[i] = pos + 1;
            a[pos] = a[i];
        }
    }
    for (auto x: a) cout<<x<<" ";cout<<endl;
    for (auto x: dp) cout<<x<<" ";cout<<endl;
    int res = *max_element(dp, dp + n);
    cout <<n-res << endl;

    return 0;
}


//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    int a[] = {9, 2, 4, 6, 7, 3};
//    int pos = lower_bound(a, a + 1, 4)-a;
//    cout << pos << endl; // In ra giá tr? 3
//    return 0;
//}
