#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))


int get_max_index( int* weights, int* values,int n) {
    int max_j = 0;
    double max = 0;

    for (int j = 0; j < n; j++) {
       if( *(weights+j)!=0 && max< (double)(*(values+j)/ (*(weights+j)))){
            max = (double)(*(values+j))/(*(weights+j));
            max_j = j;
        }
    }
    return max_j;
}  
double get_optimal_value(int capacity, int* weights, int* values,int n) {
  double value = 0.0;
  int a;
  for(int i=0;i<n;i++){
	  if(capacity==0)
		  return value;
	 /* for(int j=0;j<n;j++){
		if( *(weights+j)!=0 &&max_unit_price< (double)(*(values+j)/ (*(weights+j)))){
			max_unit_price=(double)(*(values+j))/(*(weights+j));
			max_unit_index=j;
		}  
	  }*/

	  int index = get_max_index(weights, values,n);
	  if(*(weights+index)>capacity)
		  a=capacity;
	  else
		  a=*(weights+index);
      value += a * (double)(*(values+index))/(*(weights+index));
      *(weights+index) =(*(weights+index))- a;
      capacity -= a;

  }
	return value;
}


int main() {
  int n,i;
  int capacity;
  scanf("%d%d",&n,&capacity);
  unsigned int values[n],weights[n];
  for(i=0;i<n;i++){
	  scanf("%d%d",&values[i],&weights[i]);
  }
  double optimal_value = get_optimal_value(capacity, weights, values,n);
  printf("%f",optimal_value);
  
}