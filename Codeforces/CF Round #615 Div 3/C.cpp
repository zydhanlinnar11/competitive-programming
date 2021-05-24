#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<bool> primalitytable(100000, true);
vector<int> primeNumbers;

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    for(int i=2; i*i <= n; i++)
        if((n % i) == 0) return false;
    return true;
}

void sieve() {
    for(int i=0; i<primalitytable.size(); i++) {
        if(primalitytable[i] && isPrime(i)) {
            int factor = 2;
            while(factor * i < primalitytable.size())
                primalitytable[i * factor] = false, factor++;
            primeNumbers.push_back(i);
        }
    }
}

void prog() {
    int n, n_backup;
    cin>>n;
    n_backup = n;
    if(isPrime(n)) {
        cout<<"NO\n";
        return;
    }
    map<int, unsigned> howMany;
    for(int primeNumber : primeNumbers) {
        if(primeNumber > n) break;
        while((n % primeNumber) == 0) {
            n /= primeNumber;
            howMany[primeNumber]++;
        }
    }
    if(n != 1)
        howMany[n] = 1, n = 1;
    int a, b, c;
    a = howMany.begin()->first;
    if(--howMany[a] == 0) howMany.erase(a);
    b = howMany.begin()->first;
    if(--howMany[b] == 0) howMany.erase(b);
    if(a == b) b *= (c = howMany.begin()->first);
    if(--howMany[c] == 0) howMany.erase(c);
    if(a == 0 || b == 0 || a == b) {
        cout<<"NO\n";
        return;
    }
    c = n_backup / (a * b);
    if(c == a || c == b || a == 1 || b == 1 || c == 1) {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n"<<a<<' '<<b<<' '<<c<<'\n';
    // for(auto i : howMany)
    //     cout<<i.first<<'^'<<i.second<<' ';
    // cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    sieve();
    while(t--) prog();
}