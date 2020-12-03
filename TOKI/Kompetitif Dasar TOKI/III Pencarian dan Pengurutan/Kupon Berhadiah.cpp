#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    int diff[1000];
    cin>>n>>x;
    int min = INT_MAX;
    int minDiff = INT_MAX;
    int coupon[1000];
    for (int i = 0; i<n; i++) {
        cin>>coupon[i];
        // Selalu ambil nilai dengan selisih terkecil
        diff[i] = abs(x-coupon[i]);
        if (diff[i]<minDiff) {
            minDiff = diff[i];
            min = INT_MAX;
        }
        if(diff[i]==minDiff && coupon[i]<min) {
            min = coupon[i];
        }
    }
    cout<<min<<endl;
    return 0;
}