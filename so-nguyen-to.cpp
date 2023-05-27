#include <bits/stdc++.h>
using namespace std;

void findPreviousSubset(int n, int k, vector<int>& X) {
int i = k - 1;
while (i >= 0 && X[i] == n - k + i + 1) {
i--;
}
if (i < 0) {
for (int j = 0; j < k; j++) {
cout << j + 1 << " ";
}
cout << endl;
} else {
X[i]++;
for (int j = i + 1; j < k; j++) {
X[j] = X[j - 1] + 1;
}
for (int j = 0; j < k; j++) {
cout << X[j] << " ";
}
cout << endl;
}
}

int main() {
int t;
cin >> t;
while (t--) {
int n, k;
cin >> n >> k;
vector<int> X(k);
for (int i = 0; i < k; i++) {
cin >> X[i];
}
findPreviousSubset(n, k, X);
}
return 0;
}
