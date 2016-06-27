#include <ESP8266WiFi.h>

WiFiServer server(80); //Initialize the server on Port 80
const short int LED=2;
void setup() {

WiFi.mode(WIFI_AP); //Our ESP8266-12E is an AccessPoint 
WiFi.softAP("Hello_IoT", "check1234"); // Provide the (SSID, password); . 
server.begin(); // Start the HTTP Server
Serial.begin(115200);
IPAddress IP=WiFi.softAPIP();
Serial.print("Server IP is:");
Serial.println(IP);
pinMode(LED, OUTPUT);
digitalWrite(LED,LOW);

}



void loop(){
  WiFiClient client=server.available();
  if(!client)
  return;
  
  Serial.println("Connected");

  String request=client.readStringUntil('\r');
  Serial.println(request);

  if(request.indexOf("/OFF")!=-1)
  {  digitalWrite(LED, HIGH);}
  else if(request.indexOf("/ON")!=-1)
  {
    digitalWrite(LED,LOW);}
  
  


String s ="HTTP/1.1 200 OK\r\n";
s +="Content-Type: text/html\r\n\r\n";
s +="<!DOCTYPE HTML>";
s+="<html lang ='en'>";
s+="<head>";
s+="<title> LED on/OFF </title>";
s +="<br><input type=\"button\" name=\"b1\" value=\"Turn LED ON\" onclick=\"location.href='/ON'\">";
s +="<br><br>";
s +="<input type=\"button\" name=\"b1\" value=\"Turn LED OFF\" onclick=\"location.href='/OFF'\">";
s += "</html>\n";

client.flush(); //clear previous info in the stream 
client.print(s); // Send the response to the client 
delay(1); 
Serial.println("Client disonnected"); //Looking under the hood
}
