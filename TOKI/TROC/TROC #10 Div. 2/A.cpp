#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin>>s>>t;
    int len = s.length();
    for(int i=0; i<len; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i]-'A'+'a';
        if(t[i] >= 'A' && t[i] <= 'Z')
            t[i] = t[i]-'A'+'a';
    }
    if(s == t)
        cout<<"20/20\n";
    else cout<<"x_x\n";
    return 0;
}