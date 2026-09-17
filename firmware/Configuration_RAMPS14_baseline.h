/**
 * P04: Custom 3D Printer
 * [RECONSTRUCTED] Baseline Marlin Configuration
 *
 * Note: Original machine-specific parameters (e.g., precise steps/mm, PID values, bed offsets)
 * were lost. This configuration is a reconstructed baseline representing the standard RAMPS 1.4
 * Cartesian architecture documented in the historical project report.
 */

#pragma once

// ==========================================================================
// 1. Board & Architecture
// ==========================================================================
#define MOTHERBOARD BOARD_RAMPS_14_EFB  // RAMPS 1.4 (Extruder, Fan, Bed)
#define EXTRUDERS 1

// ==========================================================================
// 2. Thermal Settings
// ==========================================================================
#define TEMP_SENSOR_0 1    // 100k thermistor (EPCOS 100k)
#define TEMP_SENSOR_BED 1  // 100k thermistor
#define HEATER_0_MAXTEMP 260
#define BED_MAXTEMP 110

// Thermal Runaway Protection (CRITICAL SAFETY FEATURE)
#define THERMAL_RUNAWAY_PROTECTION_PERIOD 40
#define THERMAL_RUNAWAY_PROTECTION_HYSTERESIS 4
#define THERMAL_RUNAWAY_PROTECTION_BED_PERIOD 60
#define THERMAL_RUNAWAY_PROTECTION_BED_HYSTERESIS 2

// ==========================================================================
// 3. Kinematics & Endstops
// ==========================================================================
// Mechanical Endstops (Normally Closed recommended for safety)
#define X_MIN_ENDSTOP_INVERTING false
#define Y_MIN_ENDSTOP_INVERTING false
#define Z_MIN_ENDSTOP_INVERTING false

// Cartesian Steps per mm (Baseline approximations based on generic builds)
// X/Y: GT2 Belt (2mm pitch, 20 tooth pulley) with 1/16th microstepping -> 80 steps/mm
// Z: T8 Lead Screw (8mm lead) with 1/16th microstepping -> 400 steps/mm
// E: Standard MK8 Extruder -> 93 steps/mm
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 93 }
#define DEFAULT_MAX_FEEDRATE          { 300, 300, 5, 25 }
#define DEFAULT_MAX_ACCELERATION      { 3000, 3000, 100, 10000 }

// ==========================================================================
// 4. LCD & User Interface
// ==========================================================================
#define LCD_LANGUAGE en
#define REPRAP_DISCOUNT_SMART_CONTROLLER // Standard 20x4 LCD
