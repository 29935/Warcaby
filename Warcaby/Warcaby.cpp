#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h> 

using namespace std;

int board[16][16];
string _board[16][16];
string tile[6];

void printBoard(int size)
{
    // hidden board printing
    /*
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }*/

    // board print
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            _board[i][j] = tile[board[i][j]];
        }
    }

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

//capturedX
int capturedX(int a, int b)
{
    if (a > b)
        return b + 1;
    else
        return b - 1;
}

int main()
{
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
    char mapChoice;
    int size;
    int saveNum;
    string file_name[3] = {"save1.txt", "save2.txt", "save3.txt"};




    //choosing map size
    fstream plik;

choosingMapSize:
    bool loaded = false;
    
    while (1)
    {
        cout << "Choose map size: type c for classic or e for enlarged \n Load save: type l \n";
        cin >> mapChoice;
        if (mapChoice == 'c')
        {
            size = 8;
            break;
        }
        else if (mapChoice == 'e')
        {
            size = 16;
            break;
        }
        else if (mapChoice == 'l')
        {
            cout << "Select save file: type number from 1 to 3 \n";
            cin >> saveNum;
            if (saveNum >= 1 && saveNum <= 3)
            {
                plik.open(file_name[saveNum - 1], ios::in);
                if (plik.good())
                {
                    plik >> size;
                    plik >> player;
                    plik >> p1;
                    plik >> p2;
                    for (int i = 0; i < 16; i++)
                    {
                        for (int j = 0; j < 16; j++)
                        {
                            plik >> board[i][j];
                        }
                    }
                    loaded = true;
                    break;
                }
                else
                    cout << "No save \n";
            }
            else
                cout << "Wrong input \n";

        }
        else
        {
            cout << "Wrong input \n";
            goto choosingMapSize;
        }
    }
    
    system("cls");



    // board generation
    if (!loaded)
    {
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

        player = true;
        p1 = 12, p2 = 12;
    }


    printBoard(size);

    int xa, ya, xb, yb;



    //game////////////////////////////////////////////////////
    while (p1 && p2)
    {
        cout << "Type piece x and y and new x and y \nor type 0 to end, -1 to restart, -2 to back to menu, -3 to save\n";
        cin >> xa;
        if (xa > 0 && xa <= size)
        {
            cin >> ya >> xb >> yb;
            if (((ya > 0 && ya <= size) && (xb > 0 && xb <= size)) && ((yb > 0 && yb <= size) && !(xa == xb && ya == yb)))
            {
                xa--;
                ya--;
                xb--;
                yb--;
                // white
                if (player)
                {
                    if (board[ya][xa] == 4)
                    {
                        //man move
                        if (board[yb][xb] == 1 && (ya == yb + 1 && (xb == xa + 1 || xb == xa - 1)))
                        {
                            if(yb != 0)
                                board[yb][xb] = 4;
                            else
                                board[yb][xb] = 5;
                            board[ya][xa] = 1;
                            system("cls");
                            printBoard(size);
                            player = false;
                        }
                        //man capture
                        else if (((board[ya][xa] == 4 && board[yb][xb] == 1) && (board[ya - 1][capturedX(xa, xb)] == 2 || board[ya - 1][capturedX(xa, xb)] == 3)) && (ya == yb + 2 && (xb == xa + 2 || xb == xa - 2)))
                        {
                            board[yb][xb] = 4;
                            board[ya - 1][capturedX(xa, xb)] = 1;
                            p2--;
                            board[ya][xa] = 1;
                            system("cls");
                            printBoard(size);
                            player = false;
                        }
                        else
                        {
                            cout << "Wrong input \n" << board[ya - 1][capturedX(xa, xb) - 1] << " " << capturedX(xa, xb);
                        }
                    }
                    else
                    {
                        cout << "Wrong input \n";
                    }
                }
                // black
                else
                {
                    // man move
                    if ((board[ya][xa] == 2) && (board[yb][xb] == 1 && (ya == yb - 1 && (xb == xa + 1 || xb == xa - 1))))
                    {
                        board[yb][xb] = 2;
                        board[ya][xa] = 1;
                        system("cls");
                        printBoard(size);
                        player = true;
                    }
                    // man capture
                    else if (((board[ya][xa] == 2 && board[yb][xb] == 1) && (board[ya + 1][capturedX(xa, xb)] == 4 || board[ya + 1][capturedX(xa, xb)] == 5)) && (ya == yb - 2 && (xb == xa + 2 || xb == xa - 2)))
                    {
                        board[yb][xb] = 2;
                        board[ya + 1][capturedX(xa, xb)] = 1;
                        p1--;
                        board[ya][xa] = 1;
                        system("cls");
                        printBoard(size);
                        player = true;
                    }
                    else
                    {
                        cout << "Wrong input \n" << board[ya][xa] << " " << board[yb][xb] << " " << board[ya + 1][capturedX(xa, xb)] << " " << capturedX(xa, xb);
                    }
                }
            }
            else
            {
                cout << "Wrong input \n";
            }
        }
        // exit
        else if (xa == 0)
        {
            return 0;
        }
        // restart
        else if (xa == -1)
        {
            system("cls");
            goto restart;
        }
        // back to menu
        else if (xa == -2)
        {
            system("cls");
            goto choosingMapSize;
        }
        // save
        else if (xa == -3)
        {
            cout << "Choose save file: type number from 1 to 3 \n";
            cin >> saveNum;
            if (saveNum >= 1 && saveNum <= 3)
            {
                plik.open(file_name[saveNum - 1], ios::out);
                plik << " " << size << " " << player << " " << p1 << " " << p2 << "\n";
                for (int i = 0; i < 16; i++)
                {
                    for (int j = 0; j < 16; j++)
                    {
                        plik << board[i][j] << " ";
                    }
                    plik << "\n";
                }
            }
            else
                cout << "Wrong input \n";
        }
        else
        {
            cout << "Wrong input \n";
        }

    }

    //game end
    if (!p2)
        cout << "Black wins \n";
    else
        cout << "White wins \n";

}



