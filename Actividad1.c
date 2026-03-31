// Punto 1

#define red 3
#define amarillo 2
#define verde 1
#define blanco 5
#define no 4
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  digitalWrite(red, HIGH);
  delay(60000);
  digitalWrite(amarillo, HIGH);
  delay(3000);
  digitalWrite(amarillo, LOW);
  digitalWrite(red, LOW);
  digitalWrite(verde, HIGH);
  delay(60000);
  digitalWrite(verde, LOW);
  digitalWrite(amarillo, HIGH);
  delay(3000);
  digitalWrite(amarillo, LOW);
}

// Punto 2


void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(3, HIGH);
  delay(500);
  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(7, HIGH);
  delay(500);
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(10, HIGH);
  delay(500);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(1000);
}


// Punto 3


void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(10, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);  
  delay(500);
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  delay(500);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  delay(500);
}


// Punto 4


#define red 3
#define coso 6
#define verde 1
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  digitalWrite(red, HIGH);
  digitalWrite(coso, HIGH);
  delay(300);
  digitalWrite(coso, LOW);
  delay(6000);
  digitalWrite(red, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(coso, HIGH);
  delay(300);
  digitalWrite(coso, LOW);
  delay(6000);
  digitalWrite(verde, LOW);
}


// Punto 5


#define red 3
#define green 2
#define blue 1
#define red1 6
#define green1 5
#define blue1 4
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  // Rojo Derecha
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red, LOW);
  // Rojo Izquierda
  digitalWrite(red1, HIGH);
  delay(500);
  digitalWrite(red1, LOW);
  // Cian Derecha
  digitalWrite(blue, HIGH);
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(blue, LOW);
  digitalWrite(green, LOW);
  // Cian Izquierda
  digitalWrite(blue1, HIGH);
  digitalWrite(green1, HIGH);
  delay(500);
  digitalWrite(blue1, LOW);
  digitalWrite(green1, LOW);
  // Verde Derecha
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(green, LOW);
  // Verde Izquierda
  digitalWrite(green1, HIGH);
  delay(500);
  digitalWrite(green1, LOW);
  // Magenta Derecha
  digitalWrite(blue, HIGH);
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  // Magenta Izquierda
  digitalWrite(blue1, HIGH);
  digitalWrite(red1, HIGH);
  delay(500);
  digitalWrite(red1, LOW);
  digitalWrite(blue1, LOW);
  // Azul Derecha
  digitalWrite(blue, HIGH);
  delay(500);
  digitalWrite(blue, LOW);
  // Azul Izquierda
  digitalWrite(blue1, HIGH);
  delay(500);
  digitalWrite(blue1, LOW);
  // Blanco Derecha
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
  delay(500);
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  // Blanco Izquierda
  digitalWrite(green1, HIGH);
  digitalWrite(red1, HIGH);
  digitalWrite(blue1, HIGH);
  delay(500);
  digitalWrite(green1, LOW);
  digitalWrite(red1, LOW);
  digitalWrite(blue1, LOW);
  // Amarillo Derecha
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  // Amarillo Izquierda
  digitalWrite(red1, HIGH);
  digitalWrite(green1, HIGH);
  delay(500);
  digitalWrite(red1, LOW);
  digitalWrite(green1, LOW);
}


// Punto 6
