// Relay control using the ESP8266 WiFi chip

// Import required libraries
#include <ESP8266WiFi.h>
#include <aREST.h>
#include <aREST_UI.h>

// Create aREST instance
aREST_UI rest = aREST_UI();

// WiFi parameters
const char* ssid = "MBLAZE-DF800i-B918";//Write the wifi name which is used as a transmiter
const char* password = "88558855";//oasswird of thst wifi

// The port to listen for incoming TCP connections 
#define LISTEN_PORT           80
// Create an instance of the 
WiFiServer server(LISTEN_PORT);
void setup(void)
{  
  // Start Serial
  Serial.begin(115200);
  
  // Create UI
  rest.title("Relay Control");
  rest.button(15);
    
  // Give name and ID to device
  rest.set_id("1");
  rest.set_name("esp8266");
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
  
  // Print the IP address
  Serial.println(WiFi.localIP());
  
}

void loop() {
  
  // Handle REST calls
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while(!client.available()){
    delay(1);
  }
  rest.handle(client);
 
}
