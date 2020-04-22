#include <stdio.h>





int compute_min_refills(int dist, int tank, int stops[],int n) {
    // write your code here
	int num_of_Riffells=0;
	int current_Riffells=0;
	int last_Riffels=0;
	while(current_Riffells<=n){
		last_Riffels=current_Riffells;
		while(current_Riffells<=n && stops[current_Riffells+1]-stops[last_Riffels]<=tank){
			current_Riffells++;
			
		}
		
		if(current_Riffells==last_Riffels)
			return -1;
	
		if(current_Riffells<=n)
			num_of_Riffells++;
	}
	
    return num_of_Riffells;
}


int main() {
    int d , m ,n ;
	scanf("%d",&d);
	scanf("%d",&m);
	scanf("%d",&n);
	
	int stops[n+2];
	stops[0]=0;
	stops[n+1]=d;
	
	for(int i=1;i<=n;i++)
		scanf("%d",&stops[i]);
	
	
	printf("%d",compute_min_refills(d,m,stops,n));

    return 0;
}
