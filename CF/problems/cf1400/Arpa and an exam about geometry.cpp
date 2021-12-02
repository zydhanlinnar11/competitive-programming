#include <iostream>
using namespace std;

long long kuadrat(long long angka) {
    return angka * angka;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long ax, ay, bx, by, cx, cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    if((cy - ay)*(bx - ax) == (cx - ax)*(by - ay) ||
        (kuadrat(bx - ax) + kuadrat(by - ay)) != (kuadrat(cx - bx) + kuadrat(cy - by)))
        cout<<"NO\n";
    else cout<<"YES\n";
}