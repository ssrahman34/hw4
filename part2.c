#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct freq {
  char name[1024]; // key
  int count; // data
};

void display(struct freq ar[], int size);
int main(){
  //struct freq* freqArr[4096];
  //struct freq* mostFreq[10]; 
  struct freq hash_table[4096];
  strcpy(hash_table[0].name,"s");
  hash_table[0].count = 0;
  strcpy(hash_table[1].name,"h");
  hash_table[1].count = 2;
  strcpy(hash_table[2].name,"p");
  hash_table[2].count = 3;
  strcpy(hash_table[3].name,"j");
  hash_table[3].count = 5;
  strcpy(hash_table[4].name,"y");
  hash_table[4].count = 22;
  strcpy(hash_table[5].name,"c");
  hash_table[5].count = 31;
  strcpy(hash_table[6].name,"b");
  hash_table[6].count = 4;
  strcpy(hash_table[7].name,"a");
  hash_table[7].count = 19;
  strcpy(hash_table[8].name,"u");
  hash_table[8].count = 27;
  strcpy(hash_table[9].name,"b");
  hash_table[9].count = 8;
  strcpy(hash_table[10].name,"a");
  hash_table[10].count = 20;
  strcpy(hash_table[11].name,"u");
  hash_table[11].count = 21;



  display(hash_table, 8);
}


void Merge(struct freq* A,struct freq* L,int leftCount,struct freq* R,int rightCount) {
	int i = 0;
        int j =0;
        int k = 0;

	while(i<leftCount && j< rightCount) {
		if(L[i].count  < R[j].count) {
			A[k++].count = L[i++].count;
			strcpy(A[k++].name,L[i++].name);
		}
		else {
			A[k++].count = R[j++].count;
			strcpy(A[k++].name,R[j++].name);
		}
	}
	while(i < leftCount){
 	  A[k++].count = L[i++].count;
 	  strcpy(A[k++].name,L[i++].name);
	}	
	while(j < rightCount){
	 A[k++].count = R[j++].count;
         strcpy(A[k++].name,R[j++].name);
        }
	}

// Recursive function to sort an array of integers. 
void MergeSort(struct freq* A,int n) {
	int mid,i;
        //int *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = n/2;  // find the mid index. 

	//L = (int*)malloc(mid*sizeof(int)); 
	//R = (int*)malloc((n- mid)*sizeof(int)); 
	
        struct freq L[n];
	//for (int i = 0 ; i < int; i++){
	//  L[i].name=malloc(1024);
	//}
        struct freq R[10];
	//for (int i = 0 ; i < int; i++){
        //  R[i].name=malloc(1024);
        //}
	for(i = 0;i<mid;i++){
	  L[i].count = A[i].count; // creating left subarray
	  strcpy(L[i].name,A[i].name); // creating left subarray
	}
	for(i = mid;i<n;i++){
 	  R[i-mid].count = A[i].count; // creating right subarray
	  strcpy(R[i-mid].name,A[i].name); // creating left subarray
        }
	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
        //free(L);
        //free(R);
}

//Assumes that we have a valid freq array
void display(struct freq ar[], int size){
  if (size < 10) {
  struct freq arra[10];
    for (int i = 0; i < size; i++){
      arra[i].count = ar[i].count; //initialize our int array with first 10 counts in case all counts are the same
      strcpy(arra[i].name,ar[i].name);
    }
    MergeSort(arra, size);
    for (int i = size-1; i >= 0; i--){
      printf(" %d", arra[i].count);
    }
  return;
  }
  int i;
  struct freq array[10]; //store the 10 top counts and tweeters from least to greatest.
  for (int i = 0; i < 10; i++){
    array[i].count = ar[i].count; //initialize our int array with first 10 counts in case all counts are the same
    strcpy(array[i].name,ar[i].name);
  }
  //printf("%d %d %d %d %d %d %d %d %d %d", array[0], array[1], array[2], array[3],array[4], array[5], array[6], array[7], array[8], array[9]);
  MergeSort(array, 10);
  for(i = 10;i <size; i++){
    if (ar[i].count > array[0].count){
     array[0].count = ar[i].count;
     strcpy(array[0].name,ar[i].name);
     MergeSort(array, 10);
     }


  }
  MergeSort(array, 10);
  for (int i = 9; i >= 0; i--){
    printf("%d : %d %s\n", i,array[i].count, array[i].name);
  }
  printf("\n");
  return;
}
