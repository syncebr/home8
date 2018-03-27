/*3.	Сформировать одномерный динамический массив, и реализовать меню:
a)	Добавления элемента в массив с заданной позиции.
b)	Удаление заданного элемента  массива.
c)	Добавление нескольких элементов из массива, начиная с заданной позиции.
d)	Удаление нескольких элементов из массива, начиная с заданной позиции.
*/

#include <iostream>
using namespace std;
#include <ctime>
void init(int* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 21 - 10;
	}
}
//вывод массива на консоль
void print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

//ввод номера позиции
int getPoz(int n) {
	int poz;
	cout << "Ведите номер позиции в массиве: ";
	do {
		cin >> poz;
		if (poz<0 || poz>n) {
			cout << "Неверный номер!\n";
			cout << "Введите число от 0 до " << n << " : ";
		}
	} while (poz<0 || poz>n);
	return poz;
}

//функция вставляет в массив элемент в необходимую позицию
void insertOne(int* &arr, int &size) {
	int poz = getPoz(size);
	int elem;
	cout << "\nВведите вставляемый элемент: ";
	cin >> elem;
	int* tmp = new int[size + 1];
	//переписать все элементы до вставляемого
	for (int i = 0; i < poz; i++) {
		tmp[i] = arr[i];
	}
	tmp[poz] = elem;
	//переписать остальные элементы до конца
	for (int i = poz; i < size; i++) {
		tmp[i + 1] = arr[i];
	}
	delete[] arr;
	arr = tmp;
	size++;
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int *arr = NULL;
	int size;
	cout << "Введите размер массива: ";
	cin >> size;
	arr = new int[size];
	init(arr, size);
	print(arr, size);
	insertOne(arr, size);
	print(arr, size);
	system("pause");
	return 0;
}
