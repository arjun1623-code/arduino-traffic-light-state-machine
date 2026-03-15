# Traffic Light Controller (State Machine)

## Hardware

* Arduino Uno
* Push Button
* 3 LEDs (Red, Yellow, Green)
* 10kΩ Resistor

---

# Concept

This project implements a **traffic light controller using a Finite State Machine (FSM)**.

The controller cycles through three states:

* **RED**
* **GREEN**
* **YELLOW**

Each **valid button press** moves the system to the next state.

```
RED → GREEN → YELLOW → RED
```

The logic is implemented in a **non-blocking way using `millis()`**, allowing the Arduino to continuously monitor inputs while running the system.

---

# Why `millis()` instead of `delay()`

`delay()` pauses the microcontroller and blocks all other operations.

During a delay:

* Inputs cannot be processed
* Button presses may be missed
* System responsiveness is reduced

Using **`millis()` enables non-blocking timing**, allowing the program to:

* Continuously check the button
* Update states instantly
* Remain responsive

---

# Button Debouncing

Mechanical push buttons do **not produce a clean signal** when pressed.

Instead of switching cleanly from:

```
HIGH → LOW
```

the signal often rapidly oscillates due to **mechanical bouncing**:

```
HIGH → LOW → HIGH → LOW → HIGH → LOW
```

This bouncing can cause **multiple false triggers** for a single press.

---

# Why Simple Edge Detection Is Not Reliable

A common approach is detecting a falling edge:

```
current_state != previous_state
```

combined with a debounce timer.

Example (not recommended for this project):

```cpp
if ((current_state != previous_state) &&
    (millis() - lastPressTime >= DEBOUNCE_DELAY) &&
    (current_state == LOW)) {

    lastPressTime = millis();
    TrafficLightController();
}
```

Although this detects an **edge**, it is **not robust** because:

1. **Bounce occurs during both press and release**
2. Multiple edges may appear within a few milliseconds
3. The system may trigger multiple state transitions
4. The button signal may still be unstable when the edge is detected

So edge detection alone does **not guarantee a stable state change**.

---

# Robust Debounce Strategy Used

Instead of reacting immediately to edges, this project uses a **stable state verification approach**.

The algorithm works as follows:

1. Read the current button state
2. If the state changes, start a timer
3. Wait until the signal remains stable for the debounce interval
4. Only then accept the new state
5. Trigger the state machine transition

This ensures that **only stable button presses cause state changes**, eliminating false triggers from bouncing.

---

# State Machine Diagram

![State Machine](state_machine/state_machine.jpg)

---

# Circuit

![Circuit](circuit/circuit_diagram.png)

---

# Code

The full implementation is available in:

```
/code/traffic_light.ino
```

The code demonstrates:

* Finite State Machine implementation
* Non-blocking timing using `millis()`
* Robust push-button debouncing
* Clean state transitions

---

✅ **Key Concepts Demonstrated**

* Finite State Machines (FSM)
* Embedded debouncing techniques
* Non-blocking programming with `millis()`
* Reliable button input handling

---


That would make your repo look **much stronger for internships (IIT-H, robotics labs, embedded roles, etc.)**.

