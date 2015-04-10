#!/bin/ch -S 
#include<stdio.h>
int main() {
  char s[]="abcd"; 
  string_t p="abcd";
  printf("strcmp(s, p) = %d\n",strcmp(s, p));
  getchar(); // needed for windows only 
}
