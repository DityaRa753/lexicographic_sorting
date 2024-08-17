.PHONY: clean all clean_all
#dir names
ODIR = o
HDIR = h
SDIR = src

# Compiler
CXX ?= g++
CXXFLAGS = -std=c++98 -Wall -Ofast -fno-exceptions

# Project name
PROJECT = lex_sort

# Libraries
PATHLIBS := 
LIBS :=
INCS := -I$(HDIR)

SRCS = $(shell find $(SDIR) -name '*.cpp' | sort)
DIRS = $(shell find $(SDIR) -type d | sed 's/$(SDIR)/./g' ) 
OBJS = $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SRCS))

# Targets
$(PROJECT): buildrepo $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(PATHLIBS) $(LIBS) -o $@

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf $(PROJECT) $(ODIR)

buildrepo:
	mkdir -p $(ODIR)
