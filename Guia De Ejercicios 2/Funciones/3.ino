#include <LiquidCrystal.h>

//lcd
LiquidCrystal lcd(7,8,9,10,11,12);

void setup()
{
  lcd.begin(16, 2);
  randomSeed(analogRead(A0));
}

void loop()
{
  mostrarBienvenida();
  delay(2000);
  mostrarInicioJuego();
  delay(2000);
  mostrarFinJuego();
  delay(2000);
  mostrarPuntuacion();
  delay(3000);
}

void mostrarBienvenida()
{
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Bienvenido");
  lcd.setCursor(1,1);
  lcd.print("Proyecto Inf26");
}

void mostrarInicioJuego()
{
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Inicio de juego");
  lcd.setCursor(4,1);
  lcd.print("Suerte!");
}

void mostrarFinJuego()
{
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Fin del");
  lcd.setCursor(5,1);
  lcd.print("juego");
}

void mostrarPuntuacion()
{
  int puntaje = random(0, 1001);

  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Puntuacion:");
  lcd.setCursor(6,1);
  lcd.print(puntaje);
}
