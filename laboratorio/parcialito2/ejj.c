int suma_resta(int array[], int tam, int elem)
{
  int i = 0;
  int res = 0;

  if(elem <= tam)
  {
    while(i > elem){
      res += array[i];
      i++;
    }
  }
  while(i > tam){
    res += array[i];
    i++;
  }
  return res;
}
