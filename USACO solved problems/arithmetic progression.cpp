/*
ID: foozhan1
PROG: ariprog
LANG: C++11
*/

#include <bits/stdc++.h>
 
 using namespace std;

int n,m;
long int seq[3][10001];


bool mark[(250*250*2)+1]={0}; 
int n1;

void generate_s(){
	
	int p=0;
	int q=0;
	long int t;
	
	for(;q<=m;q++){
		for(p=0;p<=m;p++){
			t=((p*p)+(q*q));
			
			
				mark[t]=true;
				
			
		}
	}
	
	
	
}

void DFS(){
	long int a=0,b=1,pos;
	
	int j=0;
	long int max= m*m*2;
	
	
	for(;a<=max;a++){
		if(mark[a]){
		for(b=1;b<=max/(n-1);b++){
			int i=0;
			for( pos=a+b; i<n-1;i++){
				if(mark[pos]){
				pos += b;
				}
				else
					break;
				
			}
			if(i>=n-1)
			{	
				seq[1][++j]=a;
				seq[2][j]=b;
			}
		}
	}
}

}

void mysort(){ 

	int temp=0;
	int i;
	for( i=1;seq[2][i]!=0;i++){
		temp=0;
		for(int j=i+1;seq[2][j]!=0;j++){
			if(seq[2][i]>seq[2][j]){
				if(seq[2][j]<seq[2][temp] || temp==0){
					temp= j;
				}
			}
		}
	
		if(temp != 0){
			swap(seq[1][temp],seq[1][i]);
			swap(seq[2][temp],seq[2][i]);
		}
	}
	
	for( i=1;seq[2][i+1]!=0;i++){
		int x=i;						
				while(seq[1][x]>seq[1][x+1] && x>0 && seq[2][x]==seq[2][x+1]){
				swap(seq[1][x],seq[1][x+1]);
				swap(seq[2][x],seq[2][x+1]);
				x--;
			}
		}
			
	
		
	
}

int main(){
	ifstream fin("ariprog.in");
	fin>>n>>m;
	fin.close();
	
	generate_s();

	DFS();	
	mysort();
	
	ofstream fout("ariprog.out");

	if(!seq[2][1])
		fout<<"NONE"<<endl;
	for(int i=1;seq[2][i]!=0&& i<= 10000;i++){
		fout<<seq[1][i]<<" "<<seq[2][i]<<endl;
	}

	fout.close();

	return 0;
}