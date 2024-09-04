
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    HMODULE hDll = LoadLibrary("Dll1.dll");
    if (!hDll)
    {
        cerr << "Failed to load library" << endl;
        return GetLastError();
    }

    void (*ProcessFile)(string) = (void (*)(string))GetProcAddress(hDll, "ProcessFile");
    if (!ProcessFile)
    {
        cerr << "Failed to get ProcessFile procedure address from DLL.";
        return GetLastError();
    }

    ProcessFile("input.txt");

    return 0;
}