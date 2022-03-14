
#include <Bounce2.h>

Bounce left_bounce = Bounce();
Bounce right_bounce = Bounce();

#define LEFT_PIN 10
#define RIGHT_PIN 4

#define DEBOUNCE_INTERVAL 25

#define BETWEEN_KEY_DELAY 50
#define HOLD_TIME 100

void setup() {
    left_bounce.attach(LEFT_PIN, INPUT_PULLUP);
    left_bounce.interval(DEBOUNCE_INTERVAL);

    right_bounce.attach(RIGHT_PIN, INPUT_PULLUP);
    right_bounce.interval(DEBOUNCE_INTERVAL);
}

void loop() {
    left_bounce.update();
    if (left_bounce.fell()) {
        Keyboard.press(MODIFIERKEY_CTRL);
        delay(BETWEEN_KEY_DELAY);
        Keyboard.press(KEY_C);
        delay(HOLD_TIME);
        Keyboard.release(KEY_C);
        delay(BETWEEN_KEY_DELAY);
        Keyboard.release(MODIFIERKEY_CTRL);
    }

    right_bounce.update();
    if (right_bounce.fell()) {
        Keyboard.press(MODIFIERKEY_CTRL);
        delay(BETWEEN_KEY_DELAY);
        Keyboard.press(KEY_V);
        delay(HOLD_TIME);
        Keyboard.release(KEY_V);
        delay(BETWEEN_KEY_DELAY);
        Keyboard.release(MODIFIERKEY_CTRL);
    }
}