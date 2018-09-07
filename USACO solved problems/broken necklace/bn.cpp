/*
ID: foozhan1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream fin ("beads.in");
   ofstream fout ("beads.out");
   int n,r=0,max=0,l=0,j=0,mid;
   char lb=0;
   bool changed=false;
   string neck, neck2;
   fin>>n;
   fin>>neck;
   int k;
   for(k=0;(neck[k]=='r'||neck[k]=='w')&& k<n;++k){}
   	if(k != n)	
   	for(;(neck[k]=='b'||neck[k]=='w')&& k<n;++k){}
   			if(k==n){
   			fout<<k<<endl;
   			return 0;}
   	 for(k=0;(neck[k]=='b'||neck[k]=='w') && k<n;++k){}
   		if(k != n)
   	for(;neck[k]=='r'||neck[k]=='w';++k){}
   			if(k==n){
   			fout<<k<<endl;
   			return 0;}


   neck2 = neck+neck;
   n *=2;
   for(int i=0 ; i<n;l=r ){
   	if(neck2[i]=='r'){
   		r=1;
   		if(i!=0 && neck2[i-1]=='w'){
   			for( j=i-1; neck2[j]=='r' || neck2[j]=='w' ;--j)
   				r++;
   		
   		if(neck2[j]=='b')
   			if(neck2[++j]=='w')
   				for(;neck2[j]=='w';j++)
   					l--;
   		}
   		i++;
   		for (; neck2[i]=='r' || neck2[i]=='w'  ; ++i)
   		{
   			r++;

   		}													
   		mid=i;}
   		
   	else if(neck2[i]=='b'){
   		r=1;
   		
   		if(i!=0 && neck2[i-1]=='w'){
   			for(j=i-1; neck2[j]=='b' || neck2[j]=='w' ;--j)
   				r++;
   				if(neck2[j]=='r')
   			if(neck2[++j]=='w')
   				for(;neck2[j]=='w';j++)
   					l--;
   		}
   	i++;
   		for (; neck2[i]=='b' || neck2[i]=='w'; ++i)
   		{
   			r++;
   		}

   	}
   	else if(neck2[i]== 'w'){
   		r++;

   		i++;
   		for (; neck2[i]== 'w'; ++i)
   		{
   			r++;
   		}

   	}

   	if(l+r > max){
   		mid=i;
   		max= l+r;
   	}
}
	fout<<max<</*"  mid="<<mid<<*/endl;
	//fout<<neck2;
	
	
	return 0;
}
