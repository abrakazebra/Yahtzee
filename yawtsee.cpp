//A C++ console Yahtzee game
//Created by Jeremy Smith
//licensed under GPL-3

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>



struct Die//structure of die
{
	int topNumber;
	bool hold = false;
	
};
struct Player//structure of player, holds categories, category scores, and player total scores
{
	std::string theCategory[13] = { "Ones", "Twos", "Threes", "Fours", "Fives", "Sixes", "3 of a Kind", "4 of a Kind", "Full House", "Small Straight", "Large Straight", "Yahtzee", "Chance" };
	bool categoryUsed[13];
	bool gotYahtzee = false, topBonus = false;
	int totalScore, topScore;
	int categoryScore[13];
};


class Game
{
public:
	Game();
	void roll();//rolls the dice
	void testRoll();//rolls a yahtzee
	void printDice();//prints dice to screen
	void scoreBoard();//prints current player socreboard
	void initGame();//initializes game
	void initDie();//initializes die
	void play();//plays a game
	void aTurn();//plays a turn
	void placeScores(Die someDice[], int userChoice);//places scores onto correct categories
	void tabulateScores();//final tally of scores for a game
	int scoreAces(Die someDice[]);
	int scoreTwos(Die someDice[]);
	int scoreThrees(Die someDice[]);
	int scoreFours(Die someDice[]);
	int scoreFives(Die someDice[]);
	int scoreSixes(Die someDice[]);
	int scoreThreeOfAKind(Die someDice[]);
	int scoreFourOfAKind(Die someDice[]);
	int scoreFullHouse(Die someDice[]);
	int scoreSmallStraight(Die someDice[]);
	int scoreLargeStraight(Die someDice[]);
	int scoreYahtzee(Die someDice[]);
	int scoreChance(Die someDice[]);
private:
	Die myDice[5];
	Player playerNum[6];
	int roundNum = 0, rollNum = 0, currentPlayer = 0, numPlayers = 1;
};

int main()
{
	srand(time(NULL));
	char choice;

	do {
		Game newGame;	
		newGame.initGame();
		newGame.play();

		std::cout << "\nWould you like to play again? (y/n)";
		std::cin >> choice;
	} while (toupper(choice) == 'Y');
	
	


    return 0;
}

Game::Game()
{

}

void Game::testRoll()
{
	myDice[0].topNumber = 2;
	myDice[1].topNumber = 2;
	myDice[2].topNumber = 2;
	myDice[3].topNumber = 2;
	myDice[4].topNumber = 2;

}
void Game::roll()
{
	for (int i = 0; i < 5; i++)
	{
		if (!myDice[i].hold)
		{
			myDice[i].topNumber = rand() % 6 + 1;
		}
	}
}

void Game::printDice()
{
	
	std::cout << "\nYour roll: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		
		if (myDice[i].hold)
		{
			std::cout << i + 1 << ") " << myDice[i].topNumber << " - held\n";
		}
		else
			std::cout << i + 1 << ") " << myDice[i].topNumber << " \n";
	}
	
}
void Game::scoreBoard()
{
	
	std::cout << "\n---------= Scorecard =---= Player " << currentPlayer + 1 << " =---------------------\n";
	if (playerNum[currentPlayer].categoryUsed[0])
	{

		std::cout << "1) " << playerNum[currentPlayer].theCategory[0] << " " << playerNum[currentPlayer].categoryScore[0] << "\t\t\t"; 
	}
	else
	{
		std::cout << "1) " << playerNum[currentPlayer].theCategory[0] << " " << " " << "\t\t\t";
	}
	if (playerNum[currentPlayer].categoryUsed[6])
	{
        std::cout << "7) " << playerNum[currentPlayer].theCategory[6] << " " << playerNum[currentPlayer].categoryScore[6] << std::endl;
	}
	else
	{
		std::cout << "7) " << playerNum[currentPlayer].theCategory[6] << " " << " " << std::endl;
	}
	if (playerNum[currentPlayer].categoryUsed[1])
	{
		std::cout << "2) " << playerNum[currentPlayer].theCategory[1] << " " << playerNum[currentPlayer].categoryScore[1] << "\t\t\t";
	}
	else
	{
		std::cout << "2) " << playerNum[currentPlayer].theCategory[1] << " " << " " << "\t\t\t";
	}
	if (playerNum[currentPlayer].categoryUsed[7])
	{
		std::cout << "8) " << playerNum[currentPlayer].theCategory[7] << " " << playerNum[currentPlayer].categoryScore[7] << std::endl;
	}
	else
	{
		std::cout << "8) " << playerNum[currentPlayer].theCategory[7] << " " << " " << std::endl;
	}
	if (playerNum[currentPlayer].categoryUsed[2])
	{
		std::cout << "3) " << playerNum[currentPlayer].theCategory[2] << " " << playerNum[currentPlayer].categoryScore[2] << "\t\t\t";
	}
	else
	{
		std::cout << "3) " << playerNum[currentPlayer].theCategory[2] << " " << " " << "\t\t\t";
	}
	if (playerNum[currentPlayer].categoryUsed[8])
	{
		std::cout << "9) " << playerNum[currentPlayer].theCategory[8] << " " << playerNum[currentPlayer].categoryScore[8] << std::endl;
	}
	else
	{
		std::cout << "9) " << playerNum[currentPlayer].theCategory[8] << " " << " " << std::endl;
	}
	if (playerNum[currentPlayer].categoryUsed[3])
	{
		std::cout << "4) " << playerNum[currentPlayer].theCategory[3] << " " << playerNum[currentPlayer].categoryScore[3] << "\t\t\t";
	}
	else
	{
		std::cout << "4) " << playerNum[currentPlayer].theCategory[3] << " " << " " << "\t\t\t";
	}
	if (playerNum[currentPlayer].categoryUsed[9])
	{
		std::cout << "10) " << playerNum[currentPlayer].theCategory[9] << " " << playerNum[currentPlayer].categoryScore[9] << std::endl;
	}
	else
	{
		std::cout << "10) " << playerNum[currentPlayer].theCategory[9] << " " << " " << std::endl;
	}
	if (playerNum[currentPlayer].categoryUsed[4])
	{
		std::cout << "5) " << playerNum[currentPlayer].theCategory[4] << " " << playerNum[currentPlayer].categoryScore[4] << "\t\t\t";
	}
	else
	{
		std::cout << "5) " << playerNum[currentPlayer].theCategory[4] << " " << " " << "\t\t\t";
	}
	if (playerNum[currentPlayer].categoryUsed[10])
	{
		std::cout << "11) " << playerNum[currentPlayer].theCategory[10] << " " << playerNum[currentPlayer].categoryScore[10] << std::endl;
	}
	else
	{
		std::cout << "11) " << playerNum[currentPlayer].theCategory[10] << " " << " " << std::endl;
	}
	if (playerNum[currentPlayer].categoryUsed[5])
	{
		std::cout << "6) " << playerNum[currentPlayer].theCategory[5] << " " << playerNum[currentPlayer].categoryScore[5] << "\t\t\t";
	}
	else
	{
		std::cout << "6) " << playerNum[currentPlayer].theCategory[5] << " " << " " << "\t\t\t";
	}
	if (playerNum[currentPlayer].categoryUsed[11])
	{
		std::cout << "12) " << playerNum[currentPlayer].theCategory[11] << " " << playerNum[currentPlayer].categoryScore[11] << std::endl;
	}
	else
	{
		std::cout << "12) " << playerNum[currentPlayer].theCategory[11] << " " << " " << std::endl;
	}
	std::cout << "\t\t\t\t";
	if (playerNum[currentPlayer].categoryUsed[12])
	{
		std::cout << "13) " << playerNum[currentPlayer].theCategory[12] << " " << playerNum[currentPlayer].categoryScore[12] << std::endl;
	}
	else
	{
		std::cout << "13) " << playerNum[currentPlayer].theCategory[12] << " " << " " << std::endl;
	}

	
	std::cout << "----------------------------------------------------------\n";
	std::cout << "Roll Number " << rollNum << "\t" << "Round Number " << roundNum << "\t " << " Total " << playerNum[currentPlayer].totalScore << std::endl;
	std::cout << "----------------------------------------------------------\n";

}
void Game::initGame()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			playerNum[i].categoryUsed[j] = 0;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			playerNum[i].categoryScore[j] = 0;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			playerNum[i].totalScore = 0;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		playerNum[i].gotYahtzee = false;
	}
	for (int i = 0; i < 5; i++)
	{
		myDice[i].hold = false;
	}
}
void Game::initDie()
{
	for (int i = 0; i < 5; i++)
	{
		myDice[i].hold = false;
	}
}

void Game::play()
{
	int userInput;
	numPlayers = 1;
	std::cout << "Let's Play Yahtzee!\n\n" << std::endl;

	std::cout << "Enter number of players to begin (1-5) ";
	std::cin >> numPlayers;

	while (!std::cin || numPlayers < 1 || numPlayers > 5)//vaidate number of players input
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Enter a number of players 1-5 ";
		std::cin >> numPlayers;
	}

	for (int i = 0; i < 13; i++)//loops through the rounds of the game
	{
		roundNum = i + 1;//current round
		for (int j = 0; j < numPlayers; j++)//loops through the number of players in the game
		{
			currentPlayer = j;//current player
			aTurn();//current players turn

		}
	}
	tabulateScores();//show final scores
}
void Game::aTurn()
{
	int userInput;

	rollNum = 1;
	while (rollNum < 3)//shows first two rolls and asks for die holds
	{	
		roll();
		scoreBoard();
		printDice();
		std::cout << "\nTo hold or unhold a die, input the number of the die and press enter\n";
	    std::cout << "When you are ready to roll input 0 and press enter ";
		std::cin >> userInput;

		while (!std::cin || userInput < 0 || userInput > 6)//validate user input
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Please enter a number 0 to roll, or 1-6 to hold a die ";
			std::cin >> userInput;
		}

		while (userInput != 0)//holds or unholds dice
		{
			switch (userInput)
			{
			case 1:
				if (myDice[0].hold)
				{
					myDice[0].hold = false;
				}
				else
					myDice[0].hold = true;
				break;
			case 2:
				if (myDice[1].hold)
				{
					myDice[1].hold = false;
				}
				else
					myDice[1].hold = true;
				break;
			case 3:
				if (myDice[2].hold)
				{
					myDice[2].hold = false;
				}
				else
					myDice[2].hold = true;
				break;
			case 4:
				if (myDice[3].hold)
				{
					myDice[3].hold = false;
				}
				else
					myDice[3].hold = true;
				break;
			case 5:
				if (myDice[4].hold)
				{
					myDice[4].hold = false;
				}
				else
					myDice[4].hold = true;
				break;
			case 6:
				if (myDice[5].hold)
				{
					myDice[5].hold = false;
				}
				else
					myDice[5].hold = true;
				break;
			}
			scoreBoard();
			printDice();
			std::cout << "\nTo hold a die, input the number of the die and press enter\n";
			std::cout << "When you are ready to roll input 0 and press enter ";
			std::cin >> userInput;

			while (!std::cin || userInput < 0 || userInput > 6)//validate user input
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Please enter a number 0 to roll, or 1-6 to hold a die ";
				std::cin >> userInput;
			}
		}

		rollNum++;

	}

	
	roll();//final roll, shows new dialouge asking user where to put their points

/*	testRoll();*/ //test roll to test yahtzee 

	scoreBoard();
	printDice();
	std::cout << "\nWhere would you like to place your points? ";
	std::cin >> userInput;

		while (!std::cin || userInput < 1 || userInput > 13)//validate user input
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Please enter a number 1 to 13 to match a category ";
			std::cin >> userInput;
		}
	    
		


		if (playerNum[currentPlayer].categoryUsed[userInput - 1])//checks if category is already been scored
		{
			if (userInput == 12)
			{
				if (playerNum[currentPlayer].gotYahtzee == false)//if yahtzee is flagged but as zero
				{
					std::cout << "You've already used up your Yahtzee category\n";
					std::cout << "Choose a new location for this roll";
					std::cin >> userInput;
					goto skip;
				}
				else if (playerNum[currentPlayer].gotYahtzee == true)//if yahtzee is already flagged
				{
					std::cout << "Another Yahtzee! Bonus 100 awared to yahtzee category\n";
					std::cout << "Choose another location for this roll ";
					std::cin >> userInput;
					playerNum[currentPlayer].categoryScore[11] += 100;
					playerNum[currentPlayer].totalScore += 100;
					goto skip;
				}
				
			}
			std::cout << "category already used, please choose another ";
			std::cin >> userInput;
			
		}
		
			skip://from the goto
            playerNum[currentPlayer].categoryUsed[userInput - 1] = true;//sets a category to used
			placeScores(myDice, userInput);
			printDice();
		
		
		initDie();//initializes the dice holds for next player
}
void Game::placeScores(Die someDice[], int userChoice)
{
	switch (userChoice)
	{
	case 1:
		playerNum[currentPlayer].categoryScore[userChoice - 1] = scoreAces(someDice);
		break;
	case 2:
		playerNum[currentPlayer].categoryScore[userChoice - 1] = scoreTwos(someDice);
		break;
	case 3:
		playerNum[currentPlayer].categoryScore[userChoice - 1] = scoreThrees(someDice);
		break;
	case 4:
		playerNum[currentPlayer].categoryScore[userChoice - 1] = scoreFours(someDice);
		break;
	case 5:
		playerNum[currentPlayer].categoryScore[userChoice - 1] = scoreFives(someDice);
		break;
	case 6:
		playerNum[currentPlayer].categoryScore[userChoice - 1] = scoreSixes(someDice);
		break;
	case 7:
		playerNum[currentPlayer].categoryScore[userChoice - 1] = scoreThreeOfAKind(someDice);
		break;
	case 8:
		playerNum[currentPlayer].categoryScore[userChoice - 1] = scoreFourOfAKind(someDice);
		break;
	case 9:
		playerNum[currentPlayer].categoryScore[userChoice - 1] = scoreFullHouse(someDice);
		break;
	case 10:
		playerNum[currentPlayer].categoryScore[userChoice - 1] = scoreSmallStraight(someDice);
		break;
	case 11:
		playerNum[currentPlayer].categoryScore[userChoice - 1] = scoreLargeStraight(someDice);
		break;
	case 12:
		playerNum[currentPlayer].categoryScore[userChoice - 1] = scoreYahtzee(someDice);
		break;
	case 13:
		playerNum[currentPlayer].categoryScore[userChoice - 1] = scoreChance(someDice);
		break;
	}
}
int Game::scoreAces(Die someDice[])
{
	int tempScore = 0;
	for (int i = 0; i < 5; i++)
	{
		if (someDice[i].topNumber == 1)
			tempScore += 1;
	}
	playerNum[currentPlayer].totalScore += tempScore;
	return tempScore;
}

int Game::scoreTwos(Die someDice[])
{
	int tempScore = 0;
	for (int i = 0; i < 5; i++)
	{
		if (someDice[i].topNumber == 2)
			tempScore += 2;
	}
	playerNum[currentPlayer].totalScore += tempScore;
	return tempScore;
}
int Game::scoreThrees(Die someDice[])
{
	int tempScore = 0;
	for (int i = 0; i < 5; i++)
	{
		if (someDice[i].topNumber == 3)
			tempScore += 3;
	}
	playerNum[currentPlayer].totalScore += tempScore;
	return tempScore;
}
int Game::scoreFours(Die someDice[])
{
	int tempScore = 0;
	for (int i = 0; i < 5; i++)
	{
		if (someDice[i].topNumber == 4)
			tempScore += 4;
	}
	playerNum[currentPlayer].totalScore += tempScore;
	return tempScore;
}
int Game::scoreFives(Die someDice[])
{
	int tempScore = 0;
	for (int i = 0; i < 5; i++)
	{
		if (someDice[i].topNumber == 5)
			tempScore += 5;
	}
	playerNum[currentPlayer].totalScore += tempScore;
	return tempScore;
}
int Game::scoreSixes(Die someDice[])
{
	int tempScore = 0;
	for (int i = 0; i < 5; i++)
	{
		if (someDice[i].topNumber == 6)
			tempScore += 6;
	}
	playerNum[currentPlayer].totalScore += tempScore;
	return tempScore;
}
int Game::scoreThreeOfAKind(Die someDice[])
{
	int tempScore = 0, count = 0;
	for (int i = 1; i <= 6; i++)
	{
		count = 0;
		for (int j = 0; j < 5; j++)
		{
			if (i == someDice[j].topNumber)
			{
				count++;
				if (count > 2)
				{
					goto skip3;
				}
			}
		}
	}
	skip3:
	if (count > 2)
	{
		for (int i = 0; i < 5; i++)
		{
			tempScore += someDice[i].topNumber;
		}
	}
	
	
	playerNum[currentPlayer].totalScore += tempScore;
	return tempScore;
}
int Game::scoreFourOfAKind(Die someDice[])
{
	int tempScore = 0, count = 0;
	for (int i = 1; i <= 6; i++)
	{
		count = 0;
		for (int j = 0; j < 5; j++)
		{
			if (i == someDice[j].topNumber)
			{
				count++;
				if (count > 3)
				{
					goto skip4;
				}
			}
		}
	}
	skip4:
	if (count > 3)
	{
		for (int i = 0; i < 5; i++)
		{
			tempScore += someDice[i].topNumber;
		}
	}

	playerNum[currentPlayer].totalScore += tempScore;
	return tempScore;
}
int Game::scoreFullHouse(Die someDice[])
{
	int tempScore = 0, swap;
	for (int i = 0; i < 5; i++)//sort dice array
	{
		for (int j = 0; j < 4; j++)
		{
			if (someDice[j].topNumber > someDice[j + 1].topNumber)
			{
				swap = someDice[j].topNumber;
				someDice[j].topNumber = someDice[j + 1].topNumber;
				someDice[j + 1].topNumber = swap;
			}
		}
	}
	if ((someDice[0].topNumber == someDice[1].topNumber) && (someDice[1].topNumber == someDice[2].topNumber) && (someDice[3].topNumber == someDice[4].topNumber) ||
		(someDice[4].topNumber == someDice[3].topNumber) && (someDice[3].topNumber == someDice[2].topNumber) && (someDice[1].topNumber == someDice[0].topNumber))//ensure full house
	{
		//fullhouse 
		tempScore = 25;
	}

	playerNum[currentPlayer].totalScore += tempScore;
	return tempScore;
}
int Game::scoreSmallStraight(Die someDice[])
{
	int tempScore = 0, swap;

	for (int i = 0; i < 5; i++)//sort dice array
	{
		for (int j = 0; j < 4; j++)
		{
			if (someDice[j].topNumber > someDice[j + 1].topNumber)
			{
				swap = someDice[j].topNumber;
				someDice[j].topNumber = someDice[j + 1].topNumber;
				someDice[j + 1].topNumber = swap;
			}
		}
	}

	for (int x = 0; x < 4; x++)//move any matching die to the end of array
	{
		if (someDice[x].topNumber == someDice[x + 1].topNumber)
		{
			swap = someDice[x].topNumber;
			for (int y = x; y < 4; y++)
			{
				someDice[y].topNumber = someDice[y + 1].topNumber;
			}
			someDice[4].topNumber = swap;
		}
	}

	if (someDice[0].topNumber == someDice[1].topNumber - 1 && (someDice[1].topNumber == someDice[2].topNumber - 1) && (someDice[2].topNumber == someDice[3].topNumber - 1))
	{
		//small straight
		tempScore = 30;
	}

	playerNum[currentPlayer].totalScore += tempScore;
	return tempScore;
}
int Game::scoreLargeStraight(Die someDice[])
{
	int tempScore = 0, swap;

	for (int i = 0; i < 5; i++)//sort dice array
	{
		for (int j = 0; j < 4; j++)
		{
			if (someDice[j].topNumber > someDice[j + 1].topNumber)
			{
				swap = someDice[j].topNumber;
				someDice[j].topNumber = someDice[j + 1].topNumber;
				someDice[j + 1].topNumber = swap;
			}
		}
	}

	if (someDice[0].topNumber == someDice[1].topNumber - 1 && (someDice[1].topNumber == someDice[2].topNumber - 1) && (someDice[2].topNumber == someDice[3].topNumber - 1) &&
		(someDice[3].topNumber == someDice[4].topNumber - 1))
	{
		//largestraight
		tempScore = 40;
	}
	
	playerNum[currentPlayer].totalScore += tempScore;
	return tempScore;
}
int Game::scoreYahtzee(Die someDice[])
{
	int tempScore = 0, count = 1;
	
	for (int i = 0; i < 4; i++)
	{
		if (someDice[i].topNumber == someDice[i + 1].topNumber)
		{
			count++;
		}
	}


	if (count > 4)
	{
		tempScore = 50;
		playerNum[currentPlayer].gotYahtzee = true;
	}

	
	playerNum[currentPlayer].totalScore += tempScore;
	return tempScore;
}
int Game::scoreChance(Die someDice[])
{
	int tempScore = 0;

	for (int i = 0; i < 5; i++)
	{
		tempScore += someDice[i].topNumber;
	}

	playerNum[currentPlayer].totalScore += tempScore;
	return tempScore;
}

void Game::tabulateScores()
{
	int maxScore = 0;
	for (int i = 1; i <= numPlayers; i++)//add up top score
	{
		for (int j = 0; j < 6; j++)
		{
			playerNum[i].topScore += playerNum[i].categoryScore[j];
		}
	}
	for (int i = 0; i < numPlayers; i ++)//determine top bonus
	{
		if (playerNum[i].topScore > 63)
		{
			playerNum[i].topBonus = true;
			playerNum[i].totalScore += 35;
		}
	}
	for (int i = 0; i < numPlayers; i++)//print final scores
	{
		std::cout << "\nPlayer " << i + 1 << " scores";
		std::cout << "\nAces score: " << playerNum[i].categoryScore[0];
		std::cout << "\nTwos score: " << playerNum[i].categoryScore[1];
		std::cout << "\nThrees score: " << playerNum[i].categoryScore[2];
		std::cout << "\nFours score: " << playerNum[i].categoryScore[3];
		std::cout << "\nFives score: " << playerNum[i].categoryScore[4];
		std::cout << "\nSixes score: " << playerNum[i].categoryScore[5];
		if (playerNum[i].topBonus)
		{
			std::cout << "\nTop bonus: " << 64;
		}
		else
		{
			std::cout << "\nTop bonus: " << 0;
		}
		std::cout << "\n3 of a kind score: " << playerNum[i].categoryScore[6];
		std::cout << "\n4 of a kind score: " << playerNum[i].categoryScore[7];
		std::cout << "\nFull House score: " << playerNum[i].categoryScore[8];
		std::cout << "\nSmall straight: " << playerNum[i].categoryScore[9];
		std::cout << "\nLarge straight: " << playerNum[i].categoryScore[10];
		std::cout << "\nYahtzee score: " << playerNum[i].categoryScore[11];
		std::cout << "\nChance score: " << playerNum[i].categoryScore[12];
		std::cout << "\nTotal Score: " << playerNum[i].totalScore << std::endl;
	}

	for (int i = 0; i < numPlayers; i++)
	{
		
		
		for (int j = 1; j < numPlayers; j++)
		{
			
			maxScore = playerNum[i].totalScore;
			if (playerNum[j].totalScore > playerNum[i].totalScore)
			{
				maxScore = playerNum[j].totalScore;
			}
		}
	}
	for (int i = 0; i < numPlayers; i++)//print winner
	{
		if (playerNum[i].totalScore == maxScore)
		{
			std::cout << "\nPlayer " << i << " wins!\n";
		}
	}
}