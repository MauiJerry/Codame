#include <Adafruit_CircuitPlayground.h> // include circuit playground library

float sound_value; // this variable will store our sound data
float THRESHOLD = 65.0; // at what SPL are we detecting a sound?

void setup() {
  Serial.begin(9600); // initialize serial
  CircuitPlayground.begin(); // initialize Circuit Playground
}

int black = 0;
int blue = 0x0000EE;

void setAllPixels(int color)
{
  for (int i=0; i<10;i++) 
  {
    CircuitPlayground.setPixelColor(i, color);
  }  
}

// todo:  change color and tone by sound volume

void playLEDs(int color)
{
  setAllPixels(color);
  CircuitPlayground.playTone(200, 200);
  //delay(250);
  CircuitPlayground.clearPixels(); // this turns the LEDs off

  //setAllPixels(black);
}

void loop() {

  sound_value = CircuitPlayground.mic.soundPressureLevel(10);
  
  //Serial.print("Sound Sensor SPL: "); 
  //Serial.println(sound_value); 
  
  if (sound_value > THRESHOLD){
    Serial.print("SOUND DETECTED");
    Serial.println(sound_value); 
    int color = CircuitPlayground.Color(0,sound_value,sound_value);
    playLEDs(color);
  }
  else{
    Serial.println("Silence is golden..."); 
  }

  delay(200); // short delay 
}
