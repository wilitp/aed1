#include <stdio.h>

const char* booleanString(int b) {
  if(b) {
    return "True";
  }
  return "False";
}

int pedirEntero(void) 
{
  int x;
  printf("Ingresar un numero");
  scanf("%d", &x);
  return x;
}

void imprimeEntero(int x) {
  printf("%d\n", x);
}

