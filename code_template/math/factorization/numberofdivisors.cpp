
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

inline vector<int> generatePrimes() {
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
using u64 = uint64_t;
using u128 = __int128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (u64 a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

inline void prog() {
    ll n;
    cin>>n;
    vi primes = generatePrimes();
    ll ans = 1;
    for(int i: primes) {
        if((ll)i*i*i > n) break;
        int cnt = 1;
        while(n % i == 0) {
            n /= i;
            cnt++;
        }
        ans *= cnt;
    }
    if(MillerRabin(n))
        ans *= 2;
    else if((ll)sqrt(n) * (ll)sqrt(n) == n && MillerRabin((ll)sqrt(n)))
        ans *= 3;
    else if(n != 1) ans *= 4;
    cout<<ans<<'\n';
}