#include <stdio.h>
#include <ctype.h>

#define LIMIT 3             // program can only run 3 times
#define TEST_MODE_OFF 'n'   // run program as normal
#define TEST_MODE_ON  'y'   // run program as a test
#define FILENAME "file.txt" // file to track number of times program has executed

int file_counter = 0;     // used to track the number of times this program has executed
FILE *experiment;         // create a FILE pointer variable
char test_mode_response;  // create a variable to accept user response

int main() 
{
  printf("Do you wish to run this program in test mode? (y/n)\n");  // provide option to run in test mode
  scanf(" %c", &test_mode_response);                                // accept user response; space before %c handles spaces before response and removes the \n
  test_mode_response = tolower(test_mode_response);                 // convert response to lower case

  // Determine how the user responded
  do
  {  
    if (test_mode_response == TEST_MODE_ON)
      printf("You chose to run the program in test mode. You will be able to run the program but no actual update will be made.\n");
    else if (test_mode_response == TEST_MODE_OFF)
      printf("Program will run for real!\n");
    else
      printf("%c is an invalid response. Please enter 'y' or 'n'.\n", test_mode_response);
  } while (test_mode_response != TEST_MODE_OFF && test_mode_response != TEST_MODE_ON);

 experiment = fopen(FILENAME, "r+"); // initialize file as write
  if (experiment == NULL)   // The file does not exist; create it and store the value 0
  {
    printf("The file does not exist. Creating file named %s.\n", FILENAME);
    experiment = fopen(FILENAME, "w");
    if (experiment == NULL) 
    {
        printf("Error creating file");
        return 1;
    }
    fprintf(experiment, "%d", 0);   // write the value 0 to the file
    printf("File created, and value 0 is stored.\n");

    // Close the file and reopen it in read mode
    fclose(experiment);
    experiment = fopen(FILENAME, "r+");
  }

  else if (experiment != NULL) 
  {
    printf("The file exists. Opening file named %s.\n", FILENAME);

    fscanf(experiment, "%d", &file_counter);   // Read an integer from the file
    printf("Read integer from the file: %d\n", file_counter);

    // Check to see if the program has run the maximum allowable times, as defined by LIMIT
    if (file_counter == LIMIT)  // The program has run the maximum allowable times, as defined by LIMIT and the program will terminate
    {
      printf("You have run this program the maximum allowable times. Program will end.\n");
      return 1;
    }
    else  // The program has run the maximum allowable times, as defined by LIMIT and can run again
    {
      file_counter++;                           // Increment the file counter by one
      rewind(experiment);                       // Move the file pointer back to the beginning of the file
      fprintf(experiment, "%d", file_counter);  // Write the new value to the file
      fclose(experiment);                       // close the file
    }
  }
  else 
  {
    printf("Something went wrong with the file named %s.\n", FILENAME);
    printf("Error opening the file.\n");
    return 1;
  }
  for (int i=0; i < LIMIT; i++)
  {
    printf("This program is running %d of %d times allowed.\n", i+1, LIMIT);
  }
  
  return 0;
}


