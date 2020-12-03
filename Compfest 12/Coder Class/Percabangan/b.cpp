#include <iostream>
using namespace std;

int main() {
    int a, b;
    char x;
    cin>>a>>x>>b;
    if(x == '+')
        cout<<a+b<<'\n';
    else if(x == '-')
        cout<<a-b<<'\n';
    else if(x == '*')
        cout<<a*b<<'\n';
    else if(x == '/')
        cout<<a/b<<'\n';
    else cout<<a%b<<'\n';
    return 0;
}