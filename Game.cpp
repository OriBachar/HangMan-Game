#include "Game.h"

void Print(string message, bool printTop, bool printBottom)
{
    if (printTop)
    {
        cout << "-----------------------------------" << endl;

        cout << "|";
    }

    else
        cout << "|";
 

    bool front = true;

    for (int i = message.length(); i < 33; i++)
    {
        if (front)
            message = " " + message;
        
        else
            message = message + " ";
       
        front = !front;
    }

    cout << message.c_str();

    if (printBottom)
    {
        cout << "|" << endl;

        cout << "-----------------------------------" << endl;
    }

    else
        cout << "|" << endl;
}

void DrawHangman(int guessCount)
{
    switch (guessCount)
    {
        case 1:
        {
            Print("|", false, false);

            break;
        }


        case 2:
        {
            Print("|", false, false);

            Print("|", false, false);

            break;
        }

        case 3:
        {
            Print("|", false, false);

            Print("|", false, false);

            Print("O", false, false);

            break;
        }

        case 4:
        {
            Print("|", false, false);

            Print("|", false, false);

            Print("O", false, false);

            Print("|", false, false);

            break;
        }


        case 5:
        {
            Print("|", false, false);

            Print("|", false, false);

            Print("O", false, false);

            Print("/| ", false, false);

            break;
        }

        case 6:
        {
            Print("|", false, false);

            Print("|", false, false);

            Print("O", false, false);

            Print("/|\\", false, false);

            break;
        }

        case 7:
        {
            Print("|", false, false);

            Print("|", false, false);

            Print("O", false, false);

            Print("/|\\", false, false);

            Print("|", false, false);

            break;
        }

        case 8:
        {
            Print("|", false, false);

            Print("|", false, false);

            Print("O", false, false);

            Print("/|\\", false, false);

            Print("|", false, false);

            Print("/  ", false, false);

            break;
        }

        case 9:
        {
            Print("|", false, false);

            Print("|", false, false);

            Print("O", false, false);

            Print("/|\\", false, false);

            Print("|", false, false);

            Print("/ \\", false, false);

            break;
        }

    default:
        break;
    }
}

void PrintLetters(string guess, char from, char to)
{
    string s;

    for (char i = from; i <= to; i++)
    {
        if (guess.find(i) == string::npos)
        {
            s += i;

            s += " ";
        }

        else
            s += "  ";
    }

    Print(s, false, false);
}

void PrintAvailableLetters(string taken)
{
    Print("Available letters");

    PrintLetters(taken, 'a', 'm');

    PrintLetters(taken, 'n', 'z');
}

bool CheckWin(string word, string guessed)
{
    bool checkwin = true;

    string string;

    for (int i = 0; i < word.length(); i++)
    {
        if (guessed.find(word[i]) == string::npos)
        {
            checkwin = false;

            string += "_ ";

        }

        else
        {
            string += word[i];

            string += " ";
        }
    }

    Print(string, false);

    return checkwin;
}

string LoadRandomWord(string path)
{
    string word;

    vector<string> vector;

    ifstream reader(path);

    if (reader.is_open())
    {
        while (getline(reader, word))
            vector.push_back(word);

        int randomWord = rand() % vector.size();

        word = vector.at(randomWord);

        reader.close();
    }

    return word;
}

int GuessesLeft(string word, string guessed)
{

    int count = 0;

    for (int i = 0; i < guessed.length(); i++)
        if (word.find(guessed[i]) == string::npos)
            count++;
    

    return count;
}