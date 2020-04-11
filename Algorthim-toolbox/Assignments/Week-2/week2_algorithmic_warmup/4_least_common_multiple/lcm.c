#include <stdio.h>

int gcd_fast(int a, int b) ;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}


long long lcm_fast(int a , int b)
{
	return (long long )(a/gcd_fast(a,b))*b;
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
    
	printf("%llu \n",lcm_fast(a,b));
    //test_solution();
    //std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
