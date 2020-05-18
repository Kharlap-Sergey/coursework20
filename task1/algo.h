#include <fstream>
#include <iostream>

using namespace std;

const int NL = 10; // text lenght in liness
const int NS = 100; // lines length in words
const int NW = 200; // word lenght
const int MAX = NL * NS + 10; 

struct WordsList {
	char* value[NS];
	int amount = 0;
};

char* read(const char* filename); // функция, читающая текст из файла.
WordsList* extractWords(char* text);

bool isAlpha(char c);
bool isCorrect(char* word, char letter);
char* echo(const char* file);
char toLower(char c);
void ansver();
