#include <bits/stdc++.h>
using namespace std;

int findMove(int a, int b) {
    if(a % b == 0) return 0;
    return (((a / b) + 1) * b) - a;
}

int main() {
    int t, a, b;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>a>>b;
        cout<<findMove(a, b)<<'\n';
    }
    return 0;
}