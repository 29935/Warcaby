﻿#include <iostream>
#include <string>

using namespace std;

int board[16][16];
string _board[16][16];

void printBoard(int size)
{
    // board print
    cout << "  ";
    for (int i = 0; i < size; i++)
    {
        if (i + 1 < 10)
            cout << " " << i + 1 << " ";
        else
            cout << " " << i + 1;
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        if (i + 1 < 10)
            cout << i + 1 << " ";
        else
            cout << i + 1;
        for (int j = 0; j < size; j++)
        {
            cout << _board[i][j];
        }
        cout << endl;
    }
}

int main()
{
    string tile[6];
    tile[0] += 219;
    tile[0] += 219;
    tile[0] += 219;
    tile[1] = "   ";
    tile[2] += ' ';
    tile[2] += 1;
    tile[2] += ' ';
    tile[3] += '(';
    tile[3] += 1;
    tile[3] += ')';
    tile[4] += ' ';
    tile[4] += 2;
    tile[4] += ' ';
    tile[5] += '(';
    tile[5] += 2;
    tile[5] += ')';
    bool player;
    int p1, p2;
    string mapChoice;
    int size;
    
    //choosing map size
    choosingMapSize:
    cout << "Choose map size: \n type classic or enlarged \n";
    cin >> mapChoice;
    if (mapChoice == "classic")
    {
        size = 8;
    }
    else if (mapChoice == "enlarged")
    {
        size = 16;
    }
    else
    {
        cout << "Wrong input \n";
        goto choosingMapSize;
    }
    system("cls");
    


    // board generation
    restart:
    bool checker;
    for (int i = 0; i < size * 3 / 8; i++)
    {
        checker = i % 2;
        for (int j = 0; j < size; j++)
        {
            if ((checker + j) % 2)
            {
                board[i][j] = 2;
            }
            else
            board[i][j] = 0;
        }
    }

    for (int i = size * 3 / 8; i < (size * 2 / 8) + (size * 3 / 8); i++)
    {
        checker = i % 2;
        for (int j = 0; j < size; j++)
        {
            if ((checker + j) % 2)
            {
                board[i][j] = 1;
            }
            else
                board[i][j] = 0;
        }
    }
    for (int i = (size * 2 / 8) + (size * 3 / 8); i < size; i++)
    {
        checker = i % 2;
        for (int j = 0; j < size; j++)
        {
            if ((checker + j) % 2)
            {
                board[i][j] = 4;
            }
            else
                board[i][j] = 0;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
           _board[i][j] = tile[board[i][j]];
        }
    }

    player = true;
    p1 = 12, p2 = 12;

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

    printBoard(size);

    char xa, ya, xb, yb;

    while (1)
    {
        cin >> xa;
        if (xa > '0' && xa < '8')
        {
            cin >> ya >> xb >> yb;
            if ((ya > '0' && ya < '8') && (xb > '0' && xb < '8') && (yb > '0' && yb < '8') && !(xa == xb && ya == yb))
            {

            }
            else
            {
                cout << "Wrong input \n";
            }
        }
        else if (xa == 'r')
        {
            system("cls");
            goto restart;
        }
        else if (xa == 's')
        {
            system("cls");
            goto choosingMapSize;
        }
        else
        {
            cout << "Wrong input \n";
        }
        
    }
}

