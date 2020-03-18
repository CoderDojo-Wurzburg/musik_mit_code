/*
 ~~~ Willkommen beim CoderDojo Würzburg! ~~~
 @Topic: Code deinen eigenen Song auf dem RaspberryPi!
 @Author: Dein Name
 
 to compile: gcc -o DeinSong DeinSong.c
 ausführen: ./DeinSong -lwiringPi
*/

#include <wiringPi.h>
#include <stdio.h>

// Pin 11 am Raspberry Pi entspricht BCM GPIO 17 und WiringPi Pin 0
#define BeepPin 0

// Note / Frequenz
#define cL 129
#define cLS 139
#define dL 146
#define dLS 156
#define eL 163
#define fL 173
#define fLS 185
#define gL 194
#define gLS 207
#define aL 219
#define aLS 228
#define bL 232

#define c 261
#define cS 277
#define d 294
#define dS 311
#define e 329
#define f 349
#define fS 370
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466

#define cH 523
#define cHS 554
#define dH 587
#define dHS 622
#define eH 659
#define fH 698
#define fHS 740
#define gH 784
#define gHS 830
#define aH 880
#define aHS 910
#define bH 933

// Diese Funktion erzeugt die Squarewave, die den Piezo-Lautsprecher mit einer bestimmten Frequenz erklingen lässt.
void beep(unsigned int note, unsigned int duration)
{
    
  // Dies ist die Halbperiode jeder Note.
  long beepDelay = (long)(1000000/note);
    
  // So viel Zeit brauchen wir fuer die Note
  long time = (long)((duration*1000)/(beepDelay*2));
  for (int i=0;i<time;i++)
  {
    // erste Halbperiode
    digitalWrite(BeepPin, HIGH);
    delayMicroseconds(beepDelay);
    // zweite Halbperiopde
    digitalWrite(BeepPin, LOW);
    delayMicroseconds(beepDelay);
  }

  // Fügt eine kleine Paus hinzu um einzelne Noten zu trennen.
  digitalWrite(BeepPin, LOW);
  delay(20);
}

void play()
{
    // Komponiere dein Lied!
    // Beispiel:
    // beep( note, zeit);
    beep( c, 200);
    
}

int main(void)
{
      // Überprüft ob alles glatt läuft
      if(-1 == wiringPiSetup())
      {
        printf("setup wiringPi failed!");
        return 1;
      }
    
      // Prepare GPIO0
      pinMode(BeepPin, OUTPUT);
      play();

      return 0;
}
