# UWS.B FAQ

### What is the UWS.B?
A compact tilt-activated parachute deployment device for model rockets. It fires an electric igniter when the rocket tilts beyond a user-set angle (detected via Earth's magnetic field).

### How accurate is the tilt detection?
It works reliably in the 45–80° range from vertical. The exact angle depends on local magnetic conditions and rocket orientation. Always test on the ground before flight.

### Where should I mount the device in the rocket?
- Place it near the recovery charge (e.g., in the nose cone or payload bay).
- **Igniter connector must point upward** during flight.
- Keep it at least 5–10 cm away from any steel, motors, or ferromagnetic parts.
- Use the 50 × 20 mm mounting holes (3 mm diameter).

### What igniters should I use?
Only commercial rocket igniters (e.g., the 0.3 m or 0.5 m electric matches commonly sold on Allegro.pl). Do **not** use homemade igniters unless thoroughly tested.

### How do I check the battery?
Power on the device. The blue LED will blink 1–5 times:
- 1 blink = < 5 % (< 3.60 V)
- 5 blinks = > 85 % (> 4.05 V)
Charge via microUSB if needed (takes up to ~1 hour).

### How do I set the trigger angle?
1. Power on.
2. Short the RST jumper for ~1 second to reset the sensor.
3. Tilt the rocket slowly until the buzzer sounds.
4. Adjust the potentiometer until the buzzer triggers at the desired angle.

### What do the LEDs mean?
- **Red (PWR)** – Power is on
- **Blue (BAT/USB)** – Battery status or USB connected
- **Green (IGN)** – Igniter continuity OK
- **Yellow (CHRG)** – Charging in progress (turns off when full)

### Do I need to arm the device?
Yes. Close the **ARM** jumper only immediately before launch. Open it right after recovery.

### Can the device fail to deploy?
Yes. Possible reasons:
- No sufficient tilt at apogee (very stable flight or ballistic trajectory)
- Rocket flies sideways or tumbles without proper tilt
- Low battery
- Igniter not connected properly
- Sensor near steel parts

**Always have a backup recovery system (e.g., timer or dual deployment).**

### Is the design open-source?
Yes. All files are provided under the CERN-OHL-S v2 license. You may build, modify, and even sell boards, but you must share your changes under the same license.

### I want to buy a ready-made unit instead of building one
The original designer occasionally produces small batches. Check the forum thread or Discord[](https://discord.gg/DJDwmmX9) for current availability.

### Can I add my own features?
Yes! There is an optional footprint for an ATtiny10 microcontroller for custom functions (e.g., booster recovery, telemetry, etc.).

### Who should I contact for questions?
- Main discussion: [Polish Rocketry Forum – UWS.B2 thread](https://forum.rakiety.org.pl/viewtopic.php?t=3159)
- English questions: open an issue in this repository