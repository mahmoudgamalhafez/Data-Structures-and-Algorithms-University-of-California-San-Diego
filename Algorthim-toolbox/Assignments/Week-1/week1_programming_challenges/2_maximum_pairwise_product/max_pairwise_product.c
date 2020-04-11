#include <stdio.h>
#include <stdlib.h>

long long MaxPairwiseProduct(long long num[],long long n)
{
    long long max_index=0;
    int temp ;
    int i;
    for(i=1;i<n;i++){
        if(num[i]>num[max_index])
            max_index=i;
    }
    temp=num[n-1];
    num[n-1]=num[max_index];
    num[max_index]=temp;

    max_index=0;
    for(i=1;i<n-1;i++){
        if(num[i]>num[max_index])
            max_index=i;
    }
    return num[max_index]*num[n-1];
}
int main()
{
	int i;
	
    long long n ;
	
    scanf("%llu",&n);
    long long numbers[n];
	
    for(i=0;i<n;i++){
		
        scanf("%llu",&numbers[i]);
    }
	printf("%llu",MaxPairwiseProduct(numbers,n));
    return 0;
}

