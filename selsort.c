/******************************************************************************************************************************
Author: Mohamed Shawky

Date: 05/08/2022

Description: Selection sort.
******************************************************************************************************************************/
#include <stdio.h>

void selsort(int a[], int size);

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
	
	selsort(arr, size);				//call selection sort

	printf("\nElements after sorting = ");
	for (int i =0 ; i<size ; i++){	//display after before sorting
		printf("%d ", arr[i]);
	}	
}

void selsort(int a[], int size){
	
	for (int i = 0; i < size - 1; i++){
		int min = i;
		for (int j = i + 1; j < size; j++){	//find minimum index each iteration
			if (a[min] > a[j]){
				min = j;
			}	
		}	//swap
		if(min!=i){		
		a[min] += a[i];
		a[i]   = a[min]-a[i];
		a[min] = a[min]-a[i];	
		}
	}
}