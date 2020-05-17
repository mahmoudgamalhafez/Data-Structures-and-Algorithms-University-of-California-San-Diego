#include <stdio.h>

int optimal_weight(int W,int n,int w[] ) {
   int value[n+1][W+1];
   int val;
   for(int i=0;i<=n;i++){

	   value[i][0]=0;
   }	
   for(int i=0;i<=W;i++){
	   value[0][i]=0;
   }	
  //write your code here
  for(int i=1;i<=n;i++){
	  for(int j=1;j<=W;j++){
		  value[i][j]=value[i-1][j];
		  if(w[i-1]<=j){
			val=value[i-1][j-w[i-1]]+w[i-1];
			if(val>value[i][j])
				value[i][j]=val;
				
		  }
		

	  }
	 
  }
 
  return value[n][W];
}

int main() {
  int n, W;
  scanf("%d%d",&W,&n);
  int weighs[n];
  for (int i = 0; i < n; i++) {
    scanf("%d",&weighs[i]);
  }
  printf("%d",optimal_weight(W,n,weighs));
}
