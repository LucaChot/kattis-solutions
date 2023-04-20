#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //test for horizontal lines
        for(int i = 0; i < 9; i++){
            bool b[9];
            for(int k = 0; k < 9; k++){
                b[k] = false;
            }
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(b[board[i][j]-49]) return false;
                b[board[i][j]-49] = true;
            }
        }
        //test for vertical lines
        for(int i = 0; i < 9; i++){
            bool b[9];
            for(int k = 0; k < 9; k++){
                b[k] = false;
            }
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                if(b[board[j][i]-49]) return false;
                b[board[j][i]-49] = true;
            }
        }

        for(int i = 0; i < 9; i++){
            bool b[9];
            int x = i % 3;
            int y = i / 3;
            for(int k = 0; k < 9; k++){
                b[k] = false;
            }
            
            for(int row = 3 * y; row < 3 * (y+1); row ++){
                for(int col = 3 * x; col < 3 * (x+1); col++){
                    if(board[row][col] == '.') continue;
                    
                    if(b[board[row][col]-'1']) return false;
                    
                    b[board[row][col]-'1'] = true;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<char> r1 = {'.','.','.','.','5','.','.','1','.'};
    vector<char> r2 = {'.','4','.','3','.','.','.','.','.'};
    vector<char> r3 = {'.','.','.','.','.','3','.','.','1'};
    vector<char> r4 = {'8','.','.','.','.','.','.','2','.'};
    vector<char> r5 = {'.','.','2','.','7','.','.','.','.'};
    vector<char> r6 = {'.','1','5','.','.','.','.','.','.'};
    vector<char> r7 = {'.','.','.','.','.','2','.','.','.'};
    vector<char> r8 = {'.','2','.','9','.','.','.','.','.'};
    vector<char> r9 = {'.','.','4','.','.','.','.','.','.'};
    vector<vector<char>> m = {r1,r2,r3,r4,r5,r6,r7,r8,r9};
    cout << s.isValidSudoku(m);
}