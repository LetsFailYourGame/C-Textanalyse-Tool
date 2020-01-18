#include <stdio.h>

//Files
char file_name;                     //file_name var. init.
char *file_ptr = &file_name;        //pointer to file_name

//Analyse
int letters[26];
int summ = 0;
int val;

void input_file_name()
{
  printf("Input Filename to read: ");       // print statement
  scanf("%s", &file_name);          // put user input into file_name
}

void analyseText()
{
  // Init Vars.
  char ch;
  int converted;

  FILE *f = fopen(file_ptr, "r"); // Init. file stream var.

  // START ****************************************************************
  if (f == NULL){ printf("\nERROR 404 : [File is not available]\n"); return; }
  else
  {
      printf("\n~ Reading: [ %s ]\n", file_ptr);

      while ((ch = fgetc(f)) != EOF) // While not End Of File read every char by char
      {
        converted = (int)ch; // Convert char by char into (int) ASCII val. 

        while(fscanf(f, "%d", &val) == 1)  // scan line by line return val 1 if num
        {
          summ += val;
        }

        for(int i = 0; i < 26; i++) // Loop : alphabet size
        {
          if(converted - (i+65) == 0 || converted - (i + 97) == 0) 
          // If current char ascii val. - (i+65) ascii val. = 0 | i = pos of ascii letter 
          {
              letters[i] += 1; // Add 1 to i pos.
          }
        }
      }      
  }
  // END ***************************************************************** 

  //START ****************************************************************
    printf("\n~ Saving results in [ output.txt ]\n");
    
    f = fopen("output.txt", "w"); //save in output file

    if (f == NULL){ printf("\nERROR 405 : [Unable to create output File]\n"); return; }
    else
    {
      // Print every letter with count
      for (int i = 0; i < 26; i++)
      {
        fprintf(f, "%lc: [ %d ]\n", (char)i+97, letters[i]); 
      }
      
      fprintf(f, "Summe aller Zahlen ist [ %d ]", summ);

      fclose(f); // Close Filestream
      printf("\nDone!\n");
    }
    //END ****************************************************************
}


int main(void) 
{
  input_file_name(); // Set file_name by User

  analyseText(); // Analyse text#

  return 0;
}