#include <bits/stdc++.h>
using namespace std;

bool pb(string s) {
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '[' || s[i] == '(')
            st.push(s[i]);
        else if(st.empty() || (st.top() == '(' && s[i] == ']')
        || (st.top() == '[' && s[i] == ')'))
            return false;
        else st.pop();
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--) {
        string s;
        cin>>s;
        cout<<(pb(s) ? "ya" : "tidak")<<'\n';
    }
    return 0;
}