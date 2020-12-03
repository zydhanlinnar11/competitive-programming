#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    unordered_map<string, int> ms;
    while(n--) {
        string cmd, name;
        cin>>cmd>>name;
        if(cmd == "DAFTAR") {
            auto i = ms.find(name);
            if(i == ms.end())
                ms.insert(make_pair(name, 1));
            else i->second++;
        } else {
            auto i = ms.find(name);
            if(i == ms.end())
                cout<<"0\n";
            else cout<<i->second<<'\n';
        }
    }
    return 0;
}