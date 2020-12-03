#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef struct mapmaker {
    string name;
    short d;
    ll b, size, *u, *l, *c;
} arr;
#define mi map[i]
#define mj map[j]

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull n, r;
    cin>>n>>r;
    arr * map = new arr[n];
    for(int i=0; i<n; i++) {
        ll cd;
        cin>>mi.name>>mi.b>>cd>>mi.d;
        mi.l = new ll[mi.d];
        mi.u = new ll[mi.d];
        mi.c = new ll[mi.d + 1];
        mi.c[mi.d] = cd;
        for(short j=0; j<mi.d; j++)
            cin>>mi.l[j]>>mi.u[j];
        for(short j=(mi.d - 1); j>=1; j--)
            mi.c[j] = mi.c[j + 1] * (mi.u[j] - mi.l[j] + 1);
        mi.c[0] = mi.b;
        for(short j=1; j<=mi.d; j++)
            mi.c[0] -= (mi.c[j] * mi.l[j - 1]);
    }
    for(int i=0; i<r; i++) {
        string tmp;
        cin>>tmp;
        int j;
        for(j=0; j<n; j++) {
            if(mj.name == tmp) break;
        }
        ll * iaddr = new ll[mj.d], addr=mj.c[0];
        for(int k=0; k<mj.d; k++) {
            cin>>iaddr[k];
            addr += (iaddr[k] * mj.c[k + 1]);
        }
        cout<<tmp<<'['<<iaddr[0];
        for(int k=1; k<mj.d; k++)
            cout<<", "<<iaddr[k];
        cout<<"] = "<<addr<<'\n';
    }
    return 0;
}