#include <iostream>
using namespace std;

int main() {
	string out[] = {"satuan", "puluhan", "ratusan", "ribuan", "puluhribuan"}, in;
    cin>>in;
    cout<<out[in.length() - 1]<<'\n';
	return 0;
}