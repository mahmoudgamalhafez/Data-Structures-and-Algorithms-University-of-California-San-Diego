#include <stdio.h>

/*
long long get_number_of_inversions(int a[], int b[], size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}
*/
long long int num_OF_inversions=0;

void merge(int arr[], int l, int m, int r) 
{
	int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
	
	  /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++;
			
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
			num_OF_inversions+=(n1-i);

        } 
        k++; 
    } 
	
	  /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
  

}

void MergeSort(int a[],int left,int right)
{
	if(left<right){
		int m=left+(right-left)/2;
		 // Sort first and second halves 
        MergeSort(a, left, m); 
        MergeSort(a, m+1, right); 
  
        merge(a, left, m, right); 
		
	}
}


void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

int main() {
  int n;
  scanf("%d",&n);
  int  Arr[n];
  for (int i = 0; i < n; i++) 
  {
	  scanf("%d",&Arr[i]);
  }
  MergeSort(Arr,0,n-1);
  //printArray(Arr,n);
  printf("%lld",num_OF_inversions);
}