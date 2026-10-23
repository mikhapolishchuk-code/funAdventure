#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int hp = 100;
int strength = 10;
int intelligence = 10;
int agility = 10;
int memoryFragments = 0;
vector <string> inventory = {};  
// GLOBAL STATS 

void stats();
void intro();
void start();
void speak(string text);
void think(string text);
void voice(string text);
void character(string name, string text);
// FUNCTION DECLARATIONS

void intro()
{
    int ans;
    cout<<"This is a text based game where you have to navigate through rooms by making smart choices and using your skills wisely"<<endl;
    cout<<"You play as a man who wakes up and doesn't even remember his own name but he has a voice inside his head that guides him but be careful things are not as they seem..."<<endl;

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
             start();
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

void start()
{
    int ans;
    bool roomResolved = false;

    cout << R"(
======================================================================
            THE LOST CITY OF OLD YORK - ACT 1 SCENE 1
                       THE CONCRETE SPIRE
======================================================================

You open your eyes to blinding sunlight filtering through a thick 
canopy of snaking vines. 

You are lying at the the top of a concrete building that has been
taken over by nature from years of neglect and human inactivity. 
When you sit up there is no one around you, it's just you.

You have no memory of who you are or how you arrived here.
    
)";

    voice("Easy there! Don't sit up too fast. We've been asleep for a long time now.");
    speak("Where... where am I? Who are you?");
    voice("I don't know who *we* are either, but I know that we have to be careful. Look around for a way to get down.");
    cout<<"You look around to see where that voice is coming from but you have no luck"<<endl;
    speak("What do you mean *we*. Who who are you? Where are you?");
    voice("I'm... right here. In your head. I know it sounds crazy, but trust me, I'm just as confused as you are. All I know is that my instincts are telling me to keep you alive.");
    think("A voice in my head? Am I losing my mind... or is this something else?");

    bool locketTaken = false;
    bool badgeTaken = false;
    bool ask1 = false;
    bool ask2 = false;

do {
    cout << R"(

What will you do now?
1. Look over the edge of the roof to survey the city below you
2. Inspect the surface you were lying on
3. Search your pockets for any personal possessions
4. Ask the voice if he remembers your name
5. Ask the voice if he has a name
0. View Player Stats

)";
    cin>>ans;

    if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n[ Please enter a valid number option. ]\n";
            continue;
        } 

    switch (ans)
    {
        case 1:
            cout<<"The city is truly a sight to behold since the streets are now rivers and buildings are habitats. *You find a wet rusted spiral staircase going down the edge of the building your on*"<<endl;
            voice("The staircase doesn't seem very secure but it's our only way down so we'll have to be extremely careful");
            roomResolved = true;
            break;

        case 2:
            if (!badgeTaken)
            {
                cout<<"You notice a silver emblem underneath you and you pick it up."<<endl;
                think("Maybe it's some sort of clue to my past");
                cout<<"You read the enscription underneath the emblem."<<endl;
                speak("It says 'U.S ARMY' does that sound familiar to you?");
                voice("No I still can't remember anything but maybe this place was destroyed by war many years ago, now this is all that's left");
                cout<<"You put the emblem in your pocket"<<endl;
                cout<<"[U.S ARMY EMBLEM has been added to your inventory]"<<endl;
                inventory.push_back("U.S ARMY EMBLEM");
                badgeTaken = true;
            }
            else
            {
                cout<<"\nThere is nothing else of interest on the surface"<<endl;
            }
            break;

        case 3: 
            if (!locketTaken)
            {
                cout<<"While feeling through your leather jacket pockets you find a locket"<<endl;
                speak("I found a locket in my pocket but it won't budge");
                voice("Interesting, if you could open it you would probably find something out about your past");
                think("It has a hole at the top maybe if I find a pin I could open it");
                cout<<"You place the locket back into your jacket pocket."<<endl;
                cout<<"[LOCKED LOCKET has been added to your inventory]"<<endl;
                inventory.push_back("LOCKED LOCKET");
                locketTaken = true;
            }
            else
            {
                cout<<"\nThere is nothing else in the pockets of your leather jacket"<<endl;
            }
            break;

        case 4:
            if (!ask1)
            {
                voice("No, I don't remember anything although...");
                speak("Go on");
                voice("It's just that I feel that my memories are only slightly out of hands reach, tempting me to try get them");
                speak("I hope this amnesia is just temporary");
                voice("Me too");
                think("Why do I get the feeling that this voice is withholding some bit of information from me. I have to be more cautious");
                cout<<"+1 INTELLIGENCE FOR THIS OBSERVATION"<<endl;
                intelligence++;
                ask1 = true;
            }
            else
            {
                cout<<"\nYou've already asked this"<<endl;
            }
            break;

        case 5:
            if (!ask2)
            {
                voice("Maybe a long time ago when the world was a different place but I feel as if I will never possess it again as opposed to my other memories with I believe I'll recover in due time");
                cout<<"*The tone that the voice used had a tone of finality*"<<endl;
                ask2 = true;
            }
            else
            {
                cout<<"\nYou've already asked this"<<endl;
            }
            break;

        case 0:
            stats();
            break;

        default:
            cout << "\nPlease enter 0, 1, 2, 3, 4 or 5.\n"<<endl;
            break;

    }

} while (!roomResolved);

    cout<<"\n"<<"With a path discovered, you start the treacherous decent down the stairwell"<<endl;
}
// THE VERY START OF THE GAME

void stats()      
{
    cout<<'\n'<<"===== PLAYER STATS ====="<<endl;
    cout<<"Hp = "<<hp<<endl;
    cout<<"Strength = "<<strength<<endl;
    cout<<"Intelligence = "<<intelligence<<endl;
    cout<<"Agility = "<<agility<<endl;
    cout<<"Memory Fragments = "<<memoryFragments<<"/5"<<endl;
    cout<<"Inventory : ";
    if (inventory.empty())
    {
        cout<<"[EMPTY]"<<endl;
        cout<<"===== END OF STATS ====="<<'\n'<<endl;
    }
    else
    {
        for(int i = 0; i<inventory.size(); i++)
        {
            cout<<inventory.at(i)<<" ";
        }

        cout<<'\n'<<"===== END OF STATS ====="<<endl;
    }
    
}
// DISPLAY STATS

void voice(string text) 
{
    cout<<"[*VOICE*]: '"<<text<<"'"<<endl;
}

// VOICE IN YOUR HEAD SPEAKING

void speak(string text)
{
    cout<<"[YOU]: '"<<text<<"'"<<endl;
}

// YOU SPEAKING 

void think(string text)
{
    cout<<"[YOU think]: '"<<text<<"'"<<endl;
}

// YOU THINKING

void character(string name, string text)
{
    cout<<"["<<name<<"]"<<" '"<<text<<"'"<<endl;
}

// ANY OTHER CHARACTER SPEAKING

int main()
{
    intro();
    
}
 