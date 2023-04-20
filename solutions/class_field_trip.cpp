//Problem B Class Field Trip
//https://open.kattis.com/contests/xjhzmw/problems/classfieldtrip

#include <iostream>
using namespace std;

int main(){
    string first, second;
    cin >> first >> second;

    cout << first << '\n';
    cout << second << '\n';
    int fpointer = 0, spointer = 0, flen = first.length(), slen = second.length();
    while(fpointer < flen && spointer < slen){
        if(first[fpointer] > second[spointer]){
            cout << second[spointer];
            spointer += 1;
        }else{
            cout << first[fpointer];
            fpointer += 1;
        }
    }

    if(fpointer == flen){
        while(spointer < slen){
            cout << second[spointer];
            spointer += 1;
        }
    }else{
        while(fpointer < flen){
            cout << first[fpointer];
            fpointer += 1;
        }
    }
    
    return 0;
}