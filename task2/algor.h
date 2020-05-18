#include <fstream>
#include <iostream>
using namespace std; 

struct Matrix {
	int n, m; // размерность матрицы
	double* values; // ссылка на элементы матрицы 
};

Matrix* read(const char* filename); // функция, читабщая матрицу из файла.
double findSum(Matrix* matr);
char* echo(const char* file);
void ansver(); 
