#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void func() {
    string s;
    cin>>s;
    int res = 0;
    vector<int> right;
    right.push_back(0);
    for(int i=0; i<s.length(); i++)
        if(s[i] == 'R')
            right.push_back(i + 1);
    right.push_back(s.length() + 1);
    for(int i=1; i<right.size(); i++) {
        res = max(right[i] - right[i - 1], res);
    }
    cout<<res<<'\n';
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