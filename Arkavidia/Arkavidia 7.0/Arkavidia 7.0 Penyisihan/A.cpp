#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin>>n>>q;
    int arr[n];
    int arrMax = -1;
    for(auto &i: arr) {
        cin>>i;
        arrMax = max(arrMax, i);
    }
    int dpSize = pow(2, arrMax) + arrMax;
    bool dp[dpSize + 1];
    dp[0] = false;

    // true -> Elon menang

    for(int i=1; i<=dpSize; i++) {
        dp[i] = false;
        for(int j: arr)
            if(j <= i && !dp[i - j]) {
                dp[i] = true;
                break;
            }
    }

    bool expectation = false;
    int cycle;
    for(int i=0; i<=dpSize; i++) {
        // if(expectation && dp[i] == false) {
        //     cycle = i + 1;
        //     printf("cycle every %d.\n", i + 1);
        //     break;
        // }
        // if(!expectation)
        //     expectation = dp[i];
        cout<<dp[i]<<'\n';
    }
    // while(q--) {
    //     int jml_tumpukan;
    //     cin>>jml_tumpukan;
    //     if(dp[jml_tumpukan % cycle])
    //         cout<<"Elon\n";
    //     else cout<<"Melvin\n";
    // }
}