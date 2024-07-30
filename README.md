<h1 align="center" id="title">LPG Gas Leakage Detection System</h1>

<p id="description">This innovative project aims to develop a comprehensive gas leakage detection system by harnessing the capabilities of the ESP8266 microcontroller for detecting gas. The LPG gas leakage detection system is built to solve the problem by successfully detecting any gas leaks and triggering the various alert mechanism as well as automatically shut off the regulator.</p>

<h2>Project Screenshots:</h2>
![IMG_0493](https://github.com/user-attachments/assets/a36a76b6-dbd0-4f6e-ad93-a622dead9eb8)
![IMG_0496](https://github.com/user-attachments/assets/36d73cba-4910-43a4-9427-b16af828794d)

  
  
<h2>🧐 Features</h2>

Here're some of the project's best features:

*   Alert mechanism that sends an email to the user when hazardous gas level is detected
*   Real-time gas level visualization feature by integrating cloud
*   Capable of detecting gas levels accurately with the utilization of MQ-2 gas sensor
*   Takes a series of safety actions when gas levels reach a hazardous point by integrating components like servo motor buzzer LED light and exhaust fan


  
<h2>MATLAB Code</h2>
```
% Creating the body for the warning/ alert
alertBody = 'GAS LEAKAGE DETECTED\nPlease attend to the situation before it
becomes hazardous'

% Creating the subject for the warning/ alert
alertSubject = 'WARNING!!!'

% API key for ThingSpeak alerts which is essential for authentication
alertApiKey = 'TAKEMfbs/F8Snn7maXk';

% Set the address for the HTTTP call
alertUrl="https://api.thingspeak.com/alerts/send";

% creating a JSON message with subject and body
jsonMessage = sprintf(['{"subject": "%s","body": "%s"}'], alertSubject,alertBody)

% weboptions creates an options object for HTTP request
% the API key and the type of content is specified
options = weboptions("HeaderFields",{'Thingspeak-Alerts-API-Key', alertApiKey;
'Content-Type','application/json'});

% webwrite sends an HTTP POST request ot the specified URL(alertUrl) with JSON
message and options
result = webwrite(alertUrl, jsonMessage, options);
```
  
<h2>💻 Built with</h2>


Technologies used in the project:

*   Arduino Programming
*   MATLAB
*   Thingspeak
*   Fritzing
*   Node MCU (Microcontroller)
*   Bread Board and Jumper Wires (Connectivity)
*   Gas Regulator (External component)
*   Servo Motor (Actuator/Output)
*   MQ2 Sensor (Sensor/Input)
*   LED light and Buzzer (Actuator/Output)
*   Resistor
*   DC Fan (External Component)
*   Relay (Switch)
*   9V Battery Pack (External Power)
