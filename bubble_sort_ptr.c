/******************************************************************************************************************************
Author: Mohamed Shawky

Date: 15/08/2022

Description: Bubble sort using pointers.
******************************************************************************************************************************/
#include <stdio.h>

int* bubble_sort(int*, int);
void main(){
	
	//variables declartion
	int arr [100], size, *ptr = NULL;
	
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
	
	ptr = bubble_sort(arr, size);
	
	printf("Elements after sorting = ");
	for (int i =0 ; i<size; i++){	//display elements after sorting
		printf("%d ", *(ptr + i));
	}
	
	
}

int* bubble_sort(int* a, int size){
for (int i = 0; i < size - 1; i++){
		for (int j =0; j < size - i - 1;j++){
			if (*(a+j) > *((a+j)+1)){		//swap elements
				*(a+j) 	   ^= *((a+(j+1));
				*(a+(j+1)) ^= *(a+j);
				*(a+j)	   ^= *((a+(j+1));
			}	
		}
	}
return a;	
}