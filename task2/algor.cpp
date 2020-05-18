#include "algor.h"
void ansver() {
	Matrix* matrix = read("input.txt");
	double sum = findSum(matrix);

	ofstream out;
	out.open("output.txt");

	for (int i = 0; i < matrix->n; i++) {
		for (int j = 0; j < matrix->m; j++) {
			out << *(matrix->values + matrix->m * i + j) << ' ';
		}
		out << endl;
	}
	out << "суммы значений элементов тех строк матрицы,\nу которых на главной диагонали расположены элементы,\nимеющие отрицательные значения = ";
	out << sum << '/';
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
Matrix* read(const char* filename) {
	Matrix* matr = new Matrix;

	ifstream in;
	in.open(filename);
	in >> matr->n;
	in >> matr->m;
	double* mass = new double[matr->n * matr->m + 1];
	for (int i = 0; i < matr->n; i++) {
		for (int j = 0; j < matr->m; j++) {
			in >> *(mass + i * matr->m + j);
		}
	}
	in.close();

	matr->values = mass;
	return matr;
}

double findSum(Matrix* matr) {
	double sum = 0;
	for (int i = 0; i <= matr->n; i++) {
		double mx = -1111111111;
		int jj = 0;
		if (*(matr->values + i * matr->m + i) < 0) {
			for (int j = 0; j < matr->m; j++) {
				sum += *(matr->values + i * matr->m + j);
			}
		}
	}
	return sum;
}