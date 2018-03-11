#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Freq {
  char name[1024]; // key
  int count; // data
};

int hashCode(int key);

struct DataItem *search(int key);

void insert(struct Freq mostFreq[10], struct Freq* ins);

int findField(char line[1024]); // function declaration


int main(int argc, char** argv){
    printf("%s %s", argv[2], argv[1]);
    char line[1024]; // current line of file
    const char* tok; // token pointer
    //char filepathfile[100]= strcat(argv[1],argv[2]);
    //printf("%s", filepathfile);
    FILE* fptr = fopen(argv[2], "r"); // file
    struct Freq* freqArr[4096]; // frequency array
    struct Freq* ptr;
    struct Freq* mostFreq[10]; // holds 10 most freq tweeters

    if (!fptr) // open file
    {
        printf("Error! opening file");
        exit(1); // program exits if file pointer returns NULL
    }
   //int field = findField(line);
   // int field = 8;
   while (fgets(line, 1024, fptr) != NULL ){ 
	printf("%s\n",line);
	printf("\n");
    //  if(ptr = search(hashCode(getfield(line, field)))){ // check if in hash
    //    ptr->count += 1;
    //  }
    //	else{
	  //insert();
    //	}
    }

   fclose(fptr); 
}//main
