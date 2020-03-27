#include <bits/stdc++.h>
using namespace std;
long long t, n, k;

void print() {
    long long kemungkinan = n * (n - 1) / 2, abanyak = n - 2, bbanyak = 2, nbaru = n;
    while(abanyak > 0 && bbanyak > 0) {
        if(k <= (kemungkinan * abanyak / nbaru))
            cout<<'a', kemungkinan = (kemungkinan * abanyak / nbaru), abanyak--, nbaru--;
        else
            cout<<'b', k -= (kemungkinan * abanyak / nbaru), kemungkinan = kemungkinan * bbanyak / nbaru, bbanyak--, nbaru--;
    }
    while(abanyak > 0)
        cout<<'a', abanyak--;
    while(bbanyak>0)
        cout<<'b', bbanyak--;
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>n>>k;
        print();
    }
}