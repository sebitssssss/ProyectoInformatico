#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

#define NEOPIXEL 6
#define NUM_LEDS 6
#define LDR A0
#define BUTTON 2
#define MODO_PRUEBA_SERIAL false

Adafruit_NeoPixel strip(NUM_LEDS, NEOPIXEL, NEO_GRB + NEO_KHZ800);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

bool sistemaEncendido = true;
bool estadoBotonAnterior = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
  lcd.begin(16, 2);
  strip.begin();
  strip.show();
}

void loop() {

  // Revisa el boton y cambia el estado encendido/apagado del sistema
  bool estadoActual = digitalRead(BUTTON);
  if (estadoActual == LOW && estadoBotonAnterior == HIGH) {
    sistemaEncendido = !sistemaEncendido;
    delay(200);
  }
  estadoBotonAnterior = estadoActual;

  // Lee el sensor LDR y lo pasa a porcentaje de 0 a 100
  int valorBruto = analogRead(LDR);
  int porcentaje = map(valorBruto, 0, 1023, 0, 100);
  porcentaje = constrain(porcentaje, 0, 100);

  // Calcula cuantos LEDs deben estar encendidos segun el porcentaje
  int cantidadLeds;
  if (porcentaje <= 30) {
    cantidadLeds = map(porcentaje, 0, 30, 0, 2);
  } else if (porcentaje <= 70) {
    cantidadLeds = map(porcentaje, 31, 70, 2, 4);
  } else {
    cantidadLeds = map(porcentaje, 71, 100, 4, 6);
  }
  cantidadLeds = constrain(cantidadLeds, 0, NUM_LEDS);

  // Enciende o apaga cada LED con su color fijo segun corresponda
  for (int i = 0; i < NUM_LEDS; i++) {
    if (sistemaEncendido && i < cantidadLeds) {
      if (i <= 1) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));
      } else if (i <= 3) {
        strip.setPixelColor(i, strip.Color(255, 255, 0));
      } else {
        strip.setPixelColor(i, strip.Color(255, 0, 0));
      }
    } else {
      strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
  }
  strip.show();

  // Determina el nombre del color actual segun el ultimo LED encendido
  String color = "-";
  if (sistemaEncendido && cantidadLeds > 0) {
    int ultimoLed = cantidadLeds - 1;
    if (ultimoLed <= 1) {
      color = "VERDE";
    } else if (ultimoLed <= 3) {
      color = "AMARILLO";
    } else {
      color = "ROJO";
    }
  }

  // Muestra el porcentaje, el estado y el color en el LCD
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print(porcentaje);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  if (sistemaEncendido) {
    lcd.print("ON");
  } else {
    lcd.print("OFF");
  }
  lcd.setCursor(16 - color.length(), 1);
  lcd.print(color);

  // Bloque de pruebas por Monitor Serial, deshabilitado pero sin borrar
  if (MODO_PRUEBA_SERIAL) {
    Serial.print("Sensor: ");
    Serial.print(porcentaje);
    Serial.print(" Porcentaje: ");
    Serial.print(porcentaje);
    Serial.print("% N Led: ");
    Serial.print(cantidadLeds);
    Serial.print(" Color: ");
    Serial.println(color);
  }

  delay(100);
}
