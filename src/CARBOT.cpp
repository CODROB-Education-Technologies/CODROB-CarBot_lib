#include "CARBOT.h"

// Constructor / Yapıcı
CARBOT::CARBOT()
{
#if defined(ESP32)
  _steeringPin = 32;
  _motorPin1 = 27;
  _motorPin2 = 33;
  _buzzerPin = 25;
  _ledPin = 26;
#elif defined(ESP8266)
  _steeringPin = 13;
  _motorPin1 = 12;
  _motorPin2 = 14;
  _buzzerPin = 5;
  _ledPin = 4;
#endif
}

// Initialize the car bot / Araç botunu başlat
void CARBOT::begin()
{
  configurePins();
#if defined(ESP32)
  _steeringServo.attach(_steeringPin, 500, 2500);
  // **ESP32 için 1000-2000 µs kullan**
#elif defined(ESP8266)
  _steeringServo.attach(_steeringPin, 500, 2500);
#else
  if (!servo.attach(pin)) // **ESP32 için 1000-2000 µs kullan**
#endif

  _steeringServo.write(90); // Set steering to the initial position / Direksiyonu başlangıç pozisyonuna ayarla
}

// Configure pins based on the platform / Platforma göre pinleri ayarla
void CARBOT::configurePins()
{
  pinMode(_motorPin1, OUTPUT);
  pinMode(_motorPin2, OUTPUT);
  pinMode(_buzzerPin, OUTPUT);
  pinMode(_ledPin, OUTPUT);
}

// Move the car forward / Aracı ileri hareket ettir
void CARBOT::moveForward()
{
  digitalWrite(_motorPin1, HIGH);
  digitalWrite(_motorPin2, LOW);
}

// Move the car backward / Aracı geri hareket ettir
void CARBOT::moveBackward()
{
  digitalWrite(_motorPin1, LOW);
  digitalWrite(_motorPin2, HIGH);
}

// Stop the car / Aracı durdur
void CARBOT::stop()
{
  digitalWrite(_motorPin1, LOW);
  digitalWrite(_motorPin2, LOW);
}

// Steer the car (0-180 degrees) / Direksiyonu verilen açıya çevir
void CARBOT::steer(int angle)
{
  _steeringServo.write(constrain(angle, 0, 180));
}

// Control the car's LED headlights / Farları kontrol et
void CARBOT::controlLED(bool state)
{
  digitalWrite(_ledPin, state ? LOW : HIGH); // LED is active LOW / LED aktif LOW
}

// Play a sound with the buzzer / Buzzer çal
void CARBOT::buzzerPlay(int frequency, int duration)
{
#if defined(ESP32)
  analogWrite(_buzzerPin, frequency);
  delay(duration);
  analogWrite(_buzzerPin, 0);
#elif defined(ESP8266)
  tone(_buzzerPin, frequency, duration);
  delay(duration);
  noTone(_buzzerPin);
#endif
}

// Play the National Anthem / İstiklal Marşı'nı çal
void CARBOT::istiklalMarsiCal()
{
#if defined(ESP32)
  // Adjusted tones for analogWrite (mapped to appropriate PWM values)
  buzzerPlay(100, 400); // C4
  delay(400);
  buzzerPlay(130, 400); // E4
  delay(400);
  buzzerPlay(160, 400); // G4
  delay(400);
  buzzerPlay(145, 400); // F4
  delay(400);
  buzzerPlay(130, 600); // E4
  delay(600);
  buzzerPlay(145, 400); // F4
  delay(400);
  buzzerPlay(130, 400); // E4
  delay(400);
  buzzerPlay(115, 400); // D4
  delay(400);
  buzzerPlay(100, 600); // C4
  delay(600);
  buzzerPlay(130, 400); // E4
  delay(400);
  buzzerPlay(145, 400); // F4
  delay(400);
  buzzerPlay(160, 400); // G4
  delay(400);
  buzzerPlay(130, 600); // E4
  delay(600);
  buzzerPlay(115, 400); // D4
  delay(400);
  buzzerPlay(100, 400); // C4
  delay(400);
  buzzerPlay(115, 600); // D4
  delay(600);

#elif defined(ESP8266)
  buzzerPlay(262, 400);
  delay(400);
  buzzerPlay(330, 400);
  delay(400);
  buzzerPlay(392, 400);
  delay(400);
  buzzerPlay(349, 400);
  delay(400);
  buzzerPlay(330, 600);
  delay(600);
  buzzerPlay(349, 400);
  delay(400);
  buzzerPlay(330, 400);
  delay(400);
  buzzerPlay(294, 400);
  delay(400);
  buzzerPlay(262, 600);
  delay(600);
  buzzerPlay(330, 400);
  delay(400);
  buzzerPlay(349, 400);
  delay(400);
  buzzerPlay(392, 400);
  delay(400);
  buzzerPlay(330, 600);
  delay(600);
  buzzerPlay(294, 400);
  delay(400);
  buzzerPlay(262, 400);
  delay(400);
  buzzerPlay(294, 600);
  delay(600);
#endif
}