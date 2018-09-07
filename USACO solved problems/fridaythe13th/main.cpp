/*
ID: foozhan1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream fin ("friday.in");
   ofstream fout ("friday.out");
    int n,counter=2,days[7]={0};
    // cin>>n;
    fin>>n;
    counter += 12;
    for(int i= 0;i<n;++i){
        counter %= 7;
        days[counter%7]++; //jan
        counter += 31;
        days[counter%7]++; //feb

        if( (1900+i)%4 == 0){

         if( ((1900+i) %100) == 0){
            // COUT << 1900+i %100;
            if( ((1900+i) %400) ==0 ){

                counter+=29  ;

           }
            else{
                counter+=28  ;

            }
        }
        else{
            counter+=29  ;

        }
        }


        else{
            counter+=28  ;

        }

        days[counter%7]++; //mar
        counter += 31;
        days[counter%7]++; //apr

        counter+= 30;
        days[counter%7]++; // may
        counter+= 31;
        days[counter%7]++; // june
        counter+= 30;
        days[counter%7]++;  // july
        counter+= 31;
        days[counter%7]++; // aug
        counter+= 31;
        days[counter%7]++; // sept
        counter+= 30;
        days[counter%7]++; // oct
        counter+= 31;
        days[counter%7]++;// nov
        counter+= 30;
        days[counter%7]++;// dec
        counter += 31;



    }
   for(int i=0; i<6;++i){
fout<<days[i]<<" ";
      // cout<<days[i]<<" ";
}
   // cout<<days[6]<<"\n";
fout<<days[6]<<"\n";

    return 0;
}
