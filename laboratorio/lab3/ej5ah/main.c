#include <stdio.h>

int main(void) {
  int i;
  printf("Ingresar un valor");
  scanf("%d", &i);
  while (i != 0) {
    i = i - 1;
  }
}
