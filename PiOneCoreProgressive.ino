#include <Arduino.h>

double pi = 0.0;                   // Variable to store the approximated value of Pi
double truePi = 3.1415926535;      // The known true value of Pi
const unsigned long maxIterations = 100000000; // Define a maximum number of iterations (10 million)
const unsigned long printInterval = 100000;   // Interval at which to print the current Pi value

double calculateRelativeError(double approximatedPi, double truePi) {
  return abs((approximatedPi - truePi) / truePi) * 100.0; // Return the error as a percentage
}

void CalculatePi() {
  unsigned long startTime = millis(); // Record the start time

  for (unsigned long k = 0; k < maxIterations; k++) { // Loop indefinitely or until maxIterations
    // Perform the Pi calculation using the Leibniz formula
    if (k % 2 == 0) {
      pi += 4.0 / (2 * k + 1); // Add the term if k is even
    } else {
      pi -= 4.0 / (2 * k + 1); // Subtract the term if k is odd
    }

    // Every 'printInterval' iterations, print the current approximation of Pi
    if ((k + 1) % printInterval == 0) {
      unsigned long currentTime = millis();    // Record the current time
      unsigned long duration = currentTime - startTime; // Calculate the duration so far
      
      Serial.print("Iterations: ");
      Serial.print(k + 1);
      Serial.print(" - Time taken: ");
      Serial.print(duration);
      Serial.println(" ms");

      Serial.print("Approximated Pi value: ");
      Serial.println(pi, 12); // Print Pi with 10 decimal places
      Serial.println("The real value of pi:  3.1415926535");

      double error = calculateRelativeError(pi, truePi); // Calculate the relative error
      Serial.print("Relative Error: ");
      Serial.print(error, 8);
      Serial.println(" %");

      Serial.println(); // Add an empty line for readability
    }
  }
}

void setup() {
  Serial.begin(115200); // Initialize serial communication at 115200 baud
  while (!Serial) {
    ; // Wait for serial port to connect. Needed for native USB boards like Arduino Leonardo
  }
  delay(1000); // Wait for a moment to ensure the serial connection is ready

  Serial.println("Continuous Pi Calculation"); // Indicate the start of the calculation
  CalculatePi(); // Call the function to calculate Pi
}

void loop() {
  // Nothing to do here
}
