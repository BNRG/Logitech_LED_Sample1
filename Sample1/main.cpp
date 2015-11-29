// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LogitechLEDLib.h" //http://gaming.logitech.com/developers "LED ILLUMINATION SDK"
#include <iostream>

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
		
	system("pause");
	LogiLedShutdown();
	return 0;
}

