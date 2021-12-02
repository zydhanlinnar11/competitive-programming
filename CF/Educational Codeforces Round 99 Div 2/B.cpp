#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int tmp;
        cin>>tmp;
        int i;
        // bool sudah = true;
        for(i=0; ; i++) {
            int res = i * (i + 1) / 2;
            if(res > tmp) {
                if(res - tmp == 1)
                    continue;
                if(i > 1 && res - tmp == (i*i + 3*i - 2) / 2)
                    continue;
                break;
            } else if(res == tmp)
                break;
        }
        cout<<i<<'\n';
    }
}