#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, total = 0;
    cin>>n;
    int arr[n];
    for(int &i: arr)
        cin>>i;
    for(int i: arr) {
        int tmp;
        cin>>tmp;
        if(i > tmp)
            total += 3;
        else if(i == tmp)
            total += 1;
    }
    cout<<total<<'\n';
}