#include <stdio.h>


int get_max_index(int a[],int n)
{
	int max_j = 0;
    long long max =-5000000000;
	for (int j = 0; j < n; j++) {
		if(a[j]!=0&& max< a[j]){
			max_j = j;
			max=a[j];
		}
	}
	
	return max_j;
}
long long max_dot_product(int a[],int b[],int n) {
  // write your code here
  int max_a,max_b;
  long long result = 0;
  for (int i = 0; i < n; i++) {
	max_a=get_max_index(a,n);
	max_b=get_max_index(b,n);
    result += ((long long) a[max_a]) * b[max_b];
	a[max_a]=0;
	b[max_b]=0;
  }
  return result;
}
int main() {
  int n;
  scanf("%d",&n);
  int a[n],b[n];
  for (int i = 0; i < n; i++) {
    scanf("%d",&a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d",&b[i]);
  }
  printf("%lld",max_dot_product(a,b,n));
}
