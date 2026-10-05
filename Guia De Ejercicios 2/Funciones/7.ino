#define tam(a,b)  sizeof(a)/sizeof(b)

int numeros[] = {12, 87, 3, 45, 99, 21, 60};

void setup()
{
  Serial.begin(9600);

  Serial.print("Original: ");
  mostrarVector(numeros, tam(numeros, int));

  ordenarMayorAMenor(numeros, tam(numeros, int));

  Serial.print("Ordenado: ");
  mostrarVector(numeros, tam(numeros, int));
}

void loop()
{
}

int* ordenarMayorAMenor(int vector[], int cantidad)
{
  for (int i = 0; i < cantidad - 1; i++)
  {
    for (int j = 0; j < cantidad - 1 - i; j++)
    {
      if (vector[j] < vector[j + 1])
      {
        int aux = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = aux;
      }
    }
  }
  return vector;
}

void mostrarVector(int vector[], int cantidad)
{
  for (int i = 0; i < cantidad; i++)
  {
    Serial.print(vector[i]);
    Serial.print("-");
  }
  Serial.println();
}
