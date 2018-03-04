/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on Jan 10, 2017, 12:02 PM
 * Purpose: Compare % Federal Military Budget vs NASA Budget
 * Source: https://www.nationalpriorities.org/budget-basics/federal-budget-101/spending/
 *         https://en.wikipedia.org/wiki/Budget_of_NASA
 */ 

//System Libraries Here
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries Here


//Function Prototypes Here

//Program Execution Begins Here
int main () {
    //Declare and process variables
    float usBdgt = 3.8E+12f,        //Total US Federal budget in $
            nasaBgt = 1.93E+10f,    //Total Fed spending on NASA in $
            miliBgt = 6.093E+11f,    //Total Fed spending on Military in $
            pNasa,  //Percent of total budget spent on NASA in %
            pMili;  //Percent of total budget spent on military in %
    
    
    //Process/Calculations Here
    pNasa = (nasaBgt/usBdgt)*100;
    pMili = (miliBgt/usBdgt)*100;
    
    //Output Located Here
    cout<<fixed<<setprecision(3)<<endl;
    cout<<"Percent of US Federal Budget spent on Nasa is "<<pNasa<<"%"<<endl;
    cout<<"Percent of US Federal Budget spent on military is "<<pMili<<"%"<<endl;
    //Exit
    return 0;
}

