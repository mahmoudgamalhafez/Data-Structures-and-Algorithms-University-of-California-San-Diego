#include <stdio.h>

int get_change(int m) {
  //write your code here
  int num_of_Coins;
  int Coins[3]={1,3,4};
  int Min_Num_OF_Coins[m+1];
  for(int i=0;i<m+1;i++)
	  Min_Num_OF_Coins[i]=0;
  
  for(int i=1;i<=m;i++){
	   Min_Num_OF_Coins[i]=1000000;
	  for(int j=1;j<=3;j++){
		  if(i>=Coins[j-1]){
			num_of_Coins=Min_Num_OF_Coins[i-Coins[j-1]]+1;
			//printf("%d\n",num_of_Coins);
			if(num_of_Coins<Min_Num_OF_Coins[i])
				Min_Num_OF_Coins[i]=num_of_Coins;
				
		  }
		  
	  }
  }
  
  return Min_Num_OF_Coins[m];
}

int main() {
  int m;
  scanf("%d",&m);
  
  printf("%d",get_change(m));
  
 }
