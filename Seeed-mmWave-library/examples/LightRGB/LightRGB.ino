#include <Arduino.h>

// The pin for the built-in LED on ESP32-C6 boards can vary.
// - Official ESP32-C6-DevKitC-1 has an RGB LED on GPIO 8.
// - Seeed Studio XIAO ESP32-C6 has a user LED on GPIO 21.
// The original pin 2 is common for older ESP32s, but not the C6.
// Try changing this value to the correct pin for your specific board.
// You can also try using LED_BUILTIN if your board definition supports it.
const int ledPin = 15;  // START BY TRYING PIN 8 or 21

void setup() {
  // Initialize the serial communication at 115200 baud
  Serial.begin(115200);
  // Wait a moment for the serial monitor to connect
  delay(1000);
  Serial.println("ESP32-C6 LED Blink Test");
  
  // Initialize the built-in LED
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.print("LED Pin configured: ");
  Serial.println(ledPin);
}

void loop() {
  Serial.println("Blinking LED ON");
  digitalWrite(ledPin, HIGH);  // Turn on LED
  delay(500);
  Serial.println("Blinking LED OFF");
  digitalWrite(ledPin, LOW);   // Turn off LED
  delay(500);

  // The original fade effect using analogWrite() might not work without
  // properly setting up the LEDC (PWM) peripheral on the ESP32-C6.
  // Let's get the basic blinking working first before re-introducing this.
}
