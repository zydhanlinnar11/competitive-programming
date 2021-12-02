#include <iostream>
#include <stack>
#include <set>
using namespace std;

void func() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<char> st;
    set<char> kumpul;
    bool sus = false;
    for(int i=0; i<n && !sus; i++) {
        if(!kumpul.empty() && kumpul.find(s[i]) != kumpul.end() && !st.empty() && st.top() != s[i])
            sus = true;
        st.push(s[i]);
        kumpul.insert(s[i]);
    }
    cout<<(!sus ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) func();
    return 0;
}