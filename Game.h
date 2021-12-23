#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

void Print(string message, bool printTop = true, bool printBottom = true);

void DrawHangman(int guessCount = 0);

void PrintLetters(string guess, char from, char to);

void PrintAvailableLetters(string taken);

bool CheckWin(string word, string guessed);

string LoadRandomWord(string path);

int GuessesLeft(string word, string guessed);



