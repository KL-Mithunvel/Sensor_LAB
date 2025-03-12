#include <DHT.h>

// Define pin numbers
#define DHTPIN 7      // DHT11 data pin connected to digital pin 7
#define MOTOR_PIN_1 5  // Motor positive terminal connected to pin 5
#define MOTOR_PIN_2 6  // Motor negative terminal connected to pin 6

#define DHTTYPE DHT11  // Define sensor type

DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor

// Define threshold temperature (in Celsius) 
#define TEMPERATURE_THRESHOLD 37

void setup() {
  // Start the serial communication for debugging
  Serial.begin(9600);
  
  // Initialize the DHT sensor
  dht.begin();
  
  // Set motor pins as OUTPUT
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  
  // Start with the motor turned off
  digitalWrite(MOTOR_PIN_1, LOW);
  digitalWrite(MOTOR_PIN_2, LOW);
}

void loop() {
  // Read the temperature from the DHT sensor
  float temperature = dht.readTemperature(); 
  
  // Check if the reading is valid
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Output temperature value to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  // Check if the temperature exceeds the threshold
  if (temperature >= TEMPERATURE_THRESHOLD) {
    Serial.println("Threshold reached! Activating motor...");
    
    // Turn on the motor for 5 seconds
    digitalWrite(MOTOR_PIN_1, HIGH);  // Set positive motor pin to HIGH
    digitalWrite(MOTOR_PIN_2, LOW);   // Set negative motor pin to LOW
    
    delay(5000);  // Wait for 5 seconds
    
    // Stop the motor
    digitalWrite(MOTOR_PIN_1, LOW);   // Turn off the motor
    digitalWrite(MOTOR_PIN_2, LOW);   // Turn off the motor
    
    Serial.println("Motor stopped!");
  }

  // Wait for 1 second before checking the temperature again
  delay(1000);  // Wait for 1 second before reading the temperature again
}
