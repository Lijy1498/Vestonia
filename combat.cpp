//PARTS:
//external variables
//top
//variables
//big loop
//reinforcements
//input for turn loop
//output stats
//which input
//help
//retreat
//change attack power
//fix the ship
//shield power
//attack
//get target
//hurt enemy
//scan
//overuse warning
//repair
//overuse damage
//enemy attack
//shield statement
//win check
//give earnings

#include <iostream>
#include <stdlib.h>     // srand, rand
#include <time.h>       // time

using namespace std;

//external variables
extern int difficulty;
extern int sUH;
extern int maxUHealth;
extern int sEH;
extern int uPlasmaGun;
extern int uPlasmaShield;
extern int strength;
extern int eneNum;
extern bool cheat;
extern int win;
extern int lose;
extern int money;
extern int cityNum;
extern int cityHealths[9][6];
extern int cityMor[9];
extern int cityPlasmaGun[9];
extern int cityPlasmaShield[9];

int clrScreen(void);
int clear(void);

//top
int combat()
{
    srand(time(NULL)); //Create random number generator seed

    //variables
    char in;//various letter inputs
    int uHealth=maxUHealth;
    int uShield=0;//user can set power to shield
    int block=uShield;//how much damage actually gets prevented?
    int hit;//how much damage actually gets dealt?
    int target;
    int turns=0;
    int power=strength;
    int repair=0;
    int inDamage;//how much damage are you taking?
    int eHealth[eneNum];
    int f,g;//for for loops
    bool finished;//is their turn over?
    bool scan=false;//have the enemies been scanned?
    bool retreat=false;
    int port;//which enemy is the port?
    int shield;//which enemy shields?
    bool overWin;//only for dummies
    //clear();

    for (f=0; f<eneNum; f++) //set the enemies' healths to 50% +/- 10
    {
        eHealth[f]=cityHealths[cityNum][f];
    }
    port=rand()%eneNum;//
    shield=rand()%eneNum;//
    while (port==shield)//don't let the shield be the same as the port
    {
        shield=rand()%eneNum;
    }

    win=false;
    //big loop
    while (uHealth>0 and not retreat and not win)
    {
        //reinforcements
        if (turns%4==0 and win!=1 and turns!=0)
        {
            if (eHealth[port]>0)
            {
                cout<<"Enemy reinforcements have arrived"<<endl;
                for (f=0; f<eneNum; f++)
                {
                    eHealth[f]=eHealth[f]+((turns/4)*5);
                };
            }
            else if (eHealth[1]>1) //if base 1 is alive, it revives base 0
            {
                cout << "Base 1 has taken back the enemy port!"<<endl;
                eHealth[port]=eHealth[1]/2;
                eHealth[shield]=eHealth[shield];
            }
        }
        cout<<endl<<endl;
        turns++;//count 1 turn finished

        //input for turn loop
        finished=false;
        while (not finished)
        {
            //bug finding
            if (cheat)
            {
                cout<<"in:"<<in<<endl;
                cout<<"uHealth:"<<uHealth<<endl;
                cout<<"uShield:"<<uShield<<endl;
                cout<<"target:"<<target<<endl;
                cout<<"turns:"<<turns<<endl;
                cout<<"power:"<<power<<endl;
                cout<<"repair:"<<repair<<endl;
                cout<<"inDamage:"<<inDamage<<endl;
                cout<<"finished:"<<finished<<endl;
                cout<<"scan:"<<scan<<endl;
                cout<<"retreat:"<<retreat<<endl;
                cout<<"port:"<<port<<endl;
                cout<<"shield:"<<shield<<endl;
                cout<<"eneNum:"<<eneNum<<endl;
                cout<<"maxUHealth:"<<maxUHealth<<endl;
                cout<<"cityMor:"<<cityMor[cityNum]<<endl;
                for (f=0; f<eneNum; f++)
                {
                    cout<<"eHealth #"<<f<<":"<<eHealth[f]<<endl;
                }
            }
            //output stats
            cout <<"NightFall Stats:"<<" health="<< uHealth<<endl<<endl;
            cout<<"Power Distribution: "<<power+repair+uShield<<"/"<<strength<< endl;
            cout<<"power (attack):"<<power<<endl;
            cout<<"fixing:"<<repair<<endl;
            cout<<"shields:"<<uShield<<endl<<endl;
            cout<<"enemy stats and ID numbers:";
            for (f=0; f<eneNum; f++)
            {
                cout<<" ("<<f<<")";
                if (scan)//only if they've been scanned
                {
                    cout<<"HP:"<<eHealth[f];
                    if (f==port)
                    {
                        cout<<"(port) ";
                    }
                    if (f==shield)
                    {
                        cout<<"(shield) ";
                    }
                }
            };
            cout<<endl<<endl;
            cout<<"your turn (enter 'h' for help)"<<endl;
            cin >>in;
            clear();
            //which input
            switch (in)
            {
            case 'h'://help
                clrScreen();
                cout<<"to do one of the following, enter the character in square brackets"<<endl;
                cout<<"[a]ttack (ends turn)"<<endl;
                cout<<"[s]can (ends turn)"<<endl;
                cout<<"[r]etreat (ends turn)"<<endl;
                cout<<"re[c]ruit soldiers (ends turn)"<<endl;
                cout<<"change how much [p]ower is being used to attack"<<endl;
                cout<<"change how much power is being used to [f]ix the ship"<<endl;
                cout<<"change how much power is being used for sh[i]elds"<<endl<<endl<<endl;
                cout<<"cityPlasmaGun:"<<cityPlasmaGun[cityNum]<<endl;
                cout<<"cityPlasmaShield:"<<cityPlasmaShield[cityNum]<<endl;
                break;
            case 'w'://cheat past the level
                if (cheat)
                {
                    overWin=true;
                    finished=true;
                }
                break;
            case 'k'://cheat lose the level
                if (cheat)
                {
                    uHealth=0;
                    finished=true;
                    cout<<"you're committing suicide";
                    cin>>f;
                    clear();
                }
                break;
            case 'r'://retreat
                finished=true;
                retreat=true;
                break;
            case 'c'://recruit
                cout<<"to which sentinel do you wish to send recruitment vessels?"<<endl;
                cin >>  target;
                clear();
                while ((cin.fail() or target > (eneNum - 1) or target < 0))//dummy
                {
                    cout<<"Unacceptable input, please input one of the bracketed numbers above."<<endl;
                    cin >>  target;
                    clear();
                }
                if ((eHealth[target]>0) and (power>0))
                {
                    int ran;
                    float rPower=power;//so that division works
                    if (cheat)
                    {
                        ran=(eHealth[target]/2)+(eHealth[target]/2);//set to the maximum random value
                    }
                    else
                    {
                        ran=(rand()%(eHealth[target]/2))+(eHealth[target]/2);//the real value, randomized
                    }
                    ran=ran-(((ran+1)/(rPower/eHealth[target]))*cityMor[cityNum]);//this portion of the army surrenders
                    if (ran>0)//the number of people surrenderring can't be negative, or else bad stuff happens
                    {
                        strength=strength+ran;//you gain strength
                        eHealth[target]=eHealth[target]-(power+ran);//the enemy is weaker by the amount dealt, plus the amount betrayed
                        cout<<ran<<"soldiers have joined our cause"<<endl;
                    }
                    else
                    {
                        cout<<"none were persuaded"<<endl;
                    }
                }
                finished=true;
                if (eHealth[target]<0)
                {
                    eHealth[target]=0;
                }
                break;
            case 'p'://change attack power
                cout<<"How much power? Strength is "<<strength<<endl;
                cin>>power;
                clear();
                while ((cin.fail() or power<0 or power>uHealth+strength+1))//dummy
                {
                    cout<<"Must be positive, can't be more than your strength combined with your health."<<endl;
                    cin >>  power;
                    clear();
                }
                clrScreen();
                break;
            case 'f'://fix the ship
                cout<<"How much power to fixing the ship? Strength is "<<strength<<endl;
                cin>>repair;
                clear();
                while ((cin.fail() or repair<0 or repair>uHealth+strength+1))//dummy
                {
                    cout<<"Must be positive, can't be more than your strength combined with your health."<<endl;
                    cin >>  repair;
                    clear();
                }
                clrScreen();
                break;
            case 'i'://shield power
                cout<<"How much power to shields? Strength is "<<strength<<endl;
                cin>>uShield;
                clear();
                while ((cin.fail() or uShield<0 or uShield>uHealth+strength+1))//dummy
                {
                    cout<<"Must be positive, can't be more than your strength combined with your health."<<endl;
                    cin >>  uShield;
                    clear();
                }
                clrScreen();
                break;
            case 'a'://attack
                //get target
                cout<<"Choose a target"<<endl;
                cin>>target;
                clear();
                while ((cin.fail() or target > (eneNum - 1) or target < 0))//dummy
                {
                    cout<<"Unacceptable input, please input one of the bracketed numbers above."<<endl;
                    cin >>  target;
                    clear();
                }
                hit=power*uPlasmaGun;
                //hurt enemy
                if (target==port and eHealth[shield]>0) //if the shield is up, it prevents it's health in percent of damage to port
                {
                    if (cityPlasmaShield[cityNum]>=uPlasmaGun)//if their shield is good enough, it blocks full damage
                    {
                        eHealth[target]=eHealth[target]-((hit)-(hit*eHealth[shield]/100));
                        ///cout<<"Base 1 shields block "<<eHealth[shield]<<" percent of the damage."<<endl;
                    }
                    else//if their shield is worse than our guns, it fails
                    {
                        eHealth[target]=eHealth[target]-((hit)-(hit*eHealth[shield]/100/(uPlasmaGun+1-cityPlasmaShield[cityNum])));
                        ///cout<<"Base 1 shields block "<<eHealth[shield]<<" percent of the damage."<<endl;
                    }
                }
                else
                {
                    eHealth[target]=eHealth[target]-hit;//the enemy gets hit, looses health
                }
                if (eHealth[target]<0)
                {
                    eHealth[target]=0;
                }
                finished=true;
                break;
            case 's'://scan
                scan=true;
                finished=true;
                break;
            default://if nothing else happens, just clear the screen
                clrScreen();
                break;
            }
            //overuse warning
            if (uShield+power+repair>uHealth+strength and finished)//if they're gonna blow up the ship, warn them
            {
                cout<<"Captain, the chances of surviving using so much more power than we have are zero."<<endl;
                cout<<"press 0 to abort and change energy use or 1 to continue anyway"<<endl;
                cin>>in;
                clear();
                if (in!='1')//if they don't say to continue, get them to give more input
                {
                    finished = false;
                }
            }
        }
        clrScreen();
        //repair
        if (repair>0)
        {
            if (uHealth+repair>maxUHealth)//can't repair past the max health
            {
                cout<<"repaired "<<maxUHealth-uHealth<<endl;
                cout<<"cannot repair beyond maximum health"<<endl;
                uHealth=maxUHealth;
            }
            else
            {
                cout<<"repaired "<<repair<<endl;
                uHealth=uHealth+repair;
            }
        }
        //overuse damage
        if (power+repair+uShield>strength)//if they overuse, tax them 2 health per extra energy
        {
            uHealth=uHealth-2*((repair+power+uShield)-strength);
        }
        //enemy attack
        inDamage=0;//how much damage is collectively dealt?
        if (uPlasmaShield>=cityPlasmaGun[cityNum])//the shield blocks it's power in damage unless the enemy guns overpower
        {
            block=uShield;
        }
        else
        {
            block=uShield/(cityPlasmaGun[cityNum]+1-uPlasmaShield);
        }
        for (f=0; f<eneNum; f++) //for each enemy
        {
            if (eHealth[f]>0) //if its' alive
            {
                int ran=rand()%10;//get a random number that is extra damage dealt
                inDamage=inDamage+((ran+eHealth[f]/10)-(ran+eHealth[f]/10)*block/100);//it deals a tenth of it's health in damage
            }
        }
        cout<<"The NightFall takes "<<inDamage<<" damage"<<endl;
        uHealth=uHealth-inDamage;//take damage away from health
        //permanent damage
        if (inDamage>=10)
        {
            maxUHealth=maxUHealth-rand()%(inDamage/5);//up to a fifth of the damage can't be repaired
            strength=strength-rand()%(inDamage/5);
        }
        //shield statement
        if (uPlasmaShield<cityPlasmaGun[cityNum])//the shield blocks it's power in damage unless the enemy guns overpower
        {
            cout<<"Enemy guns overpower NightFall's Shields"<<endl;
        }
        if (uShield>0)
        {
            cout<<"Your shield blocks "<<block<<"% of incoming damage"<<endl;
        }
        //win check
        if (overWin)
        {
            win=1;
        }
        else
        {
            win=1;
            for (g=0; g<eneNum; g++) //is anyone still alive?
            {
                if (eHealth[g]>0)
                {
                    win=0;
                    if (cheat)//if you're dummy proofing, do this
                    {
                        cout<<"enemy #"<<g<<" is still alive"<<endl;
                    }
                }
            }
        }
        if (win == 1)
        {
            //give earnings
            money = money + eneNum * 250;
            cout << "You got $"<< eneNum * 250<<endl;
            cout << "You have a total of $"<< money<<endl;
        }
    }
//lose check
    if (uHealth<=0)
    {
        lose=1;
    }

//bug finding
    if (cheat)
    {
        cout<<"in:"<<in<<endl;
        cout<<"uHealth:"<<uHealth<<endl;
        cout<<"uShield:"<<uShield<<endl;
        cout<<"target:"<<target<<endl;
        cout<<"turns:"<<turns<<endl;
        cout<<"power:"<<power<<endl;
        cout<<"repair:"<<repair<<endl;
        cout<<"inDamage:"<<inDamage<<endl;
        cout<<"finished:"<<finished<<endl;
        cout<<"scan:"<<scan<<endl;
        cout<<"retreat:"<<retreat<<endl;
        cout<<"port:"<<port<<endl;
        cout<<"shield:"<<shield<<endl;
        cout<<"eneNum:"<<eneNum<<endl;
        cout<<"maxUHealth:"<<maxUHealth<<endl;
        cout<<"cityMor:"<<cityMor[cityNum]<<endl;
        cout<<"cityPlasmaGun:"<<cityPlasmaGun[cityNum]<<endl;
        cout<<"cityPlasmaShield:"<<cityPlasmaShield[cityNum]<<endl;
        for (f=0; f<eneNum; f++)
        {
            cout<<"eHealth #"<<f<<":"<<eHealth[f]<<endl;
        }
        cin >>f;
        clear();
    }
    for (f=0; f<eneNum; f++) //set the enemies' healths to 50% +/- 10
    {
        cityHealths[cityNum][f]=eHealth[f];
    }
    return 0;
}
