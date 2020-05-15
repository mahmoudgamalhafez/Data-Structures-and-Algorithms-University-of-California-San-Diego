#include <stdio.h>

void optimal_sequence(int m)
{
	
	int Min_Num_OF_Operations[m+1];
	int predecessor[m+1];
	int sequences[m+1];

	for(int i=0;i<m+1;i++){
	  Min_Num_OF_Operations[i]=0;
	  predecessor[i]=0;
	  sequences[i]=0;
	}
	predecessor[1]=1;
	

	for(int i=2;i<=m;i++){
		Min_Num_OF_Operations[i]=Min_Num_OF_Operations[i-1]+1;
		predecessor[i]=i-1;
		
		if(i%3==0){
			if (Min_Num_OF_Operations[i/3] < Min_Num_OF_Operations[i]) 
			{
				Min_Num_OF_Operations[i] = Min_Num_OF_Operations[i/3] + 1;
				predecessor[i]=i/3;
			}
			
		}
		if(i%2==0){
			if (Min_Num_OF_Operations[i/2] < Min_Num_OF_Operations[i])
			{
				Min_Num_OF_Operations[i] = Min_Num_OF_Operations[i/2] + 1;
				predecessor[i]=i/2;
			}
			
		}
		
	}
	printf("%d\n",Min_Num_OF_Operations[m]);
	int k=m;
	sequences[m]=m;
	for(int i=m-1;i>=0;i--){
		sequences[i]=predecessor[k];
		k=predecessor[k];
		if(k==1){
			break;
		}
			
	}
	
	for(int i=0;i<=m;i++){
		if(sequences[i]!=0)
			printf("%d ",sequences[i]);
	}
  
}

int main() {
  int m;
  scanf("%d",&m);
  optimal_sequence(m);
}