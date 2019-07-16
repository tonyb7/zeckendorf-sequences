#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <utility>

using namespace std;

vector<vector<multiset<pair<int, int>>>> prepareGrid(const int x, const int y);
void printSet(const multiset<pair<int, int>> elt);
vector<vector<multiset<pair<int, int>>>> generateGrid(vector<vector<multiset<pair<int, int>>>> &grid, int x, int y);

int main() {
	int x;
	cout << "Enter x coordinate ";
	cin >> x;

	int y;
	cout << "Enter y coordinate ";
	cin >> y;

	vector<vector<multiset<pair<int, int>>>> answer = prepareGrid(x, y);
	answer = generateGrid(answer, x, y);
	printSet(answer[x][y]);

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

// Print the grid
void printSet(const multiset<pair<int, int>> elt) {
	bool added = false;
	string output_str = "The multiset at this position is {";

	for (auto pair : elt) {
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

// Generate the grid
vector<vector<multiset<pair<int, int>>>> generateGrid(vector<vector<multiset<pair<int, int>>>> &grid, int x, int y) {
	for (int i = 0; i < x; ++i) {
		pair<int, int> pair = { i, 0 };
		grid[i][0].insert(pair);
	}

	for (int j = 0; j < y; ++j) {
		for (int k = 0; k < x; ++k) {
			for (int l = 0; l < j; ++j) {
				for (int m = 0; m < k; ++m) {
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


