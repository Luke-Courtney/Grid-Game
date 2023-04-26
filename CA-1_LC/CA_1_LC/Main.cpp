//Luke Courtney
//GameplayProgramming Y2S2 CA1
//Player controls 'o' on the game board and must move using N,S,E,W to reach the crown 'M'
//Player must avoid contact with enemies 'x'. Enemies move vertically in columns.
//If player hits an enemy, two 20 sided dice are rolled, one for the player and one for the enemy
//If the player rolls higher, the enemy dies
//If the enemy rolls higher, the player gets hit for damage equal to that of 3x the enemies speed

#include "GameCharacter.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"
int main()
{ 
    //Creating game object and initializing
    Game g1;
    g1.init();

    bool running = true; //Game will end if set to false

    while(running)
    {
        //Printing the menu
        g1.menu();

        //Taking input
        char userIn = ' ';
        cin >> userIn;

        //Responding to user input
        switch (userIn)
        {
            case '1': // Print main menu
                cout << "\nStarting game\n" << endl;
                break;

            case '2': //Print rules menu
                g1.rules();
                cout << "\n" << endl;
                break;

            case '3': //Quit game
                cout << "\nQuitting game" << endl;
                exit(0);
                break;

            default: //Default case
                cout << "\nInvalid entry" << endl;
                
        }

        //Looping battle, draw, update 25 times
        for (int i = 0; i < 15; i++)
        {
            g1.battle();
            g1.draw();
            g1.update();
            cout << "Turns remaining: " << (25 - i) << "\n" << endl; //Printing out turns remaining
        }//End game loop

        //Asking user if they want to play again
        cout << "\n Play again? " << endl;
        cout << "      [y/n]  " << endl;
        cin >> userIn;

        if ((char)tolower(userIn) == 'n') { //Setting running to false if the user says no
            running = false;
        }
    }
        
    
    return 0;
}