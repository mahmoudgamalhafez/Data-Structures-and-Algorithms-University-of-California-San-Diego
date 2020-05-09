#include <stdio.h>

int get_majority_element(int a[], int left,int right) 
{
	
    if (left == right) return -1;
    if (left + 1 == right) return a[left];

    int left_elem = get_majority_element(a, left, (left + right - 1) / 2 + 1);
    int right_elem = get_majority_element(a, (left + right - 1) / 2 + 1, right);

    int lcount = 0;
    for (int i = left; i < right; i++) {
        if (a[i] == left_elem) lcount += 1;
    }
    if (lcount > (right - left) / 2) return left_elem;

    int rcount = 0;
    for (int i = left; i < right; i++) {
        if (a[i] == right_elem) rcount += 1;
    }
    if (rcount > (right - left) / 2) return right_elem;

    return -1;

}


int main() {
  int n;
  scanf("%d",&n);
  int  Arr[n];
  for (int i = 0; i < n; i++) {
	  scanf("%llu",&Arr[i]);
  }
  printf("%d",get_majority_element(Arr,0,n)!=-1);
  
}
