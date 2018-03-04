/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on 
 * Purpose: 
 */

//System Libraries Here
#include <iostream>

using namespace std;

//User Libraries Here


//Function Prototypes Here
bool Restart();
void ver1();
void ver2();
//Program Execution Begins Here

int main() {
    //Declare and process variables
    bool restart;
    
    char ver;           //chooses version of triangle

    //Process/Calculations Here
    do {
        cout<<"1 - Line #\n"
                "2 - Term #"<<endl;
        cin>>ver;
        while(ver!='1'&&ver!='2'){
            cout<<"Pick 1 or 2."<<endl;
            cin>>ver;
        }
        if(ver=='1'){ver1();}
        if(ver=='2'){ver2();}
       

        restart = Restart();
    } while (restart);

    //Output Located Here

    //Exit
    return 0;
}

void ver1(){
    short  nLines=0,     //total number of lines
            lTerms,     //number of terms per line
            count=1,      //loops output
            nLine=1;      //determines value of lTerms
    long pasc[10000];
   
        pasc[0]=1;
        pasc[1]=1;
        pasc[2]=1;
    
 cout<<"Enter the number of lines."<<endl;
        cin>>nLines;
        for(nLine;nLine<=nLines;){
            for(long spaces=nLines-nLine;spaces>0;spaces--){
                cout<<" ";
            }
            for(lTerms=nLine;lTerms>0;lTerms--,count++){
                    if(count==1){pasc[count]=1;}
                    else if(pasc[count-nLine]==1&&pasc[count-nLine+1]==1&&count!=5){
                            pasc[count]=1;
                    }else{
                    pasc[count]=pasc[count-nLine]+pasc[count-nLine+1];
                    }
                    cout<<pasc[count]<<" ";
                
            }
                nLine++;
                cout<<endl;
        }
}

void ver2(){
    short   nTerm=0,     //total number of terms
            lTerms,      //number of terms per line
            count=1,     //loops output
            nLine=1;     //determines value of lTerms
    long pasc[10000];
    char view;      //shows triangle
    bool tri;       //uses view to show triangle
   
        pasc[0]=1;
        pasc[1]=1;
        pasc[2]=1;
 cout<<"Enter the term number."<<endl;
        cin>>nTerm;
        cout<<"Would you like to see the triangle as well as the inputted "
                "term? y/n"<<endl;
        cin>>view;
        while(view!='y'&&view!='n'){
            cout<<"Please input y or n."<<endl;
            cin>>view;
        }
        //tri=view=='y'?true:false;
        if(view=='y'){tri=true;}else{tri=false;}
    if(tri==true){
            for(count;count<=nTerm;){
                for(long spaces=nTerm-nLine;spaces>0;spaces--){
                    cout<<" ";
                }
                for(lTerms=nLine;lTerms>0;lTerms--){
                    if(count<=nTerm){
                        if(count==1){pasc[count]=1;}
                        else if(pasc[count-nLine]==1&&pasc[count-nLine+1]==1&&count!=5){
                                pasc[count]=1;
                        }else{
                        pasc[count]=pasc[count-nLine]+pasc[count-nLine+1];
                        }
                        cout<<pasc[count]<<" ";
                        count++;
                    }
                }
                    nLine++;
                    cout<<endl;
            }
                    }
    else{
            for(count;count<nTerm;){
                for(lTerms=nLine;lTerms>0;lTerms--){
                    if(count<=nTerm){
                    if(count==1){pasc[count]=1;}
                    else if(pasc[count-nLine]==1&&pasc[count-nLine+1]==1&&count!=5){
                            pasc[count]=1;
                    }else{
                    pasc[count]=pasc[count-nLine]+pasc[count-nLine+1];
                    }
                    if(count==nTerm){cout<<pasc[count]<<endl;}
                    count++;
                }
                }
                    nLine++;
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

//        1         nLine=1 - count=1
//       1 1        nLine=2 - count=2,3
//      1 2 1       nLine=3 - count=4,5,6
//     1 3 3 1      nLine=4 - count=7,8,9,10
//    1 4 6 4 1     nLine=5 - count=11,12,13,14,15
//   1 5 10 10 5 1                
//  1 6 15 20 15 6 1