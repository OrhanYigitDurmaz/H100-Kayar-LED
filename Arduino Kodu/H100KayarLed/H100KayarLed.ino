//H100 Kayar Led Projesi
// Scalable yazılmıştır, istediğiniz kadar ledli olarak kullanabilirsiniz
// Credit 2023 Orhan Yiğit Durmaz orhanyigitv2durmaz [at] gmail [dot] com

#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 30     //her taraftaki led sayısı. iki tarafa da 30 ar adet koyduğumuz için burası 30.

#define STRIP0 6           //birinci şeridin bağlandığı dijital pin.
#define STRIP1 7           //ikinci şeridin bağlandığı dijital pin.

#define PIN0 2
#define PIN1 3

#define BRIGHTNESS 80    //parlaklığı ayarlar. eğer regülatörün amperi yetiyorsa 100 yapabilirsiniz. (LM2596 kulllanıyorsanız 80de kalmalı)

Adafruit_NeoPixel strip0(NUMPIXELS, STRIP0, NEO_GRB + NEO_KHZ800);   //birinci şeridimizi  (strip0 öğesini) oluşturuyoruz
Adafruit_NeoPixel strip1(NUMPIXELS, STRIP1, NEO_GRB + NEO_KHZ800);   //ikinci  şeridimizi  (strip1 öğesini) oluşturuyoruz

void setup() {  // arduinonun başlangıçta 1 kere kullanacağı kodlar.
  strip0.begin();  //birinci şeridimizi başlatıyoruz
  strip1.begin();  //ikinci şeridimizi başlatıyoruz

  strip0.clear();  //bütün ledleri kapatır
  strip1.clear();  //bütün ledleri kapatır
  
  strip0.setBrightness(0);   //Başlangıçtaki (animasyon öncesi) parlaklık
  strip1.setBrightness(0);

  strip0.fill(strip0.Color(255, 255, 255));
  strip1.fill(strip0.Color(255, 255, 255));

  strip0.show();
  strip1.show();
   
  //bu döngüde parlaklığı yavaşça artırıyorum
  for (int i = 0; i < BRIGHTNESS + 1; i++) {
    strip0.setBrightness(i);
    strip1.setBrightness(i);

    strip0.show();
    strip1.show();

    delay(100);

  }

}

void loop() {   //arduinonun devamlı çalıştıracağı kodlar.
  
  if (digitalRead(PIN0) == HIGH && digitalRead(PIN1) == LOW) {  // eğer biri yanıyorsa (sağ veya sol)
    for (int i = 0; i < NUMPIXELS + 1; i++)
      strip0.setPixelColor(i, 220, 100, 0);  //turuncu
      strip0.show();
      delay(100);
    delay(1000); //tüm ledleri kapatmadan önce bir saniye bekliyoruz
    strip0.clear(); //tüm ledleri kapatıyoruz (bundan sonrası loop zaten tekrar tekrar çalışacak)
    strip0.show(); //ledlerimizi güncelliyoruz
  } else if (digitalRead(PIN0) == LOW && digitalRead(PIN1) == HIGH) {  // eğer biri yanıyorsa (sağ veya sol)
    for (int i = 0; i < NUMPIXELS + 1; i++)
      strip1.setPixelColor(i, 220, 100, 0);  //turuncu
      strip1.show();
      delay(100);
    delay(1000); //tüm ledleri kapatmadan önce bir saniye bekliyoruz
    strip1.clear(); //tüm ledleri kapatıyoruz (bundan sonrası loop zaten tekrar tekrar çalışacak)
    strip1.show(); //ledlerimi güncelliyoruz
  } else if (digitalRead(PIN0) == LOW && digitalRead(PIN1) == LOW) {  // eğer hiçbiri yanmıyorsa
    strip0.fill(strip0.Color(255, 255, 255));
    strip1.fill(strip0.Color(255, 255, 255));
    strip0.show();
    strip1.show();
  } else if (digitalRead(PIN0) == HIGH && digitalRead(PIN1) == HIGH) {  // dörtlüler (yani ikisi de) yanıyorsa
    
    //YAPMADIM YAPICAM
    
    strip0.fill(strip0.Color(255, 255, 255));
    strip1.fill(strip0.Color(255, 255, 255));
    strip0.show();
    strip1.show();
  }



}