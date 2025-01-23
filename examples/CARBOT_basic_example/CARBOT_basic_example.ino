#include <CARBOT.h>

CARBOT carBot;

void setup()
{
  carBot.begin(); // Initialize the car bot / Araç botunu başlat
}

void loop()
{
  // Turn on LED headlights / LED farları aç
  carBot.controlLED(true);
  delay(2000);

  // Turn off LED headlights / LED farları kapat
  carBot.controlLED(false);
  delay(2000);

  // Move the car forward / Aracı ileri hareket ettir
  carBot.moveForward();
  delay(2000);

  // Stop the car / Aracı durdur
  carBot.stop();
  delay(2000);

  // Steer left / Direksiyonu sola çevir
  carBot.steer(45);
  delay(2000);

  // Center the steering / Direksiyonu ortala
  carBot.steer(90);
  delay(2000);

  // Move the car backward / Aracı geri hareket ettir
  carBot.moveBackward();
  delay(2000);

  // Stop the car / Aracı durdur
  carBot.stop();
  delay(2000);

  // Steer right / Direksiyonu sağa çevir
  carBot.steer(135);
  delay(2000);

  // Center the steering / Direksiyonu ortala
  carBot.steer(90);
  delay(2000);

  // Play a sound with the buzzer / Buzzer çal
  carBot.buzzerPlay(1000, 500);
  delay(2000);
}
