#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull n;
    cin>>n;
    n = ((ull)3 * (ull)pow(2, n)) - (ull)2;
    cout<<n<<'\n';
    return 0;
}