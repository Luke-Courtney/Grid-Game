#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Crown.h"
#include "GameCharacter.h"
#include <iostream>

//Create and assign values to objects (Health, position etc)
//Creating:
	//1 Player
	//8 Enemies
void Game::init()
{
	cout << "Initializing";

	//Creating seed for RNG from time
	srand(time(0)); 

	//Creating player object and pointer
	User = new Player(); //Create pointer new Player object called User
	int randHealth = (rand() % 30) + 140;  //Creating random health value between 140 & 170
	int randSpeed = (rand() % 3) + 2;	   // Creating random speed value between 2 and 4
	User->spawn("Player_1", randHealth, randSpeed, 0, 0);	//Spawning user at (0,0) with Health between 140 & 170, a speed between 2 & 4 and a Unique ID

	//Creating Enemy objects and pointers.
	//Spawning enemies with random health between 90 & 150 and speed between 1 & 3
	enemy1 = new Enemy(); //Enemy 1
	randHealth = (rand() % 30) + 90;
	randSpeed = (rand() % 3) + 1;
	int randY = (rand() % 10);
	enemy1->spawn("Enemy_1", randHealth, randSpeed, 1, randY); //Enemy_1 at (1,rand)

	enemy2 = new Enemy(); //Enemy 2
	randHealth = (rand() % 30) + 90;
	randSpeed = (rand() % 3) + 1;
	randY = (rand() % 10);
	enemy2->spawn("Enemy_2", randHealth, randSpeed, 2, randY); //Enemy_2 at (2,rand)

	enemy3 = new Enemy(); //Enemy 3
	randHealth = (rand() % 30) + 90;
	randSpeed = (rand() % 3) + 1;
	randY = (rand() % 10);
	enemy3->spawn("Enemy_1", randHealth, randSpeed, 3, randY); //Enemy_3 at (3,rand)

	enemy4 = new Enemy(); //Enemy 4
	randHealth = (rand() % 30) + 90;
	randSpeed = (rand() % 3) + 1;
	randY = (rand() % 10);
	enemy4->spawn("Enemy_4", randHealth, randSpeed, 4, randY); //Enemy_4 at (4,rand)

	enemy5 = new Enemy(); //Enemy 5
	randHealth = (rand() % 30) + 90;
	randSpeed = (rand() % 3) + 1;
	randY = (rand() % 10);
	enemy5->spawn("Enemy_5", randHealth, randSpeed, 5, randY); //Enemy_5 at (5,rand)

	enemy6 = new Enemy(); //Enemy 6
	randHealth = (rand() % 30) + 90;
	randSpeed = (rand() % 3) + 1;
	randY = (rand() % 10);
	enemy6->spawn("Enemy_4", randHealth, randSpeed, 6, randY); //Enemy_6 at (6,rand)

	enemy7 = new Enemy(); //Enemy 7
	randHealth = (rand() % 30) + 90;
	randSpeed = (rand() % 3) + 1;
	randY = (rand() % 10);
	enemy7->spawn("Enemy_4", randHealth, randSpeed, 7, randY); //Enemy_7 at (7,rand)

	enemy8 = new Enemy(); //Enemy 8
	randHealth = (rand() % 30) + 90;
	randSpeed = (rand() % 3) + 1;
	randY = (rand() % 10);
	enemy8->spawn("Enemy_4", randHealth, randSpeed, 8, randY); //Enemy_8 at (8,rand)

	crown1 = new Crown(); //Crown
	randY = (rand() % 10);
	crown1->spawn("Crown1", 999, 999, 9, randY); //Crown at (9,rand)

	characterList.push_back(User);
	characterList.push_back(enemy1);
	characterList.push_back(enemy2);
	characterList.push_back(enemy3);
	characterList.push_back(enemy4);
	characterList.push_back(enemy5);
	characterList.push_back(enemy6);
	characterList.push_back(enemy7);
	characterList.push_back(enemy8);
	characterList.push_back(crown1);

	list<GameCharacter*>::const_iterator iter; //Remove when working
	for (iter = characterList.begin(); iter != characterList.end(); ++iter)
	{
		cout << "\n" << endl;
		(*iter)->stats();
	}
}

//Cycle through the list of GameCharacter and call the render function for each object
void Game::render()
{
	list<GameCharacter*>::const_iterator iter;
	for (iter = characterList.begin(); iter != characterList.end(); ++iter)
	{
		(*iter)->render();
	}
}

//Cycle through the list of GameCharacter and call the update function for each object
void Game::update()
{

	list<GameCharacter*>::const_iterator iter;
	for (iter = characterList.begin(); iter != characterList.end(); ++iter)
	{
		(*iter)->update();
	}

	//Checking if player has reached the crown
	if ((User->getX() == crown1->getX()) && (User->getY() == crown1->getY()))
	{
		//Printing win message
		cout << "You have found the crown!" << endl;
		cout << "You win!" << endl;
		exit(0);//Ending game with code 0
	}
}

//Check the list to see if two objects occupy the same coords declare that a battle must take place
//Battle will generate two random numbers between 1 and 20. One for the player and one for the enemy
//Highest number wins
//If player wins, enemy dies
//If enemy wins, player takes damage equal to 1/2 the enemies health
void Game::battle()
{
	//Rolling 2 20 sided dice (d20) to determine attacks.
	//Character with higher number will hit the other one
	int userDice = (rand() % 20) + 1;
	int enemyDice = (rand() % 20) + 1;

	//Getting player position
	int playerX = User->getX();
	int playerY = User->getY();

	//Iterating through 
	list<GameCharacter*>::const_iterator iter;
	iter = characterList.begin();//Setting iter to start of list. It will be advanced by 1 to skip first slot (User)
	for (advance(iter, 1); iter != characterList.end(); ++iter)
	{
		if ((*iter)->getX() == playerX && (*iter)->getY() == playerY)//If enemy and player share a space
		{
			//Checking if enemy is alive
			if ((*iter)->isAlive())
			{
				if((*iter) != crown1)//Stopping crown from hitting player
				{
					//If Enemy is alive
					//Printing text
					cout << "]-----[  Rolling d20  ]-----[" << endl;
					cout << " - You rolled a: " << userDice << endl;
					cout << " - Enemy rolled a: " << enemyDice << "\n" << endl;

					//Comparing dice
					if (userDice > enemyDice)
					{
						cout << "You defeated the enemy." << endl;
						(*iter)->setHealth(0);
					}
					else {
						//Finding enemy damage dealt
						int damage = (*iter)->getHealth()/2; //Damage is equal to half enemies health

						cout << "The enemy hit you." << endl;
						cout << "You took " << damage << " damage." << endl;

						User->takeDamage(damage);
					}//End dice compare
				}
			}//End if isAlive
		}//End if player/enemy cell check
	}//End list loop
}//End battle()

//Cycle through the list of GameCharacters and call the stats function for each object
void Game::stats()
{
	cout << "Stats";

	list<GameCharacter*>::const_iterator iter;
	for (iter = characterList.begin(); iter != characterList.end(); ++iter)
	{
		cout << "\n" << endl;
		(*iter)->stats();
	}
}

//remove any objects from the list whose health is 0
void Game::clean()
{
	//Non Functional

	cout << "\n Cleaning \n" << endl;

	//Adding alive characters to list cleanList
	list<GameCharacter*>::const_iterator iter;
	for (iter = characterList.begin(); iter != characterList.end(); ++iter)
	{
		if ((*iter)->isAlive() == true)
		{
			cleanList.push_back((*iter));
		}
	}//end characterList loop

	//Clearing characterList
	characterList.clear();

	//Adding all from cleanList to characterList
	list<GameCharacter*>::const_iterator iter2;
	for (iter = cleanList.begin(); iter2 != cleanList.end(); ++iter2)
	{
			characterList.push_back((*iter2));
	}//end cleanList loop

}

//Draws a game board.
/*
Loops through all cells/spaces
Loops through list of characters and checks if any of them are alive and in the given cell
If they are, an icon is drawn for them
	X for enemy
	O for player
A _ is drawn for empty spaces
All spaces are followed by a |
*/
void Game::draw()
{
	string line = "|";

	//Loop through all cells
	for (int y = 9; y >= 0; y--)
	{
		for (int x = 0; x < 10; x++)
		{
			bool cellOccupied = false;

			//Looping through character list
			list<GameCharacter*>::const_iterator iter;
			for (iter = characterList.begin(); iter != characterList.end(); ++iter)
			{
				if ((*iter)->isAlive())
				{
					if ((*iter)->getX() == x && (*iter)->getY() == y)//if character is in cell
					{
						if ((*iter) == User)
						{
							//If its a player
							line = line + "O|";
						}
						else if ((*iter) == crown1)
						{
							//If iter is the crown
							line = line + "M|";
						}
						else
						{
							//If iter is an enemy
							line = line + "x|";
						}

						cellOccupied = true;
						break;//Breaking iter loop if anything is drawn in the cell. Stops two things from being drawn in once space
					}//End if cell occupied
				}
			}//End iter loop

			if (cellOccupied == false)
			{
				line = line + "_|";
			}
		}//End X loop
		cout << line << endl;
		line = "|";
	}//End Y loop
}//End draw()

//Prints the main menu and takes in user input
void Game::menu()
{
	//Printing menu
	cout << "]-----------------[" << endl;
	cout << "]--[ Main Menu ]--[" << endl;
	cout << "]--[           ]--[" << endl;
	cout << "]--[ 1. Play   ]--[" << endl;
	cout << "]--[ 2. Rules  ]--[" << endl;
	cout << "]--[ 3. Quit   ]--[" << endl;
	cout << "]--[           ]--[" << endl;
	cout << "]-----------------[" << endl;
}//End menu()

//Prints rules
void Game::rules()
{
	//Printing rules
	cout << "]-----------------[" << endl;
	cout << "] Goal:           [" << endl;
	cout << "] Reach the crown [" << endl;
	cout << "]   at the other  [" << endl;
	cout << "] side of the map [" << endl;
	cout << "] -  -  -  -  -  -[" << endl;
	cout << "] Enemies:        [" << endl;
	cout << "] Hitting an enemy[" << endl;
	cout << "]  will roll two  [" << endl;
	cout << "] 20 sided dice to[" << endl;
	cout << "]  determine who  [" << endl;
	cout << "] gets hit by who [" << endl;
	cout << "]                 [" << endl;
	cout << "] If hit, you will[" << endl;
	cout << "] take some damage[" << endl;
	cout << "]                 [" << endl;
	cout << "]   If hit, the   [" << endl;
	cout << "]  enemy will be  [" << endl;
	cout << "] killed and will [" << endl;
	cout << "] no longer appear[" << endl;
	cout << "]  on the board   [" << endl;
	cout << "]-----------------[" << endl;

	cout << "\nPress any key to continue" << endl;

	string userIn2;
	cin >> userIn2;
}
