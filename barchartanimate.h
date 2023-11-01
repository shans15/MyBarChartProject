// Project 3 
//
// Author: Sarthak Hans
// UIN - 679812530
// Milestone 3

// This class will animate the bar chart onto the terminal for the user.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;
//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;
    vector<string> grouping;  // vector for all grouping
    int index;  // color index value
  
  //
  // file_input() - parses through the line from file and adds it in appropriate containers
  //
    void file_input (ifstream &file, int& int_text, string& line, string& name, string& year, string& country, string& need, string& grouping_string) {
      
      getline(file, line);  // extra line
      
      stringstream s(line);
      
      getline(s, need, ',');
      year = need;
      getline(s, need, ',');
      name = need;
      getline(s, need, ',');
      country = need;
      getline(s, need, ',');
      
      int_text = stoi(need);
      getline(s, need, ',');
      grouping_string = need;
    }

  //
  // adding_bar() - add each file group in grouping to separate bars
  //
    void adding_bar(string grouping_string) {
      int size = (int)grouping.size();
      for (int i = 0; i < size; i++) {
        if (grouping[i] == grouping_string) {
          return;
        }
      }
      grouping.push_back(grouping_string);
    }

  //
  // double_array() - if size matches capacity, double the capacity
  //
    void double_array (int& size, int& capacity) {
      if (size == capacity) {
        int new_capacity = capacity * 2;
        BarChart *adding = new BarChart[new_capacity];
        
        for (int i = 0; i < size; i++) {
          adding[i] = barcharts[i];
        }
      
        delete[] barcharts;
        capacity = new_capacity;
        barcharts = adding;
        
        adding = nullptr;
      }
    }

 public:
    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        capacity = 4;
        size = 0;
        barcharts = new BarChart[capacity];
        index = 0;
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        if (barcharts != nullptr) {
          delete[] barcharts;
          barcharts = nullptr;
        }
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
      if (file.eof()) {
        return;
      }
      string line, need, year, name, country, grouping_string;
      int int_text, data;
      getline(file, line); // empty line
      if (file.eof()) {
          return;
      }
      getline(file, line);
      data = stoi(line);  // amount of data in file
      BarChart new_bar(data);  // creating bar chart with that the amount of data in file
      for (int i = 0; i < data; i++) {  
        file_input (file, int_text, line, name, year, country, need, grouping_string);  // going through each line to add all titles
        
        adding_bar(grouping_string);  // adding the categories
        new_bar.addBar(name, int_text, grouping_string);  // adding this to the barchart
        new_bar.setFrame(year);  // setting barchart frame
        if(colorMap.count(grouping_string) == 0) {
            colorMap.insert({grouping_string, COLORS[index % 7]});
            index++;
        }
      }
      double_array(size, capacity);  // checks if cap needs to be increased
      barcharts[size] = new_bar;
      size++;
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;

    if (endIter == -1) {
      endIter = size;
    }
    for (int i = 0; i < endIter; i++) {
      usleep(3 * microsecond);
      output << CLEARCONSOLE;
      output << BLACK << title << endl;
      output << BLACK << source << endl;
      barcharts[i].graph(output, colorMap, top);
      output << BLACK << xlabel << endl;
      output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
    }
	}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        return size;
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
      if (i < 0) {
        throw out_of_range("BarChartAnimate: i out of bounds");
      } else if (i > size) {
        throw out_of_range("BarChartAnimate: i out of bounds");
      }
      return barcharts[i];  
    }
};
