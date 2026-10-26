#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <iostream>
#include <fstream>

using namespace std;

int hp = 100;
int strength = 10;
int intelligence = 10;
int agility = 10;
int memoryFragments = 0;
int loadedRoom = 0;
vector <string> inventory = {};  
// GLOBAL STATS 

const string Reset   = "\033[0m";
const string Bold   = "\033[1m";
const string Red    = "\033[31m";
const string Green   = "\033[32m";
const string Yellow  = "\033[33m";
const string Blue    = "\033[34m";
const string Magenta = "\033[35m";
const string Cyan    = "\033[36m";
// COLOUR CONSTANTS

void stats();
void intro();
void start();
void room2();
void room3();
void room4();
//void room7();
void speak(string text);
void think(string text);
void voice(string text);
void character(string name, string text);
void renderHeader(string roomTitle, string actRoom);
void typewriter(string text, int delayMs = 12);
void autosaveGame(int roomNumber);
void loadGame();
// FUNCTION DECLARATIONS

void intro()
{
    int ans;
    cout<<"This is a text based game where you have to navigate through rooms by making smart choices and using your skills wisely"<<endl;
    cout<<"You play as a man who wakes up and doesn't even remember his own name but he has a voice inside his head that guides him but be careful things are not as they seem..."<<endl;

    do
    {
        cout<<"Do you wish to start the game or load an existing save?"<<endl; 
        cout<<"1. To start the game"<<endl;
        cout<<"2. To close the game"<<endl;
        cout<<"3. To load the latest autosave from autosave.txt"<<endl;
        cout<<"0. View Player Stats"<<endl;
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

           case 3:
             loadGame();
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
    autosaveGame(1);
    renderHeader("The Concrete Block", "Act 1 Room 1");
    cout<<Green;

    typewriter(R"(

You open your eyes to blinding sunlight filtering through a thick 
canopy of snaking vines. 

You are lying at the the top of a concrete building that has been
taken over by nature from years of neglect and human inactivity. 
When you sit up there is no one around you, it's just you.

You have no memory of who you are or how you arrived here.
    
)");

    cout<<Reset;

    voice("Easy there! Don't sit up too fast. We've been asleep for a long time now.");
    speak("Where... where am I? Who are you?");
    voice("I don't know who *we* are either, but I know that we have to be careful. Look around for a way to get down.");
    cout<<Green<<Bold<<"You look around to see where that voice is coming from but you have no luck"<<Reset<<endl;
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

    if (cin.fail()) 
    {
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
                inventory.push_back("U.S_ARMY_EMBLEM");
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
                inventory.push_back("LOCKED_LOCKET");
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
                cout<<Blue<<Bold;
                typewriter("+1 INTELLIGENCE, FOR THIS OBSERVATION");
                cout<<Reset;
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
    room2();
}
// THE VERY START OF THE GAME

void room2()
{
    int ans;
    bool roomResolved = false;
    autosaveGame(2);
    renderHeader("The Rusted Decent", "Act 1 Room 2");
    cout<<Green;
    typewriter(R"(

You step onto the spiral staircase clinging to the exterior of the 
building. Decades of rain and neglect have turned the metal a deep, 
flaky orange. Every step you take produces a low, groaning echo that 
carries far across the silent, flooded canyons of the city.

Looking down, the street level is obscured by a thick, green canopy 
of towering maples and snaking vines that have swallowed the city whole.
    
)");
    cout<<Reset;

    voice("Watch your footing. One rusted bolt snaps, and it's a straight drop down to the concrete jungle.");
    speak("The metal feels like it's going to crumble under my boots. Is there any other way down?");
    voice("None that we can see from up here. We have to push through.");
    think("My legs feel steady enough, but my hands are shaking. I need to stay focused.");

    bool lookWindow = false;
    bool searchPile = false;
    bool ask1 = false;
    bool ask2 = false;

do
{
    cout << R"(

What will you do now?
1. Descend carefully, testing each step before putting your full weight on it
2. Stop and peer through a shattered office window on the building's exterior wall
3. Search through a pile of wind-blown debris stuck in the stair corner
4. Whilst descending the steps you check each step for where to best put your feet
5. Ask the voice if they remember how to navigate heights or urban combat
6. Ask the voice if it's worth it to come down these steps?
0. View Player Stats

)";

    cin>>ans;

    if (cin.fail()) 
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n[ Please enter a valid number option. ]\n";
        continue;
    } 

    

    switch(ans)
    {
        case 1:
            cout<<"You take it slow, hugging the cold concrete wall. You successfully make it halfway down the multi-story descent without incident."<<endl;
            voice("Good. Slow and steady wins the race. We're almost to street level.");
            cout<<Red<<Bold;
            typewriter("+1 AGILITY, FOR DESCENDING THE STEPS");
            agility++;
            cout<<Reset;
            speak("I hope the stairs hold until then.");
            roomResolved = true; 
            break;

        case 2:
            if(!lookWindow)
            {
                cout<<"You peer through the grime-covered window into an abandoned corporate office. Desks are buried under mounds of moss and shattered glass."<<endl;
                think("I don't see anything useful in there right now... just ghosts of the past.");
                lookWindow = true;
            }
            else
            {
                cout<<"You've already looked through the office window"<<endl;
            }
            break;

        case 3:
            if(!searchPile)
            {
                cout<<"You sift your hand through the pile of debris when..."<<endl;
                voice("Look it's a mouse");
                think("I hope it doesn't bite");
                cout<<Red<<Bold;
                typewriter("-5 HP, MOUSE BITES YOU");
                hp -= 5;
                cout<<Reset;
                speak("OWWW!");
                speak("The little one can really bite");
                think("I should be more careful with where I shove my hands");
                searchPile = true;
            }
            else
            {
                cout<<"You've already sifted through the pile of debris"<<endl;
            }
            break;

        case 4:
            cout<<"You take it slow, only stepping where your weight will be supported. You successfully make it halfway down the multi-story descent without incident."<<endl;
            voice("Good. Slow and steady wins the race. We're almost to street level.");
            cout<<Blue<<Bold;
            typewriter("+1 INTELLIGENCE, FOR THIS STRATEGY");
            cout<<Reset;
            think("Hopefully this strategy gets me down all the way safely.");
            roomResolved = true; 
            break;

        case 5:
            if (!ask1)
            {
                voice("All I know is that we should be really careful since all of this infastructure requires a lot of maintenance and it hasn't received it in years.");
                voice("And urban combat...");
                voice("I just can't remember but it's something that this city wasn't meant for");
                think("I think the voice is telling the truth this time");
            }
            else
            {
                cout<<"You've already asked this"<<endl;
            }
            break;

        case 6:
            if(!ask2)
            {
                voice("We couldn't do anything if we just stayed on top of this building so we have to get down and also I have this hunch that whatever we need to do requires us to head downstairs");
                voice("It's also getting dark soon so we had to do it before that point");
                speak("Yh staying up there didn't seem like such a great idea");
            }
            else
            {
                cout<<"You've already asked this"<<endl;
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

    room3();
    
}

//THE SECOND ROOM

void room3()
{
    int ans;
    int a;
    bool roomResolved = false;
    autosaveGame(3);
    renderHeader("The Choice", "Act 1 Room 3");
    
    cout<<Green;
    typewriter(R"(

With a sharp, deafening shriek of rusted iron, the concrete ledge beneath
your boots gives way. The lower half of the spiral staircase shears off 
completely, plummeting into the flooded abyss below and leaving you stranded against
the sheer, vertical face of the building. 

The path down is gone. Your only options now are to trust your balance on the slick,
vertical drainpipes dangling over the flooded streets, or force your way
through the shadowy, glass-shattered doors of the office floor beside you.
    
)");
    cout<<Reset;

    voice("WHOA! HANG ON! The rest of th-");
    speak("The rest of the stairs are gone");
    speak("I can't just fly the rest of the way down");
    voice("I'll try find us another way down");
    think("I should be panicking like crazy but I have this slight sense of calm among the other feelings of stress, maybe I'm used to these types of situations where not everything goes well");

do
{
    cout << R"(

What will you do now?
1. Use your legs to smash the already weak glass in order to get inside the building and continue traversing downward through there
2. Slide down the rusty pipe to get down to a balcony below you (Requires >10 AGILITY or -5 HP)
0. View Player Stats

)";

    cin>>ans;

    if (cin.fail()) 
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n[ Please enter a valid number option. ]\n";
        continue;
    } 

    switch(ans)
    {
        case 1:

            cout<<"The glass shatters cleanly after you kick it and you go inside the building"<<endl;
            voice("It certainly smells better than it looks");
            speak("Now I see why we decided to take the spiral staircase instead of going inside the building");
            speak("This place is overgrown so much that even the vines have vines");
            a = 0;
            roomResolved = true; 
            break;

        case 2:

            if(agility>10)
            {
                cout<<"You manage to get onto the pipe without trouble"<<endl;
                speak("It feels more secure than it looks");
                think("I sure hope it does because I'm out of ideas");
            }
            else
            {
                cout<<"You clumsly manage to get onto the pipe but you obtain a mild muscle pull in the process"<<endl;
                cout<<Red<<Bold;
                typewriter("-5 HP, MILD MUSCLE INJURY");
                hp -= 5;
                cout<<Reset;
                think("That may not have been my best idea so far");
            }
            a = 1;
            roomResolved = true;
            break;

        case 0:
            stats();
            break;

        default:
            cout << "\nPlease enter 0, 1, 2, 3, 4 or 5.\n"<<endl;
            break;
    }
    } while (!roomResolved);

    if(a==0)
    {
        room4();
    }
    else
    {
        //room7();
    }

}

//THE THIRD ROOM -> THE FOURTH / THE SEVENTH ROOM

void room4 ()
{
    int ans;
    bool roomResolved = false;
    autosaveGame(4);
    renderHeader("The Mossy Balcony Escape", "Act 1 Room 4");
    
    cout<<Green;
    typewriter(R"(

You grab the cold, rusted drainage pipe and slide down its length. Metal 
groans under your hands until your boots hit solid marble—you drop safely 
onto a wide, open-air balcony protruding from the lower floor.

Thick green moss carpets the stone floor, a massive iron access 
door leads back inside toward the building.

)");
    cout<<Reset;

    voice("Well, that was a wild ride! My hands are still tingling, but look at that view. We landed on a lower balcony.");
    speak("Phew... at least the pipes held. We're much closer to the ground now.");
    think("That slide took serious balance. My instincts kicked in without me even thinking about it.");

    bool doorTried = false;
    bool lockedBoxTried = false;

do
{
    cout << R"(

What will you do now?
1. Try the door that leads inside the building
2. Climb down the balcony to continue down the same pipe
3. Try break open the locked box that rests on the balcony floor (-5HP)
0. View Player Stats

)";

    cin>>ans;

    if (cin.fail()) 
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n[ Please enter a valid number option. ]\n";
        continue;
    } 

    switch(ans)
    {
        case 1:
            if(!doorTried)
            {
                cout<<"You try the door"<<endl;
                speak("The door isn't budging");
                voice("The other side is practically boarded up with vines we won't be able to get through");
            }
            else
            {
                cout<<"You've already tried this"<<endl;
            }
            break;

        case 2:

            cout<<"You climb down the balcony and reach the same pipe"<<endl;
            speak("I'd say im pretty confident with this pipe holding me");
            voice("I'll trust you on this one but I'm still skeptical");
            roomResolved = true;
            break;

        case 3:
            if(!lockedBoxTried)
            {
                cout<<"You smash the locked box into the wall of the building"<<endl;
                speak("OWW!");
                speak("My fingers...");
                cout<<Red<<Bold;
                typewriter("-5 HP, YOU HIT YOUR FINGERS AGAINST BRICK");
                hp -= 5;
                cout<<Reset;
                voice("Look it's open");

                if(intelligence>11)
                {
                    int a = 0;
                    speak("I almost missed it but look there's a pin inside the box");
                    cout<<"PIN has been added to your inventory"<<endl;
                    inventory.push_back("PIN");

                    for(int i = 0; i<inventory.size(); i++)
                    {
                        if(inventory.at(i) == "LOCKED_LOCKET")
                        {
                            speak("And it's just the one that I need to open my locket");
                            cout<<"You unlock the LOCKED LOCKET"<<endl;
                            inventory.at(i) = "UNLOCKED_LOCKET";
                            voice("It's a picture of you and your family... In a garden");
                            speak("I remember now, it's my old house and my family... I still can't really remember them, but it's a work in progress");
                            cout<<Blue<<Bold;
                            typewriter("+1 MEMORY FRAGMENT, YOU UNLOCKED YOUR LOCKET");
                            memoryFragments++;
                            cout<<Reset;
                            a = 1;
                        }
                    }

                    if(a == 0)
                    {
                        think("It might be useful in the future");
                    }
                    
                }
                else
                {
                    speak("There's nothing inside the box");
                    voice("Yh, I guess there is nothing there");
                    think("How strange");
                }
            }
            else
            {
                cout<<"You have already done this"<<endl;
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

    //room5();
}

/*void room7()
{
    int ans;
    bool roomResolved = false;
    autosaveGame(5);
    renderHeader("The OverGrown Corridor", "Act 1 Room 7");
    
    cout<<Green;
    typewriter(R"(

You step through the shattered glass into a cavernous, dark office floor. 
Desk chairs are overturned, and thick blankets of ivy crawl across the 
cracked linoleum floor, choking the life out of old computer terminals.

A flickering emergency light casts long, eerie shadows down a long 
corridor that leads deeper into the building's core.

)");
    cout<<Reset;

    voice("Well, we're inside. It's darker than I'd like, but at least we're out of the wind.");
    speak("It feels like stepping into a tomb. Watch where you step.");

    bool deskSearched = false;

    do
    {
        cout << R"(

What will you do now?
1. Follow the dark corridor deeper into the building's interior
2. Search through the drawers of an old reception desk half-buried in vines
3. Ask the voice if they hear that strange scratching sound coming from the ceiling
0. View Player Stats

)";

        cin >> ans;

        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n[ Please enter a valid number option. ]\n";
            continue;
        }

    switch(ans)
    {
        case 1:
            
            break;

        case 2:

            break;

        case 3:

            break;
            

        case 0:
            stats();
            break;

        default:
            cout << "\nPlease enter 0, 1, 2, 3, 4 or 5.\n"<<endl;
            break;
    }

    } while (!roomResolved);

    //room6();    
}
*/
void stats()      
{
    cout<<Green<<'\n'<<"===== PLAYER STATS ====="<<endl;
    cout<<"Hp = "<<hp<<endl;
    cout<<"Strength = "<<strength<<endl;
    cout<<"Intelligence = "<<intelligence<<endl;
    cout<<"Agility = "<<agility<<endl;
    cout<<"Memory Fragments = "<<memoryFragments<<"/5"<<endl;
    cout<<"Inventory : ";
    if (inventory.empty())
    {
        cout<<"[EMPTY]"<<endl;
        cout<<"===== END OF STATS ====="<<'\n'<<Reset<<endl;
    }
    else
    {
        for(int i = 0; i<inventory.size(); i++)
        {
            cout<<inventory.at(i)<<" ";
        }

        cout<<'\n'<<"===== END OF STATS ====="<<Reset<<endl;
    }
    
}

// DISPLAY STATS

void voice(string text) 
{
    cout<<Yellow;
    typewriter("[*VOICE*]: '" + text + "'");
    cout<<Reset;
}

// VOICE IN YOUR HEAD SPEAKING

void speak(string text)
{
    cout<<Cyan;
    typewriter("[YOU]: '" + text + "'");
    cout<<Reset;
}

// YOU SPEAKING 

void think(string text)
{
    cout<<Magenta;
    typewriter("[YOU think]: '" + text + "'");
    cout<<Reset;
}

// YOU THINKING

void character(string name, string text)
{
    typewriter("[" + name + "]" + " '" + text + "'");
}

// ANY OTHER CHARACTER SPEAKING

void renderHeader(string roomTitle, string actRoom)
{
    cout<<Green<<Bold;
    cout<<"======================================================================"<<endl;
    typewriter("             THE LOST CITY OF OLD YORK - " + actRoom);
    typewriter("                     " + roomTitle);
    cout<<"======================================================================"<<endl;
    cout<<Reset;
}

//DISPLAYS THE HEADER FOR EVERY ROOM

void typewriter(string text, int delayMs)
{
    for(char c : text)
    { 
        cout<<c<<flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }

    cout<<endl;
}

//ADDS DELAY TO EACH CHARACTER BEING TYPED

void autosaveGame(int roomNumber)
{
    ofstream saveFile("autosave.txt");

    if(saveFile.is_open())
    {
        saveFile<<roomNumber<<endl;
        saveFile<<hp<<" "<<strength<<" "<<intelligence<<" "<<agility<<" "<<memoryFragments<<endl;
        
        if(inventory.empty())
        {
            saveFile<<"0"<<endl;
        }
        else
        {
            saveFile<<inventory.size()<<" ";

            for(int i = 0; i<inventory.size(); i++)
            {
                saveFile<<inventory.at(i)<<" ";
            }
        }

        saveFile.close();
        
    }
    else
    {
        cout<<Red<<Bold<<"ERROR, FILE CANNOT BE OPENED"<<Reset;
    }
}

void loadGame()
{
    int temp = 0;
    ifstream inFile("autosave.txt");
    
    if(inFile.is_open() && inFile.peek() != EOF)
    {
        inFile>>loadedRoom;
        inFile>>hp;
        inFile>>strength;
        inFile>>intelligence;
        inFile>>agility;
        inFile>>memoryFragments;
        inFile>>temp;

        if(temp!=0)
        {
            for(int i = 0; i<temp; i++)
            {
                string item;
                inFile>>item;
                inventory.push_back(item);
            }
        }

        switch (loadedRoom)
        {
            case 1:
                start();
                break;

            case 2:
                room2();
                break;

            case 3:
                room3();
                break;

            case 4:
                room4();
                break;
            
            default:
                intro();
                break;
        }
    }
    else
    {
        cout<<Red<<Bold<<"ERROR, FILE CANNOT BE OPENED OR FILE IS EMPTY"<<Reset;
    }

}

//SAVES YOUR STATS TO A TXT FILE

int main()
{
    intro();
    
}
 