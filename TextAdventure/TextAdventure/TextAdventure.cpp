#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
using namespace std;




int main() {

    string name;
    bool hasIdol = false;

    int torchDurability = 100; // Torch durability

    // Title Art
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

    // Locations
    Location entranceChamber = Location("Entrance Chamber", "A shrill cold passes through you, chilling you to the bones.", "Go to the Entrance Chamber");
    Location queensChamber = Location("Queen's Chamber", "You traverse a narrow passageway leading to the Queen's Chamber, the air is thick with mystery and the walls seem to whisper secrets of ancient royalty.", "Go to the Queen's Chamber.");
    Location grandGallery = Location("Grand Gallery", "Its towering walls stretch above you, echoing the footsteps of those long gone, a sense of wonder and awe fills you.", "Go to the Grand Gallery.");
    Location subterraneanChamber = Location("Subterranean Chamber", "You descend into the depths of the pyramid, reaching the Subterranean Chamber, it feels as though something ancient watches you from the shadows.", "Go to the Subterranean Chamber.");
    Location kingsChamberHallway = Location("hallway to the King's Chamber", "Some of the floor tiles seem out of place, could there be a trap lying ahead?", "Go to the hallway to the King's Chamber.");
    Location kingsChamberDoor = Location("doorway to the King's Chamber", "A pedestal is laid bare before you, you think to yourself: Was there anything in the Queen's Chamber meant for this?", "Go to the doorway of the King's Chamber.");
    Location kingsChamber = Location("King's Chamber", "The door opens to reveal the mounds of treasure left behind by the pharaoph.", "Congratulations " + name + " You win, enjoy your new-found riches! Game over.");


    // Pathways between locations
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


    // Keeps track of the players' current location
    Location* currentLocation = &entranceChamber;
    int userinput;

    // Introduction
    cout << "Enter your name, brave explorer: \n";
    cin >> name;
    cout << "Welcome " << name << "!";
    cout << "\n";
    cout << "After weeks of traveling, you finally stand at the foot of the Great Pyramid. \n";
    cout << "The relentless desert sun beats down on you, and the pyramid seems like the only refuge. \n";
    cout << "Legends speak of mysteries hidden deep within these ancient stones. \n";
    cout << "You steel yourself and step into the shadowed entrance. \n";


    // Game loop - Tells player where they are and where they can go
    while(true) {
        cout << "========================================" << endl;
        cout << "You are in the " << currentLocation->getName() << endl;
        cout << currentLocation->getDescription() << endl;

        // Player choice
        cout << "What shall you do?:" << endl;
        for (int i = 0; i < currentLocation->getPathways().size(); i++) {
            cout << "[" << i << "]" << " " << currentLocation->getPathways()[i]->getFarDescription() << endl;
        }

        

        // Player interactions for locations
        if (currentLocation == &queensChamber) {
            cout << "Or: There is a vase in the corner of the room with the lid ajar. " << endl;
            cout << "[" << currentLocation->getPathways().size() << "] " << "Search the vase" << endl;
        } 


        cout << ">>>";
        cin >> userinput;

        // Inputting 1 brings up the invalid message
        
        
        
        



        
        if (userinput == currentLocation->getPathways().size()) {

          cout << "You open the vase to reveal a golden idol. Pocketing it, you feel it may have some importance... " << endl;



        }
       
        
        // King's Chamber hallway - trap with % chance of killing the player
        // King's Chamber doorway - reference to the idol and checks the player inventory
        


        // Ensures the program does not get stuck in a loop if an incorrect input is entered 
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "You stand still, uncertain of which path to take. Perhaps you should choose one of the available chambers. \n";
            cout << "What shall you do?:" << endl;
            for (int i = 0; i < currentLocation->getPathways().size(); i++) {
                cout << "[" << i << "]" << " " << currentLocation->getPathways()[i]->getFarDescription() << endl;
            }
            cout << ">>>";
            cin >> userinput;
            continue;
        }

        if (userinput >= 0 && userinput < currentLocation->getPathways().size()) {
            currentLocation = currentLocation->getPathways()[userinput];
            system("cls");
        }
        // if the player inputs an incorrect number/letter
        else {
            system("cls");
            cout << "You stand still, uncertain of which path to take. Perhaps you should choose one of the available chambers. \n" << endl;
            cout << "What shall you do?:" << endl;
            for (int i = 0; i < currentLocation->getPathways().size(); i++) {
                cout << "[" << i << "]" << " " << currentLocation->getPathways()[i]->getFarDescription() << endl;
            }
            cout << ">>>";
            cin >> userinput;
        }


        // Torch (active)
        cout << "Torch durability: " << torchDurability << "% \n";


        // Ends the game if the torch is depleted
        if (torchDurability <= 0) {
            cout << "Your torch flickers one last time and goes out, leaving you in complete darkness. \n";
            cout << "Without light, you can no longer continue your adventure. \n";
            cout << "Game Over.";
            break;
        }


        
        
        

        // Reduces torch durability after each choice
        torchDurability -= 5;

        cout << "The adventure continues... \n";

    }
    return 0;
}





