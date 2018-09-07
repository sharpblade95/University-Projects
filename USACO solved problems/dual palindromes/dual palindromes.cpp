/*
ID: foozhan1
PROG: dualpal
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
	ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");

    int n,s;

    fin>>n>>s;
   
	int flag =0 , b=2;  


    for(int i=s+1 , j=0; j<n ;i++){
    	flag=0;
    	b=2;
    	while(flag <2 && b<=10){
    		if(isPoli(baseToB(i,b))){
    			flag++;
    		}
      		b++;
    	}
    	if (flag ==2){
    		j++;
    		fout<<i<<endl;
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