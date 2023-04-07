#include <iostream>
#include <Windows.h>
#include <powerbase.h>
#include <winnt.h>
#include "powerstatus.h"

using namespace std;


Gucbilgial::Gucbilgial() {
    GetSystemPowerStatus(&powerstatus);
    status = powerstatus.BatteryLifePercent; // pil y�zdesi
    life = powerstatus.BatteryLifeTime; // kalan �m�r
    flag = powerstatus.BatteryFlag; //durum
}

void Gucbilgial::BilgiAl() {
    
	switch (powerstatus.ACLineStatus)
	{
	case 1:
		cout << "bilgisayar suan sarja takili pil seviyesi: ";
		if (status == 255) { cout << "pil seviyesi alg�lanamad�" << endl; }
		else { cout <<status << endl; }
        break;
	case 0:
		cout << "bilgisayar suan sarja takili degil. pil seviyesi: ";
		if (status == 255) { cout << "pil seviyesi alg�lanamad�" << endl; }
		else { cout << status << endl; }
        cout << (life != 0 ? to_string(life / 60) + " dakika tahmini kalan sure " : "") << endl;
        break;
	default:
		break;
	}
    
    switch (flag)
    {
    case 1:
        cout << "Pil durumu: Y�ksek - pil kapasitesi y�zde 66'dan fazla."<<endl; break;
    
    case 2:
        cout << "Pil durumu: D���k - Pil Kapasitesi y�zde 33'ten az" << endl; break;
    
    case 4:
        cout << "Pil durumu: �OK KR�T�K - Pil Kapasitesi y�zde 5'ten az. L�tfen cihaz�n�z� �arja tak�n." << endl; break;
    
    case 8:
        cout << "Pil durumu: sarj oluyor." << endl; break;
    
    case 128:
        cout << "Bu cihazda pil bulunamad�." << endl; break;
    
    case 255:
        cout << "Tan�mlanamayan Durum - BatteryFlag bilgi alamad� " << endl; break;

    case 0:
        cout << "Pil seviyesi ideal" << endl; break;
    default:
        cout << "Birsey oldu ancak ne oldu bende bilmiyorum. Flag:" << flag << endl;
        break;
    }
   
}
