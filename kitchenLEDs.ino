#define timer 59 //specifies the time (in seconds) to wait before turning lights off after no movement detected.

int lsensP = A0;  //variable definition starts
int msensP = 23;
int G = 11;
int R = 12;
int B = 13;
int lvalue = 0;
int mvalue = 0;    
boolean lightON = false;
boolean DarkEmpty = false; //variable definition ends


void setup()
{
  //Serial.begin(9600);
  pinMode(msensP, INPUT);  //set PIR sensor as input
}



/*Defined Colors (different RGB (red, green, blue) values for colors
(to add your own ie. fuscia experiment and then add to the list)
const byte RED[] = {255, 0, 0}; 
const byte ORANGE[] = {83, 4, 0}; 
const byte YELLOW[] = {255, 255, 0}; 
const byte GREEN[] = {0, 255, 0}; 
const byte BLUE[] = {0, 0, 255}; 
const byte INDIGO[] = {4, 0, 19}; 
const byte VIOLET[] = {23, 0, 22}; 
const byte CYAN[] = {0, 255, 255}; 
const byte MAGENTA[] = {255, 0, 255}; 
const byte WHITE[] = {255, 255, 255}; 
const byte BLACK[] = {0, 0, 0}; 
const byte PINK[] = {158, 4, 79};
*/



void loop()
{
  lvalue = analogRead(lsensP);    //read light sensor
  mvalue = digitalRead(msensP);    //read PIR sensor
  //Serial.println(mvalue);    //print sensor values
  //Serial.println(lvalue);    //to serial for debugging
  
  
  
  //------------------------------------------------------code to turn ON the LEDs--------------------------------------
  if (lightON == false && mvalue == 1 && lvalue < 600)    //check if leds are off and room is dark and there is movement
    {   
      
     /* for (int i=0; i<=158; i++) //turn ON the red LED
      {
        analogWrite(R, i); 
        delay(7);
      }*/
      
      for (int i=0; i<=255; i++) //turn ON the blue LED
      {
        analogWrite(B, i);
        delay(7);
      }
      
      for (int i=0; i<=255; i++) //turn ON the green LED
      {
        analogWrite(G, i);    
        delay(7);
      }
         
      
      
      lightON = true;
      DarkEmpty = false;
    } //------------------------------------------end of code to turn ON LEDs----------------------------------------------
    
    
     //-------------------------------------------code to check if no movement for the duration of 'timer'-----------------
     if (lightON == true && mvalue == 0)
      {
        int n = 0;
          for (int i=0; i<=timer; i++)
          {
            delay(1000);
            n = digitalRead(msensP);
            //Serial.println(i);
            //Serial.println(n);
            if (n)
            {break;}
          }
          if (!n)
          {
            DarkEmpty = true;
          }
      }
      //----------------------------------------end of movement checking--------------------------------------------------
      
    
    if (lightON == true && (DarkEmpty == true || lvalue >= 700) ) //-----------code to turn OFF the LEDs----------------------------------------
    {
      /*for (int i=158; i>=0; i--)
      {
        analogWrite(R, i);
        delay(7);
      }*/
      
      
      for (int i=255; i>=0; i--)
      {
        analogWrite(G, i);    
        delay(7);
      }
         
      for (int i=255; i>=0; i--)
      {
        analogWrite(B, i);
        delay(7);
      }
      lightON = false;
    }
 }//--------------------------------------------end of code to turn OFF the LEDs----------------------------------------
 
