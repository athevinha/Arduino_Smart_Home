#define LIGHTPIN 3
#define LIGHTSENSOR A0

void setup() {
  pinMode(LIGHTPIN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(LIGHTPIN); 
  Serial.println(sensorValue);
  if(sensorValue >= 600){
    digitalWrite(LIGHTPIN, HIGH);
  }
  else{
    digitalWrite(LIGHTPIN,LOW);
  }
}
