#include <stdio.h>
#include <string.h>

int compare_varaible(char variables[20][20], char var[20], int vIndex) {
  int duplicate = 1;
  while(vIndex >= 0) {
    int i = 0;
    while(1) {
      if(variables[vIndex][i] && var[i]) {
        if(variables[vIndex][i] != var[i]) {
          duplicate = 0;
          break;
        }
      } else {
        break;
      }
      i++;
    }
    vIndex--;
  }
  return duplicate;
}

int main(void) {
  char mystr[200], lines[100][200], variables[20][20], tmpvr;
  int sr = 0, i; // sr - start reading, i - index
  int line_index = 0, lti = 0; // line temp index  
  int var_index = 0;
  printf("Enter a string: \n");
  gets(mystr);

  while(mystr[i]) {
    char current = mystr[i];
    if(current != ' ') sr = 1;
    if(current == ';') {
        sr = 0;
        line_index++;
        lti = 0;
    }
    if(sr) {
      lines[line_index][lti++] = current;
    }
    i++;
  }
  
  
  int tmp_line_index = 0;
  while(tmp_line_index <= line_index) {
    printf("%s\n", lines[tmp_line_index++]);
  }

  i = 0; // line no
  
  while(i <= line_index) {
    // iterating over the lines array and extracting the variables from the lines;
    int j = 0; // line character index;
    sr = 0; // stop reading by default
    int tvi = 0; // temp variable index
    char tv[20]; // temp variable;
    while(lines[i][j]) {
      char current = lines[i][j];
      if(current == ' ') sr = 1; // start reading
      if(current != ' ' && sr == 1) {
        tv[tvi++] = current;
      }
      j++;
    }
    if(var_index == 0) {
      strcpy(variables[var_index++], tv);
    } else {
      if(compare_varaible(variables, tv, var_index)) { // found
        printf("Error - are you re-declaring variable %s\n", tv);
      } else { // not found
        strcpy(variables[var_index++], tv);
        printf("%s - declared\n", tv);
      }
    }
    printf("ci: %s %d\n", tv, var_index);
    i++;
  }

  // int ti = 0;
  // if(ti <= var_index) {
  //   printf("%s\n", variables[ti++]);
  // }

  return 0;
}