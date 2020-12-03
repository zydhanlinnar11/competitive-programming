#include <cstdio>
#define ll long long
ll prob(ll n) {
    ll sum = 0;
    while(n > 1) {
        if(n & 1) n = (n * 3) + 1;
        else n >>= 1;
        sum++;
    }
    return ++sum;
}

int main() {
    ll a, b;
    while(scanf("%lld %lld", &a, &b) == 2) {
        ll MAX = 0;
        printf("%lld %lld ", a, b);
        if(a > b) {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        for(ll i=a; i<=b; i++) {
            ll tmp = prob(i);
            MAX = ((tmp > MAX) ? tmp : MAX);
        }
        printf("%lld\n", MAX);
    }
    return 0;
}