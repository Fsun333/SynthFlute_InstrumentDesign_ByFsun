#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"



#define BMP_SCK A5
//#define BMP_MISO 12
#define BMP_SDA A4
//#define BMP_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BMP3XX bmp; // I2C
//Adafruit_BMP3XX bmp(BMP_CS); // hardware SPI
//Adafruit_BMP3XX bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);  // Software SPI


// Button variables
const int buttonPin = A3;
int buttonState;

const int button2Pin = A1;
int button2State;

const int button3Pin = A2;
int button3State;


const int button4Pin = D8;
int button4State;


const int button5Pin = A7;
int button5State;

const int button6Pin = D4;
int button6State;

const int button7Pin = D9;
int button7State;

const int button8Pin = D10;
int button8State;


// Potentiometer variables
const int potPin = A0;
int potValue = 0;


void setup() {
  Serial.begin(9600);     

  while (!Serial);
  Serial.println("Adafruit BMP388 / BMP390 test");

  if (!bmp.begin_I2C()) {   // hardware I2C mode, can pass in address & alt Wire
  //if (! bmp.begin_SPI(BMP_CS)) {  // hardware SPI mode  
  //if (! bmp.begin_SPI(BMP_CS, BMP_SCK, BMP_MISO, BMP_MOSI)) {  // software SPI mode
    Serial.println("Could not find a valid BMP3 sensor, check wiring!");
    while (1);
  }

  // Set up oversampling and filter initialization
  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);

     

  //------------------------------- Buttons -------------------------------// 


  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);
  pinMode(button5Pin, INPUT_PULLUP);
  pinMode(button6Pin, INPUT_PULLUP);
  pinMode(button7Pin, INPUT_PULLUP);
  pinMode(button8Pin, INPUT_PULLUP);

  pinMode(potPin, INPUT);
}

void loop() {
  /**************************** BUTTON ****************************/

  buttonState = digitalRead(buttonPin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  button4State = digitalRead(button4Pin);
  button5State = digitalRead(button5Pin);
  button6State = digitalRead(button6Pin);
  button7State = digitalRead(button7Pin);
  button8State = digitalRead(button8Pin);

  Serial.print("Button: "); // Header
  Serial.println(buttonState);   // Value

  Serial.print("Button2: "); // Header
  Serial.println(button2State);   // Value
  
  Serial.print("Button3: "); // Header
  Serial.println(button3State);   // Value

  Serial.print("Button4: "); // Header
  Serial.println(button4State);   // Value

  Serial.print("Button5: "); // Header
  Serial.println(button5State);   // Value

  Serial.print("Button6: "); // Header
  Serial.println(button6State);   // Value

  Serial.print("Button7: "); // Header
  Serial.println(button7State);   // Value

  Serial.print("Button8: "); // Header
  Serial.println(button8State);   // Value



//**************************** POTENTIOMETER ****************************/
 potValue = analogRead(potPin);

  Serial.print("Pot: ");
  Serial.println(potValue);
//**************************** Pressure Sensor ****************************/

  if (! bmp.performReading()) {
    Serial.println("Failed to perform reading :(");
    return;
  }
  Serial.print("Temperature: ");
  Serial.print(bmp.temperature);
  Serial.println(" *C");

  Serial.print("Pressure: ");
  Serial.print(bmp.pressure / 100.0);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude: ");
  Serial.print(bmp.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.println();

  delay(50);
} 


