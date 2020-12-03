#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    int n, day = 0, contest[200000] = {0};
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>contest[i];
    }
    sort(contest, contest + n);
    for(int i=0; i<n; i++)
        if(contest[i] >= day + 1)
            day++;
    cout<<day<<endl;
}