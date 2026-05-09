# Leaky-Integrate-Fire-Arduino 
A beginner-friendly Arduino project that simulates a neuron using a pushbutton and LED!

Over spring break, I wanted to see if I could get an Arduino to behave like a neuron. I didn't just want it to blink an LED, I wanted it to actually model the integrate-and-fire dynamics that computational neuroscientists use to describe how real neurons work.

This is a pretty basic C++ sketch, but the biology behind it is real.

## Concept
* Button press → Excitatory Input (EPSP) \
  Each press slightly increases the membrane potential.
* Decay/Leak → Passive membrane property \
  If presses are too far apart, the membrane potential slowly decays back to zero.
* Threshold → Action potential \
  When the potential exceeds a set threshold, the neuron "fires" and the LED lights up.
* Refractory period → Rest after firing \
  After firing, the neuron cannot fire again immediately, mimicking biological neurons.

This project combines software modelling of neuron behaviour with physical inputs/outputs on an embedded system.

## Hardware
* Arduino Uno R3 - acts as the neuron
* Pushbutton on Pin 2 - input signal
* LED on Pin 13 - output spike
* USB connection - powers Arduino and allows serial monitoring

Wiring tip:
* One leg of the button → 5V
* Other leg → Pin 2, with a 2kΩ pull-down resistor to GND
* LED uses built-in pin 13

## Code Highlights
* ```
  membranePotential++ // adds input from button press
  ```
* ```
  membranePotential -= decayRate // leaky behaviour
  ```
* ```
  if (membranePotential >= threshold) // neuron fires, LED blinks
  ```
* ```
  refractoryPeriod // prevents immediate firing
  ```

## How It Works
1. Press the button repeatedly. Each press adds a small increment to the membrane potential.
2. If presses are fast enough to reach the threshold, the LED lights up briefly (this is the neuron "spiking").
3. If presses are too slow, decay subtracts from the potential (like a leaky neuron).
4. After firing, the neuron enters a refractory perod during which further presses are ignored.

## Video Demos
1. The basic spike: Threshold = 3. Three presses → one spike. The neuron sums inputs until it crosses threshold, then fires.

https://github.com/user-attachments/assets/9e48a45a-e946-4617-8c35-13f91926c391

2. The decay leak: Press too slowly and the membrane potential decays back to zero. This is the "leaky" part of leaky-integrate-and-fire. The real neurons lose charge over time too.

https://github.com/user-attachments/assets/de6263b2-5144-4638-b3b7-a9fd277eea42

3. The refractory period: After firing, the neuron ignores input for 1 second. That is its refractory period. Real neurons need time to reset their ion channels before they can fire again.

https://github.com/user-attachments/assets/1b33b4b4-3af3-428c-8939-af07005df129

## Learning Points
* Got hands-on experience with Arduino and basic C++
* Learned how a neuron adds up signals, leaks over time, and fires
* Explored how biology can be simulated using simple electronics

*Note:* This is my first real C++ project, I am more at home in Python. The code is intentionally simple so the biological model stays front and center. The LIF model is the most widely used model in computational neuroscience, and it turns out an Arduino Uno is more than enough hardware to run one!

## 👩‍💻 Author 
Mrunmayee Wankhede \
MS-QBB @ CMU
