#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    bool genap = true;
    int A[n];
    for(int &i: A)
        cin>>i;
    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        bool local_genap = (A[i] % 2 == 0);
        if((genap && local_genap) || (!genap && !local_genap))
            genap = true;
        else genap = false;
    }
    cout<<(genap ? 0 : 1)<<'\n';
}