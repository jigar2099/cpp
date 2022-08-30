#include<iostream>
using namespace std;

int getMin(int numbers[], int size) {
	int min = numbers[0];
	for (int i = 1; i < size; i++) {
		if (numbers[i] < min)
			min = numbers[i];
	}
	return min;
}
int getMax(int numbers[], int size) {
	int max = numbers[0];
	for (int i = 0; i < size; i++) {
		if (numbers[i] > max)
			max = numbers[i];
	}
	return max;
}

void getMinMax(int numbers[], int size, int* min, int* max) {
	for (int i = 0; i < size; i++) {
		if (numbers[i] > *max)
			*max = numbers[i];
		if (numbers[i] < *min)
			*min = numbers[i];
	}
}


int main() {
	int numbers[5] = { -1,-3,-4,5,6 };
	//cout << "Min is :" << getMin(numbers, 5)<<endl;
	//cout << "Max is : " << getMax(numbers, 5)<<endl;
	int min = numbers[0];
	int max = numbers[0];
	getMinMax(numbers, 5, &min, &max);
	cout << "Min is : " << min << " and Max is : " << max << endl;

	return 0;
}