#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    queue<string> qu;
    while(q--) {
        int cmd;
        string name;
        cin>>cmd;
        switch(cmd) {
            case 1:
                cin>>name;
                qu.push(name);
                break;
            case 2:
                cout<<qu.front()<<'\n';
                qu.pop();
                break;
        }
    }
    return 0;
}