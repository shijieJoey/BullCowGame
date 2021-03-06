// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    // Debug what the hidden word is
    // PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord);

    PrintLine(TEXT("Welcome to the Bull Cows!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess and press enter to continue..."));    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();






    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You have won!"));
    }
    else 
    {
        if(Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The Hidden Word is %i characters long, try again!"), HiddenWord.Len());
        }
        
        PrintLine(TEXT("You have lost!"));
    }
    
    
}

void UBullCowCartridge::SetupGame() 
{
    HiddenWord = TEXT("cake");
    Lives = 4;
    bGameOver = false;
}