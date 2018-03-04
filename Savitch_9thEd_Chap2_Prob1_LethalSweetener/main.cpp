/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on Jan 9, 2017, 12:50 PM
 * Purpose: Calculate Lethality of Soda
 */ 

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
using namespace std;

//User Libraries Here


//Function Prototypes Here

//Program Execution Begins Here
int main () {
    //Declare and process variables
    
    float lethlM = 5,    //needed to kill a mouse - 5g
        mMouse = 35;              //mass of mouse - 35g
    unsigned int lethlH,                   //lethal dose for human
        aftrMss,                  //mass of person inputted in lbs.
        mHuman,                   //mass of human in grams
        cans,          //amount of cans of soda in cans
        mSoda;                    //mass of soda in grams
    const float cncntr = .001;    //concentration of sweetener 
    const short convM = 454; //conversion from lbs. - g (45400/100)
    const short mCan = 350; //amount of soda/can in grams
    char ans; //answer for restart    
    bool restart = false;
    
    //Process/Calculations Here
   
    do {
    
        cout<<"This program calculates the amount of diet soda pop you need to \n"
                "drink to receive a lethal dose of artificial sweetener,\n"
                "based on your weight. Please input the weight(lbs.) at which you\n"
                "will stop dieting."<<endl;
                while(!(cin >> aftrMss)){                               //this block of code was copied from 
		cin.clear();                                            //http://www.cplusplus.com/forum/beginner/21595/
		cin.ignore(numeric_limits<streamsize>::max(), '\n');    //to solve the problem of infinite output loop
		cout << "Invalid input.  Try again: ";                  //when given an invalid input
	}
	cout << "You entered: " << aftrMss <<" lbs." << endl;	
        
    
        mHuman = aftrMss*convM; //converts mass from lbs. - g
        lethlH = (lethlM/mMouse)*mHuman; //determines lethal dosage based on input
        mSoda = lethlH/cncntr; //shows the amount of soda needed to achieve 
                               //lethal dose, in grams
        cans = mSoda/mCan; //converts lethal soda amount to cans
        
        
            //Output Located Here
        cout<<"The lethal amount of soda is "<<mSoda<<"g, or "<<cans<<" cans"<<endl;
        
        cout<<"Would you like to run the program again? y/n"<<endl;
        cin>>ans;
        while(ans != 'y' && ans !='n' && ans!= 'Y' && ans!= 'N'){
            cout<<"Please enter y/n"<<endl;
                    cin>>ans;
    }
          if(ans=='y' || ans=='Y')
            restart = true;
        else
            restart = false;
    } while(restart);
    //Exit
    return 0;
    
    }

