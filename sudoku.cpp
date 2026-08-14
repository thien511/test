#include <iostream>
#include <vector>
using namespace std;

const int N = 9;
bool rowUsed[N][N] = {false};
bool colUsed[N][N] = {false};
bool boxUsed[N][N] = {false};



void solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int num = board[i][j] - '1';
                int boxIndex = (i / 3) * 3 + j / 3;
                rowUsed[i][num] = colUsed[j][num] = boxUsed[boxIndex][num] = true;
            }
        }
    }
    backTrack(board, 0, 0);
}

int main()
{
    vector<vector<char>> board(9, vector<char>(9));
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            char num; cin >> num;
            board[i][j] = num;
        }
    }
    solveSudoku(board);
    for(auto i : board) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}