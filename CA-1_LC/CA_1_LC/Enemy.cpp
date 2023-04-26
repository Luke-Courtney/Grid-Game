#include "Enemy.h"

void Enemy::update()
{
    //Generating random number from 1 to 10
    int randNum = (rand() % 10) + 1;

    //Checking if randNum value is less than 9
    //If it is, enemy moves by 1
    if (randNum < 9)
    {
        //Generating a new random number to decide movement direction
        randNum = (rand() % 10) + 1;

        //if randNum is greater than 4, enemy moves up, else down
        if (randNum > 4)
        {
            //Checking if moving up would go over edge of play area. (10x10 grid)
            //If so, moves down instead and subtract from health
            if (m_y + 1 >= 10)
            {
                //If over edge
                m_y = m_y - 1; //Moving down instead
                m_health = m_health - m_speed * 3; //Subtracting from health
            }
            else {
                //If in bounds
                m_y = m_y + 1;
            }
        }
        else {
            //Checking if moving down would go over edge of play area. (10x10 grid)
            //If so, moves up instead and subtract from health
            if (m_y - 1 < 0)
            {
                //If over edge
                m_y = m_y + 1; //Moving up instead
                m_health = m_health - m_speed * 3; //Subtracting from health
            }
            else {
                //If in bounds
                m_y = m_y - 1;
            }
        }

    }
}