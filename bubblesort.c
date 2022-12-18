 /******************************************************************************************************************************
Author: Mohamed Shawky

Date: 05/08/2022

Description: Bubble sort.
******************************************************************************************************************************/
#include <stdio.h>

void BubbleSort(int a[], int size);

void main(void){
	
	//variables declartion
	int arr [100], size;
	
	printf("Array size = ");
	scanf("%d", &size);				//inputs array size
	
	printf("Array elements = \n");
	for (int i =0 ; i<size; i++){	//inputs array elements
		scanf("%d", &arr[i]);
	}
	
	printf("Elements before sorting = ");
	for (int i =0 ; i<size; i++){	//display elements before sorting
		printf("%d ", arr[i]);
	}
	
	BubbleSort(arr, size);			//call bubble sort

	printf("\nElements after sorting = ");
	for (int i =0 ; i<size ; i++){	//display after before sorting
		printf("%d ", arr[i]);
	}	
}

void BubbleSort(int a[], int size){	/* Ascending order */
	for (int i = 0; i < size - 1; i++){
		for (int j =0; j < size - i - 1;j++){
			if (a[j] > a[j+1]){		//swap elements
				a[j] ^= a[j+1];
				a[j+1] ^= a[j];
				a[j] ^= a[j+1];
			}	
		}
	}
}