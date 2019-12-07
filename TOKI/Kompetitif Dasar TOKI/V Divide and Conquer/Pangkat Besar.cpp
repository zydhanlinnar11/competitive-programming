#include <stdio.h>
#include <iostream>
#include <cmath>
#define mod 1000000

using namespace std;
 
unsigned long long ezbgt(unsigned long long, unsigned long long);
unsigned long long kalimod(unsigned long long, unsigned long long);
 
int main() {
    unsigned long long a, b, hasil;
    scanf("%llu %llu", &a, &b);
    hasil = ezbgt(a,b);
    if(pow(a,b)>999999) {
        if(hasil == 0) {
            cout<<"00000";
        } else {
            unsigned long long digit=0, temp = hasil;
            while(temp>0) {
                temp /= 10;
                digit++;
            }
            if(digit<6) {
                for(int i = 1; i <= (6-digit); i++) {
                    cout<<"0";
                }
            }
        }
    }
    printf("%llu\n", hasil);
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