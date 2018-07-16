/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FbullCowGame.h"

using FText = std::string;
using int32 = int;

void GameIntro();
int main();
void PlayGame();
FText Getguess();
bool AskToPlayAgn();
FbullCowGame BCGame;


     // MAIN METHOD
	int main() 
	{
		do{
			GameIntro();
			PlayGame();
			
			
		}while(AskToPlayAgn() );

		return 0; //Exit the application
	}

	void PlayGame()
	{
		BCGame.Reset();
		int32 MaxTries = BCGame.GetMaxTries();
		//std::cout << MaxTries << std::endl;
	
		//TODO change from for to while loop once we are validating tries 
	for (int32 count = 0; count <= MaxTries; count++) 
		{
		
		FText Guess = Getguess();   //TODO make loop to check for valid guess
		//submit valid guess to the game 
		//print32 number of bulls and cows 
		std::cout << "Your guess was: " + Guess << std::endl;
		std::cout << std::endl;

		}
	// TODO summarise game 
}




 //METHOD is the game intro 
	void GameIntro() 
	{

	constexpr int32  WORD_LENGTH = 5;
	std::cout << "							Welcome to Bulls and Cows " << std::endl;
	std::cout << "							  Made by Shuhel Ahmed      " << std::endl;
	std::cout << "			                   Can you guess the " << WORD_LENGTH << " letter word I am thinking off ? \n";
	return;
	
	}




// METHOD asks for a guess and returns it.
	FText Getguess()
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try: " << CurrentTry << std::endl << "Enter your guess: ";


		FText Guess = "";
		std::getline(std::cin, Guess);
		return Guess;
		
		
	}

	bool AskToPlayAgn()
	{
		std::cout << "Do you want to play again? " << std::endl;
		FText Response = "";
		std::getline(std::cin,Response);
 		return (Response[0] == 'y' || Response[0] == 'Y');
	}

	