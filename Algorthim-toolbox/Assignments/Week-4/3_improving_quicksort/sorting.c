#include <stdio.h>
#include <stdlib.h> 

 int m1 ,m2;
// This function swaps values pointed by xp and yp 
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void partition2(int a[], int l, int r) {
  int x = a[l];
  int j = l;
  int k;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(&a[i],&a[j]);
    }
  }
  
  swap(&a[l],&a[j]);
  for(int i=l;i<j;i++){
	  if(a[i]==a[j]){
		  swap(&a[i],&a[j]);
	  }
  }
  k=j-1;
  for(int i=j+1;i<r;i++){
	  if(a[i]==a[j]){
		  swap(&a[i],&a[k--]);
	  }
  }
 
  m1=k+1;
  k=j+1;
  for(int i=j+1;i<r;i++){
	  if(a[i]==a[j]){
		  swap(&a[i],&a[k++]);
	  }
  }
  m2=k-1;
  return ;
}

void randomized_quick_sort(int a[] , int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(&a[l],&a[k]);
  partition2(a, l, r);
  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}

int main() {
  int n;
  scanf("%d",&n);
  int  Arr[n];
  for (int i = 0; i < n; i++) {
	  scanf("%d",&Arr[i]);
  }
  randomized_quick_sort(Arr, 0,n);
  for (int i = 0; i < n; i++) {
	  printf("%d ",Arr[i]);
  }
}