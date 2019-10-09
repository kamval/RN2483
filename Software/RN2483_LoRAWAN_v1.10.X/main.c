/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18LF46K22
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

// Choose Activation Method ABP == 1; OTAA == 0; 
uint8_t activationMethod = 0;

// OTAA Activation Method Keys
uint8_t deviceEUI[8]        = { 0x00, 0x09, 0x50, 0xDF, 0x9B, 0xE2, 0x73, 0x3B };
uint8_t applicationEUI[8]   = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x00, 0xB6, 0x92 };
uint8_t applicationKey[16]  = { 0x60, 0x86, 0x59, 0xFB, 0xFD, 0xB0, 0xD7, 0x3E, 0x0C, 0x71, 0x85, 0x31, 0x70, 0x8E, 0x7A, 0x8D };

// ABP Activation Method Keys
uint8_t nwkSKey[16] 		= { 0x1A, 0xBB, 0x89, 0xEB, 0x2A, 0xB0, 0x24, 0xE4, 0x1D, 0xCD, 0x53, 0x2D, 0x74, 0x01, 0x37, 0xE2 };
uint8_t appSKey[16] 		= { 0x77, 0xD1, 0x17, 0x66, 0xE8, 0xBD, 0xE5, 0xD4, 0xE0, 0xA7, 0xE8, 0x71, 0xB5, 0x6E, 0x57, 0x9C };
uint32_t deviceAddr 		= 0x2601198B;

// Data to be send
uint8_t data[8]          	= { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// Time counter 
uint8_t counter = 0; 

// ADC variables 
uint32_t adcResult = 0; 
uint32_t adcVoltage = 0;

// Function prototypes 
void RxData(uint8_t* pData, uint8_t dataLength, OpStatus_t status) { }
void RxJoinResponse(bool status) { }

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    printf("\rSYSINIT!");         
    
    //LORAWAN_Reset(ISM_EU868);
    LORAWAN_Init(RxData, RxJoinResponse);
    
    if(activationMethod == 0){
        // Activation Method OTAA
        LORAWAN_SetApplicationEui(applicationEUI);
        LORAWAN_SetDeviceEui(deviceEUI);
        LORAWAN_SetApplicationKey(applicationKey);    
        // Issue Join
        LORAWAN_Join(OTAA);
        printf("\rOTAA Joined!");
    }
    else{    
        // Activation Method ABP
        LORAWAN_SetNetworkSessionKey(nwkSKey);
        LORAWAN_SetApplicationSessionKey(appSKey);
        LORAWAN_SetDeviceAddress(deviceAddr);
        // Issue Join
        LORAWAN_Join(ABP);
        printf("\rABP Joined!");
    } 
           
    while (1)
    { 
        // Add your application code
        LORAWAN_Mainloop();
        
        // All other function calls of the user-defined
        // application must be made here
        
        if (TMR5_HasOverflowOccured())  							//Has T5 Overflowed?
        {
            counter ++;
            
            adcResult = ADC_GetConversion(channel_AN0);           	// Read ADC Result when conversion is done
            adcVoltage = 3.25513*adcResult;
            
            TMR5IF = 0;                 							//Clear the T5 overflow flag
        }
        
        if (counter == 1)
        {   

            data[6] = (uint16_t) adcVoltage >> 8;
            data[7] = (uint16_t) adcVoltage & 0xFF;
            
            LORAWAN_Send(UNCNF, 2, data, 8);
            
            counter = 0;
        }    
    }
}
/**
 End of File
*/