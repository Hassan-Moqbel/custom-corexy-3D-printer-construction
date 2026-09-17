# RAMPS 1.4 Power & Mechatronics Specifications

## Power Distribution & Constraints
The RAMPS (RepRap Arduino Mega Pololu Shield) 1.4 board is designed to distribute power to both the logical systems (Arduino, LCD) and the high-current physical loads (Heaters, Bed, Steppers). 

The board features a dual power rail architecture powered by a **12V 30A (360W)** switched-mode power supply (SMPS):
- **11A Rail**: Dedicated exclusively to the Heated Bed (approx. 132W draw). Protected by an 11A PTC polyfuse (MF-R1100).
- **5A Rail**: Supplies the Extruder Hotend (40W), Stepper Drivers (approx. 1A-2A max total), and the Arduino Mega 2560 voltage regulator. Protected by a 5A PTC polyfuse (MF-R500).

> [!WARNING] 
> **Thermal Degradation of MOSFETs and PTC Fuses**
> The stock RAMPS 1.4 uses STP55NF06L MOSFETs which can run hazardously hot when pushing 11A continuously to a heated bed, sometimes melting the green power terminals. Similarly, PTC polyfuses degrade over time under sustained high temperatures, increasing their internal resistance and causing voltage drops. To mitigate fire risks, an external MOSFET module is highly recommended for driving the heated bed.

## Stepper Driver Tuning (A4988)
To prevent stepper motors from overheating or skipping steps, the A4988 driver current must be properly tuned via the onboard potentiometer. 

The maximum trip current $I_{trip}$ delivered to the motor coils is calculated by:
$$ I_{trip} = \frac{V_{ref}}{8 \times R_{sense}} $$

For a typical A4988 driver with $R_{sense} = 0.1 \Omega$ and a target motor current of $1.0\text{A}$:
$$ V_{ref} = 8 \times 1.0\text{A} \times 0.1\Omega = 0.8\text{V} $$
Measuring the voltage from the tuning potentiometer to GND and adjusting it to $0.8\text{V}$ ensures the motor receives exactly $1.0\text{A}$ per phase.
