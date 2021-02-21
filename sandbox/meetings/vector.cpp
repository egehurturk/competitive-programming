/*
Vector: Dynamically resible array
When the memory is full, allocate a 2x memory and copy the vector to the new memory (Repeat this)
*/


#include <iostream>

using namespace std;

class cvector {
public:
	int size;
	int maxsize;
	int* start;

	cvector() {
		size = 0;
		maxsize = 1;
		start = (int *) malloc(1 * sizeof(int));
	}
	cvector(int _size) {
		if (_size < 1)
			_size = 1;
		maxsize = _size;
		start = (int *) malloc(maxsize * sizeof(int));
	}

	int operator[](int index) {
		if (index < size)
			return start[index];
		return -1;
	}

	void push_back(int value) {
		start[size++] = value;
		if (size == maxsize) {
			maxsize *= 2;
			int* new_start = (int* ) malloc(maxsize * sizeof(int));

			for (int i = 0; i < size; i++) 
				*(new_start + i) = *(start + i);

			int* temp = start;
			start = new_start;
			free(temp);
		}
	}

	void pop_back() {
		size--;
	}

	int getsize() {
		return size;
	}
};



int main(void) {
	cvector vct(1);
	vct.push_back(2);
	vct.push_back(8);
	vct.push_back(6);
	vct.push_back(11);
	vct.pop_back();
	vct.pop_back();

	for (int i = 0; i < vct.getsize(); i++) 
		printf("%d\n", vct[i]);
}








