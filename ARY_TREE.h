#pragma once
#include "Node_2.h"
#include <iostream>
#include <vector>
using namespace std;
class ARY_TREE
{
    Node_2* root;

public:
    ARY_TREE();
    void insertion(string a, string meaning);
    void N_InsertNode(Node_2* leaf, string a, int index, string meaning);
    void insertion(string a, string syno, string anto);
    void N_InsertNode(Node_2* leaf, string a, int index, string syno, string anto);
    void tra_wo_tracking(string a, System::Windows::Forms::TextBox^ box);
    void tra(string a, System::Windows::Forms::TextBox^ box);
    void print_meaning(string meaning, System::Windows::Forms::TextBox^ box);
    void break_string_into_vector(string a, vector<string>& b);
    void findsynonym(string a, System::Windows::Forms::TextBox^ box);
    void Traversal_Synonym(Node_2* leaf, string a, int index, System::Windows::Forms::TextBox^ box);
    void Traversal(Node_2* leaf, string a, int index, System::Windows::Forms::TextBox^ box);
    void Traversal_Wo_Track(Node_2* leaf, string a, int index, System::Windows::Forms::TextBox^ box);
};