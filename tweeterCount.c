#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX 20000

struct Freq {
  char *key; // name
  int data; // count
};



struct Freq *hashArray[MAX];
struct Freq *freqArr[10];



int hashCode(char *str);
char* getname(char* line, int field);
struct Freq *search(char* key, int *a);
void insert(char *key, int data);
int findField(char *line); // function declaration


int main(int argc, char** argv){
   // printf("%s %s\n", argv[2], argv[1]);
    char* line = malloc(1024); // current line of file
//    const char* tok; // token pointer
    //char filepathfile[100]= strcat(argv[1],argv[2]);
    FILE* fptr = fopen(argv[2], "r"); // file
//    struct Freq* freqArr[4096]; // frequency array
    struct Freq* ptr = NULL;
//    struct Freq* mostFreq[10]; // holds 10 most freq tweeters
    int field;
    char *tweetName;
    if (!fptr) // open file
    {
        printf("Error! opening file");
        exit(1); // program exits if file pointer returns NULL
    }

    if(fgets(line, 1024, fptr) != NULL){
        field = findField(line);
    } //split header to get name column.

    else {
	     printf("This is an empty file!");
    }

   while (fgets(line, 1024, fptr) != NULL){
     tweetName = getname(line, field);
     int a;
     ptr = search(tweetName, &a);

     if(ptr != NULL) { // check if in hash
       ptr->data += 1;
       //printf("%d\n", a);
       for (int i = 0; i < 10; i++) {
         if(ptr->data > freqArr[i]->data){
           // move down everything
           for (int j = i; j < 10; j++) {
           //while(j < )
             freqArr[j+1]->key = freqArr[j]->key;
             freqArr[j+1]->data = freqArr[j]->data;
           }

           freqArr[i]->key = ptr->key;
           freqArr[i]->data = ptr->data;
         }

         if(freqArr[i] == NULL){
          freqArr[i]->key = ptr->key;
          freqArr[i]->data = ptr->data;
         }
       }
     }

     else {
       insert(tweetName, 1);
     }
	 }

   for (int i = 0; i < 10; i++) {

     printf("name: %s\t\tfreq: %d\n", freqArr[i]->key, freqArr[i]->data);

     //if(hashArray[i] != NULL && hashArray[i]->key != NULL)
      //printf("name: %s\t\tfreq: %d\n", hashArray[i]->key, hashArray[i]->data);
   }

  //getname(line, field);
  //      strcpy(name,getname(line, field));
  // printf("%s",getname(line, field));
      //printf("%s", name);

   fclose(fptr);
}//main


int hashCode(char *str)
{
    int key = 0;
    char *tmp = str;

    while('\0' != *tmp)
    {
        // for each character, multiply the current hashcode by 31 and add the character's ascii value
        // multiply by 31 is the same as left shift by 5 and subtract value
        key = key << 5;
        key = key - key + *tmp;
        tmp++;
    }
    return(key);
}

struct Freq *search(char *key, int *a) {
   //get the hash

   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {

      if(hashArray[hashIndex]->key == key){
         *a = hashIndex;
         return hashArray[hashIndex];
       }

      //go to next cell
      ++hashIndex;

      //wrap around the table
      hashIndex %= MAX;
   }

   return NULL;
}

void insert(char *key, int data) {

   struct Freq *item = (struct Freq*) malloc(sizeof(struct Freq));
   item->data = data;
   item->key = key;
   //printf("%s\n", item->key);

   //get the hash
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != NULL) {
      //go to next cell
      ++hashIndex;

      //wrap around the table
      hashIndex %= MAX;
   }

   hashArray[hashIndex] = item;

   //printf("%s\t%d\n", hashArray[hashIndex]->key,hashIndex);
}





char* getname(char* line, int field){
    char* token = malloc(1024);
    token = strsep(&line, ",");
    int i = 0;
    while (token!=NULL){
      //printf( "New token:      %s index: %d\n", token,i);
      if(i == field){
	       return token;
      }

      token = strsep(&line,",");
	    i++;
}
    return token; // no name field

}

int findField(char* line){ // find where name field is
    char* token = malloc(100);
    token = strtok(line, " ,");
    for (int i = 1;token != NULL; i++){
      //printf( " %s\n", token );
      token = strtok(NULL," ,");
      if ((token!=NULL) && (strcmp(token,"name") == 0)) return ++i;
    }
    return -1; // no name field
}
