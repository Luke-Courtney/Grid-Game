#pragma once
#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#include <iostream>

using namespace std;

class GameCharacter
{

protected:
    std::string m_typeID;
    int m_health; //Health value. This will be generated randomly
    int m_speed; //Speed value. This will be generated randomly
    int m_x; //X position
    int m_y; //Y position

public:
    void spawn(std::string typeID, int health, int speed, int x, int y); // create an object
    void render();         // print to the screen the typeID and its x and y coords
    virtual void update(); //virtual function
    void stats();          // print all stats relating to the object
    bool isAlive();        //return true if its health is greater than 0

    int getX();
    int getY();
    int getHealth();

    void setHealth(int newHealth);
    void takeDamage(int damage);
};
#endif