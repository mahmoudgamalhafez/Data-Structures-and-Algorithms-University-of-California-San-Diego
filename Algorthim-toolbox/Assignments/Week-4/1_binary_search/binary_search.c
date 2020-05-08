#include <stdio.h>


int binary_search(long long int arr[],int n, long long int x) {
  int low = 0, high = n; 
  int mid;
  
  //write your code here
  while(low<=high)
  {
	 mid=(int)(low+((high-low)/2.0));
	 if(x==arr[mid])
		 return mid;
	 else if(x<arr[mid])
		 high=mid-1;
	 else
		 low=mid+1;
  }
  return -1;
}
/*
int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}*/

int main() {
  int n;
  scanf("%d",&n);
  long long int  Arr[n];
  for (int i = 0; i < n; i++) {
	  scanf("%llu",&Arr[i]);
  }
  int m;
  scanf("%d",&m);
  long long int  a[m];
  for (int i = 0; i < m; i++) {
	  scanf("%llu",&a[i]);
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
	printf("%d  ",binary_search(Arr,n,a[i]));
	
  }
}
