#include "Node_2.h"
#include<windows.h>

Node_2::Node_2()
{
    child.resize(26);
    synonym = "NULL";
    antonym = "NULL";
    meaning = "NULL";
    data = '0';
    for (int i = 0; i < 26; i++)
    {
        child.push_back(NULL);
    }

}
void Node_2::createchildren()
{
    for (int i = 0; i < 26; i++)
    {
        child.push_back(NULL);
    }
}
Node_2* Node_2::value(int index)
{
    return child[index];
}