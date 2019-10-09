### RN2483_LoRAWAN_v1.20

Added BME280 sensor support. Generated a build in exmaple for [Weather click](https://www.mikroe.com/weather-click) manufactured by [MikroElektronika](https://www.mikroe.com/) and supported by MCC. 

<p align="center">
  <img width="1000" height="489" src="https://github.com/kamval/RN2483/blob/master/Documents/RN2483_LoRAWAN_v1.20.X.png">
</p>

Tips and tricks: Disable BME280 I2C interrupt. 

<p align="center">
  <img width="500" height="451" src="https://github.com/kamval/RN2483/blob/master/Documents/RN2483_LoRAWAN_v1.20.X.Tips.png">
</p>

Added a very simple code, to support the listed peripherals above and manage the payload data format. 
The data is send to [The Things Network](https://www.thethingsnetwork.org/) every ~5 min::

 <p align="center">
  <img width="1000" height="404" src="https://github.com/kamval/RN2483/blob/master/Documents/TTN_RN2483_LoRAWAN_v1.20.X.png">
</p>

A TTN Decoder is used parse the data received by the node:

```
function Decoder (bytes) {
  var temperature = (bytes[0] << 8) | bytes [1];
  var pressure = (bytes[2] << 8) | bytes [3];
  var humidity = (bytes[4] << 8) | bytes [5];
  var voltage = (bytes[6] << 8) | bytes [7];

  return {

    celcius: temperature / 100.0,
    pressure: pressure,
    humidity: humidity / 100.0,
    voltage: voltage / 1000

  };
}
```