#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define mpair(a, b) make_pair(a, b)

void func() {
    string s;
    cin>>s;
    for(int i = 0; i < s.length(); i += 2)
        cout<<s[i];
    cout<<s.back()<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        func();
    return 0;
}