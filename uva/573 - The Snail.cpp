#include <cstdio>
#define ull long long

int main() {
    ull h, u, d, f;
    while(1) {
        scanf("%llu %llu %llu %llu", &h, &u, &d, &f);
        if(h == 0) break;
        ull i=1;
        long double pos = 0, power = (long double)u;
        while(1) {
            power = (long double)u - ((long double)(i - 1) * u * (long double)f / 100);
            if(power < 0) power = 0;
            pos += power;
            if(pos > (long double)h) {
                printf("success on day %llu\n", i);
                break;
            }
            pos -= d;
            if(pos < 0) {
                printf("failure on day %llu\n", i);
                break;
            }
            i++;
        }
    }
    return 0;
}