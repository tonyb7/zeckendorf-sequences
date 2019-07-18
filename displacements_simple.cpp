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
	cout << "got here" << endl;
	vector<vector<multiset<pair<int, int>>>> answer = prepareGrid(x, y);
	cout << "got here too!" << endl;

	cout << "Height " << answer.size() << " Width " << answer[0].size() << endl;
	cout << "got here too!" << endl;

	answer = generateGrid(answer, x, y);

	printSet(answer[x][y]);

	return 0;
}

// Initialize grid with right vectors/data structures
vector<vector<multiset<pair<int, int>>>> prepareGrid(const int x, const int y) {
	vector<vector<multiset<pair<int, int>>>> grid;
	grid.reserve(x);
	cout << "got here" << endl;

	for (int i = 0; i < x; ++i) {
		vector<multiset<pair<int, int>>> row;
		row.reserve(y);
		grid.push_back(row);
	}
	cout << "got here" << endl;

	for (auto& row : grid) {
		multiset<pair<int, int>> elt;
		for (int j = 0; j < y; ++j) {
			row.push_back(elt);
		}
	}
	cout << "got here" << endl;

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
	cout << "wooo 1" << endl;
	for (int i = 0; i < x; ++i) {
		cout << "wooo 2" << endl;

		for (int j = 0; j < y; ++j) {
			cout << "wooo 3" << endl;

			pair<int, int> a_pair = make_pair(i, j);
			cout << "wooo 3.2" << endl;
			cout << "i " << i << " J " << j << endl;
			grid[i][j].insert(a_pair);
			cout << "wooo 3.3" << endl;

			for (int k = 0; k < i; ++k) {
				cout << "wooo 4" << endl;

				for (int l = 0; l < j; ++l) {
					cout << "\twooo 5" << endl;

					for (auto elt : grid[k][l]) {
						cout << "\t\twooo 6" << endl;

						a_pair = make_pair(i - k, j - l);
						cout << "\t\twooo 6.2" << endl;

						grid[i][j].insert(a_pair);
						cout << "\t\twooo 6.3" << endl;
					}
					cout << "\t\t wooo 6.4" << endl;
				}

				cout << "\t wooo 5.2" << endl
			}
		}
	}

	return grid;
}


