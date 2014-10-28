// Load Libraries
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>     // srand, rand
#include <time.h>       // time
#include <math.h>

using namespace std;

int bigHouse (void);
int midHouse (void);
int smlHouse (void);
int boss (void);
int randMap (void);
int buildMap (void);
int randEncounter(void);

extern int c;
extern int cheat;
extern int cityX [9];
extern int cityY [9];
extern int cityNum;
extern int cityHealths [9][6];
extern int cityMor[9];
extern int cityPlasmaGun[9];
extern int cityPlasmaShield[9];
extern int cityScience[9];
extern int cityRule[9];///friendly/unfriendly liches, civilian rule, invaders rule
extern int n;
extern int Size;
extern int encounterType;
extern int city[9];
extern int newGame;
extern int difficulty;
extern int eneNum;
extern int clrScreen(void);
extern int clear();
extern int sh;
extern void gotoxy(int, int);
extern int f,g;//for for loops
int x = 2;
int y = 2;
//Cursor for the map
int Map()
{
    //Declare variables
    int lastx, lasty;
    char a;

    //Clear the screen
    clrScreen();

    //Set variables
    n = 1;

    // start an Infinite Loop
    while(n == 1)
    {
        // Head to LastX and LastY and clear old +
        gotoxy(lastx, lasty);
        printf(" ");
        buildMap();
        // Draw New + and check if + is off the map
        if (x <= 49 and x >= 1 and y <= 19 and y >= 2)
        {
            gotoxy(x,y);
            printf("+");
        }
        else
        {
            x = lastx;
            y = lasty;
            gotoxy(x,y);
            printf("+");
        }
        if (kbhit())
        {
                // Get Input
            a = getch();
            // Remember Old X and Y
            lastx = x;
            lasty = y;
            // If Down Arrow is Pressed, Y is increased
            if (a == 80)
            {
                y = y + 1;
                randEncounter();
            }
            // If Up Arrow is Pressed, Y is decreased
            if (a == 72)
            {
                y = y - 1;
                randEncounter();
            }
            // If Right Arrow is Pressed, X is increased
            if (a == 77)
            {
                x = x + 1;
                randEncounter();
            }
            // If Left Arrow is Pressed, X is decreased
            if (a == 75)
            {
                x = x - 1;
                randEncounter();
            }
            // If Spacebar is Pressed, Check if collision
            if (a == 32)
            {
                //Check if player is going to boss room
                if (23 <= x and x <= 28)
                {
                    if (8 <= y and y <= 12)
                    {
                        eneNum = 4 + difficulty;
                        n = 2;
                        clrScreen();
                        gotoxy(0,0);
                    }
                }
                else
                {
                    //check for collisions with city
                    for (c=0; c<9; c++)
                    {
                        if (city[c] == 1)
                        {
                            if (x == cityX[c] or x == cityX[c]+1)
                            {
                                if (y == cityY[c])
                                {
                                    //Get the number this city is
                                    cityNum = c;
                                    //Set the size of the city
                                    Size = 1;
                                    eneNum = 1 + difficulty;
                                    n = 2;
                                    clrScreen();
                                    gotoxy(0,0);
                                }
                            }
                        }
                        else if (city[c] == 2)
                        {
                            if (x == cityX[c] or x == cityX[c]+1)
                            {
                                if (y == cityY[c] or y == cityY[c]+1)
                                {
                                    //Get the number this city is
                                    cityNum = c;
                                    //Set the size of the city
                                    Size = 2;
                                    eneNum = 2 + difficulty;
                                    n = 2;
                                    clrScreen();
                                    gotoxy(0,0);
                                }
                            }
                        }
                        //Check city size
                        else if (city[c] == 3)
                        {
                            //check for collision
                            if (x == cityX[c] or x == cityX[c]+1 or x == cityX[c]+2)
                            {
                                if (y == cityY[c] or y == cityY[c]+1 or y == cityY[c]+2)
                                {
                                    //Get the number this city is
                                    cityNum = c;
                                    //Set the size of the city
                                    Size = 3;
                                    //set enemy number
                                    eneNum = 3 + difficulty;
                                    //stop infinite loop
                                    n = 2;
                                    //clear screen
                                    clrScreen();
                                    //reset position on screen
                                    gotoxy(0,0);
                                }
                            }
                        }
                        else if (city[c] == 4)
                        {
                            if (x == cityX[c] or x == cityX[c]+1)
                            {
                                if (y == cityY[c])
                                {
                                    Size = 1;
                                    n = 2;
                                    clrScreen();
                                    gotoxy(0,0);
                                    sh = 1;
                                }
                            }
                        }
                        else if (city[c] == 5)
                        {
                            if (x == cityX[c] or x == cityX[c]+1)
                            {
                                if (y == cityY[c] or y == cityY[c]+1)
                                {
                                    Size = 2;
                                    n = 2;
                                    clrScreen();
                                    gotoxy(0,0);
                                    sh = 1;
                                }
                            }
                        }
                        else if (city[c] == 6)
                        {
                            if (x == cityX[c] or x == cityX[c]+1 or x == cityX[c]+2)
                            {
                                if (y == cityY[c] or y == cityY[c]+1 or y == cityY[c]+2)
                                {
                                    Size = 3;
                                    n = 2;
                                    clrScreen();
                                    gotoxy(0,0);
                                    sh = 1;
                                }
                            }
                        }
                    }
                }
            }
        }

    }
    return 0;
}

int randEncounter()
{
    int prob=1;
    if (rand()%100<prob)
    {
        encounterType=1;
        n=2;
    }
    return 0;
}

int boss()
{
    gotoxy(23,8);
    cout <<"*****";
    gotoxy(23,9);
    cout <<"*/-\\*";
    gotoxy(23,10);
    cout <<"*| |*";
    gotoxy(23,11);
    cout <<"*|_|*";
    gotoxy(23,12);
    cout <<"*****";
    return 0;
}
int bigHouse()
{
    cout << " _ ";
    gotoxy(cityX[c],cityY[c]+1);
    cout << "/ \\";
    gotoxy(cityX[c],cityY[c]+2);
    cout << "|_|";
    return 0;
}

int midHouse()
{

    cout << "/\\";
    gotoxy(cityX[c],cityY[c]+1);
    cout << "||";
    return 0;
}

int smlHouse()
{
    cout << "/\\";
    return 0;
}
int libBigHouse()
{
    cout << " _ ";
    gotoxy(cityX[c],cityY[c]+1);
    cout << "/ \\";
    gotoxy(cityX[c],cityY[c]+2);
    cout << "|L|";
    return 0;
}

int libMidHouse()
{

    cout << "/\\";
    gotoxy(cityX[c],cityY[c]+1);
    cout << "L|";
    return 0;
}

int libSmlHouse()
{
    cout << "L\\";
    return 0;
}

int randMap()
{
    int midst[9];//how close is this city to the middle of the map?
    srand(time(NULL)); //Create random number generator seed
    if (newGame == 1);
    {
        for (c=0; c<9; c++)
        {
        }

        for (c=0; c<9; c++)
        {
            //set x an y variables to random within the map
            cityX[c] = rand()% 45 + 2;
            cityY[c] = rand()% 16 + 2;
            //set city sizes
            city[c] = rand()% 3 + 1;
            for (g=1; g<=2; g++)
            {
                //K-Map Method(look it up)
                if (g == 1)
                {
                    for (f=1; f<c; f++)
                    {
                        if (cityX[f]-4 <= cityX[c] and cityX[c] <= cityX[f]+4)
                        {
                            if (cityY[f]-4 <= cityY[c] and cityY[c] <= cityY[f]+4)
                            {
                                cityX[c] = rand()% 45 + 2;
                                cityY[c] = rand()% 16 + 2;
                                g = 0;
                                f = c;
                            }
                        }
                    }
                }
                else if (g == 2)
                {
                    if (20 <= cityX[c] and cityX[c] <= 27)
                    {
                        if (5 <= cityY[c] and cityY[c] <= 12)
                        {
                            cityX[c] = rand()% 45 + 2;
                            cityY[c] = rand()% 16 + 2;
                            g = 0;
                        }
                    }
                }
            }
            midst[c]=25-(sqrt (((cityX[c]-23.5)*(cityX[c]-23.5))+((cityY[c]-9)*(cityY[c]-9))));//pythagoras calculates nearness to center
            for (f=0; f<6; f++)///set cities' sentinel's healths
            {
                cityHealths[c][f]=(rand()%10)+(midst[c]*10)+10;
            }
            cityMor[c]=(rand()%5)+1;//set the morales of the cities to between 1 and 5
            cityPlasmaGun[c]=(rand()%2)+midst[c]/5;
            cityPlasmaShield[c]=(rand()%1+midst[c]/5);
            cityScience[c]=(cityPlasmaGun[c]+cityPlasmaShield[c])*250;
            cityRule[c]=0;
        }
        ///set the zeroth city's stats to default
        cityPlasmaGun[0]=1;
        cityPlasmaShield[0]=1;
        cityX[0] = 2;
        cityY[0] = 2;
        city[0] = 1;
        cityMor[0]=1;
        for (f=0; f<6; f++)
        {
            cityHealths[0][f]=30;
        }
    }
    return 0;
}

int buildMap()
{
    gotoxy(1,1);
    cout << "-------------------------------------------------";
    gotoxy(1,20);
    cout << "-------------------------------------------------";
    for (f=2; f<20; f++)
    {
        gotoxy(0,f);
        cout << "|";
        gotoxy(50,f);
        cout << "|";
    }
    boss();
    for (c=0; c<9; c++)
    {
        gotoxy(cityX[c],cityY[c]);
        if (city[c] == 3)
        {
            bigHouse();
        }
        else if (city[c] == 2)
        {
            midHouse();
        }
        else if (city[c] == 1)
        {
            smlHouse();
        }
        else if (city[c] == 6)
        {
            libBigHouse();
        }
        else if (city[c] == 5)
        {
            libMidHouse();
        }
        else if (city[c] == 4)
        {
            libSmlHouse();
        }
        if (cheat)
        {
            cout<<cityHealths[c][1];
        }
    }
    return 0;
}







