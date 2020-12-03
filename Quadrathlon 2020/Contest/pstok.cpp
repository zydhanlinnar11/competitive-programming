#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll subsetXOR(ll arr[], ll n, ll k) {
	ll max_ele = arr[0];
	for (ll i=1; i<n; i++)
	if (arr[i] > max_ele)
		max_ele = arr[i];

	ll m = (1 << (ll)(log2(max_ele) + 1) ) - 1;
	if( k > m )
	return 0;
	ll dp[n+1][m+1];

	for (ll i=0; i<=n; i++)
		for (ll j=0; j<=m; j++)
			dp[i][j] = 0;

	dp[0][0] = 1;

	for (ll i=1; i<=n; i++)
		for (ll j=0; j<=m; j++)
			dp[i][j] = dp[i-1][j] + dp[i-1][j^arr[i-1]];

	return dp[n][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n;
    ll x, arr[n];
    cout<<subsetXOR(arr, n, x);
	return 0;
}
