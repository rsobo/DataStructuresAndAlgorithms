/*
 * sorting.cpp
 *
 *  Created on: Nov 25, 2020
 *      Author: ryans
 */
#include "sorting.h"
#include <vector>
#include <algorithm>
#include <list>
#include <cmath>

//sorts data using insertion sort
void insertionSort(int data[], int low, int high, bool reversed) {
	if (reversed) {
		for (int i = low; i < high; i++) {
			int key = data[i];
			int j = i - 1;
			while (j >= 0 && data[j] < key) {
				data[j + 1] = data[j];
				j = j - 1;
			}
			data[j + 1] = key;
		}
	} else {
		for (int i = low; i < high; i++) {
			int key = data[i];
			int j = i - 1;
			while (j >= 0 && data[j] > key) {
				data[j + 1] = data[j];
				j = j - 1;
			}
			data[j + 1] = key;
		}
	}
}
//sorts data using selection sort
void selectionSort(int data[], int low, int high, bool reversed) {
	if (reversed) {
		int max;
		for (int i = 0; i < high - 1; i++) {
			max = i;
			for (int j = i + 1; j < high; j++) {
				if (data[j] > data[max]) {
					max = j;
				}
			}
			int temp = data[max];
			data[max] = data[i];
			data[i] = temp;
		}
	} else {
		int min;
		for (int i = 0; i < high - 1; i++) {
			min = i;
			for (int j = i + 1; j < high; j++) {
				if (data[j] < data[min]) {
					min = j;
				}
			}
			int temp = data[min];
			data[min] = data[i];
			data[i] = temp;
		}
	}
}
//sorts data using shell sort
void shellSort(int data[], int low, int high, bool reversed) {
	if (reversed) {
		for (int gap = (high - low) / 2; gap > 0; gap /= 2) {
			for (int i = gap; i < (high - low); i++) {
				int temp = data[i];
				int j;
				for (j = i; j >= gap && data[j - gap] < temp; j -= gap) {
					data[j] = data[j - gap];
				}
				data[j] = temp;
			}
		}
	} else {
		for (int gap = (high - low) / 2; gap > 0; gap /= 2) {
			for (int i = gap; i < (high - low); i++) {
				int temp = data[i];
				int j;
				for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
					data[j] = data[j - gap];
				}
				data[j] = temp;
			}
		}
	}
}
//sorts data using bucket sort
void bucketSort(int data[], int low, int high, bool reversed) {
	// 1) Create n empty buckets
	std::vector<int> b[high];

	// 2) Put array elements in different buckets
	for (int i = 0; i < high; i++) {
		int bi = high * data[i]; // Index in bucket
		b[bi].push_back(data[i]);
	}

	// 3) Sort individual buckets
	for (int i = 0; i < high; i++) {
		sort(b[i].begin(), b[i].end());
	}

	// 4) Concatenate all buckets into data[]
	int index = 0;
	for (int i = 0; i < high; i++) {
		for (int j = 0; j < b[i].size(); j++) {
			data[index++] = b[i][j];
		}
	}
}
//sorts data using heap sort
void heapSort(int data[], int low, int high, bool reversed) {
	for (int i = high / 2 - 1; i >= 0; i--)
		heapify(data, high, i); // One by one extract an element from heap
	for (int i = high - 1; i >= 0; i--) { // Move current root to end s
		int temp = data[0];
		data[0] = data[i];
		data[i] = temp;
		heapify(data, i, 0);
	}
}
//heap sort helper method
void heapify(int data[], int n, int i) {
	int largest = i; // Initialize largest as root
	int left = 2 * i + 1; // left = 2*i + 1
	int right = 2 * i + 2; // right = 2*i + 2 // If left child is larger than root
	if (left < n && data[left] > data[largest])
		largest = left; // If right child is larger than largest so far
	if (right < n && data[right] > data[largest])
		largest = right; // If largest is not root
	if (largest != i) {
		int temp = data[i];
		data[i] = data[largest];
		data[largest] = temp;
		heapify(data, n, largest);
	}
}
//sorts data using quick sort
void quickSort(int data[], int low, int high, bool reversed) {
	if (reversed) {
		if (low < high) {
			int pi = partitionRev(data, low, high);
			quickSort(data, low, pi - 1, reversed);
			quickSort(data, pi + 1, high, reversed);
		}
	} else {
		if (low < high) {
			int pi = partition(data, low, high);
			quickSort(data, low, pi - 1, reversed);
			quickSort(data, pi + 1, high, reversed);
		}
	}
}
//quick sort helper method
int partition(int data[], int low, int high) {
	int pivot = data[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (data[j] < pivot) {
			i++;
			int temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	int temp = data[i + 1];
	data[i + 1] = data[high];
	data[high] = temp;
	return (i + 1);
}
//quick sort helper method
int partitionRev(int data[], int low, int high) {
	int pivot = data[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (data[j] > pivot) {
			i++;
			int temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	int temp = data[i + 1];
	data[i + 1] = data[high];
	data[high] = temp;
	return (i + 1);
}
//sorts data using radix sort
void radixSort(int data[], int low, int high, bool reversed) {
	// Do counting sort for every digit
	if (reversed) {
		for (int i = 1; 10 / i > 0; i *= 10) {
			countSortRev(data, (high - low), i);
		}
	} else {
		for (int i = 1; 10 / i > 0; i *= 10) {
			countSort(data, (high - low), i);
		}
	}

}
//radix sort helper method
void countSort(int data[], int n, int exp) {
	int output[n];
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++) {
		count[(data[i] / exp) % 10]++;
	}
	// Change count[i] so that count[i] now contains actual position of this digit in output[]
	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}
	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(data[i] / exp) % 10] - 1] = data[i];
		count[(data[i] / exp) % 10]--;
	}

	// Copy the output array to data[]
	for (i = 0; i < n; i++) {
		data[i] = output[i];
	}
}
//radix sort helper method
void countSortRev(int data[], int n, int exp) {
	int output[n];
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++) {
		count[(data[i] / exp) % 10]++;
	}
	// Change count[i] so that count[i] now contains actual position of this digit in output[]
	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}
	// Build the output array
	for (i = 0; i < n; i++) {
		output[count[(data[i] / exp) % 10] - 1] = data[i];
		count[(data[i] / exp) % 10]--;
	}

	// Copy the output array to data[]
	for (i = 0; i < n; i++) {
		data[i] = output[i];
	}
}
