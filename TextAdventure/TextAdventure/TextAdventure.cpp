
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void clearTitleScreen();
string name;




int main() {
    clearTitleScreen();
    cout << ".....                                                ..       .x+=:.                                    s                                  ....      ..\n";
    cout << " .H8888888h.  ~-.                                  . uW8\"        z`    ^%                    oec :         :8      .uef^\"                    +^\"\"888h. ~\"888h     .uef^\"                                                       .uef^\"    \n";
    cout << " 888888888888x  `>        u.      ..    .     :    `t888            .   <k           u.     @88888        .88    :d88E                      8X.  ?8888X  8888f  :d88E                      .u    .                      u.   :d88E       \n";
    cout << "X~     `?888888hx~  ...ue888b   .888: x888  x888.   8888   .      .@8Ned8\"     ...ue888b    8\"*88%       :888ooo `888E            .u       '888x  8888X  8888~  `888E             u      .d88B :@8c        u      ...ue888b  `888E       \n";
    cout << "'      x8.^\"*88*\"   888R Y888r ~`8888~'888X`?888f`  9888.z88N   .@^%8888\"      888R Y888r   8b.        -*8888888  888E .z8k    ud8888.     '88888 8888X   \"88x:  888E .z8k     us888u.  =\"8888f8888r    us888u.   888R Y888r  888E .z8k  \n";
    cout << "'      x8.^\"*88*\"   888R Y888r ~`8888~'888X`?888f`  9888.z88N   .@^%8888\"      888R Y888r   8b.        -*8888888  888E .z8k    ud8888.     '88888 8888X   \"88x:  888E .z8k     us888u.  =\"8888f8888r    us888u.   888R Y888r  888E .z8k  \n";
    cout << " `-:- X8888x        888R I888>   X888  888X '888>   9888  888E x88:  `)8b.     888R I888>  u888888>      8888     888E~?888L :888'8888.     `8888 8888X  X88x.   888E~?888L .@88 \"8888\"   4888>'88\"  .@88 \"8888\"  888R I888>  888E~?888L \n";
    cout << "      488888>       888R I888>   X888  888X '888>   9888  888E 8888N=*8888     888R I888>   8888R        8888     888E  888E d888 '88%\"       `*` 8888X '88888X  888E  888E 9888  9888    4888> '    9888  9888   888R I888>  888E  888E \n";
    cout << "    .. `\"88*        888R I888>   X888  888X '888>   9888  888E  %8\"    R88     888R I888>   8888P        8888     888E  888E 8888.+\"         ~`...8888X  \"88888  888E  888E 9888  9888    4888>      9888  9888   888R I888>  888E  888E \n";
    cout << "  x88888nX\"      . u8888cJ888    X888  888X '888>   9888  888E   @8Wou 9%     u8888cJ888    *888>       .8888Lu=  888E  888E 8888L            x8888888X.   `%8\"  888E  888E 9888  9888   .d888L .+   9888  9888  u8888cJ888   888E  888E \n";
    cout << " !\"*8888888n..  :   \"*888*P\"    \"*88%\"\"*88\" '888!` .8888  888\" .888888P`       \"*888*P\"     4888        ^%888*    888E  888E '8888c. .+      '%\"*8888888h.   \"   888E  888E 9888  9888   ^\"8888*\"    9888  9888   \"*888*P\"    888E  888E \n";
    cout << "'    \"*88888888*      'Y\"         `~    \"    `\"`    `%888*%\"   `   ^\"F           'Y\"        '888          'Y\"    m888N= 888>  \"88888%        ~    888888888!`   m888N= 888> \"888*\"\"888\"     \"Y\"      \"888*\"\"888\"    'Y\"      m888N= 888> \n";
    cout << "        ^\"***\"`                                        \"`                                    88R                  `Y\"   888     \"YP'              X888^\"\"\"       `Y\"   888   ^Y\"   ^Y'                ^Y\"   ^Y'               `Y\"   888  \n";
    cout << "                                                                                             88>                       J88\"                       `88f                J88\"                                                         J88\"  \n";
    cout << "                                                                                             48                        @%                          88                 @%                                                           @%    \n";
    cout << "                                                                                             '8                      :\"                            \"\"               :\"                                                           :\"       \n";
    
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n"; 
   
    cout << "Embark on an epic adventure in ancient Egypt in this text adventure game, where you play as a daring tomb raider exploring the depths of long-forgotten pyramids." << endl;
    cout << "Face deadly traps, and unearth priceless treasures as you navigate through dark, mysterious corridors." << endl; // Intro description
    cout << "Your choices will determine your fate - will you emerge with riches or fall victim to the ancient curses that guard the Pharaoh's secrets?" << endl;
    cout << "\n"; // Clearing lines
    cout << "Enter your name, brave explorer: " << endl; // Player enters name
    cin >> name;
    cout << "\n";
    cout << "Welcome, " << name << ", and good luck." << endl;
    cout << "\n";
    cout << "\n";
   
    // Game starts, short description of intro room, offers the player the choice of where to navigate - back, forward, left, right
   
    // Back - DEATH (pointless decision)
   
    // Right - Subterranean Chamber - loot option, gives player the idol for later use with guess of weight (used later) - COLLECTIBLE ITEM
   
    // Left - Queen's Chamber - enemy to fight that could follow the player if ignored - HEALTH AND COMBAT SYSTEMS
  
    // Forward - Grand Gallery - trap for the player to navigate (careful or quick choices), with risk to health or torch lifespan - LINEAR PROGRESSION
    // If the trap results in death - BACK TO START SCREEN
   
    // Forward (after Grand Gallery) - King's Chamber - player uses idol to open door if they have it, if not then they can attempt to use a bag of sand BUT they must guess the correct weight (0-10)kg - GUESSING MECHANIC
    // If they DO NOT have the idol then they can attempt to use a bag of sand BUT they must guess the correct weight (0-10)kg - so likely die - BACK TO START SCREEN
    // If they DO have the idol - VICTORY SCREEN









}


void clearTitleScreen()
{
}
