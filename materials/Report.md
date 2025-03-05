
# Experiment 1: Automatic Street Light Control

## Aim
To design and implement a system that automatically switches a street light **ON** and **OFF** based on ambient light intensity using an Arduino and a light sensor (e.g., LDR).

## Materials Required
- Arduino leonardo
- Light Dependent Resistor (LDR)  
- 10 kΩ resistor (for voltage divider)  
- LED (to simulate the street light)  
- 220 Ω resistor (for current limiting)  
- Breadboard and jumper wires  
- Power supply (USB or external DC)

## Procedure
1. **Turn on the Arduino IDE**.  
2. **Type or paste the given code** (to read the LDR value and control the LED).  
3. **Make the necessary connections** on the breadboard:
   - Connect the LDR in a voltage divider with the 10 kΩ resistor.  
   - Connect the LED (with a 220 Ω resistor) to a digital pin on the Arduino.  
4. **Upload the code** to the Arduino after ensuring the correct board (e.g., Arduino UNO) and COM port are selected.  
5. **Test** by varying the amount of light on the LDR and observe the LED turning ON/OFF based on the threshold in the code.

## Circuit Diagram
<div align="center">
   
![image](https://github.com/user-attachments/assets/ca2fdf6f-c229-46c9-9cba-e0611984f949)
</div>

## Explanation of Circuit
- **Arduino Leonardo** is used as the microcontroller.  
- The **light sensor** is set up in a voltage divider with a 10 kΩ resistor . The output from this divider goes to the analog input pin **A1** on the Arduino.  
- The **LED** is powered through digital pin **5** on the Arduino. In practice, there should be a current-limiting resistor (e.g., 220 Ω) in series with the LED to protect it from excessive current.  
- All devices share a common **VCC** and **GND** with the Arduino.

## Code
```c
int pin_CDS = A1;   // pin number of Light Sensor
int pin_LED0 = 5;    // pin number of LED0
void setup() {
  pinMode(pin_CDS, INPUT);       // Set  light sensor pin as an input pin

  pinMode(pin_LED0, OUTPUT);        // Set LED0 pin as output pin
  // Serial Setting : Baud rate 115200, data 8bit, no parity, stop 1bit
  Serial.begin(115200);    // same as Serial.begin(115200, SERIAL_8N1)
  while(!Serial);          //Wait until the serial port is connected
}
void loop() {
  uint16_t ADC_data;
  // Read the analog value of the light sensor as a digital value
  // The higher the digital value, the brighter the light
  ADC_data = analogRead(pin_CDS);
  Serial.print("ADC Data : ");
  Serial.println(ADC_data);    // Outputs the ADC value in serial 
  // If the value measured by light sensor is less than 512, turn on LED0
  if(ADC_data < 512){
    // Output HIGH to LED0 pin (LED0 ON)
    digitalWrite(pin_LED0, 1);}
  // If the value measured by light sensor is greater than or equal to 512,turn off LED0
  else{
    // Output LOW to LED0 pin (LED0 OFF)
    digitalWrite(pin_LED0, 0);}
delay(500);
}
```
## Explanation of Code
- The code **reads the light sensor’s analog value** from pin **A1**.  
- It **turns the LED ON** if that value is below 512 (indicating lower light) and **OFF** otherwise.  
- The current sensor value is **printed to the Serial Monitor** for easy observation.  
- A small **delay** is included to slow down the update rate.

## proof of working
<div align="center">
   
 ![WhatsApp Image 2025-02-05 at 13 56 00_2e2da883](https://github.com/user-attachments/assets/2fc90af7-bdb4-4401-972f-511c609b7202)
![WhatsApp Image 2025-02-05 at 13 56 39_81a00a5c](https://github.com/user-attachments/assets/24a42191-1bcf-45d1-96bc-45c12a45bc1f)
![WhatsApp Image 2025-02-05 at 13 58 37_7a61667c](https://github.com/user-attachments/assets/c1c5c066-f251-45f8-88da-8454840351e4)

</div>

## Note

<div align="center">
  
  ![image](https://github.com/user-attachments/assets/c6ef0ba2-69b4-4557-b677-ac84cc8b6921)



| Arduino Pin Number | Light Sensor |
|-------------|--------------|
|  A1   |  CDS   |
|5      | LED0   |


</div>

 -  **Remark** : Control selection switch should be set to LED.
   
## result
When the ambient light level drops below a certain threshold (in this case, an ADC reading of 512), the Arduino turns the LED on. Conversely, if the light level is above or equal to this threshold, the LED remains off. By monitoring the serial output, you can see how the ADC value changes with the intensity of ambient light.


# Experiment 2: DC Motor Speed & Direction Control

## Aim
To control the speed and direction of a DC motor using an Arduino, a motor driver (e.g., L293D or L298N), and PWM signals.

## Materials Required
- Arduino leonardo
- DC motor (6V–12V)  
- Motor driver IC (L293D or L298N)  
- External power supply for the motor (9V or 12V)  
- Breadboard and jumper wires  
- (Optional) Potentiometer (10 kΩ) for variable speed input

## Procedure
1. **Turn on the Arduino IDE**.  
2. **Type or paste the given code** that sets motor direction pins and uses PWM for speed control.  
3. **Make the connections** as shown in the circuit diagram:
   - Connect the motor driver inputs to Arduino digital pins (for direction and PWM).  
   - Connect the DC motor to the driver outputs.  
   - Provide an external power supply to the motor driver’s motor supply pin.  
4. **Upload the code** to the Arduino, verifying the correct board and port settings.  
5. **Test** by adjusting the speed (via code or a potentiometer) and toggling direction pins; observe the motor’s response.

## Circuit Diagram
*(Insert your circuit diagram here. You can embed an image or ASCII diagram.)*


## Code
```c
int pin_DC_A=5;
int pin_DC_B=6;
void setup(){
  pinMode(pin_DC_A, OUTPUT);
  pinMode(pin_DC_B, OUTPUT);}
void loop(){
  int Speed_value;
  for(Speed_value=0;Speed_value<170;Speed_value++){
    forwardRotation(Speed_value);
    delay(20);}
    
  Stop();
  delay(7000);
  
  for(Speed_value=200;Speed_value<0;Speed_value--){
    reverseRotation(Speed_value);
    delay(20);}
  Stop();
  delay(7000);
}

void forwardRotation(int Speed)
{
  analogWrite(pin_DC_A,Speed);
  digitalWrite(pin_DC_B,0);
}
void reverseRotation(int Speed)
{
  analogWrite(pin_DC_B,Speed);
  digitalWrite(pin_DC_A,0);
}
void Stop(void)
{
  digitalWrite(pin_DC_A,0);
  digitalWrite(pin_DC_B,0);
}
```
## proof of working
## Note
## result

# Experiment 3: Servo Motor Control

## Aim
To control the angular position (speed and direction of motion) of a servo motor using Arduino, demonstrating precise position control.

## Materials Required
- Arduino leonardo
- Servo motor (e.g., SG90 or MG995)  
- Breadboard and jumper wires  
- (Optional) External power supply, if the servo needs higher current

## Procedure
1. **Turn on the Arduino IDE**.  
2. **Type or paste the given code** that uses the `Servo.h` library to control servo angle.  
3. **Make the connections** following the circuit diagram:
   - Servo signal wire to a PWM pin (e.g., pin 9).  
   - Servo Vcc to 5V, GND to Arduino GND.  
4. **Upload the code** to the Arduino, ensuring correct board and port settings.  
5. **Test** by observing the servo’s movement, which should rotate to the angles specified in the code (or respond to a potentiometer input, if used).

## Circuit Diagram
*(Insert your circuit diagram here. You can embed an image or ASCII diagram.)*

## Code
```c
#include <Servo.h>
int pin_SERVO = 13;
Servo SERVO;

void setup(){
  SERVO.attach(pin_SERVO);
  
  SERVO.write(0);
  delay(2000);
  }

void loop(){
  unsigned char angle;
  for(angle=0;angle<=180;angle+=5){
    SERVO.write(angle);
    delay(500);
    }
   delay(1000);
     for(angle=180;angle>=90;angle-=10){
    SERVO.write(angle);
    delay(1000);
   }
   delay(1000);
   SERVO.write(0);
   delay(1000);
  } 
```
## proof of working
 
## result


# Experiment 4: Laptop Cooling System using Thermal Sensor

## Aim
To monitor the temperature using a thermal sensor (e.g., LM35 or thermistor) and automatically switch a cooling fan **ON** when the temperature exceeds a certain threshold.

## Materials Required
- Arduino leonardo
- Temperature sensor (LM35)  
- DC fan (5V or 12V)  
- Transistor or motor driver (for controlling the fan)  
- Breadboard and jumper wires  
  
## Procedure
1. **Turn on the Arduino IDE**.  
2. **Type or paste the given code** to read the temperature sensor and switch the fan ON/OFF based on the threshold.  
3. **Make the connections** according to the circuit diagram:
4. **Upload the code** to the Arduino, verifying the board and port settings.  
5. **Test** by monitoring the temperature reading. When it exceeds the set threshold, the fan should automatically power ON and turn OFF when below the threshold.

## Circuit Diagram

<div align="center">
   
![image](https://github.com/user-attachments/assets/6b0c1499-4af1-4804-b85c-3e2c20aad16d)
</div>

## Explanation of Circuit
- An **Arduino** serves as the main controller.  
- The **temperature sensor** (LM35) is connected to an analog input pin (e.g., A0). This pin reads the voltage output of the sensor, which corresponds to the measured temperature.  
- A **motor driver** is used to power the **DC fan**. The Arduino’s digital output pin controls the motor driver, switching the fan power on or off. 
- The Arduino, sensor, and driver circuit share a **common ground** (GND). If the fan requires a higher voltage (e.g., 12V), an external power supply is provided, and its negative terminal is tied to the Arduino’s GND.

## Code
```c
int pin_TEMP = A4;
int pin_DC_A = 5;
int pin_DC_B = 6;
void setup(){
  pinMode(pin_TEMP, INPUT);
  pinMode(pin_DC_A, OUTPUT);
  pinMode(pin_DC_B, OUTPUT);
  pinMode(pin_TEMP, INPUT);
  while(!Serial);
}


void loop() {
  long int Temp, ADC_data;
  //Reads the analog value of temperature sensor as 10-bit digital value
  ADC_data=analogRead(pin_TEMP);
  //Convert digital value to temperature value
  //Temp=Voltage[V]*100
  Temp = ADC_data * 100 * 5/ 1023;
  //Outputs "ADC Data: " serially
  Serial.print("ADC_data:");
  //Output the measured value of temperature sensor serially
  Serial.print(ADC_data);
  //Outputs ", Temp :" serially
  Serial.print(", Temp :");
  //Outputs temperature value serially
  Serial.print(Temp);
  //outputs "[C]" serially
  Serial.println("[C]");
  delay(500);
  if(Temp<31)
  {
    forwardRotation(100);
  }
  else if(Temp>31)
  {
    reverseRotation(100);
  }
  else{
    Stop();
    }
    delay(100);
  }
  void forwardRotation(int Speed){
    analogWrite(pin_DC_A, Speed);
    digitalWrite(pin_DC_B, 0);
  }
  void reverseRotation(int Speed){
    analogWrite(pin_DC_B, Speed);
    digitalWrite(pin_DC_A, 0);
  }
  void Stop(void){
    digitalWrite(pin_DC_A, 0);
    digitalWrite(pin_DC_B, 0);
  }
```

## Explanation of Code
- The code **reads the sensor’s analog voltage** using `analogRead()`.  
- It **converts** this reading to a temperature value (depending on the specific sensor calibration).  
- The temperature is then **compared to a threshold** (e.g., 35°C).  
- If the measured temperature **exceeds the threshold**, the Arduino **sets a digital output pin HIGH**, powering the transistor and turning the fan on. Otherwise, it sets the pin LOW, turning the fan off.  
- Throughout the loop, the **temperature and fan status** can be printed to the Serial Monitor for debugging or monitoring purposes.

## proof of working
<div align="center">

 ![WhatsApp Image 2025-02-12 at 15 30 24_3ea6d17a](https://github.com/user-attachments/assets/29d70c98-5abc-48dc-b171-e15699f85f64)
 ![WhatsApp Image 2025-02-12 at 15 30 24_96132fc4](https://github.com/user-attachments/assets/da814d7f-b8fb-4694-9b14-6dcaa70e9c2c)
![WhatsApp Image 2025-02-12 at 15 30 24_119b4d66](https://github.com/user-attachments/assets/b4c44bc3-6463-47c3-b5ba-f89385220e69)
![WhatsApp Image 2025-02-12 at 15 30 24_3b0c4e17](https://github.com/user-attachments/assets/99af8e42-9d5e-4a2f-b640-4213debd5a00)
![WhatsApp Image 2025-02-12 at 15 30 24_b2ff15c6](https://github.com/user-attachments/assets/5dff178d-8d4c-4979-933f-75fbe6280492)
</div
   
## Note

## result
   The system effectively monitors the temperature of the laptop using the thermal sensor.
