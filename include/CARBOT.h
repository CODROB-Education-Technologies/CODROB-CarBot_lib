#ifndef CARBOT_h
#define CARBOT_h

#include "Arduino.h"
#include <ESP32Servo.h> // Servo kütüphanesi

class CARBOT
{
public:
  CARBOT();                     // Constructor
  void begin();                 // Başlatma fonksiyonu
  void moveForward(int speed);  // Aracı ileri hareket ettir (hız ayarı ile)
  void moveBackward(int speed); // Aracı geri hareket ettir (hız ayarı ile)
  void stop();                  // Aracı durdur
  void steer(int angle);        // Direksiyon hareketi
  void horn(int duration);      // Buzzer çalma
  void controlLED(bool state);  // LED aç/kapat

private:
  Servo _steeringServo; // Direksiyon servo motor nesnesi
  int _steeringPin;
  int _motorPin1;
  int _motorPin2;
  int _enablePin; // Hız kontrolü için PWM pini (ENA veya ENB)
  int _buzzerPin;
  int _ledPin;
};

#endif
