#ifndef GAME_H
#define GAME_H
#include "Enemy.h"
#include "Player.h"
#include "Crown.h"
#include "GameCharacter.h"
#include <list>
#pragma once
class Game : public GameCharacter
{
	public:
		void init();	//Create and assign values to objects (Health, position etc)
		void render();	//Cycle through the list of GameCharacter and call the render function for each object
		void update();	//Cycle through the list of GameCharacter and call the update function for each object
		void battle();	//Check the list to see if two objects occupy the same coords declare that a battle must take place
		void stats();	//Cycle through the list of GameCharacters and call the stats function for each object
		void clean();	//remove any objects from the list whose health is
		void draw();	//Draw game board to screen
		void menu();	//Prints the main menu
		void rules();	//Prints rules


	protected:
		GameCharacter* User;
		GameCharacter* enemy1;
		GameCharacter* enemy2;
		GameCharacter* enemy3;
		GameCharacter* enemy4;
		GameCharacter* enemy5;
		GameCharacter* enemy6;
		GameCharacter* enemy7;
		GameCharacter* enemy8;
		GameCharacter* crown1;
		list<GameCharacter*> characterList; //created a list of Creature pointers
		list<GameCharacter*> cleanList; //List used to create new characterList minus dead characters

};
#endif