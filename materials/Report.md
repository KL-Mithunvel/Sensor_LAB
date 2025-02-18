
# Experiment 1: Automatic Street Light Control

## Aim
To design and implement a system that automatically switches a street light **ON** and **OFF** based on ambient light intensity using an Arduino and a light sensor (e.g., LDR).

## Materials Required
- Arduino UNO (or equivalent)  
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


## Code

## proof of working
 
## result



# Experiment 2: DC Motor Speed & Direction Control

## Aim
To control the speed and direction of a DC motor using an Arduino, a motor driver (e.g., L293D or L298N), and PWM signals.

## Materials Required
- Arduino UNO (or equivalent)  
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

## proof of working
 
## result

# Experiment 3: Servo Motor Control

## Aim
To control the angular position (speed and direction of motion) of a servo motor using Arduino, demonstrating precise position control.

## Materials Required
- Arduino UNO (or equivalent)  
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
- circuit explanation
![image](https://github.com/user-attachments/assets/88504356-372c-42da-ab51-8b54d2f706c2)

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
## proof of working

 ![WhatsApp Image 2025-02-12 at 15 30 24_3ea6d17a](https://github.com/user-attachments/assets/29d70c98-5abc-48dc-b171-e15699f85f64)
 ![WhatsApp Image 2025-02-12 at 15 30 24_96132fc4](https://github.com/user-attachments/assets/da814d7f-b8fb-4694-9b14-6dcaa70e9c2c)
![WhatsApp Image 2025-02-12 at 15 30 24_119b4d66](https://github.com/user-attachments/assets/b4c44bc3-6463-47c3-b5ba-f89385220e69)
![WhatsApp Image 2025-02-12 at 15 30 24_3b0c4e17](https://github.com/user-attachments/assets/99af8e42-9d5e-4a2f-b640-4213debd5a00)
![WhatsApp Image 2025-02-12 at 15 30 24_b2ff15c6](https://github.com/user-attachments/assets/5dff178d-8d4c-4979-933f-75fbe6280492)


## result
   The system effectively monitors the temperature of the laptop using the thermal sensor.
