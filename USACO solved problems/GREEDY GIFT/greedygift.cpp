/*
ID: foozhan1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    string np[10] , c;
    int npa[10]={0} , a , b,d;
    fin >> a;
    for(int i = 0;i<a;i++)
     fin>> np[i];


      while(fin >> c){
		fin >> b;
		fin >> d;
		if (d==0) continue;
   	    for(int i=0; i<a ; i++){
           if(c==np[i]){
               npa[i] -= b-(b%d);
               for(int j=0;j<d ; j++){
                   fin>> c;
                   for(int k=0;k<a;k++){
                      if(np[k] == c){
                       npa[k] += b/d;
                       break;}
                }
               }
               break;
           }
    	}
		}
    
         for(int i=0; i<a ; i++)
             fout<<np[i]<<" "<<npa[i]<<"\n";


    return 0;
}
