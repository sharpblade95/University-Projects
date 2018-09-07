/*
ID: foozhan1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;




int main() {
	ofstream fout ("combo.out");
    ifstream fin ("combo.in");
   
  	int n, comb[102][102][102]={0};



  	int c1[3],c2[3];

 	fin>>n;

  	fin>>c1[0]>>c1[1]>>c1[2];
  	fin>>c2[0]>>c2[1]>>c2[2];

  	comb[c1[0]][c1[1]][c1[2]]=1;
  	comb[c1[0]][c1[1]][c1[2]]=1;




  	int x,y,z;
  	for(int i=c1[0]-2;i<=c1[0]+2;i++){
  		for(int j=c1[1]-2;j<=c1[1]+2;j++){
  			for(int k=c1[2]-2;k<=c1[2]+2;k++){
  				if(i>n){ x= i-n;}
  				else if(i<1) {x=n+i;}
  				else{ x=i;}
  				if(j>n){ y= j-n;}
  				else if(j<1) {y=n+j;}
  				else{ y=j;}
  				if(k>n){ z= k-n;}
  				else if(k<1) {z=n+k;}
  				else{ z=k;}
  				
  				comb[x][y][z]=1;

  			}
  		}
  	}

  	for(int i=c2[0]-2;i<=c2[0]+2;i++){
  		for(int j=c2[1]-2;j<=c2[1]+2;j++){
  			for(int k=c2[2]-2;k<=c2[2]+2;k++){
  				if(i>n){ x= i-n;}
  				else if(i<1) {x=n+i;}
  				else{ x=i;}
  				if(j>n){ y= j-n;}
  				else if(j<1) {y=n+j;}
  				else{ y=j;}
  				if(k>n){ z= k-n;}
  				else if(k<1) {z=n+k;}
  				else{ z=k;}
  				
  				comb[x][y][z]=1;

  			}
  		}
  	}

  	int result=0;
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			for(int k=1;k<=n;k++){
  				if(comb[i][j][k]==1)result++;
  			}
  		}
  	}
  	fout<<result<<endl;

	return 0;
}
