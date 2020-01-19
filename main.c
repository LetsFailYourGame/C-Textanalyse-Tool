#include <stdio.h>

char file_name;
char *file_ptr = &file_name;
int letters_count[26];
int sum = 0;
int val;


void input_file_name()
{
  printf("Input Filename to read: ");
  scanf("%s", &file_name);
}

void analyseText()
{
  char ch;
  int converted;

  FILE *f = fopen(file_ptr, "r");

  if (f == NULL){ printf("\nERROR 404 : [File is not available]\n"); return; }
  else
  {
      printf("\n~ Reading: [ %s ]\n", file_ptr);
      while ((ch = fgetc(f)) != EOF)
      {
       converted = (int)ch;

       while(fscanf(f, "%d", &val) == 1) { sum += val; }

        for(int i = 0; i < 26; i++)
        {
          if(converted - (i+65) == 0 || converted - (i + 97) == 0)
          {
              letters_count[i] += 1;
          }
        }
      }
  }
    float total_letters = 0.0f;
    for(int i = 0; i < 26; i++) { total_letters += (float)letters_count[i]; }
    float one_percent = 1.0f / total_letters;
    printf("\n~ Saving results in [ output.txt ]\n");

    f = fopen("output.txt", "w");
    if (f == NULL){ printf("\nERROR 405 : [Unable to create output File]\n"); return; }

    else
    {
      for (int i = 0; i < 26; i++)
      {
        fprintf(f, "%c:\t[ %d ]\t--> [ %.3f %% ]\n", (char)i+97, letters_count[i], (one_percent * (float)letters_count[i])*100 );
      }
      fprintf(f, "\nSum of all Numbers [ %d ]", sum);
      fclose(f);
      printf("\nDone!\n");
    }
}


int main(void)
{
  input_file_name(); // Set file_name by User

  analyseText(); // Analyse text

  return 0;
}
