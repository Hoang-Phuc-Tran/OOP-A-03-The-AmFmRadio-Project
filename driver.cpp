/*
 * FILE:        driver.cpp
 * Project:	    PROG 1385 - Assignment 3
 * Author:	    Hoang Phuc Tran
 * Student ID:  8789102
 * Date:		June 23, 2022
 * Description:  This file contains user interface for the AmFmRadio and Displays menu that has 9 options:
 *  1. Toggle power 2. Set volume 3. Toggle band 4. Set button 5. Select button
 *  6. Show current settings  7. Scan up  8. Scan down  9. Quit.
 */

#include <stdio.h>
#include <stdlib.h>
#include "AmFmRadio.h"

#include <iostream>
using namespace std;

/* ---------------------------------------------------------------------
 * In case you haven't seen an "enum" declaration before, here are a 
 * couple of links to you to check out and read up about them ...
 * the concept of an "enum" is simple and is truly meant to clean up your
 * code and make it more readable ...
 *   1. https://www.codesdope.com/c-enum/
 *   2. https://en.cppreference.com/w/c/language/enum
 *   3. https://www.programiz.com/c-programming/c-enumeration
 * --------------------------------------------------------------------- */
enum menuItems
{
	kMenuNothing = 0,	// special constant for initialization only
	kMenuTogglePower = 1, kMenuSetVolume, kMenuToggleAMFM, kMenuSetButton, kMenuSelectButton,
	kMenuShowCurrentSettings, kMenuScanUp, kMenuScanDown ,kMenuQuit
};


int main()
{
	int			volume_OK = 0;
	int			button_OK = 0;
	int			button_num = 0;
	menuItems	choice = kMenuNothing;
	char		buf[20] = {0};
	AmFmRadio	jazzy(true);
	bool		on = false;
	
	cout << "a";
	do
	{
		printf("\n\nMAIN MENU\n");
		printf("=========\n\n");
		printf("1.  Toggle Power\n");
		printf("2.  Set Volume\n");
		printf("3.  Toggle AM / FM\n");
		printf("4.  Set a Button \n"); 
		printf("5.  Select a Button \n"); 
		printf("6.  Show Current Settings\n"); 
		printf("7.  Scan Up \n"); 
		printf("8.  Scan Down \n");
		printf("9.  Quit the Program\n");
		printf("\nMake a selection from the menu\n");
		// Get input from the user 
		fgets(buf, sizeof buf, stdin);
		// Convert the string to interger
		choice = (menuItems) atoi(buf);
		
		// Check the choice
		switch( choice )
		{
		// Option 1
		case kMenuTogglePower:
			// call the PowerToggle to turn on or turn off the radio
			jazzy.PowerToggle();
			break;
		// Option 2
		case kMenuSetVolume: 
			on = jazzy.IsRadioOn();
			// Check the radio is on to set volume
			if (on)
			{
				// Call the SetVolume method
				volume_OK = jazzy.SetVolume();
				// Check the return value of volum_OK
				if (volume_OK == 0)
				{
					printf("\nVolume was set to 0.");
				}
				else if (volume_OK == 2)
				{
					printf("\nVolume was set to 100.");
				}
			}
			else
			{
				printf("\nThe radio must be turned on before the "
					"volume can be set!");
			}
			break;
		// Option 3
		case kMenuToggleAMFM:
			on = jazzy.IsRadioOn();
			// Check the radio is on or off
			if( on )
			{
				jazzy.ToggleFrequency();
			    
			}
			else
			{
				printf("\nThe radio must be turned on before the "
					"band can be toggled!");
			}
			break;
		// Option 4
		case kMenuSetButton:
			on = jazzy.IsRadioOn();
			// Check the radio is on or off
			if( on )
			{
				printf("\nWhich button do you want to set?");
				// Get input from the user
			    fgets(buf, sizeof buf, stdin);
				// convert to interger and minus 1 to find the real index
			    button_num = atoi(buf) - 1;
				// Call SetButton method to set the button
			    button_OK = jazzy.SetButton(button_num);
				// Check the return vaalue of button_OK
			    if( button_OK == 0 )
				{
					printf("\nYou entered an invalid button number!");
				}
			}
			else
			{
				printf("\nYou must turn the radio on before you set the buttons!\n");
			}
			break;
		// Option 5
		case kMenuSelectButton:
			on = jazzy.IsRadioOn();
			// Check the radio is on or off
			if( on )
			{
				printf("\nEnter the number of the button: ");
				// Get input from the user
			    fgets(buf, 20, stdin);
				// convert to interger and minus 1 to find the real index
			    button_num = atoi(buf) - 1;
				// Call SelectCurrentStation method to select the button
			    button_OK = jazzy.SelectCurrentStation(button_num);
				if( button_OK == 0 )
				{
					printf("\nYou entered an invalid button number!");
				}
			}
			else
			{
				printf("\nYou must turn the radio on before you set the buttons!\n");
			}
			break;
		// Option 6
		case kMenuShowCurrentSettings:
			// Display all the data member of AmFmRadio class
			jazzy.ShowCurrentSettings();
			break;
		// Option 7
		case kMenuScanUp:
			on = jazzy.IsRadioOn();
			// Check the radio is on or off
			if( on )
			{
				// Call the ScanUp method 
				jazzy.ScanUp();
			}
			else
			{
				printf("\nYou must turn the radio on before you can use the scan button!\n");
			
			}
			break;
		// Option 8
		case kMenuScanDown:
			on = jazzy.IsRadioOn();
			// Check the radio is on or off
			if (on)
			{
				// Call the ScanUp method
				jazzy.ScanDown();
			}
			else
			{
				printf("\nYou must turn the radio on before you can use the scan button!\n");

			}
			break;
		// Option 9
		case kMenuQuit:
		    break;
		default:
			printf("You have entered an invalid selection. Please make \n"
				   "another selection.\n");
			break;

		}

		if( (choice != kMenuShowCurrentSettings) && (choice != kMenuQuit) )
			jazzy.ShowCurrentSettings();

	}while( choice != kMenuQuit );

	printf("\nGoodbye!\n");
	return 0;


}