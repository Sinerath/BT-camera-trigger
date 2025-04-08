#include <BleKeyboard.h>

#define SWITCH_PIN 16  // Switch connected between IO16 and GND

BleKeyboard bleKeyboard("Timelapse trigger", "SteamCookies", 100);
bool keyPressed = false;  // Track if the key was pressed

void setup() {
    Serial.begin(115200);
    pinMode(SWITCH_PIN, INPUT_PULLUP);  // Activate internal pull-up
    bleKeyboard.begin();
}

void loop() {
    if (bleKeyboard.isConnected()) {
        bool switchState = digitalRead(SWITCH_PIN);

        // Trigger on button press (switch opens, pin goes HIGH)
        if (switchState == HIGH && !keyPressed) {
            bleKeyboard.press(KEY_MEDIA_VOLUME_UP);
            Serial.println("Switch pressed");
            delay(50);  // Short press duration
            bleKeyboard.release(KEY_MEDIA_VOLUME_UP);
            keyPressed = true;  // Prevent repeat triggers
        }

        // Reset when button is released (switch closes, pin goes LOW)
        if (switchState == LOW && keyPressed) {
            keyPressed = false;
            Serial.println("Switch released");
            delay(50);  // Debounce release
        }

    } else {
        Serial.println("Waiting for BLE connection...");
    }

    delay(50);  // Loop debounce
}
