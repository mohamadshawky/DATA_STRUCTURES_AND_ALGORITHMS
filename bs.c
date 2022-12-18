/******************************************************************************************************************************
Author: Mohamed Shawky

Date: 05/08/2022

Description: Binary Search.
******************************************************************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool binarysearch(int[], int, int);

void main(void){
	
	//variables declartion
	int arr [100], size=0, value=0;
	bool flag = false;

	
	printf("Array size = ");
	scanf("%d", &size);				//inputs array size
	
	printf("Array elements (Sorted in ascending order) = \n");
	for (int i =0 ; i<size; i++){	//inputs array elements
		scanf("%d", &arr[i]);
	}
	
	printf("Value = ");
	scanf("%d", &value);			//inputs value to search
	
	flag = binarysearch(arr, size, value);
	
	if (flag){
		printf("%d is found", value);
	}
	else {
		printf("%d is not found", value);
	}
}


bool binarysearch(int a[], int size, int val){
	
	int low =0, high = size-1;
	
	while(low <= high){	//to check if the number is not found
		
		int mid = low + (high-low)/2;
		
		if (val == a[mid]){
			return true;
		}
		else if (val > a[mid]){
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return false;
}