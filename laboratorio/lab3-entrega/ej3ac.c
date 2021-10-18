#include <stdio.h>
#include <assert.h>

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

// 1.c
int main() {
  int x, y;
  x = pedirEntero();
  y = pedirEntero();
  assert(x=2 && y==5);
  y = y + y;
  x = x + y;
  printf("x=%d; y=%d\n", x, y);

  return 0;
}

/* | Programa                  | Usuario ingresa    | Produce una salida  | */
/* | ------------------------  | ------------------ | ------------------- | */
/* | 1.a ejecucion 1           |         x->1       |        x->5         | */
/* | 1.a ejecucion 2           |         x->2       |        x->5         | */
/* | 1.a ejecucion 3           |         x->3       |        x->5         | */
/* | 1.b ejecucion 1           |    x->1, y->1      |      x->2, y->2     | */
/* | 1.b ejecucion 2           |    x->2, y->2      |      x->4, y->4     | */
/* | 1.b ejecucion 3           |    x->3, y->3      |      x->6, y->6     | */
/* | 1.c ejecucion 1           |    x->1, y->1      |      x->3, y->2     | */
/* | 1.c ejecucion 2           |    x->2, y->2      |      x->6, y->4     | */
/* | 1.c ejecucion 3           |    x->3, y->3      |      x->9, y->6     | */
