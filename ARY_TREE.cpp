#include "ARY_TREE.h"
#include<windows.h>
#include <msclr\marshal_cppstd.h>
using namespace System;
#define backtostring msclr::interop::marshal_as<std::string>
#define gotoString msclr::interop::marshal_as<String^>

ARY_TREE::ARY_TREE()
{
    root = new Node_2;
}
void ARY_TREE::insertion(string a, string meaning)
{
    N_InsertNode(root, a, 0, meaning);
}
void ARY_TREE::N_InsertNode(Node_2* leaf, string a, int index, string meaning)
{
    int chi_ind = int(toupper(a[index])) - int('A');
    if ((a.size() == index) || int(a[index]) < 'A' || (int(a[index]) > 'Z' && int(a[index]) < 'a') || int(a[index]) > 'z')
    {
        return;
    }
    else if (leaf->child[chi_ind] == NULL)
    {
        leaf->child[chi_ind] = new Node_2;
        leaf->child[chi_ind]->data = a[index];
        leaf = leaf->child[chi_ind];
        if (index + 1 == a.size() || (int(a[index + 1]) >= 0 && isdigit(a[index + 1])))
        {
            leaf->meaning = meaning;
        }
        N_InsertNode(leaf, a, index + 1, meaning);
    }
    else if (leaf->child[chi_ind] != NULL)
    {
        leaf = leaf->child[chi_ind];
        N_InsertNode(leaf, a, index + 1, meaning);
    }
}
void ARY_TREE::insertion(string a, string syno, string anto)
{
    N_InsertNode(root, a, 0, syno, anto);
}
void ARY_TREE::N_InsertNode(Node_2* leaf, string a, int index, string syno, string anto)
{
    int chi_ind = int(toupper(a[index])) - int('A');
    if ((a.size() == index) || int(a[index]) < 'A' || (int(a[index]) > 'Z' && int(a[index]) < 'a') || int(a[index]) > 'z')
    {
        return;
    }
    else if (leaf->child[chi_ind] == NULL || index + 1 == a.size())
    {
        if (leaf->child[chi_ind] == NULL)
        {
            leaf->child[chi_ind] = new Node_2;
            leaf->child[chi_ind]->data = a[index];
        }
        leaf = leaf->child[chi_ind];
        if (index + 1 == a.size() || (int(a[index + 1]) >= 0 && isdigit(a[index + 1])))
        {
            leaf->synonym = syno;
            leaf->antonym = anto;
        }
        N_InsertNode(leaf, a, index + 1, syno, anto);
    }
    else if (leaf->child[chi_ind] != NULL)
    {
        leaf = leaf->child[chi_ind];
        N_InsertNode(leaf, a, index + 1, syno, anto);
    }
}
void ARY_TREE::tra_wo_tracking(string a, System::Windows::Forms::TextBox^ box)
{
    Traversal_Wo_Track(root, a, 0,box);

}
void ARY_TREE::tra(string a, System::Windows::Forms::TextBox^ box)
{
    Traversal(root, a, 0,box);

}
void ARY_TREE::print_meaning(string meaning, System::Windows::Forms::TextBox^ box)
{
    string temp;
    char a = '1';
    for (int i = 0; i < meaning.size() - 1; i++)
    {
        if (meaning[i] == ' ' && meaning[i + 1] == a)
        {
            a++;
            temp += '\n';
            //cout << endl;
            box->AppendText(Environment::NewLine);
        }
        temp += meaning[i];
        //cout << meaning[i];
        box->AppendText(Char::ToString(meaning[i]));
    }
}
void ARY_TREE::break_string_into_vector(string a, vector<string>& b)
{
    string temp;
    for (int i = 0; i < a.size(); i++)
    {
        if ((a[i] == ' ') && temp.size() >= 1)
        {
            temp[0] = toupper(temp[0]);
            b.push_back(temp);
            temp = "";

        }
        else if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
        {
            temp += a[i];
        }
    }
}
void ARY_TREE::findsynonym(string a, System::Windows::Forms::TextBox^ box)
{
    Traversal_Synonym(root, a, 0,box);
}
void ARY_TREE::Traversal_Synonym(Node_2* leaf, string a, int index, System::Windows::Forms::TextBox^ box)
{
     int chi_ind = int(toupper(a[index])) - int('A');
     if (leaf->child[chi_ind] == NULL)
     {
         return;
     }
     else if (leaf->child[chi_ind]->data == a[index])
     {
         leaf = leaf->child[chi_ind];
         if (index + 1 == a.size())
         {

             if (leaf->synonym == "NULL")
             {
                 //cout << "NO SYNONYMS OR ANTONYMS FOUND!";
                 box->AppendText(gotoString("NO SYNONYMS OR ANTONYMS FOUND!"));
                 return;
             }
             else
             {
                 //cout << leaf->synonym;
                 //cout << leaf->antonym;
                 box->AppendText("Synonyms:");
                 box->AppendText(gotoString(leaf->synonym));
                 box->AppendText(Environment::NewLine);
                 box->AppendText("Antonyms:");
                 box->AppendText(gotoString(leaf->antonym));
                 return;
             }
         }

         return Traversal_Synonym(leaf, a, index + 1,box);
     }
}
void ARY_TREE::Traversal(Node_2* leaf, string a, int index, System::Windows::Forms::TextBox^ box)
{
    static string syn_bef = "NULL";
    static string ant_bef = "NULL";
    static string word_bef = "NULL";
    static string meaning_bef = "NULL";
    int chi_ind = int(toupper(a[index])) - int('A');
    if (leaf->child[chi_ind] == NULL)
    {

        if (meaning_bef != "NULL")
        {
        Cleanmax:
            //cout << word_bef;////////////////
            box->AppendText(gotoString(word_bef));

            print_meaning(meaning_bef,box);/////////////
            if (syn_bef != "NULL" && ant_bef != "NULL")
            {
                /*cout << endl;////////////
                cout << "SYNONYM:";
                cout << syn_bef;
                cout << endl;//////////////

                cout << "ANTONYM:";

                cout << ant_bef;////////////*/
                box->AppendText(Environment::NewLine);
                box->AppendText("Synonym:");
                box->AppendText(gotoString(syn_bef));
                box->AppendText(Environment::NewLine);
                box->AppendText("Antonym:");
                box->AppendText(gotoString(ant_bef));
                syn_bef = "NULL";
                ant_bef = "NULL";
            }
            meaning_bef = "NULL";
        }
        return;
    }
    else if (leaf->child[chi_ind]->data == a[index])
    {
        leaf = leaf->child[chi_ind];
        if (index + 1 == a.size())
        {
            if (leaf->meaning == "NULL")
            {
                goto Cleanmax;
            }
            //cout << a;
            box->AppendText(gotoString(a));

            print_meaning(leaf->meaning,box);
            syn_bef = "NULL";
            ant_bef = "NULL";
            if (leaf->synonym != "NULL" && leaf->antonym != "NULL")
            {

                /*cout << endl;

                cout << "SYNONYM:";

                cout << leaf->synonym;///////////
                cout << endl;
                cout << "ANTONYM:";
                cout << leaf->antonym;////////////*/
                box->AppendText(Environment::NewLine);
                box->AppendText("Synonym:");
                box->AppendText(gotoString(leaf->synonym));
                box->AppendText(Environment::NewLine);
                box->AppendText("Antonym:");
                box->AppendText(gotoString(leaf->antonym));
            }
            return;
        }
        else if (leaf->meaning != "NULL")
        {
            word_bef = a.substr(0, index + 1);
            meaning_bef = leaf->meaning;
            if (leaf->synonym != "NULL" && leaf->antonym != "NULL")
            {
                syn_bef = leaf->synonym;
                ant_bef = leaf->antonym;
            }
        }
        Traversal(leaf, a, index + 1,box);
    }
}
void ARY_TREE::Traversal_Wo_Track(Node_2* leaf, string a, int index, System::Windows::Forms::TextBox^ box)
{
    int chi_ind = int(toupper(a[index])) - int('A');
    if (leaf->child[chi_ind] == NULL)
    {
        return;
    }
    else if (leaf->child[chi_ind]->data == a[index])
    {
        leaf = leaf->child[chi_ind];
        if (index + 1 == a.size())
        {
            if (leaf->meaning == "NULL")
            {
                return;
            }
            //cout << a;
            box->AppendText(gotoString(a));
            print_meaning(leaf->meaning,box);////////////////////////////////
            if (leaf->synonym != "NULL" && leaf->antonym != "NULL")
            {

                /*cout << endl;
                cout << "SYNONYM:";

                cout << leaf->synonym;/////////////////////////////////////
                cout << endl;
                cout << "ANTONYM:";
                cout << leaf->antonym;/////////////////////////////////////*/
                box->AppendText(Environment::NewLine);
                box->AppendText("Sysnonym:");
                box->AppendText(gotoString(leaf->synonym));
                box->AppendText(Environment::NewLine);
                box->AppendText("Antonym:");
                box->AppendText(gotoString(leaf->antonym));
            }
            return;
        }
        return Traversal_Wo_Track(leaf, a, index + 1, box);
    }

}