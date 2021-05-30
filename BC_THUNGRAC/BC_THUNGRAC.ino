  #include <Servo.h> 
const int trig = 7;     // chân trig của HC-SR04
const int echo = 6;     // chân echo của HC-SR04
const int servoPin = 5; 
Servo Servo1; 
void setup() { 
   Servo1.attach(servoPin); 
   Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu
}
void loop(){ 
    unsigned long duration; 
    int distance;       
    digitalWrite(trig,0);
    delayMicroseconds(2);
    digitalWrite(trig,1);  
    delayMicroseconds(5); 
    digitalWrite(trig,0);  
    duration = pulseIn(echo,HIGH);  
    distance = int(duration/2/29.412);
    if(distance >=30){
      distance = 30;
    }
     Serial.print(distance);
    Serial.println("cm");
    delay(5);
   // Make servo go to 0 degrees 
   if(distance <= 15){
    Servo1.write(0);
    delay(4000);
   }
    Servo1.write(90);
}
