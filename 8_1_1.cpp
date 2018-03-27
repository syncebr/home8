/*Сформировать и распечатать динамический одномерный массив (число элементов запросить у пользователя).
Заполнить случайными числами от -5 до 5.
Удалить из массива все нулевые элементы.
Новый массив должен занимать ровно столько памяти, сколько ему необходимо.
Распечатать новый массив.*/

#include<iostream>
#include<ctime>

using namespace std;

template <typename MyT>
void generateArr(MyT *, int);
template <typename MyT>
void printArr(MyT *, int);

void deleteZero(int *&arr, int &size) {
	int *ptr = arr;
	int counter = 0;
	while (ptr < arr + size) {
		if (*ptr) 	counter++;
		ptr++;
	}
	ptr = NULL;
	ptr = new int[counter];
	int *ptrTmp = ptr;
	while (ptrTmp < ptr + counter) {
		if (*arr) {
			*ptrTmp = *arr;
			ptrTmp++;
		}
		arr++;
	}
	arr = ptr;
	size = counter;
}


int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int size;
	cout << "Введите размер массива: ";
	cin >> size;
	int *arr = new int[size];
	generateArr(arr, size);
	printArr(arr, size);
	deleteZero(arr, size);
	printArr(arr, size);
	cout << size << endl;
	delete[] arr;
	system("pause");
	return 0;
}

template <typename MyT>
void generateArr(MyT arr[], int size) {
	MyT *ptrArr = arr;
	while (ptrArr < (arr + size)) {
		*ptrArr = rand() % 11 - 5;
		ptrArr++;
	}
}

template <typename MyT>
void printArr(MyT arr[], int size) {
	MyT *ptrArr = arr;
	if (size == 0) cout << "aray is empty";
	while (ptrArr < (arr + size)) {
		//printf("%2d   ", *ptrArr);
		cout << *ptrArr << "\t";
		ptrArr++;
	}
	cout << endl;
}
