#include <bits/stdc++.h>
using namespace std;

vector<int> generatePrimes() {
    vector<int> primes;
    int n = 1e6;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for(int i=0; i<=n; i++) {
        if(is_prime[i]) primes.push_back(i);
    }
    return primes;
}