#include <iostream>
using namespace std;

int main(){
    string text, cipher;
    cin >> text >> cipher;
    int len = text.length();

    for(int i = 0; i < len; i++){
        if(i % 2 == 0) text[i] = (((text[i]-65) - (cipher[i]-65)) % 26)+ 65;
        else text[i] = (((text[i]-65) + (cipher[i]-65)) % 26)+ 65;
    }
    cout << text;
    return 0;
}