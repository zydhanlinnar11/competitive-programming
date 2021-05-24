#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    cout<<(((n / 2) % 2 || (m / 2) % 2) ? "No\n" : "Yes\n");
}