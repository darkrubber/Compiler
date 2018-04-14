#ifndef PRODUCTION_H
#define PRODUCTION_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Production
{
    public:
        Production();
        Production(ifstream&);
        Production(const vector<string>& words) : phrases(words) {
	}
      vector<string>::iterator begin() {
		return phrases.begin();
	}

	vector<string>::const_iterator begin() const {
		return phrases.begin();
	}

	vector<string>::iterator end() {
		return phrases.end();
	}

	vector<string>::const_iterator end() const {
		return phrases.end();
	}

private:
	vector<string> phrases;
};

#endif // PRODUCTION_H
