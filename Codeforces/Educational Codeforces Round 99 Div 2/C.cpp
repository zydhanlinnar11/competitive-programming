#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int x, y;
        cin>>x>>y;
        cout<<x - 1<<" "<<y<<'\n';
    }
}