#include <Keyboard.h>

static uint8_t __clock_prescaler = (CLKPR & (_BV(CLKPS0) | _BV(CLKPS1) | _BV(CLKPS2) | _BV(CLKPS3)));

void setup() 
{
  delay(2000);
    
  setPrescaler();
    
  Keyboard.begin();
  //CHROMEBOOK KEYBOARD KEY SEQUENCE
  //PART ONE: WIFI SETUP
  delay(1000);
      
  type(KEY_LEFT_ALT,false);
  type(KEY_LEFT_SHIFT,false);
  type('S',false);
  Keyboard.releaseAll();
  delay(500);
  
  for(int i = 0; i < 3; i++) 
  {
    type(KEY_TAB,false);
    Keyboard.releaseAll();
  }
      
  type(KEY_RETURN,false);
  Keyboard.releaseAll();
  delay(1000);
  
  for(int i = 0; i < 4; i++) 
  {
    type(KEY_LEFT_SHIFT,false);
    type(KEY_TAB,false);
    Keyboard.releaseAll();
  }
      
  type(KEY_RETURN,false);
  Keyboard.releaseAll();
  delay(200);
  
  print(F("INSERT WIFI NAME"));
  delay(200);
      
  type(KEY_TAB,false);
  Keyboard.releaseAll();
  delay(200);
      
  type(KEY_DOWN_ARROW,false);
  Keyboard.releaseAll();
  delay(200);
      
  type(KEY_DOWN_ARROW,false);
  Keyboard.releaseAll();
  delay(200);
      
  type(KEY_TAB,false);
  Keyboard.releaseAll();
  delay(200);
  
  print(F("INSERT WIFI PASSWORD"));
  delay(1000);
  
  for(int i = 0; i < 2; i++) 
  {  
    type(KEY_TAB,false);
    Keyboard.releaseAll();
    delay(200);
  }
  delay(1000);
      
  type(KEY_RETURN,false);
  Keyboard.releaseAll();
  
  //LONG PAUSE WHILE CONNECTION IS ESTABLISHED.
  for(int i = 0; i < 15; i++) 
  {
    delay(1000);
  }
  
  //PART ONE AND ONE HALF: GO THROUGH FIRST RUN SETUP.
   
  for(int i = 0; i < 4; i++) 
  {
    type(KEY_TAB,false);
    Keyboard.releaseAll();
    delay(1000);
  }

  type(KEY_RETURN,false);
  Keyboard.releaseAll();
  delay(500);
      
  type(KEY_RETURN,false);
  Keyboard.releaseAll();
  delay(500);
  
  //PART TWO: ENROLLMENT (LONG PAUSES IN CASE IT'S HAVING ISSUES WITH WIFI OR RENDER)
  for(int i = 0; i < 7; i++) 
  {
    delay(1000);
  }
      
  type(KEY_LEFT_CTRL,false);
  type(KEY_LEFT_ALT,false);
  type('e',false);
  Keyboard.releaseAll();
  delay(8000);
  
  print(F("INSERT ADMIN EMAIL"));
  delay(200);
      
  type(KEY_RETURN,false);
  Keyboard.releaseAll();
  delay(3000);
  
  print(F("INSERT ADMIN PASSWORD"));
  delay(200);
         
  type(KEY_RETURN,false);
  Keyboard.releaseAll();
  
  delay(10000);
  type(KEY_RETURN,false);
  Keyboard.releaseAll();
  
  Keyboard.end();
}

void type(int key, boolean release) 
{
  Keyboard.press(key);
  if(release)
    Keyboard.release(key);
}

void print(const __FlashStringHelper *value) 
{
  Keyboard.print(value);
}

void loop(){}

void setPrescaler() 
{
  // Disable interrupts.
    uint8_t oldSREG = SREG;
    cli();

    // Enable change.
    CLKPR = _BV(CLKPCE); // write the CLKPCE bit to one and all the other to zero

    // Change clock division.
    CLKPR = 0x0; // write the CLKPS0..3 bits while writing the CLKPE bit to zero

    // Copy for fast access.
    __clock_prescaler = 0x0;

    // Recopy interrupt register.
    SREG = oldSREG;
}

