// Zeckendorf thing for Annie Xu
// It was really fun! - Tony Bai
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <utility>

using namespace std;

vector<vector<pair<int, set<int>>>> prepareGrid(const int lim);
void printGrid(const vector<vector<pair<int, set<int>>>> answer);
vector<vector<pair<int, set<int>>>> generateGrid(vector<vector<pair<int, set<int>>>> & grid);
pair<int, set<int>> findElementAt(const int i, const int j,
	vector<vector<pair<int, set<int>>>>  &grid, unordered_set<int> &forbidden_sums, int &prev_elt);
int find_smallest_unused_int(unordered_set<int> &forbidden_sums, const int prev_elt);

int main() {
	int lim;
	cout << "How many rows do you want to generate? ";
	cin >> lim;

	vector<vector<pair<int, set<int>>>> answer = prepareGrid(lim);
	answer = generateGrid(answer);
	printGrid(answer);

	return 0;
}

// Print the grid
void printGrid(const vector<vector<pair<int, set<int>>>> answer) {
	for (vector<pair<int, set<int>>> vec : answer) {
		for (pair<int, set<int>> pair : vec) {
			cout.width(3);
			cout << left << pair.first << " ";
		}
		cout << "\n";
	}
}

// Initialize grid with right vectors/data structures
vector<vector<pair<int, set<int>>>> prepareGrid(const int lim) {
	vector<vector<pair<int, set<int>>>> grid;
	for (int i = 0; i < lim; ++i) {
		vector<pair<int, set<int>>> row;
		// row.resize(lim);
		grid.push_back(row);
	}

	return grid;
}

// Generate the grid
vector<vector<pair<int, set<int>>>> generateGrid(vector<vector<pair<int, set<int>>>> & grid) {
	int width = (int) grid.size();
	unordered_set<int> forbidden_sums;
	int prev_elt = 0;

	// Traverse the grid across skewed diagonals
	for (int j = 1; j <= width; ++j) {
		for (int i = 0; i < j; ++i) {
			pair<int, set<int>> next_elt = findElementAt(i, grid[i].size(), grid, forbidden_sums, prev_elt);
			grid[i].push_back(next_elt);
		}
	}

	return grid;
}

// Find element at position (i, j). Update forbidden sums. Returns pair, which contains the
// number at position (i, j) and the new forbidden sums added from that position.
pair<int, set<int>> findElementAt(const int i, const int j,
		vector<vector<pair<int, set<int>>>>  &grid, unordered_set<int> &forbidden_sums, int &prev_elt) {

	pair<int, set<int>> pair = make_pair(0, set<int>());

	pair.first = find_smallest_unused_int(forbidden_sums, prev_elt);
	pair.second.insert(pair.first);
	forbidden_sums.insert(pair.first);
	prev_elt = pair.first;

	for (int x = 0; x < i; ++x) {
		for (int y = 0; y < j; ++y) {
			for (auto prev_path_sum : grid[x][y].second) {
				pair.second.insert(pair.first + prev_path_sum);
				forbidden_sums.insert(pair.first + prev_path_sum);
			}
		}
	}

	return pair;
}

// Find the smallest int not in the forbidden_sums set. Start searching from prev_elt.
int find_smallest_unused_int(unordered_set<int> &forbidden_sums, const int prev_elt) {
	int index = prev_elt + 1;
	while (forbidden_sums.count(index)) ++index;
	return index;
}
