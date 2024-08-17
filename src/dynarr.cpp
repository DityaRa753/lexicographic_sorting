#include "dynarr.hpp"

DynArr::DynArr()
{
  size = 32;
  current = 0;
  vec = new char[size];
  if(!vec)
    return;
}

DynArr::~DynArr()
{
  delete [] vec;
}

void DynArr::Push(char ch)
{
  if(current >= size-1) {
    unsigned int nsize = size * 2;
    char *arr = new char[nsize];
    if(!arr)
      return;
    unsigned i;
    for(i = 0; i < current; i++)
      arr[i] = vec[i];
    delete vec;
    vec = arr;
    size = nsize;
  }
  vec[current] = ch;
  ++current;
  vec[current] = '\0';
}

const char* DynArr::Access() const
{
  return vec;
}

void DynArr::Clean()
{
  unsigned int i;
  for(i = 0; i < size; i++)
    vec[i] = 0;
  current = 0;
}
