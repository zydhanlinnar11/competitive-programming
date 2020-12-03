#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin>>n;
    vector<ll> arr(n, 0);
    arr[0] = 2;
    for(int i=1; i<n; i++)
        arr[i] = arr[i - 1] * 2;
    for(int i=1; i<n; i++)
        arr[i] += arr[i - 1];
    cout<<arr[n - 1]<<'\n';
    return 0;
}