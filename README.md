# PiOneCoreProgressive
Arduino sketch to approximate Pi using the Leibniz series. Configurable for up to 100M iterations, printing progress every 100k steps. Outputs the current Pi value, elapsed time, and relative error. Ideal for performance benchmarking and educational purposes. Compatible with various microcontrollers.

## Features

- **Leibniz Series Calculation**: Approximates Pi using the simple alternating series formula.
- **Configurable Parameters**:
  - `maxIterations`: Maximum number of iterations for the Pi calculation (default: 100 million).
  - `printInterval`: Number of iterations between each output to the serial monitor (default: 100,000).
- **Real-time Output**:
  - Prints the current approximation of Pi with 12 decimal places.
  - Outputs the time taken in milliseconds for every `printInterval` iterations.
  - Calculates and displays the relative error compared to the true value of Pi (`3.1415926535`).

## Setup

1. **Hardware Requirements**:
   - Arduino board or compatible microcontroller (e.g., ESP32, Arduino Uno).
   - USB connection to a computer with a serial monitor (e.g., Arduino IDE).

2. **Software Requirements**:
   - Arduino IDE installed on your computer.
   - Serial Monitor configured to 115200 baud rate for proper communication.

## How It Works

1. The sketch initializes serial communication at a baud rate of 115200.
2. The Pi calculation begins, iterating up to `maxIterations`.
3. At every `printInterval` iterations, the current approximation of Pi, elapsed time, and relative error are printed to the serial monitor in a human-readable format.
4. The output can be observed in the Arduino IDE's Serial Monitor.

## Example Output


