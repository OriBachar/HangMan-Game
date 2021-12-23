#include "Game.h"

int main()
{
    srand(time(0));

    string guesses;

    string wordToGuess;

    wordToGuess = LoadRandomWord("Words.txt");

    int tries = 0;

    bool win = false;

    do
    {
        system("cls"); 

        Print("HANGMAN");

        DrawHangman(tries);

        PrintAvailableLetters(guesses);

        Print("Guess the word");

        win = CheckWin(wordToGuess, guesses);

        if (win)
            break;

        char temp;

        cout << ">"; cin >> temp;

        if (guesses.find(temp) == string::npos)
            guesses += temp;

        tries = GuessesLeft(wordToGuess, guesses);

    } while (tries < 10);

    if (win)
       Print("YOU WIN! :)");


    else
    {
        Print("GAME OVER! :(", true, false);

        Print("The word is:", false, false);

        Print(wordToGuess, false, true);
    }

    system("pause"); 

    getchar();

    return 0;
}