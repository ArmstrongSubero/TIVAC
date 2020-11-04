/*
 * File:   main.c
 * Author: Armstrong Subero
 * Processor: TM4C123GXL, 3.3v
 * Program: Source file for application
 * Compiler: TI (v20.2.1LTS, Code Composer Studio Version: 10.1.1.00004)
 * Program Version 1.0
 * Program Description: This is the main file
 * Hardware Description: An LED is connected to pin PD0 via a 1k resistor
 *
 *
 * Modified From: TI Examples
 *
 * Change History:
 *
 * Author                Rev     Date          Description
 * Armstrong Subero      1.0     25/10/2020    Initial Release
 *
 * Updated on October 25, 2020, 05:52 PM
 */


//////////////////////////////////////////////////////////////////////////
// Include and defines
//////////////////////////////////////////////////////////////////////////
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"


/*!
* @brief The program entry point
* @param[in] void
* @param[in] void
* @return N/A
*/
int
main(void)
{
        volatile uint32_t ui32Loop;

        //
        // Enable the GPIO port that is used for the LED.
        //
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

        //
        // Check if the peripheral access is enabled.
        //
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD))
        {
        }

        //
        // Enable the GPIO pin for the LED (PD0).  Set the direction as output, and
        // enable the GPIO pin for digital function.
        //
        GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0);

        //
        // Loop forever.
        //
        while(1)
        {
            //
            // Turn on the LED.
            //
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, GPIO_PIN_0);

            //
            // Delay for a bit.
            //
            for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
            {
            }

            //
            // Turn off the LED.
            //
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0x0);

            //
            // Delay for a bit.
            //
            for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
            {
            }
        }
} /* main() */

/*** end of file ***/
