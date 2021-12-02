#include <iostream>
using namespace std;
typedef long long ll;

void func() {
    ll n;
    cin>>n;
    ll sum = 0;
    ll it = 1;
    while(it <= n) {
        for(int i=1; i<=9 && it * i <= n; i++) {
            sum++;
        }
        it = it * 10 + 1;
    }
    cout<<sum<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) func();
    return 0;
}