#include <bits/stdc++.h>
using namespace std;
typedef struct queuemember {
    int number = 0, banyak = 0;
}member;

int main() {
    int q, queue_size = 0;
    vector <member> modqueue;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        string cmd;
        cin>>cmd;
        if(cmd == "push_back") {
            int tmp;
            cin>>tmp;
            if(!modqueue.empty() && modqueue.back().number == tmp)
                modqueue[modqueue.size() - 1].banyak++;
            else modqueue.push_back({tmp, 1});
        } else if(cmd == "toFront") {
            int tmp;
            cin>>tmp;
            if(!modqueue.empty() && modqueue[0].number == tmp)
                modqueue[0].banyak++;
            else modqueue.insert(modqueue.begin(), {tmp, 1});
        } else if(cmd == "back") {
            if(modqueue.empty()) {
                cout<<"No job for Ada?\n";
                continue;
            }
            cout<<modqueue.back().number<<'\n';
            if(modqueue.back().banyak > 1)
                modqueue[modqueue.size() - 1].banyak--;
            else modqueue.pop_back();
        } else if(cmd == "front") {
            if(modqueue.empty()) {
                cout<<"No job for Ada?\n";
                continue;
            }
            cout<<modqueue.front().number<<'\n';
            if(modqueue.front().banyak > 1)
                modqueue[0].banyak--;
            else modqueue.erase(modqueue.begin());
        } else {
            if(!modqueue.empty()) reverse(modqueue.begin(), modqueue.end());
        }
    }
    return 0;
}
