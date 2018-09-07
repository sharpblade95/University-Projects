/*
ID: foozhan1
PROG: milk3
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

set <int> amounts;
auto it = amounts.begin();
int a,b,c;
bool mark[21][21][21];
void process(int fulla,int fullb,int fullc){
	if(mark[fulla][fullb][fullc])
		return;
	else
		mark[fulla][fullb][fullc]= true;
	
	if(fulla==0  )/// moshkel dare
		{
			
			/*if(fullc ==c)
				return;*/
			
			amounts.insert(fullc);
			
			
			
		}	

	if(fulla< a){
		if(fullc>0){
			if(fullc >= a-fulla)
				process(a,fullb,fullc-(a-fulla));
			else
				process(fulla+fullc,fullb,0);
		}
		if(fullb>0){
			if(fullb >= a-fulla)
				process(a,fullb-(a-fulla),fullc);
			else
				process(fulla+fullb,0,fullc);
		}
	}
	if(fullb<b){
		if(fullc>0){
			if(fullc >= b-fullb)
			process(fulla,b,fullc-(b-fullb));
			else
				process(fulla,fullb+fullc,0);
		}
		if(fulla>0){
			if(fulla >= b-fullb)
				process(fulla-(b-fullb),b,fullc);
			else
				process(0,fullb+fulla,fullc);

		}
	}
	if(fullc<c)
		if(fulla>0){
			if(fulla >= c-fullc)
				return;
				//process(fulla-(c-fullc),fullb,c);
			else
				process(0,fullb,fullc+fulla);

		}
		if(fullb>0){
			if(fullb >= (c-fullc))
				return;
				//process(fulla,fullb-(c-fullc),c);
			else
				process(fulla,0,fullb+fullc);
		}



}	




int main(){
	ifstream fin("milk3.in");
	fin>>a>>b>>c;
	fin.close();
	
	//amounts.insert(c);
	if(b>=c)
		amounts.insert(0);
	process(0,0,c);

	ofstream fout("milk3.out");
	for(int x: amounts){
		
		fout<<x;
		if(x!=c)
			fout<<" ";

	}
	
	fout<<endl;
	fout.close();

	return 0;
}
