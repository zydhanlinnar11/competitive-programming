#include <bits/stdc++.h>
using namespace std;
int quality[100000], n;

float median() {
    // Apabila jumlah data ganjil, ambil data ke-(n / 2).
    if(n%2==1) 
        return quality[n/2];
    return ((float)(quality[n/2]+quality[(n-1)/2])/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>quality[i];
    }
    sort(quality, quality+n); // Data diurutkan terlebih dahulu
    cout<<setprecision(1)<<fixed<<median()<<'\n';
    return 0;
}