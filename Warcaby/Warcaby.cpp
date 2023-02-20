#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

int board[16][16];
string _board[16][16];
string tile[6];
int p1, p2;

int stringToInt(string s)
{
    int m = 1, w = 0, d = 1;
    for(int i = s.size()-1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            w += (s[i] - '0')*d;
        }
        else if ( i == 0 && s[i] == '-')
        {
            w *= -1;
        }
        else
        {
            return -4;
        }
        d *= 10;
    }
        return w;
}

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

//captured X
int capturedX(int a, int b)
{
    if (a > b)
        return b + 1;
    else
        return b - 1;
}

// capture Check
bool captureCheck(bool a, int x, int y)
{
    //white
    if (((board[y][x] == 4 || board[y][x] == 5) && (((board[y+1][x-1] == 2 || board[y+1][x-1] == 3) && board[y+2][x-2] == 1) || ((board[y-1][x-1] == 2 || board[y-1][x-1] == 3) && board[y-2][x-2] == 1))) || (a && (((board[y+1][x+1] == 2 || board[y+1][x+1] == 3) && board[y+2][x+2] == 1) || ((board[y-1][x+1] == 2 || board[y-1][x+1] == 3) && board[y-2][x+2] == 1))))
    {
        return true;
    }
    //black
    else if (((board[y][x] == 2 || board[y][x] == 3) && (((board[y+1][x+1] == 4 || board[y+1][x+1] == 5) && board[y+2][x+2] == 1) || ((board[y-1][x+1] == 4 || board[y-1][x+1] == 5) && board[y-2][x+2] == 1))) || (a && (((board[y+1][x-1] == 4 || board[y+1][x-1] == 5) && board[y+2][x-2] == 1) || ((board[y-1][x-1] == 4 || board[y-1][x-1] == 5) && board[y-2][x-2] == 1))))
    {
        return true;
    }
    return false;
}

//multi capture
void multiCapture(int x, int y, int size)
{
    string aa, bb;
    int a, b;
    system("cls");
    printBoard(size);
    while (captureCheck(1, x, y))
    {
        cout << "Multi capture available\ntype 0 to skip turn\ntype x and y to move pawn " << x+1 << " " << y+1 << endl;
        cin >> aa;
        a = stringToInt(aa);
        if (a == 0)
        {
            break;
        }
        cin >> bb;
        b = stringToInt(bb);
        a--;
        b--;
        //white man
        if((((board[y][x] == 4 && board[b][a] == 1) && (board[capturedX(y, b)][capturedX(x, a)] == 2 || board[capturedX(y, b)][capturedX(x, a)] == 3)))&&(((x + 2 == a)||(x - 2 == a))&&((y + 2 == b)||(y - 2 == b))))
        {
            board[b][a] = 4;
            board[capturedX(y, b)][capturedX(x, a)] = 1;
            p2--;
            board[y][x] = 1;
            x = a;
            y = b;
            system("cls");
            printBoard(size);
        }
        else if((((board[y][x] == 5 && board[b][a] == 1) && (board[capturedX(y, b)][capturedX(x, a)] == 2 || board[capturedX(y, b)][capturedX(x, a)] == 3)))&&(((x + 2 == a)||(x - 2 == a))&&((y + 2 == b)||(y - 2 == b))))
        {
            board[b][a] = 5;
            board[capturedX(y, b)][capturedX(x, a)] = 1;
            p2--;
            board[y][x] = 1;
            x = a;
            y = b;
            system("cls");
            printBoard(size);
        }
        //black man
        else if ((((board[y][x] == 2 && board[b][a] == 1) && (board[capturedX(y, b)][capturedX(x, a)] == 4 || board[capturedX(y, b)][capturedX(x, a)] == 5)))&&(((x + 2 == a)||(x - 2 == a))&&((y + 2 == b)||(y - 2 == b))))
        {
            board[b][a] = 2;
            board[capturedX(y, b)][capturedX(x, a)] = 1;
            p1--;
            board[y][x] = 1;
            x = a;
            y = b;
            system("cls");
            printBoard(size);
        }
        else if ((((board[y][x] == 3 && board[b][a] == 1) && (board[capturedX(y, b)][capturedX(x, a)] == 4 || board[capturedX(y, b)][capturedX(x, a)] == 5)))&&(((x + 2 == a)||(x - 2 == a))&&((y + 2 == b)||(y - 2 == b))))
        {
            board[b][a] = 3;
            board[capturedX(y, b)][capturedX(x, a)] = 1;
            p1--;
            board[y][x] = 1;
            x = a;
            y = b;
            system("cls");
            printBoard(size);
        }
        else
        {
            system("cls");
            cout << "Wrong input\n";
            printBoard(size);
        }
    }

}

//king movement
bool kingCheck(int size, int x, int y, int xx, int yy)
{
    bool checkTab[size][size];
    for(int i = 0; i < size; i ++)
    {
         for(int j = 0; j < size; j ++)
            {
                checkTab[i][j] = false;
            }
    }
    int a = x + 1, b = y + 1;
    while (a < size && b < size)
    {
        if (board[b][a] == 1)
        {
            checkTab[b][a] = true;
            a++;
            b++;
        }
        else
        {
            break;
        }
    }
    a = x + 1;
    b = y - 1;
    while (a < size && b < size)
    {
        if (board[b][a] == 1)
        {
            checkTab[b][a] = true;
            a++;
            b--;
        }
        else
        {
            break;
        }
    }
    a = x - 1;
    b = y + 1;
    while (a < size && b < size)
    {
        if (board[b][a] == 1)
        {
            checkTab[b][a] = true;
            a--;
            b++;
        }
        else
        {
            break;
        }
    }
    a = x - 1;
    b = y - 1;
    while (a < size && b < size)
    {
        if (board[b][a] == 1)
        {
            checkTab[b][a] = true;
            a--;
            b--;
        }
        else
        {
            break;
        }
    }
    return checkTab[yy][xx];
}

// king capture
bool kingCap(int size, int x, int y, int xx, int yy)
{
    bool f = false;

    int a = x + 1, b = y + 1;
    while (a < size && b < size)
    {
        if (board[b][a] == 1)
        {
            a++;
            b++;
        }
        else
        {
            if(((board[y][x] == 5 && (board[b][a] == 3 || board[b][a] == 2))||(board[y][x] == 3 && (board[b][a] == 5 || board[b][a] == 4)))&& (board[yy][xx] == board[b+1][a+1]))
            {
                f = true;
            }
            break;
        }
    }
    a = x + 1;
    b = y - 1;
    while ((a < size && b < size)&!f)
    {
        if (board[b][a] == 1)
        {
            a++;
            b--;
        }
        else
        {
            if(((board[y][x] == 5 && (board[b][a] == 3 || board[b][a] == 2))||(board[y][x] == 3 && (board[b][a] == 5 || board[b][a] == 4)))&& (board[yy][xx] == board[b-1][a+1]))
            {
                f = true;
            }
            break;
        }
    }
    a = x - 1;
    b = y + 1;
    while ((a < size && b < size)&!f)
    {
        if (board[b][a] == 1)
        {
            a--;
            b++;
        }
        else
        {
            if(((board[y][x] == 5 && (board[b][a] == 3 || board[b][a] == 2))||(board[y][x] == 3 && (board[b][a] == 5 || board[b][a] == 4)))&& (board[yy][xx] == board[b+1][a-1]))
            {
                f = true;
            }
            break;
        }
    }
    a = x - 1;
    b = y - 1;
    while ((a < size && b < size)&!f)
    {
        if (board[b][a] == 1)
        {
            a--;
            b--;
        }
        else
        {
            if(((board[y][x] == 5 && (board[b][a] == 3 || board[b][a] == 2))||(board[y][x] == 3 && (board[b][a] == 5 || board[b][a] == 4)))&& (board[yy][xx] == board[b-1][a-1]))
            {
                f = true;
            }
            break;
        }
    }
    return f;
}


//main/////////////////////////////////////////////////////////////
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
    char mapChoice;
    int size;
    int saveNum;
    string file_name[3] = { "save1.txt", "save2.txt", "save3.txt" };




    //choosing map size
    fstream plik;

choosingMapSize:
    bool loaded = false;

    while (1)
    {
        cout << "Choose map size: type c for classic or e for enlarged \nLoad save: type l \n";
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
plik.close();
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

    string cm1, cm2, cm3, cm4;
    int xa, ya, xb, yb;



    //game////////////////////////////////////////////////////
    while (p1 && p2)
    {
        cout << "Type piece x and y and new x and y \nor type 0 to end, -1 to restart, -2 to back to menu, -3 to save\n";
        if(player)
            cout << "White move\n";
        else
            cout << "Black move\n";
        cin >> cm1;
        xa = stringToInt(cm1);
        if (xa > 0 && xa <= size)
        {
            cin >> cm2 >> cm3 >> cm4;
            ya = stringToInt(cm2);
            xb = stringToInt(cm3);
            yb = stringToInt(cm4);
            if (((ya > 0 && ya <= size) && (xb > 0 && xb <= size)) && ((yb > 0 && yb <= size) && !(xa == xb && ya == yb)))
            {
                xa--;
                ya--;
                xb--;
                yb--;
                // white
                if (player)
                {
                    //man move
                    if ((board[ya][xa] == 4 && board[yb][xb] == 1) && (ya == yb + 1 && (xb == xa + 1 || xb == xa - 1)))
                    {
                        if (yb != 0)
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
                        if (yb != 0)
                            board[yb][xb] = 4;
                        else
                            board[yb][xb] = 5;
                        board[ya - 1][capturedX(xa, xb)] = 1;
                        p2--;
                        board[ya][xa] = 1;
                        if(captureCheck(1, xb, yb))
                        {
                            multiCapture(xb, yb, size);
                        }
                        system("cls");
                        printBoard(size);
                        player = false;
                    }
                    //king move
                    else if (board[ya][xa] == 5 && kingCheck(size,xa,ya,xb,yb))
                    {
                        board[yb][xb] = 5;
                        board[ya][xa] = 1;
                        system("cls");
                        printBoard(size);
                        player = false;
                    }
                    //king capture
                    else if ((((board[ya][xa] == 5 && board[yb][xb] == 1)&&kingCap(size,xa,ya,xb,yb)))||(((board[ya][xa] == 5 && board[yb][xb] == 1) && (board[ya - 1][capturedX(xa, xb)] == 2 || board[ya - 1][capturedX(xa, xb)] == 3)) && (ya == yb + 2 && (xb == xa + 2 || xb == xa - 2))))
                    {
                        board[yb][xb] = 5;
                        board[ya][xa] = 1;
                        p2--;
                        board[capturedX(ya, yb)][capturedX(xa, xb)] = 1;
                        if(captureCheck(1, xb, yb))
                        {
                            multiCapture(xb, yb, size);
                        }
                        system("cls");
                        printBoard(size);
                        player = false;
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
                    if ((board[ya][xa] == 2 && board[yb][xb] == 1) && (ya == yb - 1 && (xb == xa + 1 || xb == xa - 1)))
                    {
                        if (yb != size-1)
                            board[yb][xb] = 2;
                        else
                            board[yb][xb] = 3;
                        board[ya][xa] = 1;
                        system("cls");
                        printBoard(size);
                        player = true;
                    }
                    // man capture
                    else if (((board[ya][xa] == 2 && board[yb][xb] == 1) && (board[ya + 1][capturedX(xa, xb)] == 4 || board[ya + 1][capturedX(xa, xb)] == 5)) && (ya == yb - 2 && (xb == xa + 2 || xb == xa - 2)))
                    {
                        if (yb != size-1)
                            board[yb][xb] = 2;
                        else
                            board[yb][xb] = 3;
                        board[ya + 1][capturedX(xa, xb)] = 1;
                        p1--;
                        board[ya][xa] = 1;
                        if(captureCheck(1, xb, yb))
                        {
                            multiCapture(xb, yb, size);
                        }
                        system("cls");
                        printBoard(size);
                        player = true;
                    }
                    //king move
                    else if (board[ya][xa] == 3 && kingCheck(size,xa,ya,xb,yb))
                    {
                        board[yb][xb] = 3;
                        board[ya][xa] = 1;
                        system("cls");
                        printBoard(size);
                        player = true;
                    }
                    //king capture
                    else if ((((board[ya][xa] == 3 && board[yb][xb] == 1)&&kingCap(size,xa,ya,xb,yb)))||(((board[ya][xa] == 3 && board[yb][xb] == 1) && (board[ya + 1][capturedX(xa, xb)] == 4 || board[ya + 1][capturedX(xa, xb)] == 5)) && (ya == yb - 2 && (xb == xa + 2 || xb == xa - 2))))
                    {
                        board[yb][xb] = 3;
                        board[ya][xa] = 1;
                        p2--;
                        board[capturedX(ya, yb)][capturedX(xa, xb)] = 1;
                        if(captureCheck(1, xb, yb))
                        {
                            multiCapture(xb, yb, size);
                        }
                        system("cls");
                        printBoard(size);
                        player = true;
                    }
                    else
                    {
                        cout << "Wrong input \n";
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
plik.close();
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


