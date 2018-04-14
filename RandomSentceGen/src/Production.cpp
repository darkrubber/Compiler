#include "Production.h"

Production::Production(){}

Production::Production(ifstream& myfile)
{
    string str;
	while (myfile >> str) {
		if (str == ";")
			break;
		phrases.push_back(str);
	}
}
