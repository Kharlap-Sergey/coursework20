#include "menu.h"

void menu() {
	while (true) {
		cout << "введите 1 - для перезаписи информации\n\
введите 2 - для показа записаных данных;\n\
введите 3 - для назождения ответа;\n\
введите 4 - для пока результатов;\nиначе программа будет завершнена\n";
		int step;
		cin >> step;
		switch (step) {
		case 1: {
			char c;
			cout << "введите букву на которую должны начинаться и заканчиваться слова\n";
			cin >> c;
			cout << "введите через запятую слова, для поиска начинающихся\
 и заканчивающихся на указанную букву, заканчивающиеся точкой\n";
			char* text = new char[MAX];
			int len = 0;
			cin.get();
			cin.get(text, MAX - 10, '\n');
			cin.get();

			ofstream out;
			out.open("input.txt");
			out << c << ": ";
			out << text << '/';
			out.close();

			break;
		}
		case 2: {
			char* text = echo("input.txt");
			cout << "текст:\n";
			cout << text << endl << endl;
			break;
		}
		case 3: {
			cout << "ответ подсчитан\n\n";
			ansver();
			break;
		}
		case 4: {
			char* text = echo("output.txt");
			cout << "текст:\n";
			cout << text << endl << endl;
			break;
		}
		default:
			return;
		}
	}
}