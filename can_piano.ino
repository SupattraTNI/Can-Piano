/* Original project by Oh Hai Seng 07 November 2013 
 To watch the Demo of his Project:
     http://www.youtube.com/watch?v=X4QNT5hOHLs&list=TLlm-tAV1gEzDF4VV39VdjCSLNlfe0tTpU

*/

// Import the CapacaitiveSensor Library.
#include <CapacitiveSensor.h>


 
#define speaker 11


// Set the Send Pin & Receive Pin.
CapacitiveSensor   cs_12_10 = CapacitiveSensor(12,10);        
CapacitiveSensor   cs_12_9 = CapacitiveSensor(12,9);         
CapacitiveSensor   cs_12_8 = CapacitiveSensor(12,8);     
CapacitiveSensor   cs_12_7 = CapacitiveSensor(12,7);     
CapacitiveSensor   cs_12_6 = CapacitiveSensor(12,6);      
CapacitiveSensor   cs_12_5 = CapacitiveSensor(12,5);         
CapacitiveSensor   cs_12_4 = CapacitiveSensor(12,4);  
CapacitiveSensor   cs_12_3 = CapacitiveSensor(12,3);     


void setup()                    
{
  cs_12_7.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  
  // Arduino start communicate with computer.
  Serial.begin(9600);
}

void loop()                    
{
  // Set a timer.
  long start = millis();
  
  // Set the sensitivity of the sensors.
  long total1 =  cs_12_10.capacitiveSensor(3000);
  long total2 =  cs_12_9.capacitiveSensor(3000);
  long total3 =  cs_12_8.capacitiveSensor(3000);
  long total4 =  cs_12_7.capacitiveSensor(3000);
  long total5 =  cs_12_6.capacitiveSensor(3000);
  long total6 =  cs_12_5.capacitiveSensor(3000);
  long total7 =  cs_12_4.capacitiveSensor(3000);
  long total8 =  cs_12_3.capacitiveSensor(3000);
  


  Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t");                    // tab character for debug windown spacing

  Serial.print(total1);                  // print sensor output 1
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total2);                  // print sensor output 2
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total3);                  // print sensor output 3
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total4);                  // print sensor output 4
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total5);                  // print sensor output 5
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total6);                  // print sensor output 6
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total7);                  // print sensor output 7
                                         // Leave some space before print the next output
  Serial.print("\t");
  Serial.println(total8);                // print sensor output 8
                                         // "println" - "ln" represent as "line", system will jump to next line after print the output.
  
  
  
  
  // When hand is touched the sensor, the speaker will produce a tone.
  // I set a threshold for it, so that the sensor won't be too sensitive.
  if (total1 > 1000) tone(speaker,262);   // frequency
  if (total2 > 1000) tone(speaker,294);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
  if (total3 > 1000) tone(speaker,330);
  if (total4 > 1000) tone(speaker,349);
  if (total5 > 1000) tone(speaker,392);
  if (total6 > 1000) tone(speaker,440);
  if (total7 > 1000) tone(speaker,494);
  if (total8 > 1000) tone(speaker,523);
  
  // When hand didn't touch on it, no tone is produced.
  if (total1<=1000  &  total2<=1000  &  total3<=1000 & total4<=1000  &  total5<=1000  &  total6<=1000 &  total7<=1000 &  total8<=1000)
    noTone(speaker);

  delay(10);                             // arbitrary delay to limit data to serial port 
}
