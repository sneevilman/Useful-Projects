/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on February 6, 2017, 11:08 AM
 * Purpose: Linear Search
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries Here


//Function Prototypes Here
bool Restart();
void filAray(int [],int);
void prntAry(int [],int,int);
void smalst(int[],int,int);
void linSrch(int[],int,int,int[],int);
//Program Execution Begins Here

int main() {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare and process variables
    bool restart;
    const int SIZE=200;
    const int utilize=SIZE/2;
    const int posSize=100;
    int array[utilize]={},
        positns[posSize];

    //Process/Calculations Here
    do {
        filAray(array,utilize);
        prntAry(array,utilize,10);

        int find;
        cout<<"What value to find? Type a number between 10 and 99"<<endl;
        cin>>find;
        linSrch(array,utilize,find,positns,posSize);
        cout<<find<<" was found at ";
                for(short sub=0;sub<posSize&&positns[sub]>9;sub++){
                 cout<<positns[sub]<<", ";   
                }

        restart = Restart();
    } while (restart);

    //Output Located Here

    //Exit
    return 0;
}


void smalst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i])swap(a[pos],a[i]);
    }
}



void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
}

void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}

void linSrch(int a[],int n,int val,int p[], int size){
    int pos=0;            //position of position in position array
    for(int i=0;i<n;i++){
        if(a[i]==val){
            p[pos]=i;
            pos++;
        }
    }
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