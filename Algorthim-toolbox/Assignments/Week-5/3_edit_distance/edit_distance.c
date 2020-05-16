#include <stdio.h>
#include <string.h>

#define MAX_LENGTH	100
int smallest(int a, int b, int c) 
{ 
	int min;
   if( (a<b) && (a<c) )
   {
      min = a;
   }
   else if(b<c)
   {
      min = b;
   }
   else
   {
      min = c;
   }
   return min;
} 
int edit_distance(char  str1[],char str2[],int n ,int m) {
  //write your code here
  
  int D[n+1][m+1];
  for(int i=0;i<n+1;i++)
	  D[i][0]=i;
  for(int i=0;i<m+1;i++)
	  D[0][i]=i;
  
  for(int i=1;i<=n;i++){
	  for(int j=1;j<=m;j++){
		  if(str1[i-1]==str2[j-1]){
			  D[i][j]=smallest(D[i-1][j-1],D[i-1][j]+1,D[i][j-1]+1);
		  }
		  else{
			  D[i][j]=smallest(D[i-1][j-1]+1,D[i-1][j]+1,D[i][j-1]+1);
		  }
	  }
  }
  return D[n][m];
}

int main() {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];
  int n ,m ;
  scanf("%s",str1);
  scanf("%s",str2);
  n=strlen(str1);
  m=strlen(str2);
  printf("%d",edit_distance(str1,str2,n,m));
  return 0;
}