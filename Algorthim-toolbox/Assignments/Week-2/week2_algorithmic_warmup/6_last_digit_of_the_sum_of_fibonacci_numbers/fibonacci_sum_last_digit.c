#include <stdio.h>

int fibonacci_sum_naive(unsigned long long int n) {
	if (n <= 1)
        return n;
	
	//printf("%llu\n", n);

    unsigned long long int  previous = 0;
    unsigned long long int current  = 1;
	unsigned long long int tmp_previous;
	unsigned long long int last_digit=1;
    for (unsigned long long int i = 0; i < n-1 ; ++i) {
        tmp_previous = (previous%10);
        previous = (current%10);
        current = (tmp_previous + current)%10;
		last_digit+=current;
    }

    return last_digit%10 ;
}



int main() {
    unsigned long long int  n ;
	scanf("%llu",&n);
	
	//printf("%llu\n", n);
    
	printf("%d \n",fibonacci_sum_naive(n));
    //test_solution();
    //std::cout << fibonacci_fast(n) << '\n';
    return 0;
}