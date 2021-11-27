#pragma once
#include <iostream>
#include <fstream>
#include<string>
#include "ARY_TREE.h"
using namespace std;
class Dictionaryy
{
    string filename;
    char letter;
    fstream fin;
    string line;
    ofstream fout;
    ARY_TREE N1;
public:
    string transformtoproper(string word);
    void SentenceMeaning_Without_Word_Tracking(string sentence, System::Windows::Forms::TextBox^ box);
    void SentenceMeaning(string sentence, System::Windows::Forms::TextBox^ box);
    void WriteSynAnt();
    void WriteIntoTree();
    void search_word_wo_tracking(string a, System::Windows::Forms::TextBox^ box);
    void search_word(string a, System::Windows::Forms::TextBox^ box);
    void find_syno(string a , System::Windows::Forms::TextBox^ box);
};

