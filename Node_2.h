#pragma once
#include <iostream>
#include <vector>
class ARY_TREE;
using namespace std;
class Node_2
{
    //static int keeper;
    char data;
    string meaning;
    string synonym;
    string antonym;
    vector<Node_2*> child;
    Node_2();
    void createchildren();
    Node_2* value(int index);
    friend class ARY_TREE;
};

