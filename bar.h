// Project 3 
//
// Author: Sarthak Hans
// UIN - 679812530
// Milestone 1

// This file creates a Bar class which aggregates related information (name, value, and category) for use in a bar chart

#include <iostream>
#include <string>
#include "myrandom.h" // used in graders, do not remove
using namespace std;

//
// Bar
//
class Bar {
 private:
  string name;
  int value;
  string category;

 public:

    // default constructor:
    Bar() {
      name = "";
      value = 0;
      category = "";
    }

    // second constructor, this is with parameters:
    Bar(string name, int value, string category) {
        
        // TO DO:  Write this constructor.
      this->name = name;
      this->value = value;
      this->category = category;
        
    }

    // destructor:
    virtual ~Bar() {} //not required

    // getName: Getter function for name
	string getName() {
        return this->name; 
	}

    // getValue: Getter function for value
	int getValue() {
        return this->value;
	}

    // getCategory: Getter function for category
	string getCategory() {
        return this->category;
	}

	// operators
    // < operator, returns true if current Value < other Value
	bool operator<(const Bar &other) const {
    if (this->value >= other.value) {
      return false;
    } else {
        return true;
    }
	}
    // <= operator, returns true if current Value <= other Value
	bool operator<=(const Bar &other) const {
    if (this->value > other.value) {
      return false;
    } else {
        return true;
    }
	}
    // > operator, returns true if current Value > other Value
	bool operator>(const Bar &other) const {
    if (this->value > other.value) {
      return true;
    } else {
        return false;
    }
	}
    // >= operator, returns true if current Value >= other Value
	bool operator>=(const Bar &other) const {
    if (this->value >= other.value) {
      return true;
    } else {
        return false;
    }
  }
};

