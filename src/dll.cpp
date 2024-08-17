#include "dll.hpp"
#include <string.h>
#include <stdio.h>

DLL::DLL()
{
  first = 0;
  last = 0;
}

void DLL::DeleteNodes(Node *node)
{
  if(!node)
    return;
  DeleteNodes(node->next);
  delete node;
}

DLL::~DLL()
{
  DeleteNodes(first);
}

void DLL::PushBack(const char *a_str)
{
  if(last) {
    last->next = new Node(a_str, 0, last);
    if(!last->next)
      return;
    last = last->next;
  }
  else {
    first = new Node(a_str, 0, 0);
    last = first;
  }
}

DLL::Node::Node(const char *a_str, Node *a_next, Node *a_prev)
{
  next = a_next;
  prev = a_prev;
  size_t len = strlen(a_str);
  str = new char[len+1];
  if(!str)
    return;
  strcpy(str, a_str);
}

DLL::Node::~Node()
{
  delete [] str;
}

#ifdef DEBUG
void DLL::print_list_do(Node *n)
{
	if(!n)
		return;
	printf("prev: %p ; next: %p; data: %s\n", n->prev, n->next, n->str);
	print_list_do(n->next);
}

void DLL::print_list()
{
	print_list_do(first);
}

#endif

void DLL::RemoveDo(Node *n, const char *str)
{ // if last == n, mark as last
  if(!n)
    return;
  RemoveDo(n->next, str);
  if(0 == strcmp(n->str, str)) {
    if(n == first) {
      n->next->prev = NULL;
      first = n->next;
    }
    else if(n == last) {
      n->prev->next = NULL;
      last = n->prev;
    }
    else {
      n->prev->next = n->next;
      n->next->prev = n->prev;
    }
    delete n;
  }
}

void DLL::Remove(const char *str) // remove from list
{
  RemoveDo(first, str);
}

void DLL::PrintLIFODo(Node *node)
{
  if(!node)
    return;
	printf("%s ", node->str);
  PrintLIFODo(node->next);
}

void DLL::PrintLIFO()
{
  PrintLIFODo(first);
}

void DLL::PrintFIFODo(Node *node)
{
  if(!node)
    return;
  PrintFIFODo(node->next);
  printf("\"%s\" ", node->str);
}

void DLL::PrintFIFO()
{
  PrintFIFODo(first);
}

void DLL::RemoveLast()
{
  Node *l = last;
  last = l->prev;
  last->next = NULL;
  delete l;
}

unsigned DLL::PowerWordDo(const char *s, unsigned int power)
{
  if(!*s)
    return power;
  return PowerWordDo(s+1, power + *s);
}

unsigned DLL::PowerWord(const char *s) { return PowerWordDo(s, 0); }

bool DLL::StarMatch(const char *s, const char *p)
{
  if(!*s)
    FindPat("", p);
  if(FindPat(s, p))
    return true;
  return StarMatch(s+1, p);
}

bool DLL::FindPat(const char *s, const char *p)
{
  switch(*p) {
    case 0:
      return *s == 0;
    case '*':
      return StarMatch(s, p+1);
    default:
      if(!*s || (*s != *p && *p != '?'))
        return false;
      return FindPat(s+1, p+1);
  }
}

void DLL::SwapChar(char *c, char *c2)
{
  char t = *c;
  *c = *c2;
  *c2 = t;
}

void DLL::ShiftString(char *s, char ch)
{
  if(!*s)
    return;
  if(*s == ch && *(s+1)) {
    ShiftString(s+1, ch);
    SwapChar(s, s+1);
  }
  ShiftString(s+1, ch);
}

unsigned DLL::StrLenBeforeCharDo(const char *s, char ch, unsigned int len)
{
  if(!*s || *s == ch)
    return len;
  return StrLenBeforeCharDo(s+1, ch, len+1);
}

unsigned DLL::StrLenBeforeChar(const char *s, char ch)
{
  return StrLenBeforeCharDo(s, ch, 0);
}

char* DLL::TruncateStringByChar(char *s, char ch)
{
  unsigned int len = StrLenBeforeChar(s, ch);
  char *new_str = new char[len+1];
  memcpy(new_str, s, len);
  new_str[len] = '\0';
  delete [] s;
  return new_str;
}

void DLL::RemoveCharsDo(Node *n, char pat)
{
  if(!n)
    return;
  n->str = TruncateStringByChar(n->str, pat);
  RemoveCharsDo(n->next, pat);
}

void DLL::RemoveChars(char pat)
{
  RemoveCharsDo(first, pat);
}

int DLL::SortLexCmp(const char *s1, const char *s2)
{
  if(!*s1 || *s1 > *s2)
    return 1;
  if(!*s2 || *s2 > *s1)
    return -1;
  if(*s1 == '\0' && *s2 == '\0')
    return 0;
  return SortLexCmp(s1+1, s2+1);
}

char* DLL::StrDupDo(const char *str, unsigned int depth)
{
  char *res =
    *str ? StrDupDo(str+1, depth+1) : new char[depth+1];
  res[depth] = *str;
  return res;
}

char* DLL::StrDup(const char *s)
{
  return StrDupDo(s, 0);
}


/* lost implementation
void DLL::Swap(Node *a, Node *b)
{
  unsigned int len_a, len_b;
  len_a = strlen(a->str); // max one word
  len_b = strlen(b->str);

  const char *temp = StrDup(a->str);
  delete [] a->str;
  a->str = new char[len_b+1];
  strncpy(a->str, b->str, len_b);
  delete [] b->str;
  b->str = new char[len_a+1];
  strncpy(b->str, temp, len_a);
}
*/

#ifdef TESTNODES
void DLL::SwapNodes(Node *n1, Node *n2)
{
	Node *n2_prev = n2->prev;
	Node *n2_next = n2->next;
	Node *n1_prev = n1->prev;
	Node *n1_next = n1->next;
	
	if(n1_prev) {
		n1_prev->next = n2;
	}
	if(n1_next) {
		n1_next->prev = n2;
	}
	if(n2_next) {
		n2_next->prev = n1;
	}
	if(n2_prev) {
		n2_prev->next = n1;
	}
	n1->next = n2->next;
	n1->prev = n2->prev;
	n2->next = n1_next;
	n2->prev = n1_prev;
}
#endif

void DLL::SwapNodesVal(Node *a, Node *b)
{
	char *temp = a->str;
	a->str = b->str;
	b->str = temp;
}

void DLL::LoopNode(Node *head, Node *tail)
{
  if(!tail)
    return;
  if(1 == SortLexCmp(head->str, tail->str))
    SwapNodesVal(head, tail);
  LoopNode(head, tail->next);
}

void DLL::SortLexDo(Node *n)
{
  if(n == last) // exclude penultimate and last
    return;
  LoopNode(n, n->next); 
  SortLexDo(n->next);
}

void DLL::SortLexicographic()
{
  SortLexDo(first);
}
