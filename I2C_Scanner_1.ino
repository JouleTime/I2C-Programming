
// --------------------------------------
// i2c_scanner
//
// Version 1
//    This program (or code that looks like it)
//    can be found in many places.
//    For example on the Arduino.cc forum.
//    The original author is not know.
// Version 2, Juni 2012, Using Arduino 1.0.1
//     Adapted to be as simple as possible by Arduino.cc user Krodal
// Version 3, Feb 26  2013
//    V3 by louarnold
// Version 4, March 3, 2013, Using Arduino 1.0.3
//    by Arduino.cc user Krodal.
//    Changes by louarnold removed.
//    Scanning addresses changed from 0...127 to 1...119,
//    according to the i2c scanner by Nick Gammon
//    http://www.gammon.com.au/forum/?id=10896
// Version 5, March 28, 2013
//    As version 4, but address scans now to 127.
//    A sensor seems to use address 120.
// Version 6, May 2015
//    Added tests at specific addresses for known devices.
//    Why do a blind search when we are expecting to 
//    find parts connected. You may also find hidden devices.
//    www.jouletime.com
//
// This sketch tests the standard 7-bit addresses
// Devices with higher bit address might not be seen properly.
//

#include <Wire.h>


void setup()
{
  Wire.begin();

  Serial.begin(9600);
  Serial.println("\nI2C Scanner");
}


void loop()
{
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("!");

      if (address==0x03){
        Serial.print("          This may be software reset address for a LED-driver connected.");
      Serial.println();
          Serial.println();}
       
      if (address==0x1C){
        Serial.print("          You may have an Accelerometer-01 connected.");
      Serial.println();
          Serial.println();}
 
      if (address==0x1D){
        Serial.print("          You may have an Accelerometer-02 connected.");
      Serial.println();
          Serial.println();}
     
      if (address==0x20){
        Serial.print("          You may have a 16-Bit Expander connected.");
      Serial.println();
          Serial.println();}
      
      if (address==0x2C){
        Serial.print("          You may have a Digital Pot. connected.");
       Serial.println();
           Serial.println();}

      if (address==0x3E){
        Serial.print("          You may have a 6-bit DAC connected.");
       Serial.println();
           Serial.println();}
       
      if (address==0x4C){
        Serial.print("          You may have a Temp Sensor connected.");
      Serial.println();
          Serial.println();}
      
       if (address>=0x50 && address<=0x57){
        Serial.print("          You may have a EEPROM Memory (Various) connected.");
      Serial.println();
          Serial.println();}
      
      if (address==0x60){
        Serial.print("          You may have a 12-bit DAC connected.");
      Serial.println();
          Serial.println();}
      
      if (address==0x61){
        Serial.print("          You may have a LED-Driver connected.");
      Serial.println();
          Serial.println();}
      
      if (address==0x6F){
        Serial.print("          You may have a RTCC connected.");
      Serial.println();
          Serial.println();}
  
      if (address==0x70){
        Serial.print("          This may be the All-Call address for a LED-driver connected.");
      Serial.println();
          Serial.println();}
        
      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknow error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(5000);           // wait 5 seconds for next scan
}
