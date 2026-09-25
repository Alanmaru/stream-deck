#include <HID-Project.h>

const int bt1 = 2;
const int bt2 = 4;
const int bt3 = 6;
const int bt4 = 8; //Those are the 4 buttons

const int potenciometro = A0; //Here we declare the potentiometer
int valorAnterior = 0; //a variable that will be useful for simple filtering in the future

int estadoAnteriorbt1 = HIGH;
int estadoAnteriorbt2 = HIGH;
int estadoAnteriorbt3 = HIGH;
int estadoAnteriorbt4 = HIGH;

void setup() {

  pinMode(bt1, INPUT_PULLUP);
  pinMode(bt2, INPUT_PULLUP);
  pinMode(bt3, INPUT_PULLUP);
  pinMode(bt4, INPUT_PULLUP);

  valorAnterior = analogRead(potenciometro);

  Keyboard.begin();
  Consumer.begin();
}

void loop() {

  int estadoActualbt1 = digitalRead(bt1);
  int estadoActualbt2 = digitalRead(bt2);
  int estadoActualbt3 = digitalRead(bt3);
  int estadoActualbt4 = digitalRead(bt4);

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

int valorActual = analogRead(potenciometro);

if (valorActual > valorAnterior + 10) {
    Consumer.write(MEDIA_VOLUME_UP);
    valorAnterior = valorActual;
}

if (valorActual < valorAnterior - 10) {
    Consumer.write(MEDIA_VOLUME_DOWN);
    valorAnterior = valorActual;
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


