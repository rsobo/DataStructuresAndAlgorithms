/*
 * sorting.h
 *
 *  Created on: Nov 25, 2020
 *      Author: ryans
 */
#ifndef SORTING_H_
#define SORTING_H_

void insertionSort(int data[], int low, int high, bool reversed);

void selectionSort(int data[], int low, int high, bool reversed);

void shellSort(int data[], int low, int high, bool reversed);

void bucketSort(int data[], int low, int high, bool reversed);

void heapSort(int data[], int low, int high, bool reversed);
void heapify(int arr[], int n, int i);

void quickSort(int data[], int low, int high, bool reversed);
int partition(int data[], int low, int high);
int partitionRev(int data[], int low, int high);

void radixSort(int data[], int low, int high, bool reversed);
void countSort(int arr[], int n, int exp);
void countSortRev(int arr[], int n, int exp);

#endif /* SORTING_H_ */
