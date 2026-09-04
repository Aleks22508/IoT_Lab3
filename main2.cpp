#include <Arduino.h>

uint8_t value;

void setup(){

// configure PD7-PD4 as inputs (0x0F)

  DDRD &= 0x0F;

// enable input pullup (0xF0)

  PORTD |= 0xF0;

// configure PB3-PB0 (0x0F)

  DDRB &= 0x0F;

  Serial.begin(9600);
}

void loop(){

// read switches

  value = PIND;

// mask the values (0xF0)

  value &= 0xF0;

// shift right value >> 4

  value >>= 4;

// invert the value

  value = ~value;

// mask value (0x0F)

  value &= 0x0F;

// invert the value

  value = ~value;

// add 1

  value = value + 1;

// mask the value

  value &= 0x0F;

// display on LED

  PORTB = value;

// print to serial monitor

  Serial.print("Binary: ");
  Serial.println(value, BIN);
  Serial.print("Decimal: ");
  Serial.println(value);
  Serial.println("--------");

  delay(1000);
}