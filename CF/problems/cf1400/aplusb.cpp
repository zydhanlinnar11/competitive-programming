#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin>>a>>b;
    if(a.length() < b.length()) {
        string tmp = b;
        b = a;
        a = tmp;
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int carry = 0, i;
    for(i=0; i<b.length(); i++) {
        int sum = carry;
        carry = 0;
        sum += (a[i] + b[i]) - 2 * '0';
        carry = sum / 10;
        sum %= 10;
        a[i] = sum + '0';
    }

    while(carry > 0 && i < a.length()) {
        int sum = carry;
        carry = 0;
        sum += a[i] - '0';
        carry = sum / 10;
        sum %= 10;
        a[i] = sum + '0';
        i++;
    }

    if(carry != 0)
        cout<<carry;
    
    for(auto j=a.rbegin(); j != a.rend(); j++) {
        cout<<*j;
    }

    cout<<'\n';

    return 0;
}