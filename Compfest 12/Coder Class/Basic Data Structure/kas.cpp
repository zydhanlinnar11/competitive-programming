#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    deque<string> qu;
    while(q--) {
        int cmd;
        string name;
        cin>>cmd;
        if(cmd == 1) {
            cin>>name;
            qu.push_front(name);
        } else if(cmd == 2) {
            cin>>name;
            qu.push_back(name);
        } else if(cmd == 3) {
            cout<<qu.front()<<'\n';
            qu.pop_front();
        } else {
            cout<<qu.back()<<'\n';
            qu.pop_back();
        }
    }
    return 0;
}