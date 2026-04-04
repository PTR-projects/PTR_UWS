 # Changelog

All notable changes to the UWS hardware design will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),  
and the project uses **hardware versioning** (B1 → B2).

---

## [UWS B2.1]

**Minor hardware revision** – focused on safety, charging reliability, and small manufacturing improvements.

### Added
- PPTC (self-resetting polymeric fuse) in the igniter circuit  
  → protects against accidental shorts and over-current without needing replacement

### Changed / Improved
- Different battery charger IC  
- USB LED behavior updated: now lights up (solid) when the battery is fully charged
- Miscellaneous layout optimizations (cleaner routing, better component placement)
- Mounting holes spacing made flexible: works with **both 50 × 20 mm and 50 × 19 mm**  
  → increased compatibility with Arecorder while remaining backward-compatible

### Notes
- All other features, dimensions, weight (~11 g), connectors, and functionality remain identical to B2.
- This is the **current recommended version** – all design files (KiCad, Gerber, BOM) in this repository belong to **UWS B2.1**.

## [UWS B2]

**Major hardware revision** – significant improvements in reliability, safety, manufacturability, and future-proofing compared to B1.

### Added
- Optional footprint for ATtiny10 microcontroller in the igniter trigger path  
  (allows custom firmware for special flights, e.g. booster recovery, staging, or additional logic)
- Enlarged and clearer silkscreen labels + Polish Rocketry Society (PTR) logo

### Changed / Improved
- **New measurement amplifier**  
  Works at much lower voltages with negligible offset (major improvement over B1)
- Angle regulation circuit completely reworked  
  Easier to adjust ranges, sensitivity, and compensate for “problematic” KMZ51 sensors
- Simplified signal path  
  Removed the extra comparator that was used in B1 to stabilize transient states
- Slightly improved sensor reset circuit
- Battery voltage measurement accuracy improved
- Igniter control logic reversed (now permanently grounded, switched on +V side)  
  → Eliminates risk of accidental firing if igniter wire shorts to ground
- Mounting holes metallization disconnected from GND  
  → Significantly reduces risk of accidental short circuits during mounting
- Improved ground and power routing on the PCB
- PCBs now delivered as 6-up panels with bottom-layer SMD components **pre-soldered** (except the new measurement amplifier)

### Manufacturing / Assembly
- Boards now come from ALLPCB/JLCPCB as ready-to-reflow panels (huge time saver)
- Same overall dimensions, weight (~11 g), mounting holes (50 × 20 mm, Ø 3 mm), battery, and connectors as B1

### Safety & Reliability
- Reduced risk of accidental igniter firing
- Reduced risk of shorts via mounting holes
- Better PCB layout for cleaner power/ground planes

---

## [UWS B1]

**Initial public version** by bartekM (Polskie Towarzystwo Rakietowe), based on the original **UWS5** design by Jaskiniowiec.

### Core Features (shared with B2)
- Tilt detection via KMZ51 magnetic sensor
- User-adjustable trigger angle (potentiometer)
- Built-in igniter continuity check (green LED + buzzer)
- Integrated 1S 80 mAh Li-Po + microUSB charging (100 mA)
- 5-level battery voltage indicator (blue LED)
- PWR / ARM / RST jumpers
- Red PWR, green IGN, yellow CHRG, blue BAT/USB LEDs

### Known Limitations (addressed in B2)
- Older measurement amplifier (higher offset, worse low-voltage performance)
- Extra comparator in signal path (more complex, less reliable in some edge cases)
- Igniter switched on GND side → risk of accidental firing on short
- Mounting holes tied to GND → higher short risk
- No provision for extra microcontroller
- Smaller/crowded silkscreen labels

---

## Notes

- Both B1 and B2 are **fully functional** and have been successfully flown by members of the Polish Rocketry Society.
- All design files in this repository belong to **UWS.B2** (current recommended version).
- B1 design files are **not included** in this repo (historical reference only). If you need the old B1 Gerbers/schematics, check the original forum thread:  
  [UWS.B1 – t=3040](https://forum.rakiety.org.pl/viewtopic.php?t=3040)
- Full discussion and build photos are in the B2 thread:  
  [UWS.B2 – t=3159](https://forum.rakiety.org.pl/viewtopic.php?t=3159)

**Stay safe and fly high!** 🚀