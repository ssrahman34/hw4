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
   //int field = 8;
   while (fscanf(fptr, "%s", line) == 1){ 
	//printf("%s\n",line);
	//printf("\n");
    //  if(ptr = search(hashCode(getfield(line, field)))){ // check if in hash
    //    ptr->count += 1;
    //  }
    //	else{
	  //insert();
    //	}
    }

   fclose(fptr); 
}//main


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
