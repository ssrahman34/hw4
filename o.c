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
  strcpy(hash_table[12].name,"w");
  hash_table[12].count = 55;


  display(hash_table, 13);
}


void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i = 0;
        int j =0;
        int k = 0;

	for(int q = 0;i<leftCount && j< rightCount;q++) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

void MergeSort(int *A,int n) {
	int mid,i;
        int *L, *R;
	if(n < 2) return; 

	mid = n/2;  // find the mid index. 

	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	int k = 0;
	while(k<mid){
 	L[k] = A[k]; // creating left subarray
 	k++;
	}
        int j = mid;
	while(j<n){
		R[j-mid] = A[j]; // creating right subarray
		j++;
	}
	MergeSort(L,mid);
	MergeSort(R,n-mid); 
	Merge(A,L,mid,R,n-mid); 
        free(L);
        free(R);
}

//Assumes that we have a valid freq array
void display(struct freq ar[], int size){
  if (size < 10) {
    int arra[10];
    for (int i = 0; i < size; i++){
      arra[i] = ar[i].count; //initialize our int array with first 10 counts in case all counts are the same
    }
    MergeSort(arra, size);
    for (int i = size-1; i >= 0; i--){
    for (int j = 0; j < size; j++){
      if(ar[j].count == arra[i])
         printf("%s %d\n", ar[j].name, arra[i]);
    } //loop through our array of structs
    }
  return;
  }
  int i;
  int array[10]; //store the 10 top counts from least to greatest.
  for (int i = 0; i < 10; i++){
    array[i] = ar[i].count; //initialize our int array with first 10 counts in case all counts are the same
  }
  MergeSort(array, 10);
  for(i = 10;i <size; i++){
    if (ar[i].count > array[0]){
     array[0] = ar[i].count;
     MergeSort(array, 10);
     }


  }
  MergeSort(array, 10);
  for (int i = 9; i >= 0; i--){
        for (int j = 0; j < size; j++){
      if(ar[j].count == array[i])
         printf("%s %d\n", ar[j].name, array[i]);
    } //loop through our array of structs
  }
  return;
}
