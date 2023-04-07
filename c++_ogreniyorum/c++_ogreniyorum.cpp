#include <iostream>
#include <Windows.h>

int main() {
    SYSTEM_POWER_STATE powerState = {};
    if (GetSystemPowerState(&powerState)) {
        std::cout << "Sistem güç durumu: " << powerState << std::endl;
    }
    else {
        std::cout << "Güç durumu alýnamadý. Hata kodu: " << GetLastError() << std::endl;
    }
    return 0;
}
