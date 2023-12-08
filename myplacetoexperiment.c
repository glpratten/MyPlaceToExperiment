#include <stdio.h>

#define TESTMODEOFF 0 // run program as normal
#define TESTMODEON  1 // run program as a test

int i;
FILE *experiment;   // create a FILE pointer variable
char filename[255]; // create variable to store desired path/filename
char testmoderesponse;

int main() 
{
  
  printf("Do you wish to run this program in test mode? (y/n)\n");  // provide option to run in test mode. No coupon will be produced
  scanf("%c", &testmoderesponse);

  if (testmoderesponse == 'y' || testmoderesponse == 'Y')
  {
    printf("You chose to run the program.\n");
    printf("Enter the path and filename: ");
    scanf("%s", filename); // get file path & name from the user
    printf(filename);
    experiment = fopen(filename, "w"); // initialize file as read/write

    if (experiment != NULL) 
    {
      printf("File created successfully!\n");
      fclose(experiment);  // close the file
    }
    else 
    {
      printf("Failed to create the file.\n");
    }
  }
  else if (testmoderesponse == 'n' || testmoderesponse == 'N')
  {
    printf("You chose not to run the program.\n");
  }
  else
  {
    printf("Invalid response. Please enter 'y' or 'n'.\n");
  }
  i++;
  
  return 0;
}
