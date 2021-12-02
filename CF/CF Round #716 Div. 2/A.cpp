#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool isPerfectSquare(int n) {
    int root = sqrt(n);
    return (root * root) == n;
}

void prog() {
    int n;
    cin>>n;
    bool anyImperfect = false;
    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        if(!isPerfectSquare(tmp)) anyImperfect = true;
    }
    
    if(anyImperfect) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) prog();
    return 0;
}