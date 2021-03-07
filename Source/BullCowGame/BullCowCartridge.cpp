// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else 
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame() 
{
    // Welcome the player
    PrintLine(TEXT("Welcome to the Bull Cows!"));

    // Basic set up member variables for this game    
    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len();
    bGameOver = false;

    // Give hints for the player
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess and\nPress enter to continue..."));    

    // Debug what the hidden word is
    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to play again..."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You have won!"));
        EndGame();
        return;
    }

    --Lives;
    PrintLine(TEXT("Lost a life!"));

    if(Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The hidden word was: %s."), *HiddenWord);
        EndGame();
        return;
    }

    if(Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden word is %i letters long."), HiddenWord.Len());
        PrintLine(TEXT("Sorry, try guessing again!"));
        PrintLine(TEXT("You have %i lives remaining."), Lives);
        return;
    }

    if(!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters, guess again!"));
        PrintLine(TEXT("You have %i lives remaining."), Lives);
        return;
    }

    
}

bool UBullCowCartridge::IsIsogram(FString Guess) const
{
    for (int32 Index = 0; Index < Guess.Len() - 1; Index++)
    {
        for(int32 Comparison = Index + 1; Comparison < Guess.Len(); Comparison++)
        {
            if(Guess[Index] == Guess[Comparison])
            {
                return false;
            }
        }
    }

    return true;
}