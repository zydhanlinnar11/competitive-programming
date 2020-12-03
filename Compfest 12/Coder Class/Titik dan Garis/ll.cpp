#include <bits/stdc++.h>
using namespace std;

int det(int arr[][2]) {
    return (arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x[4], y[4];
    for(int i=0; i<4; i++)
        cin>>x[i]>>y[i];
    int b1 = y[1] - y[0], a1 = x[1] - x[0];
    int b2 = y[3] - y[2], a2 = x[3] - x[2];
    int constant1 = (b1 * x[0]) - (a1 * y[0]);
    int constant2 = (b2 * x[2]) - (a2 * y[2]);
    int matriks0[2][2] = {{b1, -a1}, {b2, -a2}}, det0 = det(matriks0);
    int matriks1[2][2] = {{constant1, -a1}, {constant2, -a2}}, det1 = det(matriks1);
    int matriks2[2][2] = {{b1, constant1}, {b2, constant2}}, det2 = det(matriks2);
    double resx = (double)det1 / det0, resy = (double)det2 / det0;
    if(max(x[0], x[1]) >= resx && min(x[0], x[1]) <= resx && max(x[2], x[3]) >= resx && min(x[2], x[3]) <= resx
    && max(y[0], y[1]) >= resy && min(y[0], y[1]) <= resy && max(y[2], y[3]) >= resy && min(y[2], y[3]) <= resy)
        cout<<setprecision(9)<<fixed<<(double)det1 / det0<<' '<<(double)det2 / det0<<'\n';
    else cout<<"-1 -1\n";;
    return 0;
}