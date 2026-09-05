# UWS.B - Tilt-Based Parachute Deployment System for Model Rockets

[![License: CERN-OHL-S v2](https://img.shields.io/badge/License-CERN--OHL--S%20v2-blue.svg)](LICENSE)  
**Open-source design files for the UWS.B amateur rocket recovery device**

The **UWS.B** (Układ Wyzwalania Spadochronu – version made by bartekM) is a compact, lightweight, tilt-activated parachute deployment system designed for model and high-power rockets. It uses a magnetic sensor to detect changes in the Earth's magnetic field caused by rocket tilt at apogee and fires a pyrotechnic igniter to deploy the recovery parachute.

Inspired by the original UWS5 by "Jaskiniowiec", the UWS.B was developed by bartekM (Polskie Towarzystwo Rakietowe / Polish Rocketry Society) and improved with smaller electronics components, easier assembly, and additional features.

**This repository contains complete design files** (schematics + PCB layout, Gerber files) so you can build your own units.

## Features

- Fully automatic tilt-triggered parachute deployment
- Built-in Li-Po battery with USB charging
- Igniter continuity check (LED + buzzer)
- Visual battery voltage indicator (5-level blinking)
- User-adjustable trigger angle via potentiometer (typically 45–80° from vertical)
- Arm/disarm jumper for safety
- Sensor reset jumper
- Compact and lightweight (~11 g)
- Easy-to-assemble PCB (mostly SMD with reflow + few THT parts)
- Optional footprint for ATtiny10 microcontroller for future extensions
- Coated with protective lacquer (PVB60 recommended)

## Technical Specifications

| Parameter              | Value                          |
|------------------------|--------------------------------|
| Dimensions             | 56 × 26 mm    |
| Mounting holes         | 50 × 20 mm spacing, Ø 3 mm    |
| Weight                 | ~11 g                          |
| Battery                | 1S Li-Po 80 mAh (Turnigy)      |
| Charging               | microUSB, 100 mA, 4.5–6 V     |
| Sensor                 | KMZ51 magnetic field sensor    |
| Indicators             | PWR (red), BAT/USB (blue), IGN (green), CHRG (yellow) |
| Audio                  | Buzzer for continuity & trigger |
| Connectors             | 2-pin igniter header           |

## How It Works

The KMZ51 sensor measures the Earth's magnetic field. When the rocket tilts beyond the angle set by the potentiometer, the device detects the change and (if armed) fires the igniter. The system assumes the rocket is flying vertically and will tilt naturally at apogee.

**Important:** The device relies on sufficient tilt. It may not trigger if the rocket flies perfectly straight, sideways, or tumbles without tilting.

## Repository Contents

- `hardware/` – Hardware design files (schematic + PCB)
- `firmware/` – Firmware for on-board battery meter
- `docs/` – FAQ, usage instructions etc

## Building Your Own UWS.B (DIY method)

1. Order PCBs (6-up panel recommended) from JLCPCB / ALLPCB.
2. Source components (see BOM).
3. Apply solder paste with laser-cut stencil → place SMD parts → reflow (modified mini oven works great).
4. Hand-solder THT parts (buzzer, potentiometer, headers, battery wires, microUSB).
5. Program the microcontroller for battery voltage measurement (pre-compiled hex included).
6. Break panels, sand edges, solder battery, test everything.
7. Coat board with PVB60 or similar conformal coating.

## Building Your Own UWS.B (lazy method)

1. Order PCBs (6-up panel recommended) from JLCPCB / ALLPCB with assembly service.
2. Source missing components (see BOM).
3. Hand-solder THT parts (buzzer, potentiometer, headers, battery wires, microUSB).
4. Program the microcontroller for battery voltage measurement (pre-compiled hex included).
5. Break panels, sand edges, solder battery, test everything.
6. Coat board with PVB60 or similar conformal coating.

## Usage Instructions

### Angle Setup (recommended before every flight)
0. Make sure that ARM jumper is no inserted!
1. Insert igniter or metal wire to simulate igniter.
2. Power on (insert PWR jumper).
3. Reset sensor (short RST jumper for ~1 s).
4. Tilt rocket until buzzer sounds → adjust potentiometer to desired angle.
5. Repeat steps 3 and 4 until you are satified.

### Pre-Launch Checklist
0. Power on by inserting PER jumper.
1. Check battery level (blue LED blinks - 1 short = battery dead, 5 = batery full).
2. Verify igniter continuity (green LED + buzzer).
3. Check trigger angle.
4. Insert igniter into parachute charge.
5. Close ARM jumper.
6. Launch.

### After Flight
- Remove ARM jumper immediately.
- Remove PWR jumper.
- Inspect device for damage.

## Safety & Warnings

- This is an **amateur / experimental** device. Always verify functionality on the ground before flight.
- Keep away from steel/ferromagnetic parts (affects sensor).
- Use only commercial electric igniters designed for rockets.
- Test the entire recovery system (parachute + charge) before flight.
- The designer and contributors are not liable for damage or injury resulting from use or misuse.

## License

- **Hardware designs** – [CERN Open Hardware Licence Version 2 – Strongly Reciprocal](LICENSE_hardware)  
- **Firmware & software** – [MIT LICENSE](LICENSE)
- **Documentation** – CC-BY-SA 4.0

See [LICENSE](LICENSE) file for details.

You are free to build, modify, and even sell boards as long as you share your modifications under the same license.

## Credits & Links

- Original designer: **bartekM** (Polskie Towarzystwo Rakietowe)
- Inspiration: UWS5 by Jaskiniowiec
- Forum threads (Polish):
  - [UWS.B2](https://forum.rakiety.org.pl/viewtopic.php?t=3159)
  - [UWS.B1](https://forum.rakiety.org.pl/viewtopic.php?t=3040)
- Support the author: [Buy Me a Coffee](https://www.buymeacoffee.com/bartekM)

## Contributing

Pull requests welcome! Bug reports, improvements, translations, and new features are appreciated.
