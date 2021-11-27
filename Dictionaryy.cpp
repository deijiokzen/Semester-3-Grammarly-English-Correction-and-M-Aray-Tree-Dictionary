#include "Dictionaryy.h"
#include<windows.h>
using namespace System;
string Dictionaryy::transformtoproper(string word)
{
    word[0] = toupper(word[0]);
    for (int i = 1; i < word.size(); i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}
void Dictionaryy::SentenceMeaning_Without_Word_Tracking(string sentence, System::Windows::Forms::TextBox^ box)
{
    if (sentence.size() == 0)
        return;
    //sentence.erase(remove(sentence.begin(), sentence.end(), ','), sentence.end());
    //sentence.erase(remove(sentence.begin(), sentence.end(), '.'), sentence.end());
    if (sentence[sentence.size() - 1] != ' ')
    {
        sentence += ' ';
    }
    string word = "";
    for (auto x : sentence)
    {
        if (x == ' ' && word.size() != 0)
        {
            string temp;
            for (int j = 0; j < word.size(); j++)
                temp += toupper(word[j]);
            if (temp == "AND" || temp == "HERE" || temp == "WHY" || temp == "WHAT" || temp == "WHEN" || temp == "HIM" || temp == "HER" || temp == "ARE" || temp == "YOU" || temp == "IN" || temp == "OR" || temp == "A" || temp == "AN" || temp == "THE" || temp == "IF" || temp == "WE" || temp == "THEM" || temp == "AT" || temp == "THAT" || temp == "HE" || temp == "SHE" || temp == "IT")
            {
                word = "";
                continue;
            }
            search_word_wo_tracking(transformtoproper(word),box);
            //cout << endl;
            box->AppendText(Environment::NewLine);
            word = "";
        }
        else if ((x >= 'A' && x <= 'Z') || (x >= 'A' && x <= 'z') && (!(x >= '1' && x <= '9')))
        {
            word = word + x;
        }

    }

}
void Dictionaryy::SentenceMeaning(string sentence, System::Windows::Forms::TextBox^ box)
{
    if (sentence.size() == 0)
        return;
    //sentence.erase(remove(sentence.begin(), sentence.end(), ','), sentence.end());
    //sentence.erase(remove(sentence.begin(), sentence.end(), '.'), sentence.end());
    if (sentence[sentence.size() - 1] != ' ')
    {
        sentence += ' ';
    }
    string word = "";
    for (auto x : sentence)
    {
        if (x == ' ' && word.size() != 0)
        {
            string temp;
            for (int j = 0; j < word.size(); j++)
                temp += toupper(word[j]);
            if (temp == "AND" || temp == "HERE" || temp == "WHY" || temp == "WHAT" || temp == "WHEN" || temp == "HIM" || temp == "HER" || temp == "ARE" || temp == "YOU" || temp == "IN" || temp == "OR" || temp == "A" || temp == "AN" || temp == "THE" || temp == "IF" || temp == "WE" || temp == "THEM" || temp == "AT" || temp == "THAT" || temp == "HE" || temp == "SHE" || temp == "IT")
            {
                word = "";
                continue;
            }
            search_word(transformtoproper(word),box);
            //cout << endl;
            box->AppendText(Environment::NewLine);
            box->AppendText(Environment::NewLine);
            word = "";
        }
        else if ((x >= 'A' && x <= 'Z') || (x >= 'A' && x <= 'z') && (!(x >= '1' && x <= '9')))
        {
            word = word + x;
        }

    }

}
void Dictionaryy::WriteSynAnt()
{
    fout.close();
    fin.close();
    string line2;
    char letter = 'A';
    while (letter != 'Z' + 1)
    {
        string a(1, letter);
        //filename = "DictionaryLetters/AA.txt";
        filename = "SynAnt/" + a + ".txt";
        fin.open(filename);

    synonn:
        while (getline(fin, line, '\n'))
        {
            string temp = line;
            if (line.find("ANT.") != string::npos)
                goto synonn;
            getline(fin, line2, '\n');

            if (line2.find("ANT.") != string::npos)
            {
                string word = line.substr(0, line.find(" ") - 1);
                string synonym = line.substr(line.find(" ") + 1, line.size() - 1);
                string antonym = line2.substr(line2.find(" ") + 1, line2.size() - 1);

                N1.insertion(word, synonym, antonym);

            }


            if (!fin.good())
                break;
        }
        letter++;
        fin.close();
    }
    cout << "SYNONYMS WRITTEN INTO TREE!" << endl;
    return;
}
void Dictionaryy::WriteIntoTree()
{
    fout.close();
    fin.close();
    char letter = 'A';
    while (letter != 'Z' + 1)
    {
        string a(1, letter);
        //filename = "DictionaryLetters/AA.txt";
        filename = "DictionaryLetters/" + a + ".txt";
        fin.open(filename);

        while (getline(fin, line, '\n'))
        {

            string word = line.substr(0, line.find(" "));
            word.erase(remove(word.begin(), word.end(), '-'), word.end());
            word.erase(remove(word.begin(), word.end(), ' '), word.end());

            string meaning = line.substr(line.find(" "), line.size() - 1);

            N1.insertion(word, meaning);
            if (!fin.good())
                break;

        }
        letter++;
        fin.close();
    }
    cout << "DICTIONARY WRITTEN INTO TREE!" << endl;
    return;
}
void Dictionaryy::search_word_wo_tracking(string a, System::Windows::Forms::TextBox^ box)
{
    N1.tra_wo_tracking(a,box);
}
void Dictionaryy::search_word(string a, System::Windows::Forms::TextBox^ box)
{
    int b = a.find("ing");
    if (b != string::npos)
    {
        a.resize(b + 1);
        a[b] = 'e';
    }
    N1.tra(a,box);
}
void Dictionaryy::find_syno(string a, System::Windows::Forms::TextBox^ box)
{
    a[0] = toupper(a[0]);
    for (int i = 1; i < a.size(); i++)
    {
        a[i] = tolower(a[i]);
    }
   N1.findsynonym(a,box);
}


