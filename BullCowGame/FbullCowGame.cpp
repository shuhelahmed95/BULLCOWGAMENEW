#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } //Constructor runs reset method.

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


// I reset the game by setting the Max tries 8(default) and the current try 1.
void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}



EGuessStatus FBullCowGame::CheckGuessValidity (FString Guess ) const
{
	if (false)    
	{
		return EGuessStatus::Not_Isogram;
	}
	else if(false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) 
	{
		return EGuessStatus::Wrong_Length;
	}
	else 
	{
		return EGuessStatus::OK;
	}
}

// receives a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
    int32 WordLength = MyHiddenWord.length(); //assuming same length as guess

    for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++ ) // 1.looping thorugh hiddenwordLength 
            {
            // compare letters against the guess
            for (int32 GChar=0; GChar < WordLength; GChar++){  //2. looping thorugh guess ( with same iteration as hiddenword length) 
                if(Guess[GChar] == MyHiddenWord[MHWChar]){        //3. if at any time the cycles match (of 1 and 2)

                    if(MHWChar == GChar){      //4. if letters match       
                    BullCowCount.Bulls++;  //  5. increment bulls

                    }
                    else {                      //6.if they don't match, increment the cow's 
						BullCowCount.Cows++; //if letter doesn't match and matches another letter increment cows.


                        }

                  }

            }

    }
// should be: right letter right place  +1 bull
// should be: right letter wrong place +1 cow
// I think wrong letter not present in hidden word, will incriment the cows.


	return BullCowCount;
}






