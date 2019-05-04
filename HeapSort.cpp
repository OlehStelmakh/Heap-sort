#include <iostream>
#include <ctime>

using namespace std;

int sizeOfArray();
int* createArray(int size);
void randomFunc(int* arr, int size);
void outputFunc(int* arr, int size);
void heapSort(int* arr, int size);
void siftDown(int* arr, int root, int bottom, int size, int& countPerm, int& countComp);

int main() {
	int size = sizeOfArray();
	int* arr = createArray(size);
	randomFunc(arr, size);
	outputFunc(arr, size);
	heapSort(arr, size);
	outputFunc(arr, size);
}

int sizeOfArray() {
	int size;
	cout << "Enter a size of array: ";
	cin >> size;
	return size;
}

int* createArray(int size) {
	int* tempArr = new int[size];
	return tempArr;
}

void randomFunc(int* arr, int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
	}
}

void outputFunc(int* arr, int size) {
	cout << "[ ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}

void heapSort(int* arr, int size) {
	int countComp = 0;
	int countPerm = 0;
	for (int i = (size / 2) - 1; i >= 0; i--) {
		siftDown(arr, i, size - 1, size, countPerm, countComp);
	}
	for (int i = size - 1; i >= 1; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		countPerm++;
		siftDown(arr, 0, i - 1, size, countPerm, countComp);

	}
	cout << "Comparison: " << countComp << endl;
	cout << "Permurations: " << countPerm << endl;
}

void siftDown(int* arr, int root, int bottom, int size, int& countPerm, int& countComp) {
	int maxChild;
	bool done = false; 

	while ((root * 2 <= bottom) && (!done)) {
		if (root * 2 == bottom) {
			maxChild = root * 2; 
		}
		else if (arr[root * 2] > arr[root * 2 + 1]) {
			maxChild = root * 2;
		}
		else {
			maxChild = root * 2 + 1;
		}
		countComp++;
	
		if (arr[root] < arr[maxChild]) {
			int temp = arr[root];
			arr[root] = arr[maxChild];
			arr[maxChild] = temp;
			countPerm++;
			root = maxChild;
		}
		else { done = true; }
		outputFunc(arr, size);
	}
}
