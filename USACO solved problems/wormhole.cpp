/*
ID: foozhan1
PROG: wormhole
LANG: C++11
*/


#include<bits/stdc++.h>
#include<fstream>
#include<string>
#define MAXSIZE 12
using namespace std;

long int n,x[MAXSIZE+1],y[MAXSIZE+1],total=0;
long int adj[MAXSIZE+1]={0} ,next_on_x[MAXSIZE+1];
bool pass[MAXSIZE+1]={};




void nextHole(int j){
	
	
	for(int i=1;i<=n;i++){
		if(x[i]>x[j] && y[i]==y[j]){
			if(x[next_on_x[j]]>x[i] || next_on_x[j]==0){
			 next_on_x[j]=i;
			}
		}
	}
		
}

bool cycleExists(){
	int pos;
		for(int i=1;i<=n;i++){
			pos=i;
			for(int j=0;j<n;j++){
				pos= next_on_x[adj[pos]];
			}
			if(pos != 0)
				return true;
		}
		
	
	return false;
}
int solve(){
	int i,total=0;
	for( i=1;i<=n;i++){
		if(adj[i]==0)
			break;
	}
	if(i>n){
		if(cycleExists()) return 1;
	
		else{
			return 0;
		}
	}
	

	for(int j=i+1;j<=n;j++){
		if(adj[j]==0){
			adj[j]=i;
			adj[i]=j;
			total += solve();
			adj[i]=adj[j]=0;

		}
	}
		
		return total;


}

int main(){
	
    ifstream fin ("wormhole.in");
	
	fin>>n;
	
	for(int i=1;i<=n;i++)
		fin>>x[i]>>y[i];
	
	fin.close();

	for(int i=1;i<=n;i++){
		 nextHole(i);
	}
	ofstream fout ("wormhole.out");
	
	
	fout<< solve() << endl;
	fout.close();	
	
    return 0;

}
