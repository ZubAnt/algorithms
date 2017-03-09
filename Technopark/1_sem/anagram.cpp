#include "anagram.h"

Anagram::Anagram():list(new DuallyList())
{}

Anagram::~Anagram()
{
    delete list;
}

