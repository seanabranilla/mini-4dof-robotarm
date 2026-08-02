#include "BluetoothSerial.h"
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

BluetoothSerial SerialBT;

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to enable it
#endif


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  500 
#define SERVOMAX  2600 
const int blinkPin = 27;
const int mode1Pin = 25;


int currentPosW = 180;
int currentPosE = 180;
int currentPosS = 60;
int currentPosB = 90;

int targetPosW = 180;
int targetPosE = 180;
int targetPosS = 60;
int targetPosB = 90;

const int stepDelay = 10;  //10ms delay/step
unsigned long lastUpdateTime = 0;




void moveServoE(int servoID, int angle){       //moves the elbow in 0 to 180 deg
  angle = constrain(angle, 0, 180);
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.writeMicroseconds(servoID, pulse);

}

void moveServoB(int servoID, int angle){       //moves the base 
  angle = constrain(angle, 0, 180);
  int pulse = map(angle, 0, 180, 2500, SERVOMIN);
  pwm.writeMicroseconds(servoID, pulse);

}

void moveServoW(int servoID, int angle){    //movrs the wrist 0 deg to 180 deg
  angle = constrain(angle, 0, 180);
  int pulse = map(angle, 0, 180, SERVOMAX, SERVOMIN);
  pwm.writeMicroseconds(servoID, pulse);
}

void moveServoS(int servoID, int angle){  //moves shoulder servo with limitations
  angle = constrain(angle, 60, 180);
  int pulse = map(angle, 60, 180, 2500, 1200);

  
  pwm.writeMicroseconds(servoID, pulse);
  
}

void signalBlink(){
  static unsigned long blinkTime = 0;
  static bool ledState = LOW;
  int blinkDelay = 500;
  if (millis()-blinkTime >= blinkDelay){
    blinkTime = millis();
    ledState != ledState;

    digitalWrite(blinkPin, ledState);
    
  }
  
  
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin("ESP32_Robot_Arm");
  pinMode(blinkPin, OUTPUT);
  pinMode(mode1Pin, OUTPUT);


  pwm.begin();

  pwm.setPWMFreq(50); //set at 50hz
  
  
  moveServoW(3, 180);  // Wrist
  delay(1000);
  moveServoE(2, 180);  // Elbow
  delay(1000);
  moveServoS(1, 60);  // Shoulder 
  delay(1000);
  moveServoB(0, 90);  // Base
  delay(100);
}
 

void loop() {
  digitalWrite(mode1Pin, HIGH);
  signalBlink();
 

  
  if (SerialBT.available()) {
    
    char prefix = SerialBT.read(); 
    int angle = SerialBT.parseInt(); 


    Serial.print("Received Prefix: ");
    Serial.print(prefix);
    Serial.print(" | Received Angle: ");
    Serial.println(angle);
    
    switch(prefix) {
      case 'B': // Base (Servo 0)
        targetPosB = angle;
        break;
        
      case 'S': // Shoulder (Servo 1)
        targetPosS = angle;
        break;
        
      case 'E': // Elbow (Servo 2)
        targetPosE = angle;
        break;
        
      case 'W': // Wrist/Gripper (Servo 3)
        targetPosW = angle;
        break;
        
      default:
        // Clear buffer if junk data arrives
        while(SerialBT.available() && SerialBT.read() != '\n');
        break;
    }
  }


  if (millis()-lastUpdateTime >= stepDelay){
    lastUpdateTime = millis();

    if (currentPosB != targetPosB){
      currentPosB += (targetPosB > currentPosB) ? 1 : -1;
      moveServoB(0,currentPosB);
    }

    if (currentPosS != targetPosS){
      currentPosS += (targetPosS > currentPosS) ? 1 : -1;
      moveServoS(1,currentPosS);
    }

    if (currentPosE != targetPosE){
      currentPosE += (targetPosE > currentPosE) ? 1 : -1;
      moveServoE(2,currentPosE);
    }

    if (currentPosW != targetPosW){
      currentPosW += (targetPosW > currentPosW) ? 1 : -1;
      moveServoW(3,currentPosW);
    }

    
  }
}
