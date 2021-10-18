#include <stdio.h>
#include <stdbool.h>

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

int primo(int n) 
{
  int res = 1;
  int i = 2;
  while(i < n && res)
  {
    res = res && (n % i != 0 );
    i = i + 1;
  }
  return res;
}

int main(void)
{
  int x, i, temp;
  bool res;

  x = pedirEntero();
  i = pedirEntero();
  temp = pedirEntero();
  res = temp;

  i = 2;
  res = true;

  res = primo(x);
  imprimeEntero(res);

  return 0;
}

/* Primera iteracion: (x->5, y->3, res->1) */
/* Segunda iteracion: (x->5, y->4, res->1) */
/* Tercera iteracion: (x->5, y->5, res->1) */


/* Ejercicio 5.b.2 */

/* - El programa 1 computa el cociente de la division entera entre x e y. */
/* - El programa 2 evalua si x es primo, el valor de res es la respuesta. */
