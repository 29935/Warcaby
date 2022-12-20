#include <iostream>
#include <string>

using namespace std;

int main()
{
    int board[8][8];
    string _board[8][8];
    string tile[6];
    tile[0] += 219;
    tile[0] += 219;
    tile[0] += 219;
    tile[2] = "   ";
    tile[3] = "   ";
    tile[4] = "   ";
    tile[5] = "   ";
    tile[6] = "   ";
    bool checker;
    for (int i = 0; i < 3; i++)
    {
        checker = i % 2;
        for (int j = 0; j < 8; j++)
        {
            if ((checker + j) % 2)
            {
                board[i][j] = 2;
            }
            else
            board[i][j] = 0;
        }
    }
    for (int i = 3; i < 5; i++)
    {
        checker = i % 2;
        for (int j = 0; j < 8; j++)
        {
            if ((checker + j) % 2)
            {
                board[i][j] = 1;
            }
            else
                board[i][j] = 0;
        }
    }
    for (int i = 5; i < 8; i++)
    {
        checker = i % 2;
        for (int j = 0; j < 8; j++)
        {
            if ((checker + j) % 2)
            {
                board[i][j] = 4;
            }
            else
                board[i][j] = 0;
        }
    }



    // hidden board printing
    /*
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }*/
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << _board[i][j];
        }
        cout << endl;
    }
}


