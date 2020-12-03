#include <bits/stdc++.h>
using namespace std;
struct beras {
    int weight;
    int cost;
    double CostPerWeight;
};

bool compare(beras &a, beras &b) {
    return a.CostPerWeight > b.CostPerWeight;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    double total = 0.0;
    vector<beras> arr;
    cin>>n>>x;
    for(int i=0; i<n; i++) {
        int weight;
        cin>>weight;
        arr.push_back({weight, 0, 0.0});
    }
    // hitung harga perberat
    for(auto &i : arr) {
        int cost;
        cin>>cost;
        i.cost = cost;
        i.CostPerWeight = (double)i.cost / i.weight;
    }
    sort(arr.begin(), arr.end(), compare); // urutkan data
    for(auto &i : arr) {
        // Greedy dengan mengambil semua beras termahal yang tersedia hingga kapasitas habis
        if(x == 0)
            break;
        if(i.weight < x)
            total += i.cost, x -= i.weight;
        else total += i.CostPerWeight * x, x = 0;
    }
    cout<<setprecision(5)<<fixed<<total<<'\n';
    return 0;
}