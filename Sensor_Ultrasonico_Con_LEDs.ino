int LED1 = 7;
int LED2 = 6;
int LED3 = 5;
int LED4 = 4;
int LED5 = 3;
int LED6 = 2;
int TRIG = 10;
int ECHO = 9;
int DURACION;
int DISTANCIA;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  DISTANCIA = getDistancia();
  if (DISTANCIA <= 4) {
    digitalWrite(LED6, HIGH);
  } else {
    digitalWrite(LED6, LOW);
  }
  if (DISTANCIA <= 6) {
    digitalWrite(LED5, HIGH);
  } else {
    digitalWrite(LED5, LOW);
  }
  if (DISTANCIA <= 8) {
    digitalWrite(LED4, HIGH);
  } else {
    digitalWrite(LED4, LOW);
  }
  if (DISTANCIA <= 10) {
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }
  if (DISTANCIA <= 12) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }
  if (DISTANCIA <= 14) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }
  Serial.print(DISTANCIA);
  Serial.println(" cm");
}

int getDistancia() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECHO, HIGH);
  delay(100);
  return DURACION / 58.2;
}
