int vector[5];

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop()
{
  llenarMultiplosDe10(vector, 5);

  for (int i = 0; i < 5; i++)
  {
    Serial.print(vector[i]);
    Serial.print("-");
  }
  Serial.println();

  delay(1000);
}

void llenarMultiplosDe10(int vector[], int cantidad)
{
  for (int i = 0; i < cantidad; i++)
  {
    vector[i] = random(0, 11) * 10;
  }
}
