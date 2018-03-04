/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: BigPPsucker
 *
 * Created on August 28, 2017, 1:35 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

string frmt(string);
void Merge(int[], int, int, int);
void MergeSort(int[], int, int);

unsigned const int SIZE(170000);
/*
 * 
 */
int main(int argc, char** argv) {    
    vector<bool> chkd;        //announcing variables for organizing the data, size=n (number of words)
    vector<string> wrd;
    string temp;
    ifstream in;

    in.open("zipf.txt");
    long n=0;
    while(in){
        in>>temp;
        if(temp!=""){
            wrd.push_back(temp);
            chkd.push_back(0);
            n++;
    }
    }
    in.close();
    
    wrd[n-1]="";            //prevents word doubling from temp
    
    for(long i=0;i<n;i++){
        wrd[i]=frmt(wrd[i]);
        cout<<wrd[i]<<endl;
    }
    
    cout<<"N: "<<n<<endl; 
    long l=0;               //l is separate from i to avoid empty spaces in the place/count arrays
    string place[n/2]={""};
    int count[n/2]={0};
    
    for(long i=0;i<n;i++){      //organizes the usage data for the strings saved
        if(chkd[i]==false){     //checks if the word has been checked
            place[l]=wrd[i];    //if not, sets the word as a new word
            count[l]=1;         //increments the count to one for the new word
            chkd[i]=true;       //flags the word as checked
            for(long t=1;t<(n-i);t++){      //next loop compares wrd[i] to every word after, using increment t
                if(place[l]==wrd[i+t]){       //checks word i vs word i+1, i+2, i+3 until i+t=n;
                    count[l]++;             //increments count l
                    chkd[i+t]=true;
                }
            }
            l++;                //increment l if the word hadn't been checked
        }
    }
    
    MergeSort(count,0,(n/2)-1);
    
    for(long i=0;i<l;i++){
        cout<<count[i]<<endl;
    }
    
    
    return 0;
}


string frmt(string w){
    
            transform(w.begin(), w.end(), w.begin(), ::tolower);
            for (long l=0;l<26;l++){
                char r;
                switch(l){
                    case 0: r='"'; break;
                    case 1: r='!'; break;
                    case 2: r='@'; break;
                    case 3: r='#'; break;
                    case 4: r='%'; break;
                    case 5: r='&'; break;
                    case 6: r='*'; break;
                    case 7: r='('; break;
                    case 8: r=')'; break;
                    case 9: r=','; break;
                    case 10: r='?'; break;
                    case 11: r='1'; break;
                    case 12: r='2'; break;
                    case 13: r='3'; break;
                    case 14: r='4'; break;
                    case 15: r='5'; break;
                    case 16: r='6'; break;
                    case 17: r='7'; break;
                    case 18: r='8'; break;
                    case 19: r='9'; break;
                    case 20: r='0'; break;
                    case 21: r='`'; break;
                    case 22: r=';'; break;
                    case 23: r=':'; break;
                    case 24: r='$'; break;
                    case 25: r='.'; break;
                }
                   if (w.find(r) != std::string::npos){
                        w.erase(std::remove(w.begin(), w.end(), r), w.end());
                    }
                
            }
            if(w.find('\'') != std::string::npos){
              
                if(w.substr(0,1)=="'"){
                  w.erase(0,1);
                }
                std::size_t found = w.find_last_of("'");
                if(w.substr(found+1,found+2)==""){
                    w.erase(found,found+1);
                }
            }
            return w;
}


 
// A function to split array into two parts.
void MergeSort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}

// A function to merge the two half into a sorted data.
void Merge(int a[], int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}