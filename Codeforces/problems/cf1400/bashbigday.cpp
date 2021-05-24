#include <iostream>
using namespace std;
#define MAX_CONST 100000
int count[MAX_CONST + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int strength;
        cin>>strength;

        for(int j=2; j * j <= strength; j++) {
            if(strength % j == 0) count[j]++;
            while(strength % j == 0) strength /= j;
        }

        if (strength > 1) count[strength]++;
    }

    int ans = 1;
    for(int i=0; i<=MAX_CONST; i++)
        ans = max(ans, count[i]);

    cout<<ans<<'\n';

    return 0;
}