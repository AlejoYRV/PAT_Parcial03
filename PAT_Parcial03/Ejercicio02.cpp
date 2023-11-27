#include "Ejercicio02.h"
#include <map>

vector<string>* Ejercicio02::findRepeatedDnaSequences(Node<char>* head)
{
    std::map<string, int> dnaSequences;
    vector<string>* result = new vector<string>();
    string sequence = "";
    Node<char>* current = head;

    for (int i = 0; i < 10 && current != nullptr; ++i)
    {
        sequence += current->value;
        current = current->next;
    }
    if (sequence.length() < 10)
    {
        return result;
    }
    ++dnaSequences[sequence];

    while (current != nullptr)
    {
        sequence.erase(sequence.begin());
        sequence += current->value;
        ++dnaSequences[sequence];
        current = current->next;
    }

    for (auto it = dnaSequences.begin(); it != dnaSequences.end(); ++it)
    {
        if (it->second > 1)
        {
            result->push_back(it->first);
        }
    }

    return result;
}

