/*Запросить у пользователя  размеры двумерного массива.
Выделить память под массив, заполнив его случайными числами от -5 до 5.
Найти максимальный элемент в каждой строке двумерного массива и вывести его на консоль.  
*/

#include <iostream>
#include <ctime>
using namespace std;

void generateArr(int **mas, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mas[i][j] = rand() % 11 - 5;
		}
	}
}

void printArr(int **mas, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//cout << mas[i][j] << "\t";
			printf("%2d\t", mas[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}


void maxElem(int **mas, int row, int col) {
	for (int i = 0; i < row; i++) {
		int max = mas[i][0];
		for (int j = 0; j < col; j++) {
			if (mas[i][j] > max)max = mas[i][j];
		}
		cout << " Максимальный элемент " << i + 1 << " строки = " << max << endl;
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int row, col;
	int **mas;
	cout << " Введите количество строк : ";
	cin >> row;
	cout << " Введите количество столбцов : ";
	cin >> col;
	mas = new int*[row];
	for (int i = 0; i < row; i++) {
		mas[i] = new int[col];
	}
	generateArr(mas, row, col);
	cout << " Двумерный массив \n";
	printArr(mas, row, col);
	maxElem(mas, row, col);
	//удаление двумерного массива
	for (int i = 0; i < row; i++) {
		delete mas[i];
	}
	delete[] mas;
	//
	system("pause");
	return 0;
}
