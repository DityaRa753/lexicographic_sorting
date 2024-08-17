#ifndef DYNARR_H_
#define DYNARR_H_

class DynArr {
  char *vec;
  unsigned int size;
  unsigned int current;
public:
  DynArr();
  ~DynArr();
  void Push(char);
  const char* Access() const;
  void Clean();
};

#endif
