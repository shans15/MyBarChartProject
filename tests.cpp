// Project 3 
//
// Author: Sarthak Hans
// UIN - 679812530

// Contains tests for bar.h and barchart.h

#include <iostream>
#include "barchartanimate.h"
using namespace std;

//
// BAR.H TESTING
//
bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor2() {
	Bar b("Barcelona", 1620000, "Spain");
    if (b.getName() != "Barcelona") {
    	cout << "testBarParamConstructor2: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 1620000) {
    	cout << "testBarParamConstructor2: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "Spain") {
    	cout << "testBarParamConstructor2: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor2: all passed!" << endl;
    return true;
}

bool L(Bar& b1, Bar& b2) {
  // b2 < b1
  if (b1 <= b2) {
    return false;
  } else {
    return true;
  }
}

bool LE(Bar& b1, Bar& b2, Bar& b3) {
  // b1 b2 same and smaller than b3
  if (b3 <= b1 || b3 <= b2) {
    return false;
  } else if (!(b1 <= b2)) {
    return false;
  } else {
    return true;
  }
}

bool G(Bar& b1, Bar& b2) {
  // b1 > b2
  if (b2 >= b1) {
    return false;
  } else {
    return true;
  }
}

bool GE(Bar& b1, Bar& b2, Bar& b3) {
  // b1 b2 same and smaller than b3
  if (b3 < b1 || b3 < b2) {
    return false;
  } else if (!(b1 >= b2)) {
    return false;
  } else {
    return true;
  }
}

//
// testOperator() - TESTING OPERATORS (<,<=,>,>=)
// 
void testOperator() {
  
  Bar b1("Kerela", 34630000, "India");
  Bar b2("Mumbai", 20961000, "India");
  Bar b3("Delhi", 20961000, "India");
  
  Bar b4("Chicago", 9234324, "India");
  Bar b5("Delhi", 18980000, "US");
  Bar b6("Barcelona", 9234324, "Spain");

  bool val;
  int num = 0;
  
  cout << "   < Test:" << endl;
  val = L(b1,b2);
  if (val == false) {
    cout << "test1 failed!" << endl;
  } else {
    cout << "test1 passed!" << endl;
    num++;
  }
  
  val = L(b5,b6);
  if (val == false) {
    cout << "test2 failed!" << endl;
  } else {
    cout << "test2 passed!" << endl;
    num++;
  }
  
  cout << "   <= Test:" << endl;
  val = LE(b2,b3,b1);
  if (val == false) {
    cout << "test1 failed!" << endl;
  } else {
    cout << "test1 passed!" << endl;
    num++;
  }
  
  val = LE(b4,b6, b5);
  if (val == false) {
    cout << "test2 failed!" << endl;
  } else {
    cout << "test2 passed!" << endl;
    num++;
  }
  
  cout << "   > Test:" << endl;
  val = G(b1,b2);

  if (val == false) {
    cout << "test1 failed!" << endl;
  } else {
    cout << "test1 passed!" << endl;
    num++;
  }
  
  val = G(b5,b6);
  if (val == false) {
    cout << "test2 failed!" << endl;
  } else {
    cout << "test2 passed!" << endl;
    num++;
  }
  
  cout << "   >= Test:" << endl;
  val = GE(b2,b3,b1);
  if (val == false) {
    cout << "test1 failed!" << endl;
  } else {
    cout << "test1 passed!" << endl;
    num++;
  }
  val = GE(b2,b3,b1);
  if (val == false) {
    cout << "test2 failed!" << endl;
  } else {
    cout << "test2 passed!" << endl;
    num++;
  }

  if (num == 8) {
    cout << "testBarOperator: all passed!" << endl;
  } else if (num == 0) {
    cout << "testBarOperator: all failed!" << endl;
  } else {
    cout << "testBarOperator: not all passed!" << endl;
  }
}

//
// BARCHART.H TESTING
//
bool testBarChartDefaultConstructor() {
	BarChart b;
  if (b.getSize() != 0) {
    cout << "testBarChartDefaultConstructor: getSize failed" << endl;
    return false;
  } else if (b.getFrame() != "") {
    cout << "testBarChartDefaultConstructor: getFrame failed" << endl;
    return false;
  }
  cout << "testBarChartDefaultConstructor: all passed!" << endl;
  return true;
}


bool testBarChartParamConstructor() {
	BarChart b(5);
  int index = 0;
  for (int i = 0; i < 5; i++) {
    b.addBar("sarthak",i,"hans");
    index++;
  }
  
  if (index != 5) {
    cout << "testBarChartParamConstructor: all failed!" << endl;
    return false;
  }
  cout << "testBarChartParamConstructor: all passed!" << endl;
  return true;

}

bool barChartTest () {
  cout << endl;
  cout << "***********************" << endl << endl;
  BarChart bc(4);
  bc.setFrame("2008");
  bc.addBar("Delhi",18980000,"India");
  bc.addBar("Chicago",9234324,"US");
  bc.addBar("Barcelona",1620000,"Spain");

  map<string, string> colorMap;
  colorMap["India"] = GREEN;
  colorMap["US"] = BLUE;
  colorMap["Spain"] = RED;
  bc.graph(cout, colorMap, 3);
  cout << endl;
  return true;
}

int main() {
	testBarDefaultConstructor();
	testBarParamConstructor();
  testBarParamConstructor2();
  testOperator();
  testBarChartDefaultConstructor();
  testBarChartParamConstructor();
  bool trial = barChartTest();
  if (trial == true) {
    cout << "barChartTest: all passed!" << endl;
  }
  return 0;
}
