#include <iostream>
#include <vector>
using namespace std;

const int N = 9;
bool rowUsed[N][N] = {false};
bool colUsed[N][N] = {false};
bool boxUsed[N][N] = {false};

bool backTrack(vector<vector<char>> &board, int row, int col)
{
    if (row == N)
        return true;
    if (col == N)
        return backTrack(board, row + 1, 0);
    if (board[row][col] != '.')
        return backTrack(board, row, col + 1);
    int boxIndex = (row / 3) * 3 + col / 3;
    for (int num = 0; num < 9; num++)
    {
        if (!rowUsed[row][num] && !colUsed[col][num] && !boxUsed[boxIndex][num])
        {
            board[row][col] = num + '1';
            rowUsed[row][num] = colUsed[col][num] = boxUsed[boxIndex][num] = true;
            if (backTrack(board, row, col + 1))
                return true;
            board[row][col] = '.';
            rowUsed[row][num] = colUsed[col][num] = boxUsed[boxIndex][num] = false;
        }
    }
    return false;
}

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
        
    }
    return 0;
}