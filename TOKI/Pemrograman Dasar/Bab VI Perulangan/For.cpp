#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0;
    cin>>n;
    while(n--) {
        int tmp;
        cin>>tmp;
        sum+=tmp;
    }
    cout<<sum<<'\n';
    return 0;
}