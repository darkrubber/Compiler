/*
CS 3120 Homework-1
Eugene Leung
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string,int> cat= {{"keyword",0},{"real",0},{"integer",0},{"special",0},{"identifier",0}};
map<string,int> keyword;
map<string,int> real;
map<string,int> integer;
map<string,int> id;
map<string,int> special;
vector<string> key = {"if", " then", "else","begin"," end"};
string spec[9] ={"(",")","[ " ,"]" ,"+", "-", "=", ";",","};
vector<string> digit ={"0","1","2","3","4","5","6","7","8","9"};
vector<string> character ={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
vector<string>::iterator iter;
map<string, int>::iterator miter;
map<string, int>::iterator othermiter;

int isKeyword(string word){
    iter = find(key.begin(),key.end(),word);
    miter = keyword.find(word);
    if(iter != key.end()){
        cat["keyword"]++;
        if(miter != keyword.end())
            keyword[word]++;
        else keyword.insert(pair<string, int>(word,1));
        return 1;
    }
    return 0;
}
void isIdentifier(string word){
    string s, str ="";

    for(int i =0; i< word.length(); i++){

        s= word[i];
        iter = find(character.begin(),character.end(),s);
        if(iter != character.end()){
            str.append(s);
        }
    }

    miter = id.find(str);
    if(str.length() ==0)
        return;
    else if(miter != id.end()){
        cat["identifier"]++;
        id[str]++;
    }
    else {
        id.insert(pair<string, int>(str,1));
        cat["identifier"]++;
    }
}

void isInteger(char* word){
    char* pEnd;
    stringstream ss;

    miter = integer.find(word);
    ss<<strtol(word,&pEnd,10);
    string s =ss.str();

    if(pEnd!=word){
        cat["integer"]++;
        if(miter != integer.end())
            integer[s]++;
        else integer.insert(pair<string, int>(s,1));
    }
}

int isReal(string word){
    string ints, s="";

    if(word.find('.') != string::npos){
        for(int i =0; i<word.length(); i++){
            if(word[i] !='.'){
                s= word[i];
                iter=find(digit.begin(),digit.end(),s);
                if(iter != digit.end())
                    ints.append(s);
            } else if((word[i]=='.')&&(ints.length()!= 0))
                    ints.append(".");
        }
        miter = real.find(ints);

        if(ints.length()>=3){
            cat["real"]++;
        if(miter != real.end())
            real[ints]++;
        else real.insert(pair<string, int>(ints,1));
        return 1;
        }
    }
    return 0;
}

void isSpecial(string word){

    for(int i=0; i<9;i++){
        size_t found = word.find(spec[i]);
        miter = special.find(spec[i]);

         if (found!=string::npos){
            cat["special"]++;
            if(miter != special.end())
                special[spec[i]]++;
            else special.insert(pair<string, int>(spec[i],1));
         }
    }
}

void printTokens() {
    map<string,int> printObj;

    cout<<"\n"<< "===============Summary=================="<<endl;
    for(miter = cat.begin(); miter!= cat.end(); miter++)
        if(miter->second >=1){
            cout<<'\n'<<miter->second<<" "<< miter->first<< "(s) detected ;"<<endl;
            if(miter->first =="keyword")
                printObj =keyword;
            else if(miter->first =="real")
                printObj = real;
            else if(miter->first =="integer")
                printObj = integer;
            else if(miter->first =="identifier")
                printObj = id;
            else if(miter->first =="special")
                printObj = special;
            for(othermiter = printObj.begin(); othermiter!= printObj.end(); othermiter++)
                cout<< othermiter->first << " =>"<< othermiter->second<< '\n';
    }
}  // end printTokens

int main(int argc, char *argv[])
{

	// at least one command line argument should be supplied
	if (argc < 2) {
		cerr << "Error: file name argument not given" << endl;
		exit(1);
	}
	ifstream inFile( argv[1], ios::in);  // open file for input
	// checks for errors in opening the file
	if (!inFile) {
		cerr << "File " << argv[1] << " could not be opened" << endl;
		exit(1);
	}
	char line[80];      // char array used to hold lines of text input
	char* tokenPtr;     // pointer used to tokenize string

	while (inFile.getline(line, 80)) {   	// reads upto 80 chars into line array
		cout << "line = " << line << endl;

		tokenPtr = strtok( line, "  \n~!@#$%^& *_-{}:?<>|");   	// assigns tokenPtr to  first token in line
		while (tokenPtr != NULL) {
			cout << tokenPtr << endl;
            string str= string(tokenPtr);

            if(isReal(str) ==0)
                isInteger(tokenPtr);
			if(isKeyword(str) ==0)
                isIdentifier(str);
            isSpecial(str);

			tokenPtr = strtok( NULL, "     \n~!@#$%^&*_-{}:?<>|");	// gets next token from line
		} // while
	} // end whiled

	printTokens();
	inFile.close();

	return 0;
} // end main
