#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX 20000

struct Freq {
  char *key; // name
  int data; // count
};
struct freq {
  char name[1024]; // name
  int count; // count
};


struct Freq *hashArray[MAX];
struct Freq *freqArr[10];


void display(struct freq ar[], int size);
int hashCode(char *str);
char* gettheName(char* line, int field);
struct Freq *search(char* key, int *a);
void insert(char *key, int data);

char* findName(char* line, int num);
char* getname(char* line, int field);
int findField(char *line); // function declaration


int main(int argc, char** argv){

   
    char* line = malloc(1024); // current line of file
    //char line[1024];
//    const char* tok; // token pointer
    //char filepathfile[100]= strcat(argv[1],argv[2]);
    FILE *fptr = fopen(argv[1], "r"); // file
//    struct Freq* freqArr[4096]; // frequency array
    struct freq hash_table[4096]; //max 20,000 lines
    //strcpy(hash_table[0].name,"sara");
    //hash_table[0].count = 1;
   // strcpy(ar[0].name, "S");
    //printf("%d %s\n",hash_table[0].count, hash_table[0].name);
    struct Freq* ptr = NULL;
    int field;
    char *tweetName;
    if (!fptr) // open file
    {
        printf("Error! opening file");
        exit(1); // program exits if file pointer returns NULL
    }

        if(fgets(line, 1024, fptr) != NULL){
          field = findField(line);
          //printf("%d", field);
    } //split header to get name column.

  int index = 0;
   while (fgets(line, 1024, fptr) != NULL){
    //downputs(line);
    //printf("%s", line);
     //tweetName = gettheName(line, field);
    tweetName = findName(line, field);

     //printf("%s\n ", tweetName);
     int a;
     strcpy(hash_table[index].name,tweetName);
     hash_table[index].count = 1;
     index++;
     // printf("%s \n\n", line);
//      ptr = search(tweetName, &a);

//      if(ptr != NULL) { // check if in hash
//        ptr->data += 1;
//        for (int i = 0; i < 10; i++) {

//          if(freqArr[i] && ptr->data > freqArr[i]->data){
//            // move down everything
//            for (int j = 8; j >= i ; j--) {
//                 freqArr[j+1]->key = freqArr[j]->key;
//                 freqArr[j+1]->data = freqArr[j]->data;
//                 printf("#: ");
//                 printf("%s\n", freqArr[j+1]->key);
//            }

//            freqArr[i]->key = ptr->key;
//            freqArr[i]->data = ptr->data;
//            break;
//          }

//          if(freqArr[i] == NULL){
//           freqArr[i] = (struct Freq*) malloc(sizeof(struct Freq));
// //         printf("%s\n", ptr->key);
//           freqArr[i]->key = ptr->key;
//           freqArr[i]->data = ptr->data;
//           printf("Here: ");
//          printf("%s %d\n", freqArr[i]->key, i);
//            break;
//          }
       
//         // printf("%s %d\n", freqArr[i]->key, i);
//        }
//      }

//         else {
//         insert(tweetName, 1);
//         }
	 }
    //  for (int i = 0; i <100; i ++){
    //      printf("%s %d\n",hash_table[i].name,hash_table[i].count);
    //  }
    display(hash_table, index);
//    for (int i = 0; i < 10; i++) {

//      printf("name: %s\t\tfreq: %d\n", freqArr[i]->key, freqArr[i]->data);

//      //if(hashArray[i] != NULL && hashArray[i]->key != NULL)
//       //printf("name: %s\t\tfreq: %d\n", hashArray[i]->key, hashArray[i]->data);
//    }

    //char* line = malloc(1024); 
   fclose(fptr);
}//main


// int hashCode(char *str)
// {
//     int key = 0;
//     char *tmp = str;

//     while('\0' != *tmp)
//     {
//         // for each character, multiply the current hashcode by 31 and add the character's ascii value
//         // multiply by 31 is the same as left shift by 5 and subtract value
//         key = key << 5;
//         key = key - key + *tmp;
//         tmp++;
//     }
//     return(key);
// }

// struct Freq *search(char *key, int *a) {
//    //get the hash

//    int hashIndex = hashCode(key);

//    //move in array until an empty
//    while(hashArray[hashIndex] != NULL) {

//       if(hashArray[hashIndex]->key == key){
//          *a = hashIndex;
//          return hashArray[hashIndex];
//        }

//       //go to next cell
//       ++hashIndex;

//       //wrap around the table
//       hashIndex %= MAX;
//    }

//    return NULL;
// }

// void insert(char *key, int data) {

//    struct Freq *item = (struct Freq*) malloc(sizeof(struct Freq));
//    item->data = data;
//    item->key = key;
//    //printf("%s\n", item->key);

//    //get the hash
//    int hashIndex = hashCode(key);

//    //move in array until an empty or deleted cell
//    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != NULL) {
//       //go to next cell
//       ++hashIndex;

//       //wrap around the table
//       hashIndex %= MAX;
//    }

//    hashArray[hashIndex] = item;

//    //printf("%s\t%d\n", hashArray[hashIndex]->key,hashIndex);
// }


int findField(char line[1024]){ // find where name field is

    char* token = malloc(100);
    token = strtok(line, " ,");
    for (int i = 1;token != NULL; i++){
      //printf( " %s\n", token );
      token = strtok(NULL," ,");
      if ((token!=NULL) && (strcmp(token,"name") == 0)) return ++i;
    }
    return -1; // no name field
}

char* findName(char line[1024], int num){ // find where name field is
    //printf("%s", line);
    char* token = malloc(100);
    char* linet = malloc(1024);
    strcpy(linet, line);
    token = strtok(linet, " ,");
    int i;
    for (i = 1;token != NULL; i++){
      //printf( " %s\n", token );
      token = strtok(NULL," ,");
      if ((token!=NULL) && (num == i)) 
      {
        //printf("%s is token for %d\n", token,i);
        return token;
      }
    }
    return "NONE"; // no name field
}


//SORT


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
    printf("IN Di");
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
