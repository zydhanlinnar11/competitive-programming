#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long n, k;
    cin>>n>>k;
    if(k == 1)
        cout<<n<<'\n';
    else if(n % 2 == 0)
        cout<<"0\n";
    else if(k > 2 || (n / 2) % 2 == 0)
        cout<<"1\n";
    else
        cout<<((n / 2) ^ ((n / 2) + 1))<<'\n';
    return 0;
}