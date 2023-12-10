#include <stdio.h>

#define TESTMODEOFF 'n' // run program as normal
#define TESTMODEON  'y' // run program as a test
#define COUPONCOUNTERFILENAME "couponcounterfile.txt" // file to track number of coupons that have been requested

int i;
int filecounter = 0;
FILE *experiment;   // create a FILE pointer variable
// char filename[255]; // create variable to store desired path/filename
char testmoderesponse;

int main() 
{
  printf("I will know this has compiled when I see the file named %s.\n", COUPONCOUNTERFILENAME);
    
  printf("Do you wish to run this program in test mode? (y/n)\n");  // provide option to run in test mode. No coupon will be produced
  scanf("%c", &testmoderesponse);

  if (testmoderesponse == TESTMODEON || testmoderesponse == TESTMODEON - 'a' + 'A') // recognize both upper and lower case 'y'
  {
    printf("You chose to run the program in test mode.\n");
    
  }
  else if (testmoderesponse == TESTMODEOFF || testmoderesponse == TESTMODEOFF - 'a' + 'A')  // recognize both upper and lower case 'n'
  {
    printf("You chose not to run the program in test mode.\n");
  }
  else
  {
    printf("Invalid response. Please enter 'y' or 'n'.\n");
  }
  experiment = fopen(COUPONCOUNTERFILENAME, "r+"); // initialize file as write
  if (experiment == NULL)   // The file does not exist; create it and store the value 0
  {
    printf("The file does not exist. Creating file named %s.\n", COUPONCOUNTERFILENAME);
    experiment = fopen(COUPONCOUNTERFILENAME, "w");
    if (experiemnt == NULL) 
    {
        printf("Error creating file");
        return 1;
    }
    fprintf(experiment, "%d", 0);   // write the value 0 to the file
    printf("File created, and value 0 is stored.\n");

    // Close the file and reopen it in read mode
    fclose(experiment);
    experiment = fopen(COUPONCOUNTERFILENAME, "r+");
  }

  elseif (experiment != NULL) 
  {
    printf("The file exists. Opening file named %s.\n", COUPONCOUNTERFILENAME);

    fscanf(experiment, "%d", &filecounter);   // Read an integer from the file
    printf("Read integer from the file: %d\n", filecounter);

    filecounter++;   // Increment the integer by one

    rewind(experiment);   // Move the file pointer back to the beginning of the file
    fprintf(experiment, "%d", filecounter);    // Write the new value to the file
    printf("Updated integer written to the file: %d\n", filecounter);
    
    fclose(experiment);  // close the file
  }
  else 
  {
    printf("Something went wrong with the file named %s.\n", COUPONCOUNTERFILENAME);
    printf("Error opening the file.\n");
  }
  i++;
  
  return 0;
}


