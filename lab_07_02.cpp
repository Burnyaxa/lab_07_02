// lab_07_02.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;
double *create_array(int n);
void output_array(double *arr, int n);
double max_diff(double *arr, int n);
double min_diff(double *arr, int n);
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cout << "n = "; cin >> n;
	double *arr = create_array(n);
	output_array(arr,n);
	cout << "Max difference between neighbour elements : " << max_diff(arr, n)<<endl;
	cout << "Min difference between neighbour elements : " << min_diff(arr, n) << endl;
	system("pause");
	return 0;
}
double *create_array(int n){
	double *arr = new double[n];
	return arr;
 }
void output_array(double *arr, int n){
	srand(time(NULL));
	cout << "B(n): ";
	for (int i = 0; i < n; i++){
		arr[i] = (rand() % 100 - 50) * 0.1;
		cout << arr[i] << " ";
	}
	cout << endl;
}
double max_diff(double *arr, int n){
	double max_diff = abs(arr[0] - arr[1]);
	for (int j = 2; j < n; j++){
		if (abs(arr[j] - arr[j - 1])>max_diff){
			max_diff = abs(arr[j] - arr[j - 1]);
		}
	}
	return max_diff;
}
double min_diff(double *arr, int n){
	double min_diff = abs(arr[0] - arr[1]);
	for (int g = 2; g < n; g++){
		if (abs(arr[g] - arr[g - 1]) < min_diff){
			min_diff = abs(arr[g] - arr[g - 1]);
		}
	}
	return min_diff;
}
