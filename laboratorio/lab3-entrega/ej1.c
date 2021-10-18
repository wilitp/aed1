#include <stdio.h>

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

int main(void)
{
  int x, y, z;
  x = pedirEntero();
  y = pedirEntero();
  z = pedirEntero();

  // Imprimir los valores
  printf("x+y+1=%d\n",x+y+1);
  printf("z*z+y*45-15*x=%d\n",z*z+y*45-15*x);
  printf("y - 2 == (x * 3 + 1)%%5 = %d\n",(y - 2 == (x * 3 + 1) % 5));
  printf("y / 2 * x = %d\n", y / 2 * x);
  printf("y < x *z = %d\n", (y < x *z));
}

/* | Expresion                 | (x->7, y->3, z->5) | (x->1, y->10, z->8) | */
/* | ------------------------  | ------------------ | ------------------- | */
/* | x + y + 1                 |        11          |         12          | */
/* | z\*z + y \* 45 - 15 \* x  |        55          |        499          | */
/* | y - 2 == (x \* 3 + 1) % 5 |         0          |          0          | */
/* | y / 2 \* x                |         7          |          5          | */
/* | y < x \* z                |         1          |          0          | */

/* La última expresión tiene tipo entero en mi programa, pero podríamos usar también el tipo bool */
