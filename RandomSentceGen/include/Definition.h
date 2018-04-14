#ifndef DEFINITION_H
#define DEFINITION_H
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "Production.h"

using namespace std;

class Definition
{
    public:
        Definition();
        Definition(ifstream& infile);
        string& getNonterminal();
        Production& getProduction();

    private:
        string nonterminal;
        vector<Production> expansions;
};

#endif // DEFINITION_H
