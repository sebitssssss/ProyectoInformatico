#define PIR A0
#define va 11
#define vuelve 10
#define r 6
#define g 5
#define b 3
#define sonido 9
#define boton1 4

bool estadoBoton = false;
bool ultimo = false;

void setup() {
  pinMode(PIR, INPUT);
  pinMode(vuelve, INPUT);
  pinMode(boton1, INPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(sonido, OUTPUT);
  pinMode(va, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool boton = digitalRead(boton1);
  if (boton == HIGH && ultimo == LOW) {
    estadoBoton = !estadoBoton;
  }
  ultimo = boton;

  digitalWrite(va, LOW);
  delayMicroseconds(2);
  digitalWrite(va, HIGH);
  delayMicroseconds(10);
  digitalWrite(va, LOW);

  float echo = pulseIn(vuelve, HIGH, 30000);
  float dis = echo * 0.034 / 2;

  Serial.print("Distancia actual del objeto: ");
  Serial.print(dis);
  Serial.print(" cm | Alarma: ");
  Serial.println(estadoBoton ? "Activada" : "Desactivada");

  analogWrite(r, 0);
  analogWrite(g, 0);
  analogWrite(b, 0);
  digitalWrite(sonido, LOW);

  if (!estadoBoton) {
    analogWrite(b, 255);
    return;
  }

  bool mov = digitalRead(PIR);
  if (mov == HIGH) {
    if (dis > 150) {
      Serial.println("Zona segura.");
      analogWrite(g, 255);
    }
    else if (dis >= 50 && dis <= 150) {
      Serial.println("Precaución.");
      analogWrite(r, 255);
      analogWrite(g, 30);
      digitalWrite(sonido, HIGH);
      delay(250);
      digitalWrite(sonido, LOW);
      delay(250);
    }
    else if (dis < 50) {
      Serial.println("¡Peligro!");
      analogWrite(r, 255);
      digitalWrite(sonido, HIGH);
      delay(25);
      digitalWrite(sonido, LOW);
      delay(25);
    }
  }
}