#define chicharra 3

#define tam(a,b)  sizeof(a)/sizeof(b)

int notasInicio[]    = {262, 330, 392, 523};
int tiemposInicio[]  = {150, 150, 150, 400};

int notasVictoria[]   = {392, 523, 659, 784, 0, 659, 784};
int tiemposVictoria[] = {120, 120, 120, 300, 80, 120, 500};

int notasDerrota[]   = {392, 370, 349, 330};
int tiemposDerrota[] = {300, 300, 300, 700};

int notasAlegria[] = {330, 330, 349, 392, 392, 349, 330, 294, 262, 262, 294, 330, 330, 294, 294};
int tiemposAlegria[] = {300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 450, 150, 600};

void setup()
{
  pinMode(chicharra, OUTPUT);
}

void loop()
{
  melodiaInicio();
  delay(1000);
  melodiaVictoria();
  delay(1000);
  melodiaDerrota();
  delay(1000);
  melodiaAlegria();
  delay(2000);
}

void nota(int frecuencia, int duracion)
{
  if (frecuencia == 0)
  {
    delay(duracion);
    return;
  }

  long periodo = 1000000L / frecuencia;
  long ciclos = (long)frecuencia * duracion / 1000;

  for (long i = 0; i < ciclos; i++)
  {
    digitalWrite(chicharra, HIGH);
    delayMicroseconds(periodo / 2);
    digitalWrite(chicharra, LOW);
    delayMicroseconds(periodo / 2);
  }
  delay(30);
}

void tocar(int notas[], int tiempos[], int cantidad)
{
  for (int i = 0; i < cantidad; i++)
  {
    nota(notas[i], tiempos[i]);
  }
}

void melodiaInicio()
{
  tocar(notasInicio, tiemposInicio, tam(notasInicio, int));
}

void melodiaVictoria()
{
  tocar(notasVictoria, tiemposVictoria, tam(notasVictoria, int));
}

void melodiaDerrota()
{
  tocar(notasDerrota, tiemposDerrota, tam(notasDerrota, int));
}

void melodiaAlegria()
{
  tocar(notasAlegria, tiemposAlegria, tam(notasAlegria, int));
}
