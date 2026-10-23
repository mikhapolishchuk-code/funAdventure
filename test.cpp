#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int hp = 100;
int strength = 10;
int intelligence = 10;
int agility = 10;
vector <string> inventory = {};  
// GLOBAL STATS 

void stats();
void intro();
// FUNCTION DECLARATIONS

void intro()
{
    int ans;
    cout<<"This is a text based game where you have to navigate through rooms by making smart choices and using your skills wisely"<<endl;

    do
    {
        cout<<"To view your statistics at any point in time just type '0' when prompted for any response, do you wish to start the game?"<<endl; 
        cout<<"Enter '1'to start the game"<<endl;
        cout<<"Enter '2' to close the game"<<endl;
        cout<<"Enter '0' to view statistics"<<endl;
        cin>>ans;

        if (cin.fail()) 
        {
           cin.clear();            
           cin.ignore(1000, '\n'); 
           cout << "\nINVALID CHOICE! Please enter a number.\n" << endl;
           ans = 0;                
           continue;               
        }
        // IF THE USER DOESNT ENTER AN INTEGER

        switch(ans) 
        {
           case 1:
             cout<<"start";
             break;

           case 2:
             exit(EXIT_SUCCESS);
             break;

           case 0:
             stats();
             break;

           default:
             cout << "\nPlease enter 0, 1, or 2.\n" << endl;
             ans = 0;
           break;
           // IF THE USER ENTERS AN INVALID INTEGER

        }
    } 
    while (ans==0);
}
// TELLS THE PLAYER HOW THE GAME WORKS

void stats()      
{
    cout<<'\n'<<"===== PLAYER STATS ====="<<endl;
    cout<<"Hp = "<<hp<<endl;
    cout<<"Strength = "<<strength<<endl;
    cout<<"Intelligence = "<<intelligence<<endl;
    cout<<"Agility = "<<agility<<endl;
    cout<<"Inventory : ";
    if (inventory.empty())
    {
        cout<<"[EMPTY]"<<endl;
    }
    else
    {
        for(int i = 0; i<inventory.size(); i++)
        {
            cout<<inventory.at(i)<<" ";
        }
    }
    cout<<"===== END OF STATS ====="<<'\n'<<endl;
}
// DISPLAY STATS

int main()
{
    intro();
    return 0;
}
 