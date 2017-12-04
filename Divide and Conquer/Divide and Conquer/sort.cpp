#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 100000

int *arr_add = (int *)malloc(sizeof(int)*N);
int *sort_data = (int *)malloc(sizeof(int)*N);
int data[N];
void bubble_sort(int *arr, int n);
void selection_sort(int *arr, int n);
void insertion_sort(int *arr, int n);
void merge(int *arr, int first, int middle, int last);
void merge_sort(int *arr, int first, int last);
int partition_l(int *arr, int first, int last);
void quickSort_l(int *arr, int first, int last);
int partition_f(int *arr, int first, int last);
void quickSort_f(int *arr, int first, int last);
int partition_m(int *arr, int first, int last);
void quickSort_m(int* array, int start, int end);
void swap(int* a, int* b);

void printdata(int *data, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}
int main()
{
	clock_t before, after;

	int original[N];// , data[N];

	for (int i = 0; i < N; i++) {
		original[i] = rand() % N;
	}
	for (int i = 0; i < N; i++) {
		sort_data[i] = i;
	}

	/*memcpy(data, original, N*sizeof(int));
	before = clock();
	selection_sort(data, N);
	after = clock();
	printf("Selection Sort : %lf\n", (double)(after - before) / CLOCKS_PER_SEC);


	memcpy(data, original, N*sizeof(int));
	before = clock();
	bubble_sort(data, N);
	after = clock();
	printf("Bubble Sort : %lf\n", (double)(after - before) / CLOCKS_PER_SEC);


	memcpy(data, original, N*sizeof(int));
	before = clock();
	insertion_sort(data, N);
	after = clock();
	printf("insertionSort : %lf\n", (double)(after - before) / CLOCKS_PER_SEC);*/


	memcpy(data, original, N * sizeof(int));
	before = clock();
	merge_sort(data, 0, N - 1);
	after = clock();
	printf("MergeSort : %lf\n", (double)(after - before) / CLOCKS_PER_SEC);

	/*  [pivot이 last일때]    */

	memcpy(data, original, N * sizeof(int));
	//printdata(data, N);
	before = clock();
	quickSort_l(data, 0, N - 1);
	after = clock();
	printf("QuickSort(Select middle pivot) : %lf\n", (double)(after - before) / CLOCKS_PER_SEC);
	//printdata(data, N);

	/*  [pivot이 first일때]   */

	memcpy(data, original, N*sizeof(int));	
	//printdata(data, N);
	before = clock();
	quickSort_f(data, 0, N - 1);
	after = clock();
	printf("QuickSort(pivot in first) : %lf\n", (double)(after - before) / CLOCKS_PER_SEC);
	//printdata(data, N);

	/*  [pivot이 middle일때]  */

	memcpy(data, original, N*sizeof(int));	
	//printdata(data, N);
	before = clock();
	quickSort_m(data, 0, N - 1);
	after = clock();
	printf("QuickSort(pivot in middle) : %lf\n", (double)(after - before) / CLOCKS_PER_SEC);
	//printdata(data, N);

	/*memcpy(data, sort_data, N*sizeof(int));
	before = clock();
	quickSort(data, 0, N - 1);
	after = clock();
	printf("QuickSort : %lf\n", (double)(after - before) / CLOCKS_PER_SEC);*/

}

void bubble_sort(int *arr, int n)
{
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j]>arr[j + 1]) {
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void selection_sort(int *arr, int n)
{
	int max = 0;
	int index = 0;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++)
			if (arr[j]>arr[index]) {
				max = arr[j];
				index = j;
			}
		arr[index] = arr[i];
		arr[i] = max;
		max = 0, index = 0;
	}
}
void insertion_sort(int *arr, int n)
{
	for (int i = 1; i < n; i++) {
		int tmp = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			if (tmp <= arr[j]) {
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void merge(int *arr, int first, int middle, int last)
{
	int i = first, j = middle + 1, k = first;
	while (i <= middle && j <= last) {
		if (arr[i] <= arr[j])
			arr_add[k++] = arr[i++];
		else
			arr_add[k++] = arr[j++];
	}
	while (i <= middle)
		arr_add[k++] = arr[i++];
	while (j <= last)
		arr_add[k++] = arr[j++];
	for (int i = first; i <= last; i++)
		arr[i] = arr_add[i];
}

void merge_sort(int *arr, int first, int last)
{
	if (first < last) {
		int middle = (first + last) / 2;
		merge_sort(arr, first, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, first, middle, last);
	}
}

void quickSort_l(int *arr, int first, int last)
{
	if (first <= last) {
		int q = partition_l(arr, first, last);
		quickSort_l(arr, first, q - 1);
		quickSort_l(arr, q + 1, last);
	}

}
int partition_l(int *arr, int first, int last)
{
	int middle = (first + last) / 2;

	if ((first >= middle && middle >= last) || last >= middle && middle >= first) {
		int tmp = arr[middle];
		arr[middle] = arr[last];
		arr[last] = tmp;
	}
	else if ((middle >= first && first >= last) || (last >= first && first >= middle)) {
		int tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}

	int x = arr[last];
	int i = first - 1;
	for (int j = first; j < last; j++) {
		if (arr[j] <= x) {
			i++;
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}

	}
	int tmp2 = arr[i + 1];
	arr[i + 1] = arr[last];
	arr[last] = tmp2;

	return i + 1;
}

void quickSort_f(int *arr, int first, int last)
{
	if (first <= last) {
		int q = partition_f(arr, first, last);
		quickSort_f(arr, first, q - 1);
		quickSort_f(arr, q + 1, last);
	}
}

int partition_f(int *arr, int first, int last)
{
	int x = arr[first];
	int i = first;
	for (int j = i + 1; j < last; j++) {
		if (arr[j] <= x) {
			i++;
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	//first와 i의 자리 바꿔주기
	int tmp2 = arr[first];
	arr[first] = arr[i];
	arr[i] = tmp2;

	return i;
}

void quickSort_m(int* array, int start, int end) {

	if (start >= end) return;

	int mid = (start + end) / 2;
	int pivot = array[mid];

	swap(&array[start], &array[mid]);

	int p = start + 1, q = end;

	while (1) {
		while (array[p] <= pivot) { p++; }
		while (array[q]>pivot) { q--; }

		if (p>q) break;

		swap(&array[p], &array[q]);
	}

	swap(&array[start], &array[q]);

	quickSort_m(array, start, q - 1);
	quickSort_m(array, q + 1, end);

}
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}