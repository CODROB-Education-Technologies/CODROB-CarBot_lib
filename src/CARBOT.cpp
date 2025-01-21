#include "CARBOT.h"

// Constructor
CARBOT::CARBOT()
{
  _steeringPin = 32; // Direksiyon servo motor pin
  _motorPin1 = 26;   // Motor 1 pin (L293D IN1)
  _motorPin2 = 27;   // Motor 2 pin (L293D IN2)
  _enablePin = 25;   // PWM kontrol pin (L293D ENA)
  _buzzerPin = 33;   // Buzzer pin
  _ledPin = 26;      // LED pin
}

void CARBOT::begin()
{
  // Pin modlarını ayarla
  pinMode(_motorPin1, OUTPUT);
  pinMode(_motorPin2, OUTPUT);
  pinMode(_enablePin, OUTPUT); // PWM pin
  pinMode(_buzzerPin, OUTPUT);
  pinMode(_ledPin, OUTPUT);

  // Servo motoru başlat
  _steeringServo.attach(_steeringPin);
  _steeringServo.write(90); // Başlangıç pozisyonu
}

void CARBOT::moveForward(int speed)
{
  speed = constrain(speed, 0, 255); // Hız değerini 0-255 arasında sınırlandır
  analogWrite(_enablePin, speed);   // Hız ayarı (PWM)
  digitalWrite(_motorPin1, HIGH);   // İleri hareket
  digitalWrite(_motorPin2, LOW);
}

void CARBOT::moveBackward(int speed)
{
  speed = constrain(speed, 0, 255); // Hız değerini 0-255 arasında sınırlandır
  analogWrite(_enablePin, speed);   // Hız ayarı (PWM)
  digitalWrite(_motorPin1, LOW);    // Geri hareket
  digitalWrite(_motorPin2, HIGH);
}

void CARBOT::stop()
{
  analogWrite(_enablePin, 0);    // PWM sinyalini durdur
  digitalWrite(_motorPin1, LOW); // Tüm motor çıkışlarını kapat
  digitalWrite(_motorPin2, LOW);
}

void CARBOT::steer(int angle)
{
  angle = constrain(angle, 0, 180); // Açı sınırlandırma
  _steeringServo.write(angle);      // Direksiyonu verilen açıya çevir
}

void CARBOT::horn(int duration)
{
  tone(_buzzerPin, 1000); // 1000 Hz frekansında ses çıkar
  delay(duration);        // Belirtilen süre boyunca bekle
  noTone(_buzzerPin);     // Sesi kapat
}

void CARBOT::controlLED(bool state)
{
  digitalWrite(_ledPin, state ? HIGH : LOW); // LED'i aç/kapat
}
