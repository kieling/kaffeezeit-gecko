# kaffeezeit-gecko

This is a Coffee machine automation project using the EFM32 Giant Gecko Starter Kit from Silicon labs. 
For the project were used: 
- ESP8266 Wifi  
- RC522 RFID
- movement sensor

Functionality provided is a simple web-server over Wifi to "order a coffee/start the coffee machine" using a webpage. A statistics page showing the history of orders is also implemented. In order to gather statistics when someone wants to get a coffee directly in the machine, the RFID functionality is provided, making it as easy as possible. A movement sensor was also added to avoid ordering a coffee when there is no cup present in front of the machine. 

docs/  - Docs related to the Gecko board <br />
examples/  - Example files for the ESP8266 and mbed library  <br />
src/  - Source files, including the project for the Simplicity Studio  <br />


