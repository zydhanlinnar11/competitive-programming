#include <cstdio>
typedef struct tools {
    bool state = false;
    long long cons;
}device;

int main() {
    long long n, m, c, seq = 1;
    while(scanf("%lld %lld %lld", &n, &m, &c)) {
        if(n==0 && m==0 && c==0) break;
        device *d = new device[n];
        for(long long i=0; i<n; i++)
            scanf("%lld", &d[i].cons);
        long long usage = 0, maxusage = 0;
        printf("Sequence %lld\n", seq++);
        while(m--) {
            long long act;
            scanf("%lld", &act);
            if(!d[act - 1].state) {
                d[act - 1].state = true, usage += d[act - 1].cons;
                maxusage = ((usage > maxusage) ? usage : maxusage);
            } else d[act - 1].state = false, usage -= d[act - 1].cons;
        }
        delete [] d;
        if(maxusage <= c) printf("Fuse was not blown.\nMaximal power consumption was %lld amperes.\n\n", maxusage);
        else printf("Fuse was blown.\n\n");
    }
    return 0;
}