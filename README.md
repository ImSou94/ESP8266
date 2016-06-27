# ESP8266 12E
Start porgramming the Wifi board in arduino ide

#Hardware required
ESP8266 12E development board

#Software required
Arduino IDE


#Installing drivers

1.Connect the ESP8266 12e to the computer using a USB cable
<br/>2.Go to Device manager
<br/>3.Find the port number of the connected device
<br/>4.If couldn't find the port number,Look for "USB to UART" in other devices and update its driver


#Setting Up Arduino IDEfor ESP8266 12E

<br/>1.Install arduino IDE
<br/>2.Go to File>Preferences
<br/>3.The add this link in additional board urls "http://arduino.esp8266.com/stable/package_esp8266com_index.json"
<br/>4.Then go to tools>Board Manager
<br/>5.Search for esp8266 and install the driver
<br/>6. Go to device manager of your computer
<br/>7.Under ports, check for USB to UART controller ,note its port number
<br/>8.Go to Tools>Board>NodeMCU 1.0(ESP 12e module)
<br/>9.Tools>Port and select the port which we had determined in step 7
<br/>10.Tools>Uploadspeed>115200

<br/>HOLA, we are ready to upload our first program

<br/> Select one of the program in the code section and try for yourself

