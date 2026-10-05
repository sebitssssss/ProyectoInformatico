void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop()
{
  int tiradaD6 = tirarDado(6);
  int tiradaD20 = tirarDado(20);

  Serial.print("D6: ");
  Serial.print(tiradaD6);
  Serial.print("  D20: ");
  Serial.println(tiradaD20);

  delay(1000);
}

int tirarDado(int lados)
{
  int resultado = random(1, lados + 1);
  return resultado;
}
