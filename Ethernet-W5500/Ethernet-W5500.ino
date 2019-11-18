/*
 * Source: https://br.renatocandido.org/2013/09/acendendo-um-led-via-internet-com-arduino-e-o-ethernet-shield/
 * 
 */

#include <SPI.h>
#include <Ethernet2.h>
  
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// Change address IP;
byte ip[] = { 192, 168, 1, 50 };
     
EthernetServer server(80);
  
String readString;
int Pin = 7;
  bool test = false;
  
void setup(){
  
  pinMode(Pin, OUTPUT);
  Ethernet.begin(mac, ip);
  server.begin();

}
  
void loop(){
  
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
  
        if (readString.length() < 100) {
          readString += c;             
        }
 
        if (c == '\n') {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
           
          client.println("<HTML>");
          client.println("<BODY>");
          client.println("<H1>Acende LED</H1>");
          client.println("<hr />");
          client.println("<br />");
           
          client.println("<a href=\"/?ledon\">Ligar o led</a>");
          client.println("<a href=\"/?ledoff\">Desligar o led</a><br />");   
           
          client.println("</BODY>");
          client.println("</HTML>");
           
          delay(1);
          client.stop();
           
          if(readString.indexOf("?ledon") > 0)
          {
            digitalWrite(Pin, HIGH);
          }
          else {
            if(readString.indexOf("?ledoff") > 0)
            {
              digitalWrite(Pin, LOW);
            }
          }
          readString="";    
        }
      }
    }
  }
}
