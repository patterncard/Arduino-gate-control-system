// Defining the pins being used
int pinLED13 = 13;
int pinLED12 = 12;
int pinLED11 = 11;
int pinLED10 = 10;
int pinLED9 = 9;
int pinSwitchOpenClose = 2;
 
// variables to hold the new and old switch states
boolean oldSwitchOpenCloseState = LOW;
boolean newSwitchOpenCloseState = LOW;
 
boolean stateLED13 = LOW;
boolean stateLED12 = LOW;
boolean stateLED11 = LOW;
boolean stateLED10 = LOW;
boolean stateLED9 = LOW;

int animationSpeed = 0;

void setup() 
{
    Serial.begin(9600);
 
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

    // opening and closing the gate
    pinMode(pinSwitchOpenClose, INPUT); 
}
 
void loop()
{
  animationSpeed = 400;
  
    newSwitchOpenCloseState = digitalRead(pinSwitchOpenClose);
 
    if ( newSwitchOpenCloseState != oldSwitchOpenCloseState ) 
    {
       // checking if has the button switch been closed?
       if ( newSwitchOpenCloseState == HIGH )
       {
           if ( stateLED13 == LOW ) 
           { 
            digitalWrite(pinLED13, HIGH);
            stateLED13 = HIGH; 
            delay(animationSpeed);
          
            digitalWrite(pinLED12, HIGH);
            stateLED12 = HIGH;
            delay(animationSpeed);
          
            digitalWrite(pinLED11, HIGH);
            stateLED11 = HIGH;
            delay(animationSpeed);
          
            digitalWrite(pinLED10, HIGH);
            stateLED10 = HIGH;
            delay(animationSpeed);
          
            digitalWrite(pinLED9, HIGH);
            stateLED9 = HIGH;
           }
           else                    
           {            
            digitalWrite(pinLED9, LOW);   
            stateLED9 = LOW;
            delay(animationSpeed);
            
            digitalWrite(pinLED10, LOW);   
            stateLED10 = LOW;
            delay(animationSpeed);
            
            digitalWrite(pinLED11, LOW);   
            stateLED11 = LOW;
            delay(animationSpeed);

            digitalWrite(pinLED12, LOW);
            stateLED12 = LOW;
            delay(animationSpeed);
            
            digitalWrite(pinLED13, LOW);   
            stateLED13 = LOW;
            delay(animationSpeed);

            // automatically closing the gate after strictly defined time
            delay(3 * animationSpeed);
            
            if ( stateLED13 == LOW ) 
           { 
            digitalWrite(pinLED13, HIGH);
            stateLED13 = HIGH; 
            delay(animationSpeed);
          
            digitalWrite(pinLED12, HIGH);
            stateLED12 = HIGH;
            delay(animationSpeed);
          
            digitalWrite(pinLED11, HIGH);
            stateLED11 = HIGH;
            delay(animationSpeed);
          
            digitalWrite(pinLED10, HIGH);
            stateLED10 = HIGH;
            delay(animationSpeed);
          
            digitalWrite(pinLED9, HIGH);
            stateLED9 = HIGH;
           }
           }
       }
       oldSwitchOpenCloseState = newSwitchOpenCloseState;
    }   
}