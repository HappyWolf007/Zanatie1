#include "pch.h"
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
BOOL WINAPI DllMain(HINSTANCE hDll, DWORD  dwReason, LPVOID lpReserved) {
    switch (dwReason) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) void ProcessFile(string fileName) {
    ifstream inputFile(fileName);
    ofstream outputFile("output.txt");
    string line;
    int replacements = 0; 

    while (!inputFile.eof() && inputFile.good()) {
        getline(inputFile, line);

       
        for (char& ch : line) {
            if (ch < 48) {
                ch = ' ';
                replacements++;
            }
        }

        outputFile << line << std::endl;
        
    }
    

    std::cout << "File processed successfully. Check \"output.txt\" for result." << std::endl;
    std::cout << "Count replacements: " << replacements << std::endl;
}
