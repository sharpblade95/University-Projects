/*
ID: foozhan1
PROG: numtri
LANG: C++11
*/

#include <bits/stdc++.h>
#define MAX_N 1001*1002/2

using namespace std;
int R, last;
int n[MAX_N];
bool seen[MAX_N];
int big[MAX_N];

int longest(int row,int i){
	
	if(row>R)
		return 0;
	if(seen[i]){
		return big[i];
	}
	int l,r;
	l= longest(row+1,i+row);
	
	r= longest(row+1,i+row+1);
	//cout<<"n[i]="<<n[i]<<" l="<<l<<" r="<<r<<endl;
	if(l>=r){
		seen[i]=true;
		big[i]= n[i]+l;
		return big[i];
	}
	else {
		seen[i]=true;
		big[i]= n[i]+r;
		return big[i];
		
	}

}

int main(){
	ifstream fin("numtri.in");
	fin>>R;
	 last= R*(R+1)/2;
	for(int i=1;i<=last;i++){
			fin>>n[i];
	}
	fin.close();
	
	/*//*/

	ofstream fout("numtri.out");
	fout<<longest(1,1)<<endl;
	fout.close();


	return 0;
}