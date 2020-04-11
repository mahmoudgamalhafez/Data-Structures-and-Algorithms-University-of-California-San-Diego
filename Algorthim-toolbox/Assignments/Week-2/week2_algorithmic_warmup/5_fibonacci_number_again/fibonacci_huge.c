/*mod 2 ->							 > period 2
mod 3 ->							 > period 8
mod 4 --> 0 1 1 2 3 1 0 1 1 2 3 1     > period 6

mod 5 --> 0 1 1 2 3 0 3 3 1	4 0 4 4 3 2 0     > period 20
mod 6 --> 0 1 1 2 3 1 2 1 3 4 1 5 0 5  */



#include <stdio.h>


long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_pisano(long long m) {
    long long F1 = 0, F2 = 1, F = F1 + F2;
    for (int i = 0; i < m * m; i++) {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
        if (F1 == 0 && F2 == 1) return i + 1;
    }
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    long long remainder = n % get_pisano(m);

    long long F1 = 0, F2 = 1, F = remainder;
    for (int i = 1; i < remainder; i++) {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
    }
    return F % m;
}



int main() {
	long long  a,b ;
	scanf("%llu",&a);
	scanf("%llu",&b);
    
	printf("%llu\n",get_fibonacci_huge_fast(a,b));
    //test_solution();
    //std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
