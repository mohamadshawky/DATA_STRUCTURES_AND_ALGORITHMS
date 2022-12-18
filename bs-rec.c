/******************************************************************************************************************************
Author: Mohamed Shawky

Date: 06/08/2022

Description: Binary search with recursion. 
******************************************************************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool binarysearch (int [], int, int, int);

void main(){
	
	//variables declartion
	int arr [100], size=0, value=0;
	bool flag;
	
	printf("Array size = ");
	scanf("%d", &size);				//inputs array size
	
	printf("Array elements (Sorted in ascending order) = \n");
	for (int i =0 ; i<size; i++){	//inputs array elements
		scanf("%d", &arr[i]);
	}
	
	printf("Value = ");
	scanf("%d", &value);			//inputs value to search
	
	//call binary search
	flag = binarysearch (arr, value, 0, size-1);

	//display result
	if (flag){printf("%d is found", value);}
	else {printf("%d is not found", value);}	
}

bool binarysearch (int a[], int value, int low, int high){

	int	mid = low + (high - low)/2; 
	
	if (high >= low){		//if value is not exist
		if (a[mid] == value){
			return true;
		}
		else if (value > a[mid]){	
			binarysearch(a,value,mid+1,high);
		}
		else{
			binarysearch(a,value,low,mid-1);
	}}
	else{
		return false;
	}
}