/* 
ID: foozhan123
PROG: sprime
LANG: C++11
*/

#include<bits/stdc++.h>
int N;
int p[1000],oldp[1000],counter;
using namespace std;

	
	

bool isprime(int i){
		int d;
		int t= sqrt(i)+1;
		
		for (d =3;  d < sqrt(i)+1 && (i%d !=0); d+=2);
		if( i%d != 0 ){
			return true;
			
		}

		return false;

}




 void primemaker(){
 	
	int max;
	
	p[counter++]=2;
	p[counter++]=3;
	p[counter++]=5;
	p[counter++]=7;
	
	for(int j=2,c2;j<=N;j++){
		memmove(oldp,p,sizeof oldp);
		/*for(int x:oldp){
			if(x==0)
				break;
			cout<<x<<endl;

		}*/
		for(int c=0;c<counter;++c){
			for(int i=1;i<10;i+=2){
				int r= oldp[c]*10+i;
				if(isprime(r)){
					p[c2++]=r;
				}
			}
		}
		counter  = c2;
		c2=0;
	}
	
	
}



int main(){
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");
	fin>>N;

	primemaker();


	for(int c=0;c<counter;c++)
		fout<<p[c]<<endl;
	return 0;
}
