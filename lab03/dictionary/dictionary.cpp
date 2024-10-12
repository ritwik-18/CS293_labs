#include "dictionary.h"
#include <cmath>
#include <cstring>

Dictionary::Dictionary()
{
    A = new Entry[DICT_SIZE];
};

int Dictionary::hashValue(char key[])
{
    unsigned long int hashValue = 0;
    // compute hash
    int i = 0;
    int p = 31;
    while (key[i] != '\0')
    {
        hashValue += (int(key[i]) * pow(p,i));
        i = i + 1;
    }
    double gr = (sqrt(5) - 1) / 2;
    double frac = hashValue * gr;
    frac = frac - (long)frac;
    hashValue = (int)(DICT_SIZE * frac);
    return hashValue;
}

int Dictionary::findFreeIndex(char key[])
{
    int i = hashValue(key);
    int original_index = i;
    if (A[i].key == nullptr)
        return i;
    else
    {
        i = (i + 1) % DICT_SIZE;
        while (A[i].key != nullptr && i != original_index)
        {
            i = (i + 1) % DICT_SIZE;
        }
        if (i == original_index)
            return -1;
        else
            return i;
    }
}

struct Entry *Dictionary::get(char key[])
{
    int i = hashValue(key);
    int original_index = i;
    if (std::strcmp(A[i].key,key) == 0)
        return &A[i];
    else
    {
        i = (i + 1) % DICT_SIZE;
        while ( std::strcmp(A[i].key,key) != 0 && i != original_index)
        {
            i = (i + 1) % DICT_SIZE;
        }
        if (i == original_index)
            return NULL;
        else
            return &A[i];
    }
}

bool Dictionary::put(Entry e)
{
    if (findFreeIndex(e.key) == -1)
        return false;
    else
    {
        A[findFreeIndex(e.key)] = e;
        return true;
    }
}

bool Dictionary::remove(char key[])
{
 int i = hashValue(key);
    int original_index = i;
    if (std::strcmp(A[i].key,key) == 0)
        return true;
    else
    {
        i = (i + 1) % DICT_SIZE;
        while ( std::strcmp(A[i].key,key) != 0 && i != original_index)
        {
            i = (i + 1) % DICT_SIZE;
        }
        if (i == original_index)
            return false;
        else
            return true;   
    }
}
