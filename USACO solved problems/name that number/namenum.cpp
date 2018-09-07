/*
ID: foozhan1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


string namesFound[100]={""};
int counter =0;
//static int multystart=0,multyend=0;

string findWord(string * , char*,int,int ,int , int );

 char Pinput[8][3]={
    	{'A','B','C'},
    	{'D','E','F'},
    	{'G','H','I'},
    	{'J','K','L'},
    	{'M','N','O'},
    	{'P','R','S'},
    	{'T','U','V'},
    	{'W','X','Y'} 
    };

int main() {
   
    ifstream fin ("namenum.in");
    ofstream fout ("namenum.out");
    ifstream fin2 ("dict.txt");

    string dic[5000];
    char input[20];
    int startPlace[3]={0};
    int endPlace[3]={0};
   
    int i=0;
    while(fin2>>dic[i]){
    	
       	i++;
    }


    int n=0;
    fin>>input[n];

    n++;

    while(  dic[startPlace[0]][0] != Pinput[(input[0] - '0')-2][0]){
   		startPlace[0]++;
    }

    if(input[0] != '9'){
    	endPlace[0]=startPlace[0];
   		 while(  dic[endPlace[0]][0] != Pinput[(input[0] - '0')-1][0]  ){
   			endPlace[0]++;
    	}
	}
	else {
		endPlace[0]=i-1;
	}
    	

    while(fin>>input[n]){
       	n++;
    }
   
   string exam=findWord(dic,input,0,n-1,startPlace[0],endPlace[0]);

   	if(counter != 0)
    {
        for(int m=0;namesFound[m]!="";m++){
            fout<<namesFound[m]<<endl;
        }
    }        
    else{
        fout<<"NONE"<<endl;
       // fout<<findWord(dic,input,0,n-1,startPlace[0],endPlace[0])<<endl;
    }
   
    	    
    return 0;
}

string findWord(string dic[] , char in[],int inLocation,int inputSize ,int start, int end){
	string foundWord="NONE";
	


	if(inLocation<=inputSize){
		char search[3]={Pinput[in[inLocation]-'0'-2][0],
		Pinput[in[inLocation]-'0'-2][1],
		Pinput[in[inLocation]-'0'-2][2]};
		int newStart= start;
		int newEnd=start;
         
         


		for(int x=0;x<3  ;x++){
			newStart= start;
			while(dic[newStart][inLocation] != search[x] && newStart < end){
				newStart++;
			}  
			if(newStart <= end){
				newEnd = newStart;
				while(dic[newEnd][inLocation] == search[x] && newEnd < end){
					newEnd++;
				}   

				if(newEnd != newStart){
					foundWord=findWord(dic,in,inLocation+1,inputSize,newStart,newEnd);
                    if(foundWord != "NONE" ){
                        
                        if(foundWord.size()-1 == inputSize){
                        namesFound[counter]=foundWord;
                        counter++;
                    }
                        foundWord="NONE";


                    }

				}
			}

		}
    }

    else{
       
        return dic[start];
    
    }

		return "NONE";
}