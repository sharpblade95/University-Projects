/*
ID: foozhan1
PROG: crypt1
LANG: C++
*/
#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;

bool checkDigitLength(int num1,int num2){
	int result = num1*num2;
	

if(result/1000 != 0)
return false;
else
return true;
}

bool checkFinalLength(int num1,int num2){
	int result = num1+num2;
	
if(result/10000 != 0)
return false;
else
return true;
}

set < int > st;

bool digitIsPrime(int num, int* prime, int n){
//	int temp;
//	bool flag=false;
 while(num){
 //	flag = false;
// 	temp = num%10;
 	if( st.find( num%10 ) == st.end() )
 		return false;
// 	for(int i=0;i<n && flag != true;i++){
// 		if(temp == prime[i]){
// 			flag = true;
// 		}
// 	}
// 	if (flag != true){
// 		return false;
// 	}
 	num/=10;
 }
 return true;
}


int main() {
	ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
//	#define fin cin
//	#define fout cout
    int n,prime[100], result=0;
    fin>>n;
    for(int i=0;i<n;i++)
    	fin>>prime[i], st.insert(prime[i]);

    int m1= 0;
    for(int i=0; i<n;i++){
//    	m1 = m1 + prime[i] * 100;
       	for(int j=0;j<n;j++){
// 			m1 = m1 + prime[j] * 10;
	   		for(int x=0;x<n;x++){
//	   			m1 = m1 + prime[x];
    			int m1 = prime[i] * 100 + prime[j] * 10 + prime[x];
    			for(int y=0;y<n;y++){
    				if(checkDigitLength(m1, prime[y])){
    					if(digitIsPrime(m1*prime[y] , prime , n)){
	    					for(int z=0;z<n;z++){
	    						if(checkDigitLength(m1, prime[z])){
	    							if(digitIsPrime(m1*prime[z] , prime , n)){
			    						if(checkFinalLength(m1 , prime[y]*10 + prime[z])){
			    							if(digitIsPrime(m1*((prime[y]*10) + prime[z]) , prime , n)){
			    							result++;
			    								cout << m1 << " " << i << " " << j << " " << x << " " << prime[y] << " " << prime[z] << endl;
			    							}
			    						}
			    					}
		    					}
	    					}
	    				}
	    			}
    			}
//    			m1 = m1 - prime[x];
//    			m1 = m1- (prime[x]) + (x+1 < n ? (prime[x+1]) : 0 ); 
    		}
//    		m1 = m1 - prime[j] * 10;
//   		m1 = m1 - prime[n-1];
//    		m1 = m1- (prime[j]*10) + (j+1<n ? (prime[j+1]*10) : 0 ); 
    	}
//    	m1 = m1 - prime[i] * 100;
//    	m1 = m1- (prime[i]*100) + (i+1 < n ? (prime[i+1]*100) : 0 ); 
    }

    fout<<result<<endl;

  

	return 0;
}
