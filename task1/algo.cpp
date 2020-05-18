#include "algo.h"

char* information;
char mainC;

void ansver() {
	information = read("input.txt");
	WordsList* words;

	ofstream out;
	out.open("output.txt");
	out << information << endl;

	out << endl;
	words = extractWords(information);

	mainC = toLower(mainC);
	out << "слова начинающиеся и заканчивающиеся на " << mainC << ":\n";
	for (int i = 0; i < words->amount; i++) {
		if (isCorrect(words->value[i], mainC))
			out << words->value[i] << ' ';
	}
	out << '/';
	out.close();
}

char* echo(const char* file) {
	char* text = new char[10000];
	ifstream in;
	in.open(file);
	in.get(text, 10000, '/');
	in.close();
	return text;
}

bool isCorrect(char* word, char letter) {
	return word[0] == word[strlen(word) - 1] && word[0] == letter;
}

char toLower(char c) {
	if (c >= 'А' && c <= 'Я') {
		c = c + 32;
	}
	return c;
}
bool isAlpha(char c) {
	bool ans = 'А' <= c && c <= 'я';
	return ans;
}

WordsList* extractWords(char* text) {
	WordsList* words = new WordsList;
	bool isWordStart = false;
	char* boof = new char[NW + 1];
	int len = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		if (isAlpha(text[i])) {
			boof[len] = toLower(text[i]);
			len++;
			isWordStart = true;
		}
		else {
			if (isWordStart) {
				boof[len] = '\0';
				words->value[words->amount] = boof;
				words->amount++;
				isWordStart = false;
				len = 0;
				boof = new char[NW + 1];
			}
		}
	}
	boof[len] = '\0';
	if (len != 0) words->value[words->amount] = boof, words->amount++;
	return words;
}

char* read(const char* filename) {
	ifstream in;
	in.open(filename);
	char* pointer = new char[MAX];
	char c = in.get();

	mainC = c;
	in.get();
	in.get();
	in.get(pointer, MAX - 10, '/');
	in.close();
	return pointer;
}
