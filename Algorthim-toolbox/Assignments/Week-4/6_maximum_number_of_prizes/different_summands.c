#include <stdio.h>

#define LENGTH  100000
void optimal_summands(int n) {
   int summands[LENGTH];
   int count=0;
   for(int i=1;i<=n;i++){
	   n-=i;
	   if (n <= i){
            summands[count++]=n+i;
            break;
	   }
       else if( n == 0){
            summands[count++]=i;
            break;
		}
       else
            summands[count++]=i;
		
   
   }
   printf("%d\n",count);
   for(int j =0;j<count;j++)
	   printf("%d  ",summands[j]);
  //write your code here
  return ;
}

int main() {
  int n;
  scanf("%d",&n);
  
  optimal_summands(n);
  
 
}

