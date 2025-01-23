/* EEPROM Programmer */

const int RESET = 2;
const int OUTPUT_ENABLE = 3;
const int SHIFT_CLOCK = 4; // latch input
const int STORE_CLOCK = 5; // shift data, clock pulse
const int SERIAL_DATA = 6;
const int EEPROM_D0 = 7;
const int EEPROM_D7 = 14;

void setup()
{
  Serial.begin(9600) // check baud

  pinMode(RESET, OUTPUT);
  pinMode(OUTPUT_ENABLE, OUTPUT);
  pinMode(SHIFT_CLOCK, OUTPUT);
  pinMode(STORE_CLOCK, OUTPUT);
  pinMode(SERIAL_DATA, OUTPUT);

  digitalWrite(RESET, HIGH); // clear on low
  digitalWrite(OUTPUT_ENABLE, HIGH);

  sendStatus(0);
}

void loop()
{
  int byte = receiveByte();
  if (byte == -1) return;
  sendStatus(1);



  sendStatus(0);
}

int receiveByte() {
  return Serial.read();
}

/*
 * Sends status code to host device
 * 0 - ready to receive
 * 1 - busy
 */
void sendStatus(int status)
{
  Serial.write(status);
}
