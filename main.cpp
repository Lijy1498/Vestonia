/*
TO DO:
Lich Killing (after you defeat the sentinels, story happens and you can actually kill the lich)
graphics - liam
morale and recruitment
Random Encounters

Dummy Proof
    -plasma shields vs. guns in combat
    -buying plasma shields and guns

To Do Today:
permanent ship repairs
morale and recruitement

BUGS:
boss health doesn't work
donating too much breaks it

ACTIVITIES LOG
dummy-proofed power input
moved "enemy reinforcement" to the end of the loop
doesn't say enemy reinforcements arrive if you beat the level (this was only a problem because of the above)
added a list of program parts (below)
base zero is the port, needed for reinforcements
base one can repair base 0 on reinforcement turns, and it has shields that prevent half damage to base zero - Caleb
added title(vestonia) and instructions and story-ish... open for continuation - tyler
worked on the story-Caleb
added subroutine clear() to shorten code-Brooke
<Caleb>
    changed some things about the UI
    repair is now an assigned amount of power
    overuse now deals 2x damage to ship
    strength is now 50
    added very basic scanning
</Caleb>

<Caleb>
    enemies deal 1/10+ rand between 0 and 10
    combat separated (few glitches maybe)
    added retreating (must add punishment for that)
    port and shield change now, you don't know which is which until you scan
</Caleb>
Tyler Is Working On PIRATES
<Caleb>
    you can get repaired at the shop
</Caleb>
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <stdio.h>

int Map(void);
int clrScreen(void);
int intro(void);//story and instructions, also difficulty select
int combat(void);
int shop(void);
int menu(void);
int lichEncounter(void);
int encounter(void);
int encounterType=0;

int Size=1;
int c;
int cityX [9];
int cityY [9];
int cityNum=0;
int n;
int cityHealths [9][6];
int cityMor[9];
int cityPlasmaGun[9];
int cityPlasmaShield[9];
int cityScience[9];

char activity;
int difficulty;
int sUH=100;
int sEH=50;//starting enemy health
int uPlasmaGun;
int uPlasmaShield;
int maxUHealth=sUH;
int strength=50;
bool cheat=true;//if true, disables dummy proof
bool ex=false;
void gotoxy(int, int);
int newGame;
int eneNum;
int wanted=0;//how many people follow the ship, trying to kill it
int win, lose;
int city[9];
int money;
int sh = 0;
int f,g;//for for loops

using namespace std;

int clear() //subroutine to clear out variable - use as “variable=clear()”
{
    cin.clear();
    cin.ignore(80, '\n');
    return 0;
}

int main()
{
    while (not ex)
    {
        menu();
        switch (activity)
        {
        case 'n':
            intro();
            combat();
            if (win)
            {
                lichEncounter();
            }
            while(not lose)
            {
                Map();
                if (cheat)
                {
                    cout<<"imma leave map now";
                    cin>>f;
                    clear();
                }
                while (encounterType != 0)
                {
                    encounter();
                    encounterType=0;
                    Map();
                }
                if (sh == 1)
                {
                    shop();
                    sh = 0;
                }
                else
                {
                    combat();
                    if (win)
                    {
                        lichEncounter();
                    }
                }
            }
            cout<<"You Lose! :("<<endl;
            lose=false;
            break;
        case 'x':
            ex=true;
            break;
        }
    }
    if (cheat)
    {
        cout<<"activity:"<< activity<<endl;
        cout<<"difficulty:"<< difficulty<<endl;
        cout<<"strength:"<< strength<<endl;
        cout<<"cheat:"<< cheat<<endl;
        cout<<"ex:"<< ex<<endl;
        cout<<"eneNum:"<< eneNum<<endl;
        cout<<"wanted:"<< wanted<<endl;
        cout<<"win:"<< win<<endl;
        cout<<"lose:"<< lose<<endl;
        cout<<"money:"<< money<<endl;
        cout<<"cities"<<endl;
        for (f=0; f<9; f++)
        {
            cout<<f<<":"<<city[f]<<endl;
        }
        cin>>f;
    }
    return 0;
}

// Make GOTOXY function
void gotoxy(int eex, int eey)
{
    COORD coord;
    coord.X = eex;
    coord.Y = eey;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int clrScreen ()
{
    for (int n=0; n<50; n++)
    {
        gotoxy(0,n);
        cout << "                                                                                      ";
        gotoxy(0,0);
    }
    return 0;
}




