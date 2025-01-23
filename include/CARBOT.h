#ifndef CARBOT_H
#define CARBOT_H

#include "Arduino.h"

// Include the appropriate library based on the platform
#if defined(ESP32)
#include <ESP32Servo.h>
#elif defined(ESP8266)
#include <Servo.h>
#endif

class CARBOT
{
public:
  CARBOT();                                     // Constructor / Yapıcı
  void begin();                                 // Initialize the car bot / Araç botunu başlat
  void moveForward();                           // Move the car forward / Aracı ileri hareket ettir
  void moveBackward();                          // Move the car backward / Aracı geri hareket ettir
  void stop();                                  // Stop the car / Aracı durdur
  void steer(int angle);                        // Steer the car (0-180 degrees) / Direksiyonu verilen açıya çevir
  void controlLED(bool state);                  // Control the car's LED headlights / Farları kontrol et
  void buzzerPlay(int frequency, int duration); // Play a sound with the buzzer / Buzzer çal
  void istiklalMarsiCal();                      // Play the National Anthem melody / İstiklal Marşı'nı çal

private:
  Servo _steeringServo; // Servo object for steering / Direksiyon servo motor nesnesi

  // Pins for motor, servo, buzzer, and LED / Motor, servo, buzzer ve LED pinleri
  int _steeringPin;
  int _motorPin1;
  int _motorPin2;
  int _buzzerPin;
  int _ledPin;

  void configurePins(); // Configure pins based on the platform / Platforma göre pinleri ayarla
};

#endif
