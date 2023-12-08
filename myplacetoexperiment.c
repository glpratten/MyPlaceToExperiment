#include <stdio.h>

#define TESTMODEOFF 'n' // run program as normal
#define TESTMODEON  'y' // run program as a test
#define COUPONCOUNTERFILENAME "test.txt"

int i;
FILE *experiment;   // create a FILE pointer variable
char filename[255]; // create variable to store desired path/filename
char testmoderesponse;

int main() 
{
  
  printf("Do you wish to run this program in test mode? (y/n)\n");  // provide option to run in test mode. No coupon will be produced
  scanf("%c", &testmoderesponse);

  if (testmoderesponse == TESTMODEON || testmoderesponse == TESTMODEON - 'a' + 'A') // recognize both upper and lower case 'y'
  {
    printf("You chose to run the program. The file name is %s.\n", COUPONCOUNTERFILENAME);
    
    experiment = fopen(COUPONCOUNTERFILENAME, "w"); // initialize file as write

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
  else if (testmoderesponse == TESTMODEOFF || testmoderesponse == TESTMODEOFF - 'a' + 'A')  // recognize both upper and lower case 'n'
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


