#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull t, n;
    cin>>t;
    while(t--) {
        multiset<ull> ms;
        cin>>n;
        ull cost = 0;
        while(n--) {
            ull tmp;
            cin>>tmp;
            ms.insert(tmp);
        }
        while(ms.size() >= 2) {
            auto begin = ms.begin(), next = ++begin;
            begin--;
            ull tmp = *begin + *next;
            cost += tmp;
            ms.erase(next);
            ms.erase(ms.begin());
            ms.insert(tmp);
        }
        cout<<cost<<'\n';
    }
    return 0;
}