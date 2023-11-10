#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("wordDictionary.txt");
    
    if (fin) {
        string word, partOfSpeech, definition, search;
        
        cout << "\033[34mEnter search text: \033[0m";
        cin >> search;
        
        while (true) {
            getline(fin, word, '|');
            getline(fin, partOfSpeech, '|');
            getline(fin, definition, '|');
            fin.ignore(500, '\n');
            
            if (fin.eof()) {
                break;
            }
            
            if (search == word) {
                cout << "\033[34m------------ English Dictionaries ------------\033[0m" << endl;
                cout << "\033[34mWord: " << word << "\033[0m" << endl;
                cout << "Part of speech: \033[31m" << partOfSpeech << "\033[0m" << endl;
                cout << "Definition: \033[33m" << definition << "\033[0m" << endl;
            }
        }
        
        fin.close();
    } else {
        cout << "Error: Word not found in the dictionary." << endl;
    }

    return 0;
}