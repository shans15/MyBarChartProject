// Project 3 
//
// Author: Sarthak Hans
// UIN - 679812530
// Milestone 2

// barchart.h creates and prints the bar chart with all data on it

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h" // used in graders, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");


//Color codes for light mode terminals
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};


// BarChart Class

class BarChart {
 private:
    Bar* bars;  // pointer to a C-style array
    int capacity;
    int size;
    string frame;
    
 public:
    
    // default constructor:
    BarChart() {
      this->bars = nullptr;
      this->capacity = 0;
      this->size = 0;
      this->frame = "";
        
    }
    
    // parameterized constructor:
    BarChart(int n) {
      this->bars = new Bar[n];
      this->capacity = n;
      this->size = 0;
      this->frame = "";
    }

    // copy constructor: BarChart as a parameter by value.
    // Copies values of 'other' onto current BarChart
    BarChart(const BarChart& other) {
      bars = new Bar[other.capacity];
      capacity = other.capacity;
      size = other.size;
      frame = other.frame;

      for (int i = 0; i < other.size; i++) {
        bars[i] = other.bars[i];
      }
    }

    // copy operator=
    // Called when you assign one BarChart into another, i.e. this = other;
    BarChart& operator=(const BarChart& other) {
      
      if (this == &other) {
        return *this;
      }
      delete[] bars;

      this->bars = new Bar[other.capacity];
      this->capacity = other.capacity;
      this->size = other.size;
      this->frame = other.frame;

      for (int i = 0; i < size; i++) {
        this->bars[i] = other.bars[i];
      }
      return *this;
    }

    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {
      capacity = 0;
      size = 0;
      frame = "";
      delete[] bars;
      bars = nullptr;
    }
    
    // destructor:
    virtual ~BarChart() {
      if (bars != nullptr) {
        delete[] bars;
      }
    }
    
    // setFrame: sets the value of frame
    void setFrame(string frame) {
      this->frame = frame;
    }
    
    // getFrame()
    // Returns the frame of the BarChart oboject.
    string getFrame() {
        return this->frame;
    }

    // addBar
    // adds a Bar to the BarChart. returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {
      if (size == capacity) {
        return false;
      }
      
      Bar adding(name, value, category);
      bars[size] = adding;
      size++;
      
      return true;
    }
    
    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
        return size;
    }
    
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {
      if (i < 0) {
        throw out_of_range("BarChart: i out of bounds");
      } else if (i > size) {
        throw out_of_range("BarChart: i out of bounds");
      }
      return bars[i];
    }
    
    // dump
    // Used for printing the BarChart object.
    void dump(ostream &output) {

      sort(bars, bars+size, greater<Bar>());  // sorting in descending
      
      output << "frame: " << frame << endl;
      
      for (int i = 0; i < size; i++) {
        output << bars[i].getName() << " ";
        output << bars[i].getValue() << " ";
        output << bars[i].getCategory() << endl;
      }
    }
    
    // graph
    // Used for printing out the bar.
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax = 60;  // this is number of BOXs that should be printed
                          // for the top bar (max value)
      sort(bars, bars+size, greater<Bar>());  // sorting in descending
      
      string color = "";
      string barstr = "";

      double amount;

      sort(bars, bars + size, greater < Bar > ()); // sorting in descending
  
      if (top > size) { // if there are more bars in top than the elements in file
        top = size;
      }
  
      int high = bars[0].getValue();
      
      for (int i = 0; i < top; ++i) {
        amount = (bars[i].getValue() / double(high)) * lenMax;

        if (!colorMap.count(bars[i].getCategory())) { // checks if the category is in colorMap, if not then color is set to Black
          color = BLACK;
        } else {
          color = colorMap[bars[i].getCategory()];
        }
  
        for (int j = 0; j < floor(amount); ++j) { // generating bars
          barstr += BOX;
        }
  
        output << color << barstr << " " << bars[i].getName() << " " << bars[i].getValue() << endl;
        barstr = "";
      }
    }
    
};

