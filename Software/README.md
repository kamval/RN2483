### LoRaWAN Library Plug-In for RN2483A

The LoRaWAN® Library Plug-in for the MPLAB® Code Configurator allows for quick and easy C code generation of Microchip’s LoRaWAN stack solution for LoRa® Technology end devices.

LoRaWAN stack currently supports only 8-bit PIC® devices. The minimum requirements for the PIC device to be capable of running LoRaWAN stack are the following:
- 32 kB of Flash memory
- 3 kB of RAM memory
- 1 x SPI
- 6 x GPIOs (three of the GPIOs must be interrupt-capable). If the PIC device has Peripheral Pin Select support, then an additional GPIO is required for the Chip Select of the SPI communication.
This library plug-in uses a Graphical User Interface (GUI) to accomplish the following:
- Select the requirements for the LoRaWAN stack from the device resources (modules present on the device)
- Define the communication channels for the EU 433/868 MHz ISM band
- Enable/Disable communication channels for the NA 915 MHz ISM band
- Adjust various parameters of the LoRaWAN stack in regards to the communication with the server
- Generate the necessary C code to program a PIC® microcontroller

API descriptions are provided [LoRaWAN Library Plug-In for MPLAB Code Configurator User Guide](https://github.com/kamval/RN2483/blob/master/Documents/40001864B.pdf)

### Software examples

Several examples are provided inorder to start fast from very simple one to more complex. Compiled demos can be downloaded by clicking the ZIP button in the top navbar. The demos are developed using MPLAX X v5.25, MCC v3.85.1 , XC8 v1.45. The code is simple and linear. 
