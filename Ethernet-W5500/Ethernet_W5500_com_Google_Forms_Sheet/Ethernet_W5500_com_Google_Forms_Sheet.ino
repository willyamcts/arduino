/*
	* Instruções e fonte: https://www.instructables.com/id/Post-to-Google-Docs-with-Arduino/
	* Fonte modificado para atender o módulo Ethernet W5500, necessário lib Ethernet2
*/

#include <Ethernet2.h>


///////////////////////////////
///      EDIT THIS STUFF     //
///////////////////////////////

byte mac[] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF };  //Replace with your Ethernet shield MAC
byte ip[] = {192,168,1,50};     // Your Arduino device IP address

String devid = "v53C4CA92F877E49";  // THIS IS THE DEVICE ID FROM PUSHINGBOX

int del = 300;  // Amount of seconds delay between posting to google docs.

///////////////////////////////
//       DONE EDITING        //
///////////////////////////////

 

char postmsg[100];
int increment = 0;
char server[] = "api.pushingbox.com";
EthernetClient client;
 
 
void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  delay(1000);
  Serial.println("connecting...");
}


 
void loop(){
  
 // Post to Google Form.............................................
  if (client.connect(server, 80)) {
    Serial.println("connected");
    sprintf(postmsg,"GET /pushingbox?devid=%s&status=%d HTTP/1.1", devid.c_str(), increment);  // NOTE** In this line of code you can see where the temperature value is 
      // inserted into the wed address. It follows 'status=' Change that value to whatever you want to post.
      
    client.println(postmsg);
    client.println("Host: api.pushingbox.com");
    client.println("Connection: close");
    client.println();

    Serial.println(postmsg);
    Serial.println("Host: api.pushingbox.com");
    Serial.println("Connection: close");
    Serial.println();
 
     delay(1000);
     client.stop();
  }
  
  delay(1000);
  
  if (!client.connected()) {
    //Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    return;
  }

  increment += increment; 
}

