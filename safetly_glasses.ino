# define FASTLED_INTERNAL
# include <FastLED.h>
# define NUM_LEDS  25 
# define LED_PIN 9     
CRGB leds[NUM_LEDS];
__attribute__((section(".noinit"))) unsigned int mode;
CRGB color;
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  mode++;
  color = CRGB::Blue;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  if(digitalRead(7) == HIGH){
//    button = !button;
//    
//  }
  digitalWrite(5,HIGH);
  Serial.println(mode % 2);
  if(mode % 2 == 0){
    color = CRGB::Blue;
  }else{
    color = CRGB::Red;
  }
  Serial.println(mode);
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = color;
  }
  FastLED.show();
}
