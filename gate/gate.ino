// Defining the pins being used
int pinLED13 = 13;
int pinLED12 = 12;
int pinLED11 = 11;
int pinLED10 = 10;
int pinLED9 = 9;
int pinSwitch = 2;
 
// variables to hold the new and old switch states
boolean oldSwitchState = LOW;
boolean newSwitchState = LOW;
 
boolean LEDstate = LOW;

int animationSpeed = 0;

void setup() 
{
    Serial.begin(9600);

    // light beam interruption
    // pressing the pushbutton simulate interrupting the light beam and opening the gate  
    pinMode(pinSwitch, INPUT);
    
    // gate   
    // glowing diodes simulate closing gate  
    // fadeing diodes simulate opening gate 
    pinMode(pinLED13, OUTPUT);  
    pinMode(pinLED12, OUTPUT);  
    pinMode(pinLED11, OUTPUT);
    pinMode(pinLED10, OUTPUT);
    pinMode(pinLED9, OUTPUT);
    
    digitalWrite(pinLED13,LOW); 
    digitalWrite(pinLED12,LOW); 
    digitalWrite(pinLED11,LOW); 
    digitalWrite(pinLED10,LOW); 
    digitalWrite(pinLED9,LOW);  
}
 
void loop()
{
  animationSpeed = 400;

    // read the state of the pushbutton value:
    newSwitchState = digitalRead(pinSwitch);
 
    if ( newSwitchState != oldSwitchState ) 
    {
       // check if the pushbutton is pressed
       if ( newSwitchState == HIGH )
       {
           if ( LEDstate == LOW ) 
           { 
            // closing the gate 
            digitalWrite(pinLED13, HIGH); 
            delay(animationSpeed);
          
            digitalWrite(pinLED12, HIGH);
            delay(animationSpeed);
          
            digitalWrite(pinLED11, HIGH);
            delay(animationSpeed);
          
            digitalWrite(pinLED10, HIGH);
            delay(animationSpeed);
          
            digitalWrite(pinLED9, HIGH);
            LEDstate = HIGH;
           }
           else                    
           {      
            // opening the gate      
            digitalWrite(pinLED9, LOW);   
            delay(animationSpeed);
            
            digitalWrite(pinLED10, LOW);   
            delay(animationSpeed);
            
            digitalWrite(pinLED11, LOW);   
            delay(animationSpeed);

            digitalWrite(pinLED12, LOW);
            delay(animationSpeed);
            
            digitalWrite(pinLED13, LOW);  
            delay(animationSpeed); 
            LEDstate = LOW;

            // automatically closing the gate after strictly defined time
            delay(3 * animationSpeed);
            
             if ( LEDstate == LOW ) 
                { 
                digitalWrite(pinLED13, HIGH);
                delay(animationSpeed);
          
                digitalWrite(pinLED12, HIGH);
                delay(animationSpeed);
          
                digitalWrite(pinLED11, HIGH);
                delay(animationSpeed);
          
                digitalWrite(pinLED10, HIGH);
                delay(animationSpeed);
          
                digitalWrite(pinLED9, HIGH);
                LEDstate = HIGH;
                }
           }
       }
       oldSwitchState = newSwitchState;
    }   
}