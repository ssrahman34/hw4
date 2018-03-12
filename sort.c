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
  strcpy(hash_table[8].name,"q");
  hash_table[8].count = 27;
  strcpy(hash_table[9].name,"f");
  hash_table[9].count = 8;
  strcpy(hash_table[10].name,"e");
  hash_table[10].count = 20;
  strcpy(hash_table[11].name,"u");
  hash_table[11].count = 21;



  display(hash_table, 12);
}


void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i = 0;
        int j =0;
        int k = 0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers. 
void MergeSort(int *A,int n) {
	int mid,i;
        int *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = n/2;  // find the mid index. 

	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
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
      printf(" %d", arra[i]);
    }
  return;
  }
  int i;
  char names[10][300]; //string of 10 names  
  int array[10]; //store the 10 top counts from least to greatest.
  int id[100];
  int ind = 0;
  for (int i = 0; i < 10; i++){
    array[i] = ar[i].count; //initialize our int array with first 10 counts in case all counts are the same
    strcpy(names[ind], ar[i].name);
    id[ind] = i;
    ind++;
}
  MergeSort(array, 10);
  for(i = 10;i <size; i++){
    if (ar[i].count > array[0]){
     array[0] = ar[i].count;
     id[ind++] = i; //add new index
MergeSort(array, 10);
     }
}
  MergeSort(array, 10);

  for (int i = 9; i >= 0; i--){
    printf(" %d", array[i]);
    for (int j = 0; j < size; j++){
      if(ar[j].count == array[i])
         printf(" %s", ar[j].name);
    } //loop through our array of structs 
    }//for
  return;
}
