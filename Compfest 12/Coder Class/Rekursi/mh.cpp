#include <bits/stdc++.h>
using namespace std;

void mh(short geco, char src, char pvt, char dst) {
    if(geco == 1) {
        cout<<"1 "<<src<<' '<<dst<<'\n';
        return;
    }
    mh(geco - 1, src, dst, pvt);
    cout<<geco<<' '<<src<<' '<<dst<<'\n';
    mh(geco - 1, pvt, src, dst);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    short n;
    cin>>n;
    mh(n, 'A', 'B', 'C');
    return 0;
}