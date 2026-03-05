// Pinos

const int pinoTrig = 25;
const int pinoEcho = 27;
const int pinoLed = 26;

// Função 
float obter_distancia();

void setup() {
  Serial.begin(115200);

  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  pinMode(pinoLed, OUTPUT);

  digitalWrite(pinoTrig, LOW);
}

void loop() {
  float distancia = obter_distancia();

  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if(distancia > 0 && distancia <= 20) {
    Serial.println("Intruso detectado!");
    digitalWrite(pinoLed, HIGH);
    delay(1000);
  }
    else{
      Serial.println("Ambiente seguro!");
      digitalWrite(pinoLed, LOW);
  }

  delay(3000);
}

//Medir a distância
float obter_distancia() {
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  long duracao = pulseIn(pinoEcho, HIGH, 30000);

  float distancia = (duracao / 2.0) * 0.0343;

  return distancia;
}