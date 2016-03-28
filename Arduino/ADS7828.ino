// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// ADS7828
// This code is designed to work with the ADS7828_I2CAD8 I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Analog-Digital-Converters?sku=ADS7828_I2CAD8#tabs-0-product_tabset-2

#include <Wire.h>

// ADS7828 I2C address is 0x48(72)
#define Addr 0x48

void setup()
{
  // Initialize I2C communication as MASTER
  Wire.begin();
  // Initialize serial communication, set baud rate = 9600
  Serial.begin(9600);
  delay(300);
}

void loop()
{
  byte data[2];
  
  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Send command byte
  // channel-0 selected,  A/D Converter ON
  Wire.write(0x04);
  // Stop I2C transmission
  Wire.endTransmission();
  
  // Request 2 bytes of data
  Wire.requestFrom(Addr, 2);
  
  // Read 2 bytes of data
  // raw_adc msb, raw_adc lsb
  if(Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
    
    delay(300);
    
    // Converting the data to 12 bits
    int raw_adc = ((data[0] & 0x0F) * 256) + data[1];
    
    // Output data to serial monitor
    Serial.print("Digital value of analog input : ");
    Serial.println(raw_adc);
    }
}

