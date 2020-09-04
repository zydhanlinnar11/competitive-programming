#include <iostream>

using namespace std;

int main() {
	unsigned int a[100][100],b[100][100],c[100][100],i,j,k,n,m,p;
	
	cin>>n>>m>>p;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	
	for(i=0; i<m; i++){
		for(j=0; j<p; j++){
			cin>>b[i][j];
		}
	}
	
	for(i=0; i<n; i++) {
		for(j=0; j<p; j++){
			c[i][j]=0;
			for(k=0; k<m; k++){
				c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
			}
		}
	}
	
	for(i=0; i<n; i++) {
		for(j=0; j<p; j++){
			if(j==(p-1)){
				cout<<c[i][j]<<endl;
			} else {
				cout<<c[i][j]<<" ";
			}
		}
	}
	
	return 0;
}