#include <bits/stdc++.h>
using namespace std;
typedef struct friends {
    int start, endtime;
}teman;
bool compareEnd(teman a, teman b) { return (a.endtime < b.endtime); }

int main() {
    teman a[100000];
    int n, start = 0, invited = 0;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i].start>>a[i].endtime;
        a[i].endtime += a[i].start - 1;
    }
    sort(a, a + n, compareEnd);
    for(int i=0; i < n; i++) {
        if(a[i].start > start) {
            invited++;
            start = a[i].endtime;
        }
    }
    cout<<invited<<'\n';
    return 0;
}