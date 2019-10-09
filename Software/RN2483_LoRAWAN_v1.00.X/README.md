### RN2483_LoRAWAN_v1.00

Based on guidelines provided on [LoRaWAN Library Plug-In for MPLAB Code Configurator User Guide](https://github.com/kamval/RN2483/blob/master/Documents/40001864B.pdf) by Microchip. The Guide is adapted in order to work with 868 MHz band in Europe.

<p align="center">
  <img width="1000" height="489" src="https://github.com/kamval/RN2483/blob/master/Documents/RN2483_LoRAWAN_v1.00.X.png">
</p>

Tips and tricks: to compile the generated files successfuly comment the following line: INT0_SetInterruptHandler(DIO5_ISR_Lora)

```
void DIO5_ISR_Lora_Init(void)
{
    // Comment to compile with XC8 v1.45
    //INT0_SetInterruptHandler(DIO5_ISR_Lora);
}
```

Added a very simple code, based on software flag, in order to chose between OTAA and ABP activation method. 
The data is send to [The Things Network](https://www.thethingsnetwork.org/) every several seconds:

<p align="center">
  <img width="1000" height="399" src="https://github.com/kamval/RN2483/blob/master/Documents/TTN_RN2483_LoRAWAN_v1.00.X.png">
</p>
