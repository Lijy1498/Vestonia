#include <iostream>

using namespace std;

extern int clrScreen(void);
extern int sUH;
extern int uPlasmaGun;
extern int uPlasmaShield;
extern int maxUHealth;
extern int strength;
extern int money;

extern char activity;

extern int clear();

int menu()
{
    char in;
    cout << "                                  VESTONIA" << endl<<endl;
    cout<<"To do one of the following, enter the character that is in square brackets"<<endl;
    cout<<"start a [n]ew game"<<endl;
    cout<<"e[x]it"<<endl;
    cin >>in;
    clear();
    activity='0';
    switch (in)
    {
    case 'n':
        activity='n';
        sUH=100;
        uPlasmaGun=1;
        uPlasmaShield=1;
        maxUHealth=sUH;
        strength=50;
        money=100000;
        break;
    case 'x':
        activity='x';
        break;
    }
    clrScreen();
    return 0;
}

