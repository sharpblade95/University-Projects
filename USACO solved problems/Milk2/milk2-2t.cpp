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
    
    int n, in[10000];
   fill(in , in+10000 , -1);
    cin>>n;
    int count= n;
    cin>>in[0];
    cin>>in[1];
    n--;
    int i =0;
    int firstMilk= in[0];
   while(n>0){
   	n--;
   	i +=2;
   	cin>>in[i];
   	if(in[i]< firstMilk)
   		firstMilk = in[i];
   	cin>>in[i+1];




   	/*for(int j = i-2; j>= 0 && in[j] != -1;j -= 2){
   		if(in[j] != in[j+1]){
   			if(in[i] <= in[j]){
   				if(in[i+1]<= in[j+1] && in[i+1] >= in[j]){                 
   					in[i+1] = in[j+1];
   					in[j+1] = in[j];
   				}
   				else if(in[i+1] >= in[j+1])
   				{
   					in[j] = in[j+1];
   				}
   			}
   			else if(in[i] > in[j] && in[i]<= in[j+1])
   				if(in[i+1] <= in[j+1]){
   					in[i]= in[j];
   					in[i+1]= in[j+1];
   					in[j+1]= in[j];
   				}
   				else if(in[i+1]>= in[j+1])
   				{
   					in[i] = in[j];
   					in[j+1]= in[j];
   				}
   		}
   	}*/
    
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
            if(end - start > maxMilk)                           ////////////// 6 1 3 2 4 3 6 7 9 8 12 12 17
            maxMilk = end - start;
          
        }
      }
      else
      {

         if( in[c] - end > maxNoneMilk){
          maxNoneMilk = in[c]- end;
          
        }
          start = in[c];
          end = in[c+1];
        
          if(end - start > maxMilk)
        maxMilk = end - start;
      
       
         
        
      }
    
  	}



  
  /*	int x=2;
  	for (int n = 0; in[n] != -1; n=x)
  	{
  		if(in[n] != in[n+1]){
  			 x=n+2;
  			for(;in[x] == in[x+1] && in[x] != -1; x+=2);
  			if(in[x] - in[n+1] > maxNoneMilk)
  				maxNoneMilk = in[x] - in[n+1];
  		}
   	}*/


    for(int j=0; in[j] != -1; j+=2)
      cout<<"in["<<j<<"] ="<<in[j]<<" "<<"in["<<j+1<<"] ="<<in[j+1]<<endl;

    cout<<maxMilk<<" "<<maxNoneMilk<<endl;


     return 0;
}