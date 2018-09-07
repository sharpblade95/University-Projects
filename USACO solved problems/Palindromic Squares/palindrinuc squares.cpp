/*
ID: foozhan1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
/*#include <algorithm> 
*/

using namespace std;
string baseToB(int,int);
bool isPoli(string);


int main(){
	ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    int b;

    fin>>b;
   string bBased;
   string nBased;
  


    for(int n=1; n<=300;n++){
    	bBased = baseToB(n*n,b);

    	if(isPoli(bBased)){
    		fout<<baseToB(n,b)<<" "<<bBased<<endl;
    	}
    }


return 0;
}



string baseToB(int n, int base){
	string s1;
	int a;
	int x= n;
		if(base <= 10){

			for( ; x> 0; x /= base ){
				s1 += x%base + '0';
			
				
			 }
		}
		else{
			for(; x> 0; x /= base ){
				a= x%base;
				if(a > 9){
					s1 += (a-10) + 'A';
				}
				else {
					s1 += x%base + '0';
				}
				
			 }
		}

		int size = s1.size()-1;
		char temp;
		string s2;
		for(; 0<=size ;size--){
			s2 += s1[size];
		}
   		

   return s2;
}

bool isPoli(string s){
	int i = s.size();
	if(i>1){
		for(int j=0; i>j ; i--, j++){
			if(s[j] != s[i-1]){
				return false;
			}
		}
	}
	
	return true;
}