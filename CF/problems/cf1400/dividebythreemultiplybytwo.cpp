#include <iostream>
#include <deque>
#include <map>
#include <set>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<ull> arr;
    deque<ull> dq;
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        ull tmp;
        cin>>tmp;
        arr.insert(tmp);
    }

    for(int i=0; i<n; i++) {
        if(dq.empty()) {
            ull largest = *arr.rbegin();
            dq.push_back(largest);
            arr.erase(largest);
        } else if(dq.back() % 3 == 0 && arr.find(dq.back() / 3) != arr.end()) {
            ull back = dq.back();
            dq.push_back(back / 3);
            arr.erase(back / 3);
        } else if(dq.front() % 2 == 0 && arr.find(dq.front() / 2)  != arr.end()) {
            ull front = dq.front();
            dq.push_front(front / 2);
            arr.erase(front / 2);
        } else if(arr.find(dq.front() * 3) != arr.end()) {
            ull front = dq.front();
            dq.push_front(front * 3);
            arr.erase(front * 3);
        } else if(arr.find(dq.back() * 2) != arr.end()) {
            ull back = dq.back();
            dq.push_back(back * 2);
            arr.erase(back * 2);
        }
    }

    for(int i=0; i<n; i++) {
        cout<<dq.front();
        if(i == n - 1) cout<<'\n';
        else cout<<' ';
        dq.pop_front();
    }

    return 0;
}