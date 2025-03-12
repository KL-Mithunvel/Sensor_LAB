
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
To control the speed and direction of a DC motor using an Arduino, a motor driver (BA6208F).

## Materials Required
- Arduino leonardo
- DC motor (6V–12V)  
- Motor driver IC (BA6208F)  
- Breadboard and jumper wires  
  

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
![image](https://github.com/user-attachments/assets/f6b4486d-6597-4626-afb9-31aa2b91765b)

## Explanation of Circuit
- **Microcontroller (Arduino)**: Provides the control signals for motor speed and direction.  
- **Motor Driver IC (e.g., L293D or L298N)**:
  - **Input Pins** (IN1, IN2, IN3, IN4) connect to Arduino digital pins. Two of these pins control the direction (e.g., IN1 and IN2 for one motor), while one (or both) can be used with **PWM** for speed control on Arduino pins supporting `analogWrite()`.
  - **Enable Pins** (EN1, EN2) may need to be connected to a digital pin or tied HIGH for the driver to operate.
  - **Motor Power Supply (Vs)** provides the voltage and current for the DC motor (e.g., 9V or 12V).  
  - **Logic Power (Vss)** powers the driver’s internal logic (usually 5V from the Arduino).  
- **DC Motor** is connected across the driver’s **motor output pins** (e.g., OUT1 and OUT2 for a single motor).  
- **Common Ground**: The negative terminal of the motor’s power supply and the Arduino GND are tied together to ensure the signals share a common reference.

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

## Explanation of Code
- **Pin Assignments**:  
  - Two Arduino pins are designated for motor direction (e.g., `dirPin1` and `dirPin2`).  
  - One Arduino PWM pin is designated for motor speed (e.g., `pwmPin`).  
- **Setup**:  
  - The direction pins are declared as outputs using `pinMode()`.  
  - The PWM pin is also set as an output.
- **Loop**:  
  - **Direction Control**: Set one direction pin HIGH and the other LOW to spin the motor one way; reverse their states to spin in the opposite direction.  
  - **Speed Control**: Use `analogWrite(pwmPin, speedValue);` to vary the duty cycle (0–255), controlling how fast the motor spins.  
- **Example Flow**:  
  1. **Set direction** pins to define clockwise or counterclockwise rotation.  
  2. **Write a PWM value** (e.g., between 0 and 255) to the speed pin to run the motor at the desired speed.  
  3. (Optional) **Delay** to observe the motor’s behavior before changing direction or speed again.  

By adjusting the PWM duty cycle, you regulate the motor’s speed; by switching the direction pins, you reverse the motor’s rotation. Together, these steps form a basic but effective method for **DC motor speed and direction control** using a standard motor driver IC and an Arduino.

## proof of working
![WhatsApp Image 2025-03-05 at 14 04 40_a2361a84](https://github.com/user-attachments/assets/b263fdab-30df-46d4-a129-3fac51068fdb)
![WhatsApp Image 2025-03-05 at 14 04 43_1f8acbd7](https://github.com/user-attachments/assets/68c180d5-ab0d-40aa-a085-291f7fafa030)


## Note

| Arduino Pin Number | Light Sensor |
|-------------|--------------|
|  5   |  AIN   |
|  6   |  BIN   |

## result
By adjusting the PWM output and switching the control pins for direction, the DC motor successfully varies its speed and reverses rotation. Observing the motor confirms that lower PWM duty cycles result in slower rotation, while higher duty cycles increase the motor speed. Changing the polarity via the motor driver direction pins reverses the motor’s direction, demonstrating successful control of both speed and direction.


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
</div>

## Note

   ![image](https://github.com/user-attachments/assets/0db3442c-a847-42b9-95c8-7ad493ea4e0d)

| Arduino Pin Number | Light Sensor |
|-------------|--------------|
|  A4   |  LM35   |
|  5   |  AIN   |
|  6   |  BIN   |

- THE SAME CAN BE ACHIVED WITH DHT 22 / DHT 11 (AND BOTH WAS DONE)  

## result
   The system effectively monitors the temperature of the laptop using the thermal sensor.





   ![image](https://github.com/user-attachments/assets/6e22ec96-5541-4492-b80a-bbb01d951225)

![image](https://github.com/user-attachments/assets/4c1603f0-54db-41e4-841f-499782670b70)
