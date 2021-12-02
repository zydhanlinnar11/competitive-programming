#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> plpii;
int *par;

int find(int x) {
    if(par[x] != x) {
        return par[x] = find(par[x]);
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int kota, jalan;
    cin>>kota>>jalan;
    vector<plpii> edgeList;
    par = new int[kota];
    for(int i=0; i<kota; i++)
        par[i] = i;
    for(int i=0; i<jalan; i++) {
        int src, dst;
        ll cost;
        cin>>src>>dst>>cost;
        src--, dst--;
        edgeList.push_back(make_pair(cost, make_pair(src, dst)));
    }
    sort(edgeList.begin(), edgeList.end());
    ll res = 0;
    int sambung = 0;
    for(int i=0; i < jalan && sambung < (kota - 1); i++) {
        int src = edgeList[i].second.first, dst = edgeList[i].second.second;
        int pSrc = find(src), pDst = find(dst);
        ll cost = edgeList[i].first;

        if(pSrc != pDst) {
            sambung++;
            res += cost;
            par[pSrc] = par[pDst];
        }
    }
    cout<<res<<'\n';
    return 0;
}