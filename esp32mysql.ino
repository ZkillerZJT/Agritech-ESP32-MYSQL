#include <credentials.h>
#define ESP32_MYSQL_DEBUG_PORT      Serial
int option=2; //esta opcion es la que define si se utilizará usuario admin o el usuario ESP32USER.
//En caso de if option==1, se usará el usuario "esp32user", mientras que if option==2, se usará usuario adminUser.
#define _ESP32_MYSQL_LOGLEVEL_      1

#include <ESP32_MySQL.h>
#include <WiFi.h>
#define USING_HOST_NAME             true

#if USING_HOST_NAME

    char server[] = "agritech-24-agritech2024.i.aivencloud.com";
#else
    IPAddress server();
    printf("no server hostname found. check credentials.h file or insert info directly into project");
#endif

uint16_t server_port= 10027;
const char* dbname = "defaultdb";
const char* default_table= "SENSORDATA";
const char* default_column= "Fecha";




String  CREATE_TABLE_SQL = String("CREATE TABLE " + String(dbname) + "." + String(default_table) + " (IDArduino INT NOT NULL, HumiditySensor FLOAT, LightSensor FLOAT, Fecha DATE, Hora TIME,PRIMARY KEY (IDArduino, Fecha, Hora)");
// TODO COMPLETAR LA QUERY DE INSERT SENSORDATA, SE ENCUENTRA INCOMPLETA
// String INSERT_SQL=("INSERT INTO" + dbname + "." +  default_table + ");


ESP32_MySQL_Connection conn((Client *)&client);

ESP32_MySQL_Query *query_mem;






void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial && millis() < 5000); //espera a que conecte el puerto serial
  
  ESP32_MYSQL_DISPLAY1("\NStarting Basic_Insert_ESP on", ARDUINO_BOARD);

    // Begin WiFi section
  ESP32_MYSQL_DISPLAY1("Connecting to", ssidyo);
  
  WiFi.begin(ssidyo, passyo);
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    ESP32_MYSQL_DISPLAY0(".");
  }

  // print out info about the connection:
  ESP32_MYSQL_DISPLAY1("Connected to network. My IP address is:", WiFi.localIP());
  if (option==1){
    ESP32_MYSQL_DISPLAY3("Connecting to SQL Server @", server, ", Port =", server_port);
    ESP32_MYSQL_DISPLAY5("User =", espUser, ", PW =", espPass, ", DB =", dbname);
  }
  if (option==2){
    ESP32_MYSQL_DISPLAY3("Connecting to SQL Server @", server, ", Port =", server_port);
    ESP32_MYSQL_DISPLAY5("User =", adminUser, ", PW =", adminPass, ", DB =", dbname);
  }



}

void runInsert()  //EN REVISION
{
  // Initiate the query class instance
  ESP32_MySQL_Query query_mem = ESP32_MySQL_Query(&conn);

  if (conn.connected())
  {
    ESP32_MYSQL_DISPLAY(CREATE_TABLE_SQL);// ESTA QUERY ESTÁ PENDIENTE   "INSERT_SQL"
    
    // Execute the query
    if ( !query_mem.execute(CREATE_TABLE_SQL.c_str()) )
    {
      ESP32_MYSQL_DISPLAY("Insert error");
    }
    else
    {
      ESP32_MYSQL_DISPLAY("Data Inserted.");
    }
  }
  else
  {
    ESP32_MYSQL_DISPLAY("Disconnected from Server. Can't insert.");
  }
}




void loop() {
  // put your main code here, to run repeatedly:
    ESP32_MYSQL_DISPLAY("Connecting...");
  
  //if (conn.connect(server, server_port, user, password)) server es el hostname de mi base de datos, ya especificado.
  if (option=1){
    if (conn.connectNonBlocking(server, server_port, espUser, espPass) != RESULT_FAIL)
    {
      delay(500);
      runInsert();
      conn.close();                     // close the connection
    } 
    else 
    {
      ESP32_MYSQL_DISPLAY("\nConnect failed. Trying again on next iteration.");
    }
  }
  if (option=2){
    if (conn.connectNonBlocking(server, server_port, adminUser, adminPass) != RESULT_FAIL)
    {
      delay(500);
      runInsert();
      conn.close();                     // close the connection
    } 
    else 
    {
      ESP32_MYSQL_DISPLAY("\nConnect failed. Trying again on next iteration.");
    }
  }
  ESP32_MYSQL_DISPLAY("\nSleeping...");
  ESP32_MYSQL_DISPLAY("================================================");
 
  delay(10000); // every 10 seconds
}
