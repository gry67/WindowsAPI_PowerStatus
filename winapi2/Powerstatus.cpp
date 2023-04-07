#include <iostream>
#include <Windows.h>
#include <powerbase.h>
#include <winnt.h>
#include "powerstatus.h"

using namespace std;


Gucbilgial::Gucbilgial() {
    GetSystemPowerStatus(&powerstatus);
    status = powerstatus.BatteryLifePercent; // pil yüzdesi
    life = powerstatus.BatteryLifeTime; // kalan ömür
    flag = powerstatus.BatteryFlag; //durum
}

void Gucbilgial::BilgiAl() {
    
	switch (powerstatus.ACLineStatus)
	{
	case 1:
		cout << "bilgisayar suan sarja takili pil seviyesi: ";
		if (status == 255) { cout << "pil seviyesi algýlanamadý" << endl; }
		else { cout <<status << endl; }
        break;
	case 0:
		cout << "bilgisayar suan sarja takili degil. pil seviyesi: ";
		if (status == 255) { cout << "pil seviyesi algýlanamadý" << endl; }
		else { cout << status << endl; }
        cout << (life != 0 ? to_string(life / 60) + " dakika tahmini kalan sure " : "") << endl;
        break;
	default:
		break;
	}
    
    switch (flag)
    {
    case 1:
        cout << "Pil durumu: Yüksek - pil kapasitesi yüzde 66'dan fazla."<<endl; break;
    
    case 2:
        cout << "Pil durumu: Düþük - Pil Kapasitesi yüzde 33'ten az" << endl; break;
    
    case 4:
        cout << "Pil durumu: ÇOK KRÝTÝK - Pil Kapasitesi yüzde 5'ten az. Lütfen cihazýnýzý þarja takýn." << endl; break;
    
    case 8:
        cout << "Pil durumu: sarj oluyor." << endl; break;
    
    case 128:
        cout << "Bu cihazda pil bulunamadý." << endl; break;
    
    case 255:
        cout << "Tanýmlanamayan Durum - BatteryFlag bilgi alamadý " << endl; break;

    case 0:
        cout << "Pil seviyesi ideal" << endl; break;
    default:
        cout << "Birsey oldu ancak ne oldu bende bilmiyorum. Flag:" << flag << endl;
        break;
    }
   
}
