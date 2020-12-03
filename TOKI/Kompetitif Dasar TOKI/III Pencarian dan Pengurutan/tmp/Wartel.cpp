#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    // Hanya perlu insert ke map lalu mencarinya
    map<string, string> mp;
    cin>>n>>q;
    for(int i=1; i<=n; i++) {
        string nama, nom;
        cin>>nama>>nom;
        mp.insert(make_pair(nama, nom));
    }

    for(int i=1; i<=q; i++) {
        string cari;
        cin>>cari;
        auto j = mp.find(cari);
        if(j == mp.end())
            cout<<"NIHIL\n";
        else cout<<j->second<<'\n';
    }
    return 0;
}