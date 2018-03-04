/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on 1 February, 2017, 10:35 AM
 * Purpose: Fill an array then average contents
 */

//System Libraries Here
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries Here


//Function Prototypes Here
void savings(int [],float [],float,float,int);
void prntAry(int [],float [],int);

//Program Execution Begins Here

int main() {
    //Declare and process variables
    
    char ans;
    bool restart;
    const int SIZE=100;
    int nYears=SIZE/2+1;
    int year[SIZE]=[];//initialize the entire array to 0
    float balance[SIZE]=[];//initialize to 0
    //Process/Calculations Here
    do {
        
        float  intRate=0.06f,
               gift=1.0e4f;
    
        savings(year,balance,gift,intRate,nYears);
        

    prntAry(year,balance,nYears);

        cout << endl;
        cout << "Would you like to run this program again? y/n" << endl;
        cin>>ans;
        while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N') {
            cout << "Please enter y/n" << endl;
            cin>>ans;
        }
        if (ans == 'y' || ans == 'Y')
            restart = true;
        else
            restart = false;
    } while (restart);

    //Output Located Here

    //Exit
    return 0;
}

void prntAry(int year[],float balance[],int n){
    cout<<"Year Balance"<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(6)<<year[i]<<" $"<<balance[i]<<endl;
    }
    cout<<endl;
}

void filAray(int y[],int b[],float p,float intRate,int nYears){
    y[0]=0;
    b[0]=p;
    for(int year=1;year<nYears;year++){
        y[year]=year;
        b[year]=b[year-1]*(1+intRate));
    }
}
