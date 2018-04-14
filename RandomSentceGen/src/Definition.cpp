#include "Definition.h"

Definition::Definition(){}

Definition::Definition(ifstream& infile){
    string str;

    getline(infile,str, '{');
    infile >> nonterminal;
    getline(infile, str);

  while(infile.peek() != '}') {
    Production expand(infile);
    expansions.push_back(expand);
    }
    getline(infile, str, '}');
}

Production& Definition::getProduction(){
	return expansions.at(rand()% expansions.size());
}

string& Definition::getNonterminal(){
    return nonterminal;
}
