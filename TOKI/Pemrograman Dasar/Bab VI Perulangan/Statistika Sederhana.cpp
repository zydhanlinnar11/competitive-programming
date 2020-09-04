#include <iostream>
using namespace std;

int main() {
    int n, a=-1000000, b=1000000, tmp;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>tmp;
        a = max(tmp, a);
        b = min(tmp, b);
    }
    cout<<a<<' '<<b<<'\n';
    return 0;
}