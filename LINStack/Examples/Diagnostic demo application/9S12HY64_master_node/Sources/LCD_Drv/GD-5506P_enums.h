/********************************************************************** 
                
************************************************************************/

#ifndef GD_5506_enums_h
#define GD_5506_enums_h

// Type declarations for LCD data display types

// --- Temperature Display Group ---
enum  t_temp_type  {inside_temp,outside_temp,engine_temp} temp_type;  // Temperature type being displayed
enum  t_temp_scale {C,F} temp_scale;                                   // Temperature scale being displayed

// --- Compass Display Group ---

enum t_compass_direction {N,NE,E,SE,S,SW,W,NW } direction;  // Compass direction displayed


// --- Odometer Display Group ---

// --- Clock/Mileage Display Group ---

// --- Transmission Display Group ---

enum t_transmission_gear {Park,Reverse,Neutral,Drive,Third,Second,First} gear;  // Gear selection


// --- Cruise/TCS/TPMS Display Group ---
 


#endif