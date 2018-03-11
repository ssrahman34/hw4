#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Freq {
  char name[1024]; // key
  int count; // data
};

int hashCode(int key);
char* getname(char* line, int field);
struct DataItem *search(int key);

void insert(struct Freq mostFreq[10], struct Freq* ins);

int findField(char line[1024]); // function declaration


int main(int argc, char** argv){
   // printf("%s %s\n", argv[2], argv[1]);
    char* line = malloc(1024); // current line of file
    const char* tok; // token pointer
    //char filepathfile[100]= strcat(argv[1],argv[2]);
    //printf("%s", filepathfile);
    FILE* fptr = fopen(argv[2], "r"); // file
    struct Freq* freqArr[4096]; // frequency array
    struct Freq* ptr;
    struct Freq* mostFreq[10]; // holds 10 most freq tweeters
    int field;
    if (!fptr) // open file
    {
        printf("Error! opening file");
        exit(1); // program exits if file pointer returns NULL
    }
    //if (fgets(line, 1024, fptr) != NULL)
    if (fscanf(fptr, "%s", line) == 1)
    {
	//printf("%s", line);
        field = findField(line);
	//printf("%d", field);
    }//split header to get name column.
    else {
	printf("This is an empty file!");
    }
    if (fscanf(fptr, "%s", line) == 1)
    {
	getname(line, 8);
	}
   char* name = malloc(375);
   while (fscanf(fptr, "%s", line) == 1){ 
	//if (strlen(line) > 375){
        //   printf("We have a tweeter that exceeded the max char size");
        //   exit(0);
       // }
   	//printf("%s\n", line);
//	getname(line, field);
        //strcpy(name,getname(line, field));
        //printf("%s", name);
    }	 

   fclose(fptr); 
}//main

char* getname(char* line, int field){
    char* token = malloc(1024);
printf("INHERE");
printf("%s %d", line, field);
    token = strtok(line, " ,");
    for (int i = 0;i==field; i++){
printf("INHERE");
      printf( "New token:      %s\n", token );
      if((token!=NULL) && i == field){ printf("%s", token);}
      token = strtok(NULL," ,");
    }
    //printf("%s", token);
    return token; // no name field
}

int findField(char* line){ // find where name field is
    char* token = malloc(100);
    token = strtok(line, " ,");
    for (int i = 1;token != NULL; i++){
      printf( " %s\n", token );
      token = strtok(NULL," ,");
      if ((token!=NULL) && (strcmp(token,"name") == 0)) return ++i;
    }
    return -1; // no name field
}
