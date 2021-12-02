#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    int t, n, k;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>n>>k;
        cin>>str;
        int ganti = 0;
        bool terlacak[100] = {0};
        // i == len - i - 1
        for(int i=0; i<=(k/2); i++) {
            queue<char> terpakai;
            bool sudah[30] = {false};
            int banyak[30] = {0}, terbanyak = 0;
            for(int j=i; j<n; j += k) {
                terlacak[j] = true;
                if(!sudah[str[j] - 'a']) {
                    sudah[str[j] - 'a'] = true;
                    banyak[str[j] - 'a']++;
                    terpakai.push(str[j]);
                } else banyak[str[j] - 'a']++;
            }
            for(int j=(n - i - 1); j>=0; j -= k) {
                terlacak[j] = true;
                if(!sudah[str[j] - 'a']) {
                    sudah[str[j] - 'a'] = true;
                    banyak[str[j] - 'a']++;
                    terpakai.push(str[j]);
                } else banyak[str[j] - 'a']++;
            }
            char modus = 'a';
            while(!terpakai.empty()) {
                if(terbanyak < banyak[terpakai.front() - 'a'])
                    terbanyak = banyak[terpakai.front() - 'a'], modus = terpakai.front();
                terpakai.pop();
            }
            for(int j=i; j<n; j += k) {
                if(modus != str[j]){
                    ganti++;
                str[j] = modus;}
            }
            for(int j=(n - i - 1); j>=0; j -= k) {
                if(modus != str[j]){
                    ganti++;
                str[j] = modus;}
            }
        }
        
        cout<<ganti<<'\n';
        // cout<<str<<'\n';
    }
    return 0;
}