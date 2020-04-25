#include <stdio.h>

int get_change(int m) {
  //write your code here
	static int num_of_coins=0;
	if(m==0)
		return  num_of_coins;
	if(m>=10)
		m-=10;
	else if(m>=5)
		m-=5;
	else
		m--;
	  
	num_of_coins++;
	get_change(m);
}

int main() {
  int m;
  scanf("%d",&m);
 
  printf("%d",get_change(m));
}