#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include <cstdlib>
#include "RandomSentenceGenerator.h"
#include "Definition.h"


using namespace std;



int main()
{

	/*cout << "filename: ";
	cin >> filename;
	if(myFile.fail()){
        cout << "File Not Found";
        return -1;
    }

    filename.c_str()
*/
    ifstream myFile("Poem.txt");
    RandomSentenceGenerator* gen = new RandomSentenceGenerator();
    map<string, Definition> grammar;
cout<<"hi!~~~";
    gen->read(myFile, grammar);
cout<<"hi!";
    gen->generator(grammar);
    delete gen;
    return 0;
}
