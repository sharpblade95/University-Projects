/*
ID: foozhan1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void sortPrices(int[][2],int);

int main(){
	ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int m,n;
    int farmersInfo[5000][2];

    fin>>n>>m;

    for(int i=0; i<m ; i++){
    	fin>>farmersInfo[i][0]>>farmersInfo[i][1];
    }

    sortPrices(farmersInfo,m);

    int totalPrice=0;

    for(int i=0; n > 0 ; i++){
    	if(n>= farmersInfo[i][1]){
    		n -= farmersInfo[i][1];
    		totalPrice += farmersInfo[i][0] * farmersInfo[i][1];
    	}
    	else{
    		totalPrice +=  n * farmersInfo[i][0];
    		n=0; 
    	}
    }

    fout<< totalPrice<<endl;


return 0;
}

void sortPrices(int farmersInfo[][2],int m){
	int temp[2];

	for(int i=0; i<m ; i++){
		for(int j=i+1; j<m ; j++){
			if(farmersInfo[i][0]>farmersInfo[j][0]){
				temp[0]=farmersInfo[i][0];
				temp[1]=farmersInfo[i][1];
				farmersInfo[i][0]= farmersInfo[j][0];
				farmersInfo[i][1]= farmersInfo[j][1];
				farmersInfo[j][0]= temp[0];
				farmersInfo[j][1]= temp[1];

			}
		}

	}
}