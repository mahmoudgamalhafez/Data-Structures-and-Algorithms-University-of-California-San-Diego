#include <stdio.h>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    unsigned long long int  previous = 0;
    unsigned long long int current  = 1;
	unsigned long long int tmp_previous;
    for (int i = 0; i < n - 1; ++i) {
        tmp_previous = (previous%10);
        previous = (current%10);
        current = (tmp_previous + current)%10;
    }

    return current ;
}


int main() {
    int n ;
	scanf("%d",&n);
    
	printf("%d \n",get_fibonacci_last_digit_naive(n));
    //test_solution();
    //std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
