#include <stdio.h>

int i;
FILE *experiment;   // create a FILE pointer variable
char filename[255]; // create variable to store desired path/filename

int main() 
{
  
  printf("Enter the path and filename: ");
  scanf("%s", filename); // get file path & name from the user
  printf(filename);
  experiment = fopen("filename.txt", "rw"); // initialize file as read/write

  if (experiment != NULL) 
  {
    printf("File created successfully!\n");
    fclose(experiment);  // close the file
  }
  else 
  {
    printf("Failed to create the file.\n");
  }
   i++;
   
   return 0;
}