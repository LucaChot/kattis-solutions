#include <cstddef>
#include <iostream>
using namespace std;

int main(){
    int rows, cols, classes;
    cin >> rows >> cols >> classes;

    char* m[rows][cols];
    char colours[classes]; 

    for(int i = 0; i < classes; i++){
        colours[i] = i;
    }
    int total_colours = classes;
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            char a;
            cin >> a;
            m[i][j] = colours + (a - 65);
        }
    }

    bool changes = true;
    while(changes){
        changes = false;
        for(int j = 0; j < cols; j++){
            char col_colour = *m[0][j];
            for(int i = 0; i < rows; i++){
                if(*m[i][j] != col_colour){
                    *m[i][j] = col_colour;
                    total_colours -= 1;
                    changes = true;
                }
            }
        }
    }

    cout << total_colours;
    return 0;
}