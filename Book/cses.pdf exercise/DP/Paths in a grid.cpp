#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n + 1][n + 1], sum[n + 1][n + 1];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++) {
            if(i == 0 || j == 0)
                arr[i][j] = 0;
            else cin>>arr[i][j];
            sum[i][j] = 0;
        }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            sum[i][j] = max(sum[i - 1][j], sum[i][j - 1]) + arr[i][j];
    cout<<"Maximum value : "<<sum[n][n]<<'\n';
    return 0;
}