#include <iostream>
using namespace std;

int main() {
    string a;
    cin>>a;
    if(a == "0") {
        cout<<"nol\n";
        exit(0);
    }
    bool isAngka = true;
    for(auto i : a)
        isAngka &= (i >= '0' && i <= '9' || i == '-');
    if(!isAngka)
        cout<<"kata\n";
    else if(a[0] == '-')
        cout<<"bilangan bulat negatif\n";
    else cout<<"bilangan bulat positif\n";
    return 0;
}