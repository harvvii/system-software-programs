/*
This file contains the code/program for "Take a file as input and remove comments from the file."
*/
#include <stdio.h>

int main (int argc, char *argv[])
{
  FILE *fp, *ft;
  char ch, nextc;

  fp = fopen ("input.txt", "r");
  ft = fopen ("output.txt", "w");
  if (fp == NULL)
    printf ("File does not exits");
  if (ft == NULL)
    printf ("Opening error");

  nextc = fgetc (fp);
  while (nextc != EOF)
  {
     ch = nextc;
     nextc = fgetc (fp);

     if ((ch == '/') && (nextc == '*'))
     {
        ch = fgetc (fp);
        nextc = fgetc (fp);
        while (!((ch == '*') && (nextc == '/'))) /* unroll until the end of comment*/
        {
          ch = nextc;
          nextc = fgetc (fp);
        }
        nextc = fgetc (fp);
        continue;
     }else if((ch=='/') && (nextc == '/')) // block to handle single line comment.
     {
        nextc = fgetc (fp);
        while (!(nextc == '\n')){
           nextc = fgetc (fp);
        }
       nextc = fgetc (fp);
       continue;
     }
     putc (ch, ft);
   }
  fclose (fp);
  fclose (ft);
  return 0;
 }
