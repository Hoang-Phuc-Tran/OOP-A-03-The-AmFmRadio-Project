/*
 * FILE:        AmFmRadio.h
 * Project:	    PROG 1385 - Assignment 3
 * Author:	    Hoang Phuc Tran
 * Student ID:  8789102
 * Date:		June 23, 2022
 * Description:  This file contains constants used in AmFmRadio class methods. It also contains
 a class declaration and a struct Freqs that holds 2 Frequencies (AM and FM bands).
 */ 

#ifndef _CARRADIO_H
#define _CARRADIO_H


#define MAX_FREQS 5       // maximum number of presets
#define MAX_CHAR 3        // Max length of char[]
#define MINIMUM_AM 530    // minimum frequency of AM band
#define MAX_AM 1700		  // maximum frequency of AM band   
#define MINIMUM_FM 87.9   // minimum frequency of FM band
#define MAX_FM 107.9      // maximum frequency of FM band



// This struct holds 2 frequencies: AM and FM bands
struct Freqs
{
	int AMFreq;
	float FMFreq;
	double currentStation;    // Holds a value of current_station before switch to AM or FM band
	int volumeStruct;         // Holds current NewVolume before turn off the radio
};


/* NAME: AmFmRadio
 * PURPOSE: The AmFmRadio class has been created to model the AM/FM Radio.
 *   It has an on/off power,sets volume, toggles AM/FM frequency,sets and selects. It also can 
     scan up and scan down the volume. Class has the ability to get/set the member values, 
	 as well as some methods for displaying settings.
 */
class AmFmRadio
{
private:
	Freqs	button[MAX_FREQS];
	double	current_station;
	char	frequency[MAX_CHAR];
	int		newVolume;
	bool	on;
	bool	displayOutPut;
public:
	
	// Constructors
	AmFmRadio(bool newOn = false);
	AmFmRadio(bool newOn, Freqs newButton[]);

	// Destructors
	~AmFmRadio();

	//sets on to true
	void PowerToggle();

	//returns a true if the radio is currently powered on, and false if the radio is in
	//the off position
	bool IsRadioOn();

	//toggles frequency between AM and FM and sets current station
	void ToggleFrequency();

	//sets button with current station by being passed a button number
	int SetButton(int button_num);

	//sets current station by being passed a button number
	int SelectCurrentStation(int button_num);

	//sets volume
	int SetVolume();

	// sets volume
	int SetVolume(int volume);

	//shows volume, button settings, current station, AM or FM
	void ShowCurrentSettings();

	//changes frequency up in increments of .2 for FM, 10 for AM
	void ScanUp();

	//changes frequency up in decrements of .2 for FM, 10 for AM
	void ScanDown();

	// Set value for the current_station data member
	int SetCurrentStation(double newCurrentStation);
	// Turn displayOutPut to False or True
	void ToggleDisplayOutPut();

	// Accessors
	double GetCurrentStation();     // get current_station data member
	int GetNewVolume();             // get newVolume data memeber
	char* GetFrequency();           // get "AM" / "PM" string
	Freqs* GetButton();             // get a number of presets
	bool GetDisplayOutPut();        // get displayOutPut data member

};
#endif