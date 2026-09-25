#include <HID-Project.h>

const int bt1 = 4;
const int bt2 = 2;
const int bt3 = 6;
const int bt4 = 8;

int estadoAnteriorbt1 = HIGH;
int estadoAnteriorbt2 = HIGH;
int estadoAnteriorbt3 = HIGH;
int estadoAnteriorbt4 = HIGH;

void setup() {

  pinMode(bt1, INPUT_PULLUP);
  pinMode(bt2, INPUT_PULLUP);
  pinMode(bt3, INPUT_PULLUP);
  pinMode(bt4, INPUT_PULLUP);

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
  jump();
}

if (estadoAnteriorbt2 == HIGH && estadoActualbt2 == LOW) {
  delay(65);
  prevM();
}

if (estadoAnteriorbt3 == HIGH && estadoActualbt3 == LOW) {
  delay(65);
  pauseM();
}

if (estadoAnteriorbt4 == HIGH && estadoActualbt4 == LOW) {
  delay(65);
  skipM();
}

estadoAnteriorbt1 = estadoActualbt1;
estadoAnteriorbt2 = estadoActualbt2;
estadoAnteriorbt3 = estadoActualbt3;
estadoAnteriorbt4 = estadoActualbt4;
}


void jump() { //cambio de ventana

  delay(15);

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
}

void cortar() {

  delay(15);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('x');
  Keyboard.releaseAll();
}

void reset() { //reinicia los graficos por si congela

  delay(50);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('b');
  Keyboard.releaseAll();
  delay(1000);
}

void pauseM() { //pausa la musica
  delay(15);
  Consumer.write(MEDIA_PLAY_PAUSE);
}

void skipM() { //pasa a la siguente cancion
  delay(15);
  Consumer.write(MEDIA_NEXT);
}
void prevM(){
  delay(15);
  Consumer.write(MEDIA_PREVIOUS);
}


