#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>


#define NEOPIXEL 6
#define NUM_LEDS 6
#define LDR A0
#define BUTTON 2

#define MODO_PRUEBA_SERIAL false

Adafruit_NeoPixel strip(NUM_LEDS, NEOPIXEL, NEO_GRB + NEO_KHZ800);
LiquidCrystal lcd(7,8,9,10,11,12);

bool sistemaEncendido = true;
bool estadoBotonAnterior = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON, INPUT_PULLUP);

  strip.begin();

  strip.show();
}
  
  
void loop() 
  {
    //int leerPorcentaje() {
    int valorBruto = analogRead(LDR);
    int porcentaje = map(valorBruto, 0, 1023, 0, 100);
    porcentaje = constrain(porcentaje, 0, 100);
    return porcentaje;
    int leds;

    if (porcentaje <= 30) 
    {
      leds = map(porcentaje, 0, 30, 0, 2);
    } 
    else if (porcentaje <= 70) 
    {
      leds = map(porcentaje, 31, 70, 2, 4);
    } 
    else 
    {
      leds = map(porcentaje, 71, 100, 4, 6);
    }

    leds = constrain(leds, 0, NUM_LEDS);
    return leds;

    uint32_t colorParaLed(int indice) 

    if (indice <= 1) 
    {
      return strip.Color(0, 255, 0);
    } 

    else if (indice <= 3) 
    {
      return strip.Color(255, 255, 0);
    } 

    else 
    {
      return strip.Color(255, 0, 0);
    }

    if (indice <= 1) 
    {
      return "VERDE";
    } 

    else if (indice <= 3) 
    {
      return "AMARILLO";
    } 

    else
    {
      return "ROJO";
    }

    for (int i = 0; i < NUM_LEDS; i++) 
    {

      if (sistemaEncendido && i < cantidadLeds) 
    {
      strip.setPixelColor(i, colorParaLed(i));
    } 

    else 
    {
      strip.setPixelColor(i, strip.Color(0, 0, 0));
    }

    strip.show();
    lcd.setCursor(0, 0);
    lcd.print("");
    lcd.setCursor(0, 0);
    lcd.print(porcentaje);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("");

    lcd.setCursor(0, 1);

    if (sistemaEncendido) 
    {
      lcd.print("ON");
    } 

    else 
    {
      lcd.print("OFF");
    }

    String color = "";

    if (sistemaEncendido && cantidadLeds > 0) 
    {
      color = nombreColorParaLed(cantidadLeds - 1);
    } 

    else 
    {
      color = "-";
    }

    lcd.setCursor(16 - color.length(), 1);
    lcd.print(color);
    bool estadoActual = digitalRead(BUTTON);

    if (estadoActual == LOW && estadoBotonAnterior == HIGH) 
    {
      sistemaEncendido = !sistemaEncendido;
      delay(200);
    }

    estadoBotonAnterior = estadoActual;
    revisarBoton();

    int porcentaje = leerPorcentaje();
    int cantidadLeds = porcentajeALeds(porcentaje);

    actualizarLeds(cantidadLeds);
    actualizarLCD(porcentaje, cantidadLeds);

    if (MODO_PRUEBA_SERIAL) 
    {
      Serial.print("Sensor: ");
      Serial.print(porcentaje);
      Serial.print(" Porcentaje: ");
      Serial.print(porcentaje);
      Serial.println("%");
      Serial.print("N Led: ");
      Serial.println(cantidadLeds);
      Serial.print("Color: ");

      if (cantidadLeds > 0) 
      {
        Serial.println(nombreColorParaLed(cantidadLeds - 1));
      } 
      else 
      {
        Serial.println("-");
      }
    }
  }