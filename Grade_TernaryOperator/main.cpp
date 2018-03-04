/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on Jan 12, 2017, 11:19 AM
 * Purpose: Grade with Ternary Operator
 */ 

//System Libraries Here
#include <iostream>

using namespace std;

//User Libraries Here


//Function Prototypes Here

//Program Execution Begins Here
int main () {
    //Declare and process variables
    unsigned short score;
    char grade;
    
    cout<<"This program takes the score and outputs the grade"<<endl;
    cout<<"Input the score (0-100)"<<endl;
    cin>>score;
    
    //Process/Calculations Here
    grade = (score>=90)?'A':
            (score>=80)?'B':
            (score>=70)?'C':
            (score>=60)?'D':'F';
    
    //Output Located Here
    cout<<"Your score of "<<score<<" = "<<grade<<endl;

    //Exit
    return 0;
}

