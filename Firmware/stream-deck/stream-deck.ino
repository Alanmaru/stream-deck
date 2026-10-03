#include <HID-Project.h>

const int bt1 = 2;
const int bt2 = 3;
const int bt3 = 4;
const int bt4 = 5; //Those are the 4 buttons


const int encoderA = 8; // Pins for encoder
const int encoderB = 9;
const int boton = 7;

int estadoAnteriorA;
int estadoAnteriorB;

int estadoBotonAnterior = HIGH;
// Software debounce for the encoder button
unsigned long ultimoTiempoBoton = 0;
const unsigned long tiempoDebounce = 50;

int estadoAnteriorbt1 = HIGH;
int estadoAnteriorbt2 = HIGH;
int estadoAnteriorbt3 = HIGH;
int estadoAnteriorbt4 = HIGH;

void setup() {

  pinMode(bt1, INPUT_PULLUP);
  pinMode(bt2, INPUT_PULLUP);
  pinMode(bt3, INPUT_PULLUP);
  pinMode(bt4, INPUT_PULLUP);

  pinMode(encoderA, INPUT_PULLUP);
  pinMode(encoderB, INPUT_PULLUP);
  pinMode(boton, INPUT_PULLUP);

  estadoAnteriorA = digitalRead(encoderA);
  estadoAnteriorB = digitalRead(encoderB);

  Keyboard.begin();
  Consumer.begin();
}

void loop() {

  int estadoActualbt1 = digitalRead(bt1);
  int estadoActualbt2 = digitalRead(bt2);
  int estadoActualbt3 = digitalRead(bt3);
  int estadoActualbt4 = digitalRead(bt4);

  int estadoActualA = digitalRead(encoderA);

if (estadoActualA != estadoAnteriorA && estadoActualA == LOW) {
// If channel B is HIGH, it was turned to the right (Increase Volume)
    if (digitalRead(encoderB) == HIGH) {
      Consumer.write(MEDIA_VOLUME_UP);
    } 
// If channel B is LOW, it was turned to the left (Decrease Volume)
    else {
      Consumer.write(MEDIA_VOLUME_DOWN);
    }
  }
  estadoAnteriorA = estadoActualA;

int estadoActualBoton = digitalRead(boton);

  if (estadoActualBoton != estadoBotonAnterior) {
    if ((millis() - ultimoTiempoBoton) > tiempoDebounce) {
      if (estadoActualBoton == LOW) { // click the button
        Consumer.write(MEDIA_VOLUME_MUTE);
      }
      ultimoTiempoBoton = millis();
    }
    estadoBotonAnterior = estadoActualBoton;
  }

if (estadoAnteriorbt1 == HIGH && estadoActualbt1 == LOW) {
  delay(65);  
  nextTrack();
}

if (estadoAnteriorbt2 == HIGH && estadoActualbt2 == LOW) {
  delay(65);
  switchWindow();
}

if (estadoAnteriorbt3 == HIGH && estadoActualbt3 == LOW) {
  delay(65);
  playPause();
}

if (estadoAnteriorbt4 == HIGH && estadoActualbt4 == LOW) {
  delay(65);
  previousTrack();
}


estadoAnteriorbt1 = estadoActualbt1;
estadoAnteriorbt2 = estadoActualbt2;
estadoAnteriorbt3 = estadoActualbt3;
estadoAnteriorbt4 = estadoActualbt4;
}


void switchWindow() { //Switch to the previous window
  delay(15);

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
}

void cutText() {  //Cut the text, ctrl x
  delay(15);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('x');
  Keyboard.releaseAll();
}

void copyText() {  //Copy the text, ctrl c
  delay(15);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('c');
  Keyboard.releaseAll();
}

void pasteText() {  //paste the text, ctrl v
  delay(15);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('v');
  Keyboard.releaseAll();
}

void resetGraphics() { //Restart the graphics drivers
  delay(50);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('b');
  Keyboard.releaseAll();
  delay(1000);
}

void playPause() { //Pause or start playing the song
  delay(15);
  Consumer.write(MEDIA_PLAY_PAUSE);
}

void nextTrack() { //Skip to the next song.
  delay(15);
  Consumer.write(MEDIA_NEXT);
}
void previousTrack(){ //Go back to the previous song
  delay(15);
  Consumer.write(MEDIA_PREVIOUS);
}


