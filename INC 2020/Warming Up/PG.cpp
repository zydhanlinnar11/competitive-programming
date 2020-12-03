#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, total = 0, tmp;
    cin>>n;
    cin>>tmp;
    while(n--)
        cin>>tmp, total += tmp;
    cout<<((total & 1) ? "John\n" : "Preston\n");
}