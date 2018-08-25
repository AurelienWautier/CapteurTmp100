#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

// TMP100 I2C address 
#define Addr 0x48
  
  LiquidCrystal_I2C lcd(0x27,16,2); // Check I2C address of LCD
  
 
  
  void setup()  {
    lcd.begin(4,5);                   
    lcd.backlight();
    

    // Initialise I2C communication as MASTER
  Wire.begin();
  // Initialise Serial communication, set baud rate = 9600
  Serial.begin(9600);

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select configuration register
  Wire.write(B00000001);
  // Set continuous conversion, comparator mode, 12-bit resolution
  Wire.write(B01100000);
  // Stop I2C Transmission
  Wire.endTransmission();


   Wire.beginTransmission(Addr);
   Wire.write(0x00);
   Wire.endTransmission();

  }

 
  
  void loop()  {
    
      byte msb,lsb;


      // read data on the i2c bus 
      Wire.beginTransmission(Addr);
      Wire.write(0x00);
      Wire.endTransmission();
      Wire.requestFrom(Addr, 2);
      msb = Wire.read();
      lsb = Wire.read();


      // convert data into temperature value 
      int temperatureSum = ((msb << 8)| lsb) >> 4 ;
      float celsius = temperatureSum *0.0625 ;
  
  
      // Temperature display
  
      lcd.home();                
      lcd.print("Temperature :");   
      lcd.setCursor(0, 1);
      lcd.print(celsius);
      lcd.print(" C");
      delay(500);
    
   
    

    

    
  }
