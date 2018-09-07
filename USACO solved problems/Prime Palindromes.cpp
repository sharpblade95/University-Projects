/*
ID: foozhan1
PROG: pprime
LANG: C++11
*/
#include <bits/stdc++.h>
#include <string>
using namespace std;




int a,b;


bool isprime(int i){
		int d;
		int t= sqrt(i)+1;
		
		for (d =3;  d < sqrt(i)+1 && (i%d !=0); d+=2);
		if( i%d != 0 ){
			return true;
			
		}

		return false;

	
	
}

void generatepol(){
	int temp;
	ofstream fout("pprime.out");


	if(a==5){
		fout<<5<<endl;
	
		fout<<7<<endl;		
	}
	if(a==6||a==7){
		fout<<7<<endl;
	
	}
	

	if(b>=11 && a<=101){
		for(int i=1;i<10 ;i+=2){
			temp = i*10+i;
			if(temp>b)
				break;
			if(temp<a)
				continue;
			if(isprime(temp) ){
			fout<<temp<<endl; 
			}
				
		}
	}
	if(b>=101 && a<=1001){
		for(int i=1;i<10;i +=2){
			for (int j = 0; j < 10; j++)
			{
				temp = i*100+i+j*10;
				if(temp>b)
					break;
				if(temp<a)
					continue;
				if(isprime(temp)){
				fout<<temp<<endl;
				}
				
			}
		}
	}
	if(b>=1001 && a<= 10001){
		for(int i=1;i<10;i +=2){
			for (int j = 0; j < 10; j++)
			{
				temp =i*1000+i+j*10+j*100;
				if(temp>b)
					break;
				if(temp<a)
					continue;
				if(isprime(temp)){
				fout<<temp<<endl;
				}
			}
		}
	}
	if(b>=10001 && a<= 100001){
		for(int i=1;i<10;i +=2){
			for (int j = 0; j < 10; j++)
			{
				for(int z=0;z<10;z++){
					temp = i*10000+i+j*1000+j*10+z*100;
					if(temp>b)
						break;
					if(temp<a)
						continue;
					if(isprime(temp)){
						fout<<temp<<endl;
					}
				}
			}
		}
	}
	if(b>=100001 && a<=1000001){	
		for(int i=1;i<10;i +=2){
			for (int j = 0; j < 10; j++)
			{
				for(int z=0;z<10;z++){
					temp =i*100000+i+j*10000+j*10+z*100+z*1000;
					if(temp>b)
						break;
					if(temp<a)
						continue;
					if(isprime( temp)){

						fout<<temp<<endl;

					}
				}
			}
		}
	}
	if(b>=1000001 && a<=10000001){	
		for(int i=1;i<10;i +=2){
			for (int j = 0; j < 10; j++)
			{
				for(int z=0;z<10;z++){
					for(int z2=0;z2<10;z2++){
						temp = i*1000000+i+j*100000+j*10+z*100+z*10000+z2*1000;
						if(temp>b)
							break;
						if(temp<a)
							continue;
						if(isprime( temp)){
						fout<<temp<<endl;

						}
					}
				}
			}	
		}
	}     
	if(b>=10000001 && a<=100000001){	
		for(int i=1;i<10;i +=2){
			for (int j = 0; j < 10; j++)
			{
				for(int z=0;z<10;z++){
					for(int z2=0;z2<10;z2++){
						temp =  i*10000000+i+j*1000000+j*10+z*100+z*100000+z2*10000+z2*1000;
						if(temp>b)
							break;
						if(temp<a)
							continue;
						if(isprime(temp)){
						fout<< temp<<endl;
						}
					}
				}
			}
		}
	}
		fout.close();

}

int main(){
	ifstream fin("pprime.in");
	fin>>a>>b;
	fin.close();


	generatepol();



/*
	int i=0,d,k=0;
	if(p[i]==5){
		fout<<p[i]<<endl;
		
	}*/

	




	

	/*for(int x=a;x<=b;x++){
		if(p[x])
		fout<<x<<endl;
		
	}*/





	return 0;
}