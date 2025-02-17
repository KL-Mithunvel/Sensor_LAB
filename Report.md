
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
 
## resut



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
 
## resut

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
 
## resut


# Experiment 4: Laptop Cooling System using Thermal Sensor

## Aim
To monitor the temperature using a thermal sensor (e.g., LM35 or thermistor) and automatically switch a cooling fan **ON** when the temperature exceeds a certain threshold.

## Materials Required
- Arduino UNO (or equivalent)  
- Temperature sensor (LM35, thermistor, or DS18B20)  
- DC fan (5V or 12V)  
- Transistor or motor driver (for controlling the fan)  
- Diode for back-EMF protection  
- Breadboard and jumper wires  
- External power supply (if required by the fan)

## Procedure
1. **Turn on the Arduino IDE**.  
2. **Type or paste the given code** to read the temperature sensor and switch the fan ON/OFF based on the threshold.  
3. **Make the connections** according to the circuit diagram:
   - Sensor output to an analog pin (A0) if using LM35 or thermistor.  
   - Fan controlled by a transistor or driver connected to an Arduino digital pin.  
   - Include a diode across the fan for protection.  
4. **Upload the code** to the Arduino, verifying the board and port settings.  
5. **Test** by monitoring the temperature reading. When it exceeds the set threshold, the fan should automatically power ON and turn OFF when below the threshold.

## Circuit Diagram
*(Insert your circuit diagram here. You can embed an image or ASCII diagram.)*

## Code

## proof of working
 
## resut
