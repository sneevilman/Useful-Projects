/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on Jan 9, 2017, 11:28 AM
 * Purpose: Using the random number generator
 */ 

//System Libraries Here
#include <iostream> //input output
#include <cstdlib>  //random number generator and seed
#include <ctime>     //time used for random seed

using namespace std;

//User Libraries Here


//Function Prototypes Here

//Program Execution Begins Here
int main () {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare and process variables
    unsigned char die1, die2, sum;
   
    //Process/Calculations Here
    die1=rand()%6+1;//[1,6]
    die2=rand()%6+1;//[1,6]
    
    sum=die1+die2;
    
    //Output Located Here
    cout<<"Die 1 = "<<static_cast<int>(die1)<<endl;
    cout<<"Die 2 = "<<static_cast<int>(die2)<<endl;
    cout<<"Sum = "<<static_cast<int>(sum)<<endl;
    
    //Exit
    return 0;
}

