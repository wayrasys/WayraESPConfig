/*
 Name:		WayraTouch.h
 Created:	31/07/2017 19:24:46
 Author:	Wayra Sys - Gustavo
 Editor:	http://www.visualmicro.com
*/

#ifndef _WayraESPConfig_h
#define _WayraESPConfig_h

#include <Time.h>
#include <TimeLib.h>

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <WiFiUdp.h>


class WayraESPConfig {
public:
	WayraESPConfig(String wifiName, String wifiPass);

	void Init();

	//Setters
	void setAutoSave(bool autosave);
	void setAddress(int menoryposition);
	void setImput(int imput);
	void setOutPut(int output);
	void setDebug(bool show);
	void setState(bool state);
	void setGlobalState(bool *state);

	//Getters
	int getAddress();
	int getImput();
	int getOutPut();
	bool getState();

	//Main
	void Listen(void *handleListen(bool));

	//private
private:
	String _htmlBody;
	byte _luz;

	int _imput; //Entrada del sensor
	int _output; //Salida a controlar
	bool _autosave; //Si se graba automaticamente el cambio de estado
	int _memonyInit; //Posicion en la mamoria indicando la inicializacion del modulo
	int _menonyState; //Posicion en la memoria para guardar el stado del modulo
	bool _state; //Estado de la salida
	bool *p_state; //puntero al estado gral.
	bool _showDebugState; //Imprime en el Serial el estado de la salida
	bool _lastState; //bandera para controlar el estado
	void print(char* msg, bool newline);
};

#endif

