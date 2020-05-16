#include <stdio.h>

#define MAX_LENGTH	100
/* Utility function to get max of 2 integers */
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int lcs2(int A[], int B[],int n , int m) {
  //write your code here
  int LCS[n+1][m+1];
  for(int i=0;i<n+1;i++)
	  LCS[i][0]=0;
  for(int i=0;i<m+1;i++)
	  LCS[0][i]=0;
  
  for(int i=1;i<=n;i++){
	  for(int j=1;j<=m;j++){
		  if(A[i-1]==B[j-1]){
			  LCS[i][j]=1+LCS[i-1][j-1];
		  }
		  else{
			  LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
		  }
	  }
  }
  return LCS[n][m];
}

int main() {
  int n; 
  scanf("%d",&n);
  int A[n];
  for (int i = 0; i < n; i++) {
    scanf("%d",&A[i]);
  }

  int m; 
  scanf("%d",&m);
  int B[m];
  for (int i = 0; i < m; i++) {
    scanf("%d",&B[i]);
  }
 printf("%d",lcs2(A,B,n,m));
}