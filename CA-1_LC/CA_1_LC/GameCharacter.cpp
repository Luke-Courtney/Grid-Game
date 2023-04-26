#include "GameCharacter.h"

//Spawn function
//Takes in typeID, Health, Speed, X/Y position
void GameCharacter::spawn(std::string typeID, int health, int speed, int x, int y)
{
	//Setting TypeID, Health, speed, X and Y values.
	m_typeID = typeID;
	m_health = health;
	m_speed = speed;
	m_x = x;
	m_y = y;
}

// print to the screen the typeID and its x and y coords
void GameCharacter::render()
{
	cout << "TypeID: " << m_typeID << "\nX: " << m_x << "\tY: " << m_y << "\n\n";
}

//virtual function
void GameCharacter::update()
{
}

// print all stats relating to the object
void GameCharacter::stats()
{
	cout << "Health: " << m_health << "\nSpeed: " << m_speed << "\nX: " << m_x << "\tY: " << m_y << endl;
}

//return true if its health is greater than 0
bool GameCharacter::isAlive()
{
	if (m_health > 0)
	{
		return true;
	}
	else {
		return false;
	}
}

//Get x, y and health 
int GameCharacter::getX()
{
	return m_x;
}

int GameCharacter::getY()
{
	return m_y;
}

int GameCharacter::getHealth()
{
	return m_health;
}

//Set health
void GameCharacter::setHealth(int newHealth)
{
	m_health = newHealth;
}

void GameCharacter::takeDamage(int damage)
{
	m_health = m_health - damage;
}