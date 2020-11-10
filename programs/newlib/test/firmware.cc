#include <iostream>
using namespace std;
#define LO 0.00
#define HI 10.00

int main () {
	float *array;
	array = new float [10];
	cout << "Created a dynamic array of size 10" <<std::endl;
	
	for (int i=0; i<10; i++) {
		array[i] = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));;
	}
	cout << "Loaded array with natural random floating pt numbers" <<std::endl;

	cout << "Printig the array"<<std::endl;

	for (int i=0; i<10; i++) {
		printf("array[%d] -> %f\n", i, array[i]);
	}

	delete[] array;
	cout << "deleted the array"<<std::endl;
	return 0; 
}