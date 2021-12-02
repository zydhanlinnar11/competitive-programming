#include <iostream>
using namespace std;

int main() {
    int i;
    cin>>i;
    if(i == 4 || i == 5 || i == 13 || i == 14
    || i == 22 || i == 23 || i == 31 || i == 32
    || i == 40 || i == 41) {
        cout<<"0\n";
    } else if(i == 16) {
        printf("%lld %lld %lld\n", -511LL, -1609LL, 1626LL);
    } else if(i == 24) {
        printf("%lld %lld %lld\n", -2901096694LL, -15550555555LL, 15584139827LL);
    } else if(i == 30) {
        printf("%lld %lld %lld\n", -283059965LL, -2218888517LL, 2220422932LL);
    } else if(i == 33) {
        printf("%lld %lld %lld\n", -8778405442862239LL, -2736111468807040LL, 8866128975287528LL);
    } else if(i == 39) {
        printf("%lld %lld %lld\n", -159380LL, 134476LL, 117367LL);
    } else if(i == 42) {
        printf("%lld %lld %lld\n", -80538738812075974LL, 80435758145817515LL, 12602123297335631LL);
    } else {
        for(int j=-26; j<=31; j++) {
            for(int k=-26; k<=31; k++) {
                for(int l=-26; l<=31; l++) {
                    if((j*j*j) + (k*k*k) + (l*l*l) == i) {
                        cout<<j<<' '<<k<<' '<<l<<'\n';
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}