#include "input_output.h"
#include <string>

using namespace std;

bool readInput(int &x, int &y) {
  cout << "Input coordinates to find set of displacements. Enter \"q\" to quit\n";
  string input;

  try {

    cout << "Enter x coordinate: ";
    cin >> input;

    if (input == "q") return false;
    x = stoi(input);

    cout << "Enter y coordinate: ";
    cin >> input;

    if (input == "q") return false;
    y = stoi(input);

  } catch (exception const & ex) {
    cout << "Invalid input. Quitting.\n";
    return false;
  }

  return true;
}

void printDisplacements(Displacements displacements) {
  bool added = false;
  string output_str = "The multiset at this position is {";
  
  for (auto pair : displacements.displacements) {
    added = true;
    output_str += "(";
    output_str += pair.first;
    output_str +=  ", ";
    output_str += pair.second; 
    output_str += "), ";
  }

  if (added) {
    output_str.pop_back();
    output_str.pop_back();
  }

  output_str += "}.\n";
  cout << output_str;
}
