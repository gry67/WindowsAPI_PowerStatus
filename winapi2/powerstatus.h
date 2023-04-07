#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <powerbase.h>
#include <winnt.h>

class Gucbilgial {
	
public:
	int status, life, flag;
	SYSTEM_POWER_STATUS powerstatus = {};
	Gucbilgial();
	void BilgiAl();
};