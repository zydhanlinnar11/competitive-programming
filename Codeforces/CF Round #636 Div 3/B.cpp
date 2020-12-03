#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        if((n / 2) & 1) printf("NO\n");
        else {
            printf("YES\n");
            printf("2");
            for(int i=1; i<(n/2); i++)
                printf(" %d", 2 * (i + 1));
            printf(" ");
            int i;
            for(i=1; i<(n/2); i++)
                printf("%d ", 2*i -1);
            cout<<((2*(n/2)) + i - 1)<<'\n';
        }
    }
    return 0;
}