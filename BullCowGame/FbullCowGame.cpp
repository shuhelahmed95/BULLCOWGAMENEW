#include "FbullCowGame.h"
using int32 = int;

FbullCowGame::FbullCowGame()
{
	Reset();
}

int32 FbullCowGame::GetMaxTries() const 
{
	
	
	return MyMaxTries;


}

int32 FbullCowGame::GetCurrentTry() const {return MyCurrentTry;}

void FbullCowGame::Reset()
{
	

	constexpr int32 MAXTRIES = 8;
	MyMaxTries = MAXTRIES;

	const FString Hidden_Word = "plant";
	MyHiddenWord = Hidden_Word;
	MyCurrentTry = 1;

	
	return;
}

//recieves a VALID guess and increments turn and return count
BullCowCount FbullCowGame::SubmitGuess(FString)
		{
	//increment the turn number 
	MyCurrentTry++;
	//setup a return variable
	BullCowCount BullCowCount;
	//loop through all letters in guess.
		// compare letters against hidden word

	return BullCowCount;
		}



bool FbullCowGame::IsGameWon() const
{
	return false;
}

bool FbullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
