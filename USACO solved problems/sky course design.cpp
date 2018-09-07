/*
ID: foozhan1
PROG: skidesign
LANG: C++11
*/


#include<bits/stdc++.h>
#include<fstream>
#include<string>

using namespace std;
multiset <int> test;



int main(){
	
	ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");

	int total=-1,i,n;
	fin>>n;
	while(n){
		fin>>i;
		test.insert(i);
		n--;
	}
	
	int cost;
	
	for(int i=0;i+17<=100 && *test.end()>=i;i++){
		cost=0;

		for(int x:test){

			if(x > i+17){
				cost+= (x-(i+17))*(x-(i+17));
			}
			else if(x<i){
				cost+= (i-x)*(i-x);
			}


		}
		if(total> cost || total == -1)
			total=cost;

	}
	fout<< total<<endl;
	
		

    return 0;

}
