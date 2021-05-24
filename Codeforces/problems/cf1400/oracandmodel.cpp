#include <iostream>
using namespace std;

void prog() {
    int n;
    cin>>n;
    int arr[n + 1];
    int dp[n + 1];
    for(int i=1; i<=n; i++)
        cin>>arr[i];

    for(int i=1; i<=n; i++) {
        dp[i] = 1;
        int index = i;
        for(int j=1; j * j <= index; j++) {
            if(i % j == 0 && arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
            if(i % j == 0 && arr[i / j] < arr[i])
                dp[i] = max(dp[i], dp[i / j] + 1);
        }
    }

    int longest = 1;
    for(int i=1; i<=n; i++)
        longest = max(longest, dp[i]);

    cout<<longest<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) prog();
    return 0;
}