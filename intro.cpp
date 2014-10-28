#include <iostream>

using namespace std;

extern int difficulty;
extern int randMap(void);
extern int eneNum;
extern int clrScreen(void);
extern int clear();

int intro()
{
    cout << "                                  VESTONIA" << endl<<endl;
    cout << "  You are the leader of the Vestonian Bandits, a group of terrorists rising"<<endl
         << "against the repressive rule of the Vestonian Royals. You roam from city to city"<<endl
         << "in your airship, The NightFall destroying Military bases of the vestonian"<<endl
         << "royals, recruiting soldiers, and freeing the people of each city."<<endl<<endl;
    cout<< "   Each turn, you will choose which enemy base you wish to target. In each"<<endl
        << "city, the zeroth base is the port, where reinforcements will arrive every four"<<endl
        << "turns. This port is shielded, but the shield strength is equal to the first"<<endl
        << "base's health. Then you choose how much of your strength to focus on attacking"<<endl
        << "your target. Any remaining strength will be used to repair any damage to the"<<endl
        << "ship. If you use more than your strength in firepower, the engines will"<<endl
        << "overheat and the ship will take damage."<<endl<<endl;
    cout <<endl<< "Choose level of Difficulty" << endl;
    cout << "[1]Easy [2]Medium [3]Hard" << endl;

    //Choose lvl of difficulty
    cin >> difficulty;
    while (cin.fail() or difficulty > 3 or difficulty < 1)
    {
        cout << "Please enter one of the bracketed numbers above." << endl;
        cin >>  difficulty;
        clear();
    }
    eneNum = 1 + difficulty;
    randMap();
    clrScreen();
    return 0;
}

