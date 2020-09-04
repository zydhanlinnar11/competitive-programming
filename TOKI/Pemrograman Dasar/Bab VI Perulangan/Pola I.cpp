#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    for(int i=1; i<=n; i++) {
        if(i % k)
            cout<<i;
        else cout<<'*';
        if(i != n)
            cout<<' ';
    }
    cout<<'\n';
    return 0;
}