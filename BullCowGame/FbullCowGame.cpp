#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } //Constructor runs reset method.

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }


// I reset the game by setting the Max tries 8(default) and the current try 1.
void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// receives a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// incriment the turn number
	MyCurrentTry++;

    // loop through all letters in the guess
    int32 HiddenWordLength = MyHiddenWord.length();
	// setup a return variable
	FBullCowCount BullCowCount;
    for (int32 i = 0; i < HiddenWordLength; i++ )
            {
            // compare letters against the hidden word
            for (int32 j=0; j < HiddenWordLength; j++){
                if(Guess[i] == MyHiddenWord[j]){

                    if(i == j){      //if letter matches
                    BullCowCount.Bulls++;  // increment bulls

                    }

                    else {BullCowCount.Cows++; //if letter doesn't match and matches another letter increment cows.



                        }



                  }


            }

    }
// should be: right letter right place  +1 bull
// should be: right letter wrong place +1 cow
// I think wrong letter not present in hidden word, will incriment the cows.


	return BullCowCount;
}
