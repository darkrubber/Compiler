#include "RandomSentenceGenerator.h"

RandomSentenceGenerator::RandomSentenceGenerator(){};

void RandomSentenceGenerator::generator(map<string,Definition>& gmap) {
	for (int i=0; i <3; i++) {
		Definition def = gmap.at("<start>");
		Production production = def.getProduction();
		expand(production, gmap);
		cout << endl;
	}
}

void RandomSentenceGenerator::read( ifstream& myfile, map<string,Definition>& gmap ) {
	string s;

	while (myfile >> s) {
        myfile.putback('{');

        Definition def(myfile);
        gmap[def.getNonterminal()] = def;
		}

}

void RandomSentenceGenerator::expand(Production& prod, map<string,Definition>& gmap) {

	for (auto it = prod.begin(); it< prod.end(); it++) {
		string s = *it;

		if (s.find("<") == string::npos)
			cout<< s<< endl;
			else {
			Definition def = gmap.at(s);
			Production production = def.getProduction();
			expand(production,gmap);
		}
	}
}

