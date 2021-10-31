#include <stdio.h>

typedef struct {
  char *nombre;
  int edad;
  float altura;
  float peso;
} persona_t;


float peso_promedio(persona_t arr[], unsigned int longitud);
persona_t persona_de_mayor_edad(persona_t arr[], unsigned int longitud);
persona_t persona_de_menor_altura(persona_t arr[], unsigned int longitud);

int main(void) {
  persona_t p1 = {"Paola", 21, 1.85, 75};
  persona_t p2 = {"Luis", 54, 1.75, 69};
  persona_t p3 = {"Julio", 40, 1.70, 80};
  unsigned int longitud = 3;
  persona_t arr[] = {p1, p2, p3};
  printf("El peso promedio es %f\n", peso_promedio(arr, longitud));
  persona_t p = persona_de_mayor_edad(arr, longitud);
  printf("El nombre de la persona con mayor edad es %s\n", p.nombre);
  p = persona_de_menor_altura(arr, longitud);
  printf("El nombre de la persona con menor altura es %s\n", p.nombre);
  return 0;
}

float peso_promedio(persona_t arr[], unsigned int longitud)
{
  unsigned int sum = 0;
  unsigned int i = 0;
  while(i < longitud)
  {
    sum += arr[i].peso;
    i++;
  }

  return sum / longitud;
}
persona_t persona_de_mayor_edad(persona_t arr[], unsigned int longitud)
{
  unsigned int i = 1;
  unsigned int imax = 0;
  while(i < longitud)
  {
    if(arr[imax].edad < arr[i].edad)
    {
      imax = i; 
    }
    i++;
  }
  return arr[imax];
}
persona_t persona_de_menor_altura(persona_t arr[], unsigned int longitud)
{
  unsigned int i = 1;
  unsigned int imin = 0;
  while(i < longitud)
  {
    if(arr[imin].altura > arr[i].altura)
    {
      imin = i; 
    }
    i++;
  }

  return arr[imin];
}
