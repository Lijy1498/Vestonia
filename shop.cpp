#include <iostream>
#include <stdlib.h>     // srand, rand
#include <time.h>       // time

using namespace std;

extern int f,g;//for for loops
extern int Size;
extern int clrScreen(void);
extern int money;
extern int sUH;
extern int maxUHealth;
extern int uPlasmaGun;
extern int uPlasmaShield;
extern int cityNum;
extern int cityPlasmaGun[9];
extern int cityPlasmaShield[9];
extern int cityScience[9];
//int strength=50;
extern int clear();

int shop()
{
    char item;
    int iin;//integer input
    int n=1;

    srand(time(NULL)); //Create random number generator seed

    while (n==1)
    {
        cout << "Welcome to the shop!" << endl;
        cout << "Money = $" << money << endl;
        if (maxUHealth<sUH)
        {
            cout<<"[r]epair"<<endl;
        }
        if (cityPlasmaGun[cityNum]>uPlasmaGun)
        {
            cout<<"[g]un upgrade"<<endl;
        }
        if (cityPlasmaShield[cityNum]>uPlasmaShield)
        {
            cout<<"sh[i]eld upgrade"<<endl;
        }
        if (money>1000)
        {
            cout<<"[d]onate to our science program, so that we can make better weapons and shields"<<endl;
        }
        cout<<"e[x]it"<<endl;
        cin >> item;
        clear();
        clrScreen();
        switch(item)
        {
        case 'd'://donate money to developing better shields and guns which can be bought
            cout<<"How much money do you wish to donate?"<<endl;
            cin>>iin;
            clear();
            if ((iin<=money) and not cin.fail() and iin >=0)
            {
                cityScience[cityNum]=cityScience[cityNum]-iin;///add however much money was donated to the science fund count
                money=money-iin;
                while (cityScience[cityNum]<=0)///if the science count has counted down...
                {
                    iin=0-cityScience[cityNum];///record how far it's overflown...
                    cityScience[cityNum]=(cityPlasmaGun[cityNum]+cityPlasmaShield[cityNum])*250*rand()%3;///reset the science count
                    if (rand()%(cityPlasmaGun[cityNum]+cityPlasmaShield[cityNum]+2)<cityPlasmaGun[cityNum]+1)///randomly develop shield or gun
                        ///big if statement says probably develope the less developed one
                    {
                        cityPlasmaShield[cityNum]++;
                    }
                    else
                    {
                        cityPlasmaGun[cityNum]++;
                    }
                    ///subtract the overflow
                    cityScience[cityNum]=cityScience[cityNum]-iin;
                }
            }
            else
            {
                cout<<"Unacceptable input, sorry :/"<<endl;
            }
            break;
        case 'r':
            if (maxUHealth<sUH)
            {
                cout<<"We can repair you for "<<sUH-maxUHealth<<" health for a cost of $20 per health"<<endl;
                cout<<"How much would you like to be repaired?"<<endl;
                cin>>iin;
                clear();
                if ((iin<=(sUH-maxUHealth)) and not cin.fail() and iin >=0)
                {
                    maxUHealth=maxUHealth+iin;
                    money=money-20*iin;
                }
                else
                {
                    cout<<"Unacceptable input, sorry :/"<<endl;
                }
            }
            else
            {
                cout<<"you have full health, we can't repair you."<<endl;
            }
            break;
        case 'g':
            if (cityPlasmaGun[cityNum]>uPlasmaGun)
            {
                cout<<"We can upgrade your plasma gun by "<<cityPlasmaGun[cityNum]-uPlasmaGun<<" for $1000 per level"<<endl;
                cout<<"How much would you like your gun upgraded?"<<endl;
                cin>>iin;
                clear();
                if ((iin<=(cityPlasmaGun[cityNum]-uPlasmaGun)) and not cin.fail() and iin >=0)
                {
                    uPlasmaGun=uPlasmaGun+iin;
                    money=money-1000*iin;
                }
                else
                {
                    cout<<"Unacceptable input, sorry :/"<<endl;
                }
            }
            else
            {
                cout<<"you have full health, we can't repair you."<<endl;
            }
            break;
        case 'i':
            if (cityPlasmaShield[cityNum]>uPlasmaShield)
            {
                cout<<"We can upgrade your plasma shield by "<<cityPlasmaShield[cityNum]-uPlasmaShield<<" for $1000 per level"<<endl;
                cout<<"How much would you like your shield upgraded?"<<endl;
                cin>>iin;
                clear();
                if ((iin<=(cityPlasmaShield[cityNum]-uPlasmaShield)) and not cin.fail() and iin >=0)
                {
                    uPlasmaShield=uPlasmaShield+iin;
                    money=money-1000*iin;
                }
                else
                {
                    cout<<"Unacceptable input, sorry :/"<<endl;
                }
            }
            else
            {
                cout<<"you have full health, we can't repair you."<<endl;
            }
            break;
        case 'x':
            cout<<"Thank you, come again!"<<endl;
            n=2;
            break;
        }
    }
    return 0;
}


