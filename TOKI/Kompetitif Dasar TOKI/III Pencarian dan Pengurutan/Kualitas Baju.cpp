#include <bits/stdc++.h>

using namespace std;

unsigned short quality[100000];
unsigned int n;

float median();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(unsigned int i=0; i<n; i++) {
        cin>>quality[i];
    }
    sort(quality, quality+n);
    cout<<fixed<<setprecision(1)<<median()<<endl;
    return 0;
}

float median() {
    if(n%2==1) {
        return (float)quality[n/2];
    } else {
        return ((float)(quality[n/2]+quality[(n-1)/2])/2);
    }
}