const int RELAY_PIN2 = 2;    // Pump #1 relay controller
const int RELAY_PIN1 = 3;    // Pump #2 relay controller

const int ledPin1 = 4;       // Wet tank level 25%
const int ledPin2 = 5;       // Wet tank level 50%
const int ledPin3 = 6;       // Wet tank level 75%
const int ledPin4 = 7;       // Wet tank level 100%

const int pingPin = 8;       // Trigger Pin of Ultrasonic Sensor
const int echoPin = 9;       // Echo Pin of Ultrasonic Sensor

const int ledPin5 = 10;      // Pump 1 status indicator
const int ledPin6 = 11;      // Pump 2 status indicator

const int ledPin7 = 12;      // Warning indicator

const int backupSwitchPin = 13;  // Backup float switch 

int backupSwitchState = 0;  // Backup switch status

void setup() {
   
   Serial.begin(9600);      // Starting Serial Terminal
   
   pinMode(LED_BUILTIN, OUTPUT);

   pinMode(backupSwitchPin, INPUT);
   
   pinMode(ledPin1, OUTPUT);  // Tank level indicators
   pinMode(ledPin2, OUTPUT);
   pinMode(ledPin3, OUTPUT);
   pinMode(ledPin4, OUTPUT);
   
   pinMode(ledPin5, OUTPUT);   // Pump status indicators 
   pinMode(ledPin6, OUTPUT);

   pinMode(ledPin7, OUTPUT);   // Warning lamp
   
   pinMode(RELAY_PIN1, OUTPUT);    // Pump relay controller
   pinMode(RELAY_PIN2, OUTPUT);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);

  if(cm <= 20){
    digitalWrite(ledPin1, HIGH);   // turn the LED on (HIGH is the voltage level)   
  } else {
    digitalWrite(ledPin1, LOW);
  }

  if(cm <= 15){
   digitalWrite(ledPin2, HIGH);   // turn the LED on (HIGH is the voltage level)
   digitalWrite(RELAY_PIN1, HIGH);  // Pump 1 on
   digitalWrite(ledPin5, HIGH);    // Pump 1 Status on
  } else {
   digitalWrite(ledPin2, LOW);  
   digitalWrite(RELAY_PIN1, LOW);  
   digitalWrite(ledPin5, LOW);    
  }

  if(cm <= 10){
   digitalWrite(ledPin3, HIGH);   // turn the LED on (HIGH is the voltage level)
   digitalWrite(RELAY_PIN2, HIGH);   // Pump 2 on
   digitalWrite(ledPin6, HIGH);      // Pump 2 Status on  
  } else {
   digitalWrite(ledPin3, LOW);   
   digitalWrite(RELAY_PIN2, LOW);  
   digitalWrite(ledPin6, LOW);    
  }

  if(cm <= 5){
    digitalWrite(ledPin4, HIGH);   // turn the LED on (HIGH is the voltage level)   
  } else {
    digitalWrite(ledPin4, LOW);
  }

  backupSwitchState = digitalRead(backupSwitchPin);

  if(backupSwitchState == HIGH){        // Everything turns on
    
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);

    digitalWrite(RELAY_PIN1, HIGH);
    digitalWrite(RELAY_PIN2, HIGH);

    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);

    digitalWrite(ledPin7, HIGH);

    delay(30000);                  // Prevents pumps switching on and off rapidly   
  }

  delay(5000);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
