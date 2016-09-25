
#include <iostream>
#include <fstream>
#ifdef WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#endif
#include "Utils.h"
using namespace std;


bool ReadFile(const char* pFileName, string& outFile)
{
	ifstream f(pFileName);

	bool ret = false;

	if (f.is_open()) {
		string line;
		while (getline(f, line)) {
			outFile.append(line);
			outFile.append("\n");
		}

		f.close();

		ret = true;
	}
	else {
		printf("Error opening file %s", pFileName);
	}

	return ret;
}
