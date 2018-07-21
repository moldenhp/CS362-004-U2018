// Random Testing Quiz
// Name: Peter Moldenhauer
// Class: CS 362
// Date: 7/21/18

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/**************************************************
This function produces random character values. It 
will select from the random characters from 'space' 
to '~'. On the ASCII table these are the values 
from 32 through 126. 
**************************************************/
void inputChar(char *character)
{
    int min = 32; // This is the value for 'Space'
    int max = 126; // This is the value for '~'
    int delta = max - min;
    *character = (rand() % (delta + 1)) + min;
}

/**************************************************
This function produces a random character arral of 
length 4. It will select the random characters from 
'a' to 'z'. On the ASCII table these are the values 
from 97 though 122.  
**************************************************/
void inputString(char string[])
{
    int min = 97; // This is the value for 'a'
    int max = 122; // This is the value for 'z'
    int delta = max - min;
    int i;
    for (i = 0; i < 5; i++) {
        string[i] = (rand() % (delta + 1)) + min;
    }
}

void testme()
{
  int tcCount = 0;
  char s[] = "aaaaa";
  char c;
  char *charPointer = &c;
  int state = 0;
  while (1)
  {
    tcCount++;
    inputChar(charPointer);
    inputString(s);
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
