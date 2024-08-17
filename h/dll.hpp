#ifndef DLL_H_
#define DLL_H_

class DLL {
  struct Node {
    Node *next;
    Node *prev;
    char *str;
    Node(const char*, Node *a_next = 0, Node *a_prev = 0);
    ~Node();
  };
private:
  Node *first, *last;
private:
  void DeleteNodes(Node*);
  void PrintFIFODo(Node*);
  void PrintLIFODo(Node*);
  void RemoveDo(Node*, const char*);
  void SortLexDo(Node*);
  unsigned PowerWord(const char*);
  void SwapNodesVal(Node*, Node*);
  unsigned PowerWordDo(const char*, unsigned int);
  int SortLexCmp(const char*, const char*);
  char *StrDupDo(const char*, unsigned int);
  bool StarMatch(const char*, const char*);
  bool FindPat(const char*, const char*);
  void ShiftString(char*, char ch);
  unsigned StrLenBeforeCharDo(const char*, char, unsigned int);
  unsigned StrLenBeforeChar(const char*, char);
  char* TruncateStringByChar(char*, char);
  void RemoveCharsDo(Node*, char);
  void SwapChar(char*, char*);
  void LoopNode(Node*, Node*);
public:
  DLL();
  ~DLL();
  void PushBack(const char*);
  void PrintLIFO();
  void PrintFIFO();
  void Remove(const char*);
  void RemoveLast();
  void RemoveChars(char);
  char *StrDup(const char*);
  void SortLexicographic();
#ifdef DEBUG
private:
	void print_list_do(Node*);
public:
	void print_list();
#endif
};

#endif
