#include <stdio.h>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
	int reminder;
	if(b==0)
		return a;
	else if(a==0){
		return b;
	}
	
	if(a>b){
		reminder=a%b;
		return  gcd_fast(b,reminder);
	}
	else{
		reminder=b%a;
		return  gcd_fast(a,reminder);
	}
		
}

int main() {
    int a,b ;
	scanf("%d",&a);
	scanf("%d",&b);
    
	printf("%d \n",gcd_fast(a,b));
    //test_solution();
    //std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
