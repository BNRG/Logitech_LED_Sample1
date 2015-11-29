// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Include\LogitechLEDLib.h" //http://gaming.logitech.com/developers "LED ILLUMINATION SDK"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Initializing..." << endl;
	bool SDK_initOK, SDK_verOK;
	int majVer, minVer, BuildNum;
	SDK_initOK = LogiLedInit();

	if (SDK_initOK) {
		cout << "Everything is ok!" << endl;
		SDK_verOK = LogiLedGetSdkVersion(&majVer,&minVer,&BuildNum);
		if (SDK_verOK) {
			cout << "Logitech Gaming Software Version: " << majVer << "." << minVer << "." << BuildNum << endl;
		}
		else
		{
			cout << "ERROR: Unable to retrieve version" << endl;
		}
	}
	else {
		cout << "ERROR: Nothing was detected" << endl;
	}
	string color;
	while (SDK_initOK && SDK_verOK) {
		cout << "enter a color" << endl;
		cin >> color;
		

		if (color == "red") {
			cout << "you picked red" << endl;
			LogiLedSetLighting(100,0,0);
		}
		else if (color == "green"){
			cout << "you picked green" << endl;
			LogiLedSetLighting(0,100,0);
		}
		else if (color == "blue") {
			cout << "you picked blue" << endl;
			LogiLedSetLighting(0,0,100);
		}
		else if (color == "yellow") {
			cout << "you picked yellow" << endl;
			LogiLedSetLighting(100,100,0);
		}
		else if (color == "white") {
			cout << "you picked white" << endl;
			LogiLedSetLighting(100,100,100);
		}
		else if (color == "black") {
			cout << "you picked black" << endl;
			LogiLedSetLighting(0,0,0);
		}
		else if (color == "exit") {
			LogiLedShutdown();
			return 0;
		}
		else {
			cout << "invalid color" << endl;
		}
	}		
	LogiLedShutdown();
	return 0;
}

