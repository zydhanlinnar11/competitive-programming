#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    unsigned long long arr[n], cnt=0;
    for(auto &i : arr)
        cin>>i;
    for(int i=0; i<n; i++) {
        for(int j=i + 1; j<n; j++) {
            for(int k=j + 1; k<n; k++) {
                unsigned long long a = arr[i], b = arr[j], c = arr[k];
                if(a + b > c && a + c > b && b + c > a)
                    cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
    return 0;
}