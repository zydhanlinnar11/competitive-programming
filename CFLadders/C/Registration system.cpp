#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string, int> um;
    int n;
    cin>>n;
    while(n--) {
        string tmp;
        cin>>tmp;
        auto curr = um.find(tmp);
        if(curr == um.end()) {
            cout<<"OK\n";
            um.insert(make_pair(tmp, 1));
        } else
            cout<<tmp<<curr->second++<<'\n';
    }
    return 0;
}