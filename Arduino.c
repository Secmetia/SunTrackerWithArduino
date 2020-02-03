#include <Servo.h> // include Servo library 

Servo horizontal; // horizontal servo
int servoh = 90; // stand horizontal servo

Servo vertical; // vertical servo 
int servov = 90; // stand vertical servo

// LDR pin connections
// name = analogpin;
int ldrlt = 3; //LDR top left 
int ldrrt = 2; //LDR top rigt 
int ldrld = 4; //LDR down left 
int ldrrd = 1; //ldr down right 

void setup()
{
  Serial.begin(9600);
  horizontal.attach(9); 
  vertical.attach(10);
}

void loop() 
{
  // print out the state of the button:

  int lt = analogRead(ldrlt); // top left
  int rt = analogRead(ldrrt); // top right
  int ld = analogRead(ldrld); // down left
  int rd = analogRead(ldrrd); // down rigt
  
  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right
  
  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;// check the diffirence of left and right

  
      if (avt > avd)
      {
        servov = ++servov;
        if (servov > 180)
        {
          servov = 180;
        }
      }
      else if (avt < avd)
      {
        servov= --servov;
        if (servov < 0)
        {
          servov = 0;
        }
      }
    vertical.write(servov);
    
  
  
      if (avl > avr)
      {
        servoh = --servoh;
        if (servoh < 0)
        {
        servoh = 0;
        }
      }
      else if (avl < avr)
      {
        servoh = ++servoh;
        if (servoh > 180)
        {
          servoh = 180;
        }
      }
      else if (avl == avr)
      {
      // nothing
      }
 horizontal.write(servoh);
  
  int anglevalue = servov;

  
  Serial.println(anglevalue);
  delay(10);
} 