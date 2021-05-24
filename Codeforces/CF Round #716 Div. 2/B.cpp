#include <stdio.h>
#define mod 1000000007
 
unsigned long long ezbgt(unsigned long long, unsigned long long);
unsigned long long kalimod(unsigned long long, unsigned long long);
 
int main() {
    unsigned long long a, b;
    unsigned short t, i;
    scanf("%hu", &t);
    for(i=0; i<t; i++) {
        scanf("%llu %llu", &a, &b);
        printf("%llu\n", ezbgt(a,b));
    }
    return 0;
}

unsigned long long kalimod(unsigned long long a, unsigned long long b) {
    unsigned long long hasil = 0;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) {
            hasil += a;
            hasil %= mod;
        }

        a *= 2;
        a %= mod;
        b /=2;
    }
    return hasil % mod;
}
 
unsigned long long ezbgt(unsigned long long a, unsigned long long b) {
    unsigned long long hasil=1;
    a %= mod;

    while(b > 0) {
        if(b % 2 == 1) {
            hasil = kalimod(hasil, a);
        }

        b /= 2;
        a = kalimod(a, a);
    }
    return hasil;
}