/*
ID: foozhan1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int M,S,C;
    int occupiedStall[201]={0};
    int gaps[200][100]={{0}};
    for(int i=0;i<200;i++){
    	for(int j=0;j<100;j++){
    		gaps[i][j]=0;
    	}
    }


    fin>>M>>S>>C;
    int biggestGaps[50][2]={{0}};

    int big=0;
    for(int num; fin>>num ;){
    	if(num>big){
    		big=num;
    	}
    	occupiedStall[num]=1;
    	//fout<<occupiedStall[num];
    }

    


    int i;
    for(i=0;i<201 && occupiedStall[i] ==0;i++);

    int first=i;

	int j=0,count=0,k=1;
	
    for( ;i<201;i++){
    	if( occupiedStall[i]==0){
    		for( j=i;occupiedStall[j] == 0 && j<201;j++);
    		if(j < 201){
       			for( k=0;gaps[j-i+1][k]!=0;k++);
    			gaps[j-i+1][k]= i-1;
    			//fout<<i-1<<" "<<j-i+1<<endl;

    			i=j-1;
   			}
       	}
    }


    count=0;

    for(i=199;i!=0 && count<M-1 ;i--){
 	   if(gaps[i][0] != 0){
 	   		for(j=0;j<100 && gaps[i][j] !=0;++j,count++){
 	   			biggestGaps[count][0]= gaps[i][j];
 	   			biggestGaps[count][1]= i;
 	   			//fout<<biggestGaps[count][0]<<endl;
 	   			
 	   		}
    	}
	}


	int minimumStalls = 0;

	for(;first<=big;first++){
		minimumStalls++;
		for(int x=0;x<M-1  ;x++){
			if(first==biggestGaps[x][0]){
				first += biggestGaps[x][1]-1;
			}
		}
	}


	fout<<minimumStalls<<endl;




    return 0;
}