
 #pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values intialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
	
};





class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus  CheckGuessValidity(FString) const ;

	void Reset(); // TODO make a more rich return value.
	FBullCowCount SubmitValidGuess(FString );


// ^^ Please try and ignore this and focus on the interface above ^^
private:
	// see constructor for initialisation
	int32 MyCurrentTry;           // I am the game's current try.
	int32 MyMaxTries;             // I am the game's maximum try.
	FString MyHiddenWord;         // I am the game's hidden word
};
