#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

string getType(int a) {
    string type[] = {"WS", "MS", "AS", "AS", "MS", "WS"};
    return type[(a - 1) % 6];
}

bool isPrime(ull a) {
    for(ull i=2; i*i <=a; i++) {
        if(a % i == 0) return false;
    }
    return (true && (a != 1));
}

ull getHadap(ull a) {
    ull plus[] = {1, 3, 5, 7, 9, 11};
    if(((((a - 1) / 6) % 2) == 0)) return  a + plus[5 - ((a - 1) % 6)];
    else return a - plus[(a - 1) % 6];
}

int main() {
    ull t, n, a;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>n;
        if(i > 1) cout<<'\n';
        cout<<"Kasus #"<<i<<":\n";
        bool oke = false;
        for(int j=0; j<n; j++) {
            cin>>a;
            if(oke) continue;
            ull hasil = getHadap(a);
            if(isPrime(hasil)) {
                cout<<hasil<<" "<<getType(hasil)<<'\n';
                oke = true;
            }
        }
        if(oke) continue;
        cout<<"Makanya Jangan Aneh - Aneh"<<'\n';
    }
}