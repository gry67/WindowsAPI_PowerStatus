#include <iostream>
#include <Windows.h>

int main() {
    SYSTEM_POWER_STATE powerState = {};
    if (GetSystemPowerState(&powerState)) {
        std::cout << "Sistem g�� durumu: " << powerState << std::endl;
    }
    else {
        std::cout << "G�� durumu al�namad�. Hata kodu: " << GetLastError() << std::endl;
    }
    return 0;
}
