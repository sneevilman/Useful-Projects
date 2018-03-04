/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on 
 * Purpose: 
 */

//System Libraries Here
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries Here


//Function Prototypes Here
double genTerm(double,double,double);
double Powr(double,double);
double Fact(double);
bool Restart();
//Program Execution Begins Here

int main() {
    //Declare and process variables
    bool restart;
    double n,
          deg;
    double sum;

    //Process/Calculations Here
    do {
        sum=1;
        cout<<"input degree of e"<<endl;
        cin>>deg;
        cout<<"input number of terms"<<endl;
        cin>>n;for(double i=1;i<n+1;i++){
            sum+=genTerm(i,n,deg);
        }
        cout<<"e^"<<deg<<" with a sum accuracy of "<<n<<" terms = ";
        cout<<setprecision(10)<<sum<<endl;



        restart = Restart();
    } while (restart);

    //Output Located Here

    //Exit
    return 0;
}

double genTerm(double i, double n, double d){
    double term=1,
            num,
            den;
        num=Powr(d,i);
        den=Fact(i);
        term=num/den;
//        cout<<"term # "<<i<<" = "<<term<<endl;
    return term;
}
double Powr(double t,double i){
    double y=t;
    for(short l=1;l<i;l++){
        t*=y;
    }
    return t;
}
double Fact(double i){
    double t=i;
    for(short l=i;l>1;l--){
        t*=(l-1);}
    return t;
}
bool Restart() {
    char ans;
    bool restart;
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
    return restart;
}