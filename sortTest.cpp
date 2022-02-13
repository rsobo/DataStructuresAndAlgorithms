/*
 * sortTest.cpp
 *
 *  Created on: Nov 25, 2020
 *      Author: ryans
 */
#include <iostream>
#include "sorting.h"
#include <random>
#include <time.h>
using namespace std;

void printArray(int a[]) {
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ", ";
	}
}

void reset(int sorted[], int reverse[], int random[]) {
	for (int i = 10; i >= 0; i--) {
		reverse[i] = 10 - i;
	}
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		random[i] = rand() % 10 + 1;
		sorted[i] = i + 1;
	}

}

void insertion(int sorted[], int reverse[], int random[]) {
	cout << "\n----------------------------------------\nInsertion Sort:\nSorted->Sorted = ";
	insertionSort(sorted, 0, 10, false);
	printArray(sorted);
	cout << "\nSorted->Reverse = ";
	insertionSort(sorted, 0, 10, true);
	printArray(sorted);
	cout << "\nReverse->Sorted = ";
	insertionSort(reverse, 0, 10, false);
	printArray(reverse);
	cout << "\nReverse->Reverse = ";
	insertionSort(reverse, 0, 10, true);
	printArray(reverse);
	cout << "\nRandom->Sorted = ";
	insertionSort(random, 0, 10, false);
	printArray(random);
	cout << "\nRandom->Reverse = ";
	insertionSort(random, 0, 10, true);
	printArray(random);
	reset(sorted, reverse, random);
}

void selection(int sorted[], int reverse[], int random[]) {
	cout << "\n----------------------------------------\nSelection Sort:\nSorted->Sorted = ";
	selectionSort(sorted, 0, 10, false);
	printArray(sorted);
	cout << "\nSorted->Reverse = ";
	selectionSort(sorted, 0, 10, true);
	printArray(sorted);
	cout << "\nReverse->Sorted = ";
	selectionSort(reverse, 0, 10, false);
	printArray(reverse);
	cout << "\nReverse->Reverse = ";
	selectionSort(reverse, 0, 10, true);
	printArray(reverse);
	cout << "\nRandom->Sorted = ";
	selectionSort(random, 0, 10, false);
	printArray(random);
	cout << "\nRandom->Reverse = ";
	selectionSort(random, 0, 10, true);
	printArray(random);
	reset(sorted, reverse, random);
}

void shell(int sorted[], int reverse[], int random[]) {
	cout << "\n----------------------------------------\nShell Sort:\nSorted->Sorted = ";
	shellSort(sorted, 0, 10, false);
	printArray(sorted);
	cout << "\nSorted->Reverse = ";
	shellSort(sorted, 0, 10, true);
	printArray(sorted);
	cout << "\nReverse->Sorted = ";
	shellSort(reverse, 0, 10, false);
	printArray(reverse);
	cout << "\nReverse->Reverse = ";
	shellSort(reverse, 0, 10, true);
	printArray(reverse);
	cout << "\nRandom->Sorted = ";
	shellSort(random, 0, 10, false);
	printArray(random);
	cout << "\nRandom->Reverse = ";
	shellSort(random, 0, 10, true);
	printArray(random);
	reset(sorted, reverse, random);
}

void bucket(int sorted[], int reverse[], int random[]) {
	cout << "\n----------------------------------------\nBucket Sort:\nSorted->Sorted = ";
	bucketSort(sorted, 0, 10, false);
	printArray(sorted);
	cout << "\nSorted->Reverse = ";
	bucketSort(sorted, 0, 10, true);
	printArray(sorted);
	cout << "\nReverse->Sorted = ";
	bucketSort(reverse, 0, 10, false);
	printArray(reverse);
	cout << "\nReverse->Reverse = ";
	bucketSort(reverse, 0, 10, true);
	printArray(reverse);
	cout << "\nRandom->Sorted = ";
	bucketSort(random, 0, 10, false);
	printArray(random);
	cout << "\nRandom->Reverse = ";
	bucketSort(random, 0, 10, true);
	printArray(random);
	reset(sorted, reverse, random);
}

void heap(int sorted[], int reverse[], int random[]) {
	cout << "\n----------------------------------------\nHeap Sort:\nSorted->Sorted = ";
	heapSort(sorted, 0, 10, false);
	printArray(sorted);
	cout << "\nSorted->Reverse = ";
	heapSort(sorted, 0, 10, true);
	printArray(sorted);
	cout << "\nReverse->Sorted = ";
	heapSort(reverse, 0, 10, false);
	printArray(reverse);
	cout << "\nReverse->Reverse = ";
	heapSort(reverse, 0, 10, true);
	printArray(reverse);
	cout << "\nRandom->Sorted = ";
	heapSort(random, 0, 10, false);
	printArray(random);
	cout << "\nRandom->Reverse = ";
	heapSort(random, 0, 10, true);
	printArray(random);
	reset(sorted, reverse, random);
}

void quick(int sorted[], int reverse[], int random[]) {
	cout << "\n----------------------------------------\nQuick Sort:\nSorted->Sorted = ";
	quickSort(sorted, 0, 10, false);
	printArray(sorted);
	cout << "\nSorted->Reverse = ";
	quickSort(sorted, 0, 10, true);
	printArray(sorted);
	cout << "\nReverse->Sorted = ";
	quickSort(reverse, 0, 10, false);
	printArray(reverse);
	cout << "\nReverse->Reverse = ";
	quickSort(reverse, 0, 10, true);
	printArray(reverse);
	cout << "\nRandom->Sorted = ";
	quickSort(random, 0, 10, false);
	printArray(random);
	cout << "\nRandom->Reverse = ";
	quickSort(random, 0, 10, true);
	printArray(random);
	reset(sorted, reverse, random);
}

void radix(int sorted[], int reverse[], int random[]) {
	cout << "\n----------------------------------------\nRadix Sort:\nSorted->Sorted = ";
	radixSort(sorted, 0, 10, false);
	printArray(sorted);
	cout << "\nSorted->Reverse = ";
	radixSort(sorted, 0, 10, true);
	printArray(sorted);
	cout << "\nReverse->Sorted = ";
	radixSort(reverse, 0, 10, false);
	printArray(reverse);
	cout << "\nReverse->Reverse = ";
	radixSort(reverse, 0, 10, true);
	printArray(reverse);
	cout << "\nRandom->Sorted = ";
	radixSort(random, 0, 10, false);
	printArray(random);
	cout << "\nRandom->Reverse = ";
	radixSort(random, 0, 10, true);
	printArray(random);
	reset(sorted, reverse, random);
}

int main() {

	int sorted[10], reverse[10], random[10];
	reset(sorted, reverse, random);
	cout << "Starting arrays:\nSorted = ";
	printArray(sorted);
	cout << "\nReverse = ";
	printArray(reverse);
	cout << "\nRandom = ";
	printArray(random);
	insertion(sorted, reverse, random);
	selection(sorted, reverse, random);
	shell(sorted, reverse, random);
	//bucket(sorted, reverse, random);
	heap(sorted, reverse, random);
	quick(sorted, reverse, random);
	radix(sorted, reverse, random);

	return 0;
}

