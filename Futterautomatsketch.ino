
// Intelligente Futterstation
// Projektkurs Aufgabenfeld III
// Herr Schön, Herr Rüther, Herr Hansing
// Von Julia Görzen, Violetta Kraus, Mika Manke
// Bedienung eines Servo-Motors mit Hilfe eines RFID-Chips



#include <SPI.h> 

#include <MFRC522.h> 

#include <Servo.h>

#define SS_PIN 22 

#define RST_PIN 4 

MFRC522 mfrc522(SS_PIN, RST_PIN); 

Servo FutterAusgabe; 

int pos = 0; 


  void setup() 

  { 

    Serial.begin(9600); 
    
    SPI.begin(); 

    mfrc522.PCD_Init(); 

    FutterAusgabe.attach(5);

  } 

  void loop() 

  {

    if ( ! mfrc522.PICC_IsNewCardPresent()) 
    {

    return; 

    }


    if ( ! mfrc522.PICC_ReadCardSerial()) 

    {

    return; 
    }



    Serial.print("Gerade gegessen hat das Tier mit der ID:"); 



    for (byte i = 0; i < mfrc522.uid.size; i++)

    {
 
       for (pos = 0; pos <= 180; pos +=90)
       
       { 
   
        FutterAusgabe.write(pos);              
        
        delay(90);                    
       
       }
    
       for (pos = 180; pos >= 0; pos -= 90)
       
       { 
    
          FutterAusgabe.write(pos);              
    
          delay(90);
        }
    
      Serial.print(mfrc522.uid.uidByte[i], HEX); 
-
      Serial.print(" "); 


      Serial.println(); 
  }
}
