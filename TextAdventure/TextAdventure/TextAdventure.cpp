#include <iostream> 
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <conio.h>
#include <thread>
#include <limits>
#include "Location.h"

using namespace std;

void titleText();
void delay(int seconds);
bool hasIdol = false;
bool hasFoundHiddenTreasure = false;

int main() {
    srand(time(0));
    string name;
    int torchDurability = 100;

    titleText();

    // Locations
    Location entranceChamber("Entrance Chamber.", "A shrill cold passes through you, chilling you to the bones.", "Go to the Entrance Chamber");
    Location queensChamber("Queen's Chamber.", "You traverse a narrow passageway, whispers of royalty fill the air.", "Go to the Queen's Chamber.");
    Location grandGallery("Grand Gallery.", "Towering walls echo ancient footsteps. Awe surrounds you.", "Go to the Grand Gallery.");
    Location subterraneanChamber("Subterranean Chamber.", "You descend deep. It feels like something ancient is watching.", "Go to the Subterranean Chamber.");
    Location kingsChamberHallway("hallway to King's Chamber.", "The floor tiles look off, could be a trap.", "Go to the hallway to the King's Chamber.");
    Location kingsChamberDoor("doorway to King's Chamber.", "A pedestal awaits.", "Go to the doorway of the King's Chamber.");
    Location kingsChamber("King's Chamber.", "The door opens revealing mounds of treasure!", "Enter the King's Chamber.");

    // Pathways
    entranceChamber.addPathway(queensChamber);
    entranceChamber.addPathway(grandGallery);
    entranceChamber.addPathway(subterraneanChamber);
    entranceChamber.addPathway(kingsChamberHallway);

    queensChamber.addPathway(entranceChamber);
    grandGallery.addPathway(entranceChamber);
    subterraneanChamber.addPathway(entranceChamber);
    kingsChamberHallway.addPathway(entranceChamber);
    kingsChamberHallway.addPathway(kingsChamberDoor);
    kingsChamberDoor.addPathway(kingsChamberHallway);
    kingsChamberDoor.addPathway(kingsChamber);

    Location* currentLocation = &entranceChamber;
    int userinput = -1;
    int keypressInp;

    // Intro
    cout << "Enter your name, brave explorer!:  \n";
    delay(1.5);
    cin >> name;
    delay(1.5);
    cout << "Welcome, " << name << " to... \n";
    delay(2);
    cout << "Tombs Of The Pharaoh! \n";
    delay(1.5);
    cout << "Your objective is to navigate the perilous pyramid and make it out alive with the treasure. \n";
    delay(1.5);
    cout << "Press ANY KEY to continue, if you dare: \n";
    keypressInp = _getch();
    system("cls");
    titleText();
    delay(1);
    cout << "After weeks of travelling, you finally stand at the foot of the Great Pyramid. \n";
    delay(1.5);
    cout << "The relentless desert sun beats down on you, and the pyramid seems like the only refuge. \n";
    delay(1.5);
    cout << "Legends speak of mysteries hidden deep within these ancient stones. \n";
    delay(1.5);
    cout << "You steel yourself and step into the shadowed entrance. \n";
    delay(1.5);

    // Main game loop
    while (true) {
        cout << "========================================\n";
        cout << "You are in the " << currentLocation->getName() << "\n";
        cout << currentLocation->getDescription() << "\n";

        // Pathway options
        for (int i = 0; i < currentLocation->getPathways().size(); i++) {
            cout << "[" << i << "] " << currentLocation->getPathways()[i]->getFarDescription() << "\n";
        }

        // Special room actions
        if (currentLocation == &queensChamber) {
            cout << "[" << currentLocation->getPathways().size() << "] Search the vase\n";
        }
        else if (currentLocation == &grandGallery) {
            cout << "[" << currentLocation->getPathways().size() << "] Examine ancient symbols\n";
        }
        else if (currentLocation == &subterraneanChamber) {
            cout << "[" << currentLocation->getPathways().size() << "] Investigate the cold draft\n";
        }

        cout << ">>> ";
        cin >> userinput;

        // Input validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Perhaps you should choose one of the options presented.\n";
            continue;
        }

        // Special room actions handling
        if (currentLocation == &queensChamber && userinput == currentLocation->getPathways().size()) {
            if (hasIdol) {
                cout << "The vase is empty. You already took the idol.\n";
            }
            else {
                cout << "You find a golden idol inside the vase. You take it.\n";
                hasIdol = true;
            }
            system("pause");
            system("cls");
            titleText();
            continue;
        }
        else if (currentLocation == &grandGallery && userinput == currentLocation->getPathways().size()) {
            cout << "You study the ancient symbols. You feel a strange connection to the builders of this pyramid.\n";
            // Random chance for hidden treasure
            if (!hasFoundHiddenTreasure && (rand() % 5 == 0)) {
                cout << "Behind a loose brick, you find a hidden pouch of emeralds!\n";
                hasFoundHiddenTreasure = true;
            }
            system("pause");
            system("cls");
            titleText();
            continue;
        }
        else if (currentLocation == &subterraneanChamber && userinput == currentLocation->getPathways().size()) {
            cout << "You approach the crack in the wall cautiously. Inside, you find a set of flint and steel! (+15% torch durability)\n";
            torchDurability += 15;
            if (torchDurability > 100) torchDurability = 100;
            system("pause");
            system("cls");
            titleText();
            continue;
        }

        // Movement handling
        if (userinput >= 0 && userinput < currentLocation->getPathways().size()) {
            Location* nextLocation = currentLocation->getPathways()[userinput];

            // King's Chamber access check/Locked or impassable object
            if (currentLocation == &kingsChamberDoor && nextLocation == &kingsChamber) {
                if (!hasIdol) {
                    cout << "You need to place something on the altar to enter. Maybe one of the other chambers has what you need?\n";
                    system("pause");
                    system("cls");
                    titleText();
                    continue;
                }
                else {
                    cout << "The idol glows... You place it on the pedestal. The door opens.\n";
                    system("pause");
                    system("cls");
                    titleText();
                }
            }

            // Win condition
            if (nextLocation == &kingsChamber) {
                cout << nextLocation->getDescription() << "\n";
                cout << "Congratulations, " << name << "! You have claimed the treasures of the Pharaoh!\n";
                break;
            }

            currentLocation = nextLocation;
            system("cls");
            titleText();
        }
        else {
            cout << "That path doesn't exist. Try again.\n";
            continue;
        }

        // Trap event in hallway
        if (currentLocation == &kingsChamberHallway) {
            int trapChance = rand() % 4;
            if (trapChance == 0) {
                cout << "A tile shifts under your feet. SPIKES! You fall into a trap. Game Over.\n";
                break;
            }
            else {
                cout << "You set off no traps and proceed carefully.\n";
            }
        }

        // Event in Subterranean Chamber
        if (currentLocation == &subterraneanChamber && rand() % 6 == 0) {
            cout << "You hear a faint whisper... but no one is there.\n";
        }

        // Torch durability system/Lose condition
        torchDurability -= 5;
        cout << "Torch durability: " << torchDurability << "%\n";

        if (torchDurability <= 30 && torchDurability > 0) {
            cout << "Your torch flickers dangerously...\n";
        }

        if (torchDurability <= 0) {
            cout << "Your torch goes out. Darkness surrounds you.\n";
            cout << "Without any light, you can't continue. Game Over.\n";
            break;
        }

        cout << "The adventure continues...\n";
    }

    return 0;
}

// Delay
void delay(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

// Title Art Function
void titleText() {
    
    


        cout << ".....                                                ..       .x+=:.                                    s                                  ....      ..\n";
        cout << " .H8888888h.  ~-.                                  . uW8\"        z`    ^%                    oec :         :8      .uef^\"                    +^\"\"888h. ~\"888h     .uef^\"                                                       .uef^\"    \n";
        cout << " 888888888888x  `>        u.      ..    .     :    `t888            .   <k           u.     @88888        .88    :d88E                      8X.  ?8888X  8888f  :d88E                      .u    .                      u.   :d88E       \n";
        cout << "X~     `?888888hx~  ...ue888b   .888: x888  x888.   8888   .      .@8Ned8\"     ...ue888b    8\"*88%       :888ooo `888E            .u       '888x  8888X  8888~  `888E             u      .d88B :@8c        u      ...ue888b  `888E       \n";
        cout << "'      x8.^\"*88*\"   888R Y888r ~`8888~'888X`?888f`  9888.z88N   .@^%8888\"      888R Y888r   8b.        -*8888888  888E .z8k    ud8888.     '88888 8888X   \"88x:  888E .z8k     us888u.  =\"8888f8888r    us888u.   888R Y888r  888E .z8k  \n";
        cout << " `-:- X8888x        888R I888>   X888  888X '888>   9888  888E x88:  `)8b.     888R I888>  u888888>      8888     888E~?888L :888'8888.     `8888 8888X  X88x.   888E~?888L .@88 \"8888\"   4888>'88\"  .@88 \"8888\"  888R I888>  888E~?888L \n";
        cout << "      488888>       888R I888>   X888  888X '888>   9888  888E 8888N=*8888     888R I888>   8888R        8888     888E  888E d888 '88%\"       `*` 8888X '88888X  888E  888E 9888  9888    4888> '    9888  9888   888R I888>  888E  888E \n";
        cout << "    .. `\"88*        888R I888>   X888  888X '888>   9888  888E  %8\"    R88     888R I888>   8888P        8888     888E  888E 8888.+ ~`...8888X  \"88888  888E  888E 9888  9888    4888>      9888  9888   888R I888>  888E  888E \n";
        cout << "  x88888nX\"      . u8888cJ888    X888  888X '888>   9888  888E   @8Wou 9%     u8888cJ888    *888>       .8888Lu=  888E  888E 8888L            x8888888X.   `%8\"  888E  888E 9888  9888   .d888L .+   9888  9888  u8888cJ888   888E  888E \n";
        cout << " !\"*8888888n..  :   \"*888*P\"    \"*88%\"\"*88\" '888!` .8888  888\" .888888P`       \"*888*P\"     4888        ^%888*    888E  888E '8888c. .+      '%\"*8888888h.   \"   888E  888E 9888  9888   ^\"8888*\"    9888  9888   \"*888*P\"    888E  888E \n";
        cout << "'    \"*88888888*      'Y\"         `~    \"    `\"`    `%888*%\"   `   ^\"F           'Y\"        '888          'Y\"    m888N= 888>  \"88888%        ~    888888888!`   m888N= 888> \"888*\"\"888\"     \"Y\"      \"888*\"\"888\"    'Y\"      m888N= 888> \n";
        cout << "        ^\"***\"`                                        \"`                                    88R                  `Y\"   888     \"YP'              X888^\"\"\"       `Y\"   888   ^Y\"   ^Y'                ^Y\"   ^Y'               `Y\"   888  \n";
        cout << "                                                                                             88>                       J88\"                       `88f                J88\"                                                         J88\"  \n";
        cout << "                                                                                             48                        @%                          88                 @%                                                           @%    \n";
        cout << "                                                                                             '8                      :\"                            \"\"               :\"                                                           :\"       \n";


   

}
