#include <iostream>
#include <conio.h>///for 'press any key to continue' (kbhit)

using namespace std;

extern int clrScreen(void);
extern int clear();

extern int win, lose;
extern int city[9];
extern int cityNum;
extern int Size;
extern int uPlasmaGun;
extern int uPlasmaShield;
extern int cityMor[9];
extern int cityPlasmaGun[9];
extern int cityPlasmaShield[9];

int lichEncounter()
{
    int f,g;
    char in;
    char offer;//did the lich offer something?
    cout<<"press 'k' to kill the Lich and liberate the city"<<endl;
    cout<<"press 'c' to keep the lich captive"<<endl;
    cout<<"press 'l' to leave the lich alive"<<endl<<endl;
    cout <<endl<<"LICH: ";
    if (cityPlasmaGun[cityNum]>uPlasmaGun)
    {
        cout<<"WAIT! before you kill me, I have a deal for you..."<<endl;
        cout<<"I have here the plans to our superior plasma guns"<<endl;
        cout<<"they're yours if you let me live, but if you kill me, you'll kill the plans with me"<<endl;
        offer='g';
    }
    else if (cityPlasmaShield[cityNum]>uPlasmaShield)
    {
        cout<<"WAIT! before you kill me, I have a deal for you..."<<endl;
        cout<<"I have here the plans to our superior plasma shields"<<endl;
        cout<<"they're yours if you let me live, but if you kill me, you'll kill the plans with me"<<endl;
        offer='i';
    }
    else
    {
        cout<<"Make it quick"<<endl;
    }
    cin>>in;
    clear();
    switch(in)
    {
    case ('k')://kill the lich
        //set city to liberated?
        if (Size == 1)
        {
            city[cityNum] = 4;
        }
        else if (Size == 2)
        {
            city[cityNum] = 5;
        }
        else if (Size == 3)
        {
            city[cityNum] = 6;
        }
        if (offer=='g')
        {
            cityPlasmaGun[cityNum]=1;
        }
        if (offer=='i')
        {
            cityPlasmaShield[cityNum]=1;
        }
        break;
    case ('c')://capture the lich
        //set city to liberated?
        if (Size == 1)
        {
            city[cityNum] = 4;
        }
        else if (Size == 2)
        {
            city[cityNum] = 5;
        }
        else if (Size == 3)
        {
            city[cityNum] = 6;
        }
        break;
    case('l')://leave the lich alive
        if (offer=='g')
        {
            uPlasmaGun=cityPlasmaGun[cityNum];
        }
        if (offer=='i')
        {
            uPlasmaShield=cityPlasmaShield[cityNum];
        }
        break;
    }
    cout<<"Press any key to continue"<<endl;///so that they can see what the lich says
    while (not kbhit())///wait for keyboard input
    {}
    return 0;
}





