#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <utility>

using namespace std;

vector<vector<multiset<pair<int, int>>>> prepareGrid(const int x, const int y);
void printSingleSet(const multiset<pair<int, int>> elt);
vector<vector<multiset<pair<int, int>>>> generateGrid(vector<vector<multiset<pair<int, int>>>> &grid, int x, int y);
void printX(const multiset<pair<int, int>> elt);
void printY(const multiset<pair<int, int>> elt);
void printSum(const multiset<pair<int, int>> elt);
void printAllX(const int x, const int y, vector<vector<multiset<pair<int, int>>>> &grid);
void printAllY(const int x, const int y, vector<vector<multiset<pair<int, int>>>> &grid);
void printAllPair(const int x, const int y, vector<vector<multiset<pair<int, int>>>> &grid);
void printAllSum(const int x, const int y, vector<vector<multiset<pair<int, int>>>> &grid);

int main() {
    int x;
    cout << "Enter x coordinate ";
    cin >> x;
    
    int y;
    cout << "Enter y coordinate ";
    cin >> y;
    
    vector<vector<multiset<pair<int, int>>>> answer = prepareGrid(x, y);
    answer = generateGrid(answer, x, y);
    
    string command;
    cout << "Choose: Print x or y or (x,y) or x+y ";
    cin >> command;
    if (command == "x") {
        printAllX(x, y, answer);
    } else if (command == "y") {
        printAllY(x, y, answer);
    } else if (command == "(x,y)") {
        printAllPair(x, y, answer);
    } else if (command == "x+y") {
        printAllSum(x, y, answer);
    } else {
        cout << "Invalid command" << endl;
    }
    
    return 0;
}

// Initialize grid with right vectors/data structures
vector<vector<multiset<pair<int, int>>>> prepareGrid(const int x, const int y) {
    vector<vector<multiset<pair<int, int>>>> grid;
    grid.reserve(x);
    for (int i = 0; i < x; ++i) {
        vector<multiset<pair<int, int>>> row;
        row.reserve(y);
        grid.push_back(row);
    }
    
    for (auto& row : grid) {
        multiset<pair<int, int>> elt;
        for (int j = 0; j < y; ++j) {
            row.push_back(elt);
        }
    }
    
    return grid;
}

// Print the pair at one position
void printSingleSet(const multiset<pair<int, int>> elt) {
    bool added = false;
    string output_str = "";
    
    for (auto pair : elt) {
        added = true;
        output_str += "{";
        output_str += std::to_string(pair.first);
        output_str +=  ", ";
        output_str += std::to_string(pair.second);
        output_str += "}, ";
    }
    
    cout << output_str;
}

// Print the first coordinate at one position
void printX(const multiset<pair<int, int>> elt) {
    bool added = false;
    string output_str = "";
    
    for (auto pair : elt) {
        added = true;
        output_str += std::to_string(pair.first);
        output_str +=  ", ";
    }
    
    if (added) {
        output_str.pop_back();
    }
    
    cout << output_str;
}

// Print the second coordinate at one position
void printY(const multiset<pair<int, int>> elt) {
    bool added = false;
    string output_str = "";
    
    for (auto pair : elt) {
        added = true;
        output_str += std::to_string(pair.second);
        output_str +=  ", ";
    }
    
    cout << output_str;
}

void printSum(const multiset<pair<int, int>> elt) {
    bool added = false;
    string output_str = " ";
    
    for (auto pair : elt) {
        added = true;
        output_str += std::to_string(pair.first + pair.second);
        output_str +=  ", ";
    }
    
    cout << output_str;
}

// Print the first coordinate before one position
void printAllX(const int x, const int y, vector<vector<multiset<pair<int, int>>>> &grid) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printX(grid[i][j]);
        }
    }
}

// Print the second coordinate before one position
void printAllY(const int x, const int y, vector<vector<multiset<pair<int, int>>>> &grid) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printY(grid[i][j]);
        }
    }
}

// Print the pair before one position
void printAllPair(const int x, const int y, vector<vector<multiset<pair<int, int>>>> &grid) {
    cout << "The multiset at this position is {";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printSingleSet(grid[i][j]);
        }
    }
    cout << "}.\n";
}

// Print the sum of x+y
void printAllSum(const int x, const int y, vector<vector<multiset<pair<int, int>>>> &grid) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printSum(grid[i][j]);
        }
    }
}

// Generate the grid
vector<vector<multiset<pair<int, int>>>> generateGrid(vector<vector<multiset<pair<int, int>>>> &grid, int x, int y) {
    for (int i = 0; i < x; ++i) {
        pair<int, int> pair = { i+1 , 1 };
        grid[i][0].insert(pair);
    }
    
    for (int j = 1; j < y; ++j) {
        pair<int, int> pair = { 1, j+1 };
        grid[0][j].insert(pair);
    }
    
    for (int j = 0; j < y; ++j) {
        for (int k = 0; k < x; ++k) {
            for (int l = 0; l < j - 1; ++l) {
                for (int m = 0; m < k - 1; ++m) {
                    for (auto a_pair : grid[m][l]) {
                        pair<int, int> new_pair = { k - a_pair.first, j - a_pair.second };
                        grid[k][j].insert(new_pair);
                    }
                }
            }
        }
    }
    
    return grid;
}
