#ifndef RANDOMSENTENCEGENERATOR_H
#define RANDOMSENTENCEGENERATOR_H

#include <cstring>
#include <map>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Definition.h"
#include "Production.h"

using namespace std;


class RandomSentenceGenerator
{
    public:
        RandomSentenceGenerator();
        void generator(map<string,Definition>&);
        void read( ifstream&, map<string,Definition>&);
        void expand(Production&, map<string,Definition>&);
        void addProduction(ifstream&);
    private:
        vector<string> words;

};

#endif // RANDOMSENTENCEGENERATOR_H
