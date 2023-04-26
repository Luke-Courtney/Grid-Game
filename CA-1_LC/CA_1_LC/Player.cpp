#include "Player.h"

//Checks if player is alive, if not, game ends
//Prompts user to input direction and takes input
//Updates player coordinates
//Damages player if they hit the perimiter
//Prints current coordinates and health
void Player::update()
{
    //Checking if player has died
    if (isAlive() != true)
    {
        cout << "]---[ You have died! ]---[" << endl;
        exit(0);
    }

    //Asking for and reading in input
    char inputDir = ' '; //Char for input direction
    cout << "\nInput movement direction. [N,S,E,W]" << endl; //Asking for input
    cin >> inputDir; //Taking input

    inputDir = tolower(inputDir); //Converting entry to lowercase

    //Switch statement to handle user input
    switch (inputDir)
    {
    case ('n'): //North
        m_y++; //Increasing Y value
        break;

    case ('s'): //South
        m_y--; //Decreasing Y value
        break;

    case ('e'): //East
        m_x++; //Increasing X value
        break;

    case ('w'): //West
        m_x--; // Decreasing X value
        break;

    default:
        cout << "Invalid Entry. \n User must enter N, S, E, or W" << endl;
    }


    //Handling perimiter collisions
    //Top/Bottom collisions
    if (m_y >= 10)
    {
        m_y--;      //decrimenting Y
        m_health = m_health - m_speed*2; //decrimenting health
    }
    else if (m_y < 0)
    {
        m_y++;      //Incrementing Y
        m_health = m_health - m_speed * 2;; //decrimenting health
    }

    //Left/Right collisions
    if (m_x >= 10)
    {
        m_x--;      //decrimenting X
        m_health = m_health - m_speed * 2;; //decrimenting health
    }
    else if (m_x < 0)
    {
        m_x++;      //Incrementing X
        m_health = m_health - m_speed * 2;; //decrimenting health
    }

    cout << "---------------------------" << endl;
    cout << "X: " << m_x << "  Y: " << m_y << "  Health: " << m_health << endl;
}