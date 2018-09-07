/*
ID: foozhan1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n, in[100000];
   fill(in , in+100000 , -1);
    fin>>n;
    int count= n;
    fin>>in[0];
    fin>>in[1];
    n--;
    int i =0;
    int firstMilk= in[0];
   while(n>0){
   	n--;
   	i +=2;
   	fin>>in[i];
   	if(in[i]< firstMilk)
   		firstMilk = in[i];
   	fin>>in[i+1];    
   }




      int s,y,temp1,temp2;
    for(int z=0; in[z] != -1 ; z+=2)
    { 
      s = z;
      if(in[z] != in[z+1]){
        for(y= z+2; in[y] != -1 ; y+=2){
          
          if(in[y] != in[y+1])
          if( in[s] > in[y])
          {
            s = y;
          }
        }
      }
      if(s != z){
      temp1 = in[z];
      temp2 = in[z+1];
      in[z] = in[s];
    in[z+1] = in[s+1];
      in[s] = temp1;
      in[s+1] = temp2;
    }
    }


    int maxNoneMilk = 0;
    int start=in[0], end=in[1];
   	int maxMilk = end - start;
  	for(int c=0;in[c] != -1 ; c+= 2){
  		
      if(in[c] >= start && in[c] <= end){
        if(in[c+1]>end)
        {
          end = in [c+1];
            if(end - start > maxMilk)                          
            maxMilk = end - start;
          
        }
      }
      else
      {

      		 if(in[c] - end > maxNoneMilk){
          maxNoneMilk = in[c]- end;
          
        }
          start = in[c];
          end = in[c+1];
        
          if(end - start > maxMilk)
        maxMilk = end - start;
      
       
         
        
      }
    
  	}
   	fout<<maxMilk<<" "<<maxNoneMilk<<endl;
     return 0;
}