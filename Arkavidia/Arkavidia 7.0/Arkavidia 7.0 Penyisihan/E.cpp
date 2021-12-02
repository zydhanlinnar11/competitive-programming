#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    bool bisa = true;
    for(int i=0; i<s.length(); i++) {
        if(!(s[i] >= 'a' && s[i] <= 'z')
        && !(s[i] >= 'A' && s[i] <= 'Z')
        && !(s[i] >= '0' && s[i] <= '9')) {
            cout<<"Emor tidak beruntung :(\n";
            return 0;
        } else if((s[i] >= 'A' && s[i] <= 'Z')) {
            s[i] = tolower(s[i]);
        }
    }
    for(auto i=s.rbegin(); i != s.rend(); i++) {
        cout<<*i;
    }
    cout<<'\n';
}