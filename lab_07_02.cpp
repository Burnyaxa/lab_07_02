#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

#define ARRAY_RANGE (100 - 50)*0.1 

float *createArray(int n);
void initializeArray(float *arr, int n);
void outputArray(float *arr, int n);
float getMaxNeighbourDifference(float *arr, int n);
float getMinNeighbourDifference(float *arr, int n);

int _tmain(int argc, _TCHAR* argv[])
{
	bool integer = false;
	float n;
	while (integer == false){
		cout << "Insert a size of the array :  "; cin >> n;
		if (n == int(n) && n > 0){
			integer = true;
		}
		else {
			cout << "Error. Natural number expected." << endl;
		}
	}
	float *arr = createArray(n);
	initializeArray(arr, n);
	outputArray(arr,n);
	if (n > 1){
		cout << "Max difference between neighbour elements : " << getMaxNeighbourDifference(arr, n) << endl;
		cout << "Min difference between neighbour elements : " << getMinNeighbourDifference(arr, n) << endl;
	}
	else {
		cout << "There are no neightbour elements." << endl;
	}
	system("pause");
	return 0;
}

float *createArray(int n){
	srand(time(0));
	float *arr = new float[n];
	return arr;
}

void initializeArray(float *arr, int n){
	for (int i = 0; i < n; i++){
		arr[i] = rand() % ARRAY_RANGE;
	}
}

void outputArray(float *arr, int n){
	cout << "Your array B(n): ";
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

float getMaxNeighbourDifference(float *arr, int n){
	float max_diff = 0;
	for (int i = 1; i < n; i++){
		if (fabs(arr[i] - arr[i - 1]) > max_diff){
			max_diff = fabs(arr[i] - arr[i - 1]);
		}
	}
	return max_diff;
}

float getMinNeighbourDifference(float *arr, int n){
	float min_diff = fabs(arr[0] - arr[1]);
	for (int i = 1; i < n; i++){
		if (fabs(arr[i] - arr[i - 1]) < min_diff){
			min_diff = fabs(arr[i] - arr[i - 1]);
		}
	}
	return min_diff;
}
