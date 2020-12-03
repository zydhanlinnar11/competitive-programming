#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int t;
    cin>>t;
    while(t--) {
        cin>>s;
        cout<<s.length()<<'\n';
    }
}