
const int trig = 7;     // chân trig của HC-SR04
const int echo = 6;     // chân echo của HC-SR04
const int MOTORPIN = 5;

void setup() {  
   Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu  // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu
    pinMode(MOTORPIN,OUTPUT); 
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
    if(distance <= 20) {
      digitalWrite(MOTORPIN,HIGH);
    }
    else{
      digitalWrite(MOTORPIN,LOW);
      delay(5000);
    }
 
}
