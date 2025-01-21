#include <CARBOT.h>

CARBOT carBot;

void setup()
{
  Serial.begin(115200);
  carBot.begin();
  Serial.println("CarBot Başlatıldı!");
}

void loop()
{
  // Aracı ileri hareket ettir (hız: 150)
  Serial.println("İleri hareket (hız: 150)");
  carBot.moveForward(150);
  delay(2000);

  // Aracı durdur
  Serial.println("Durdur");
  carBot.stop();
  delay(1000);

  // Aracı geri hareket ettir (hız: 200)
  Serial.println("Geri hareket (hız: 200)");
  carBot.moveBackward(200);
  delay(2000);

  // Direksiyonu 45 dereceye çevir
  Serial.println("Direksiyon: 45 derece");
  carBot.steer(45);
  delay(1000);

  // Direksiyonu 135 dereceye çevir
  Serial.println("Direksiyon: 135 derece");
  carBot.steer(135);
  delay(1000);

  // Buzzer çal
  Serial.println("Buzzer çalıyor...");
  carBot.horn(500);

  // LED'i aç ve sonra kapat
  Serial.println("LED açılıyor...");
  carBot.controlLED(true);
  delay(1000);
  Serial.println("LED kapanıyor...");
  carBot.controlLED(false);
}
