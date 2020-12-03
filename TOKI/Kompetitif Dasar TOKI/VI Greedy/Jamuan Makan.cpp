#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, dijamu = 0, terakhirselesai = 0;
    cin>>n;
    pair<int, int> tamu[n]; // Daftar teman atau tamu
    for(auto &i : tamu)
        cin>>i.second>>i.first, i.first += i.second;
    sort(tamu, tamu + n);
    for(auto i : tamu)
        if(terakhirselesai <= i.second) // Yang terakhir selesai kurang dari waktu kunjungan tamu berikutnya
            terakhirselesai = i.first, dijamu++;
    cout<<dijamu<<'\n';
    return 0;
}