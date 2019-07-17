// Zeckendorf thing for Annie Xu
// It was really fun! - Tony Bai
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <string>
#include <utility>

using namespace std;
using row = vector<pair<int, set<int>>>;

vector<row> prepareGrid(const int lim);
void printGrid(const vector<row> &answer);
vector<row> generateGrid(vector<row> & grid);
pair<int, set<int>> findElementAt(const int i, const int j,
	vector<row>  &grid, unordered_set<int> &forbidden_sums, int &prev_elt);
int find_smallest_unused_int(unordered_set<int> &forbidden_sums, const int prev_elt);

int main(int argc, char **argv) {
	int lim;

	if (argc == 1) {
		cout << "How many rows do you want to generate? ";
		cin >> lim;
	} else {
		lim = stoi(argv[1]);
	}

	vector<row> answer(lim);
	answer = generateGrid(answer);
	printGrid(answer);

	return 0;
}

// Base-10 logarithm, rounded down. One less than the number of decimal digits.
int log10(int n) {
	if (n < 10) {
		return 0;
	}

	return 1 + log10(n / 10);
}

// Print the grid
void printGrid(const vector<row> &answer) {
	int greatest = answer.back()[0].first;
	int digits = log10(greatest) + 1;

	for (const row &vec : answer) {
		for (const pair<int, set<int>> &pair : vec) {
			cout.width(digits + 1);
			cout << left << pair.first;
		}
		cout << endl;
	}
}

// Generate the grid
vector<row> generateGrid(vector<row> &grid) {
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
		vector<row>  &grid, unordered_set<int> &forbidden_sums, int &prev_elt) {

	pair<int, set<int>> pair = make_pair(0, set<int>());

	pair.first = find_smallest_unused_int(forbidden_sums, prev_elt);
	pair.second.insert(pair.first);
	forbidden_sums.insert(pair.first);
	prev_elt = pair.first;

	for (int x = 0; x < i; ++x) {
		for (int y = 0; y < j; ++y) {
			for (auto prev_path_sum : grid[x][y].second) {
				pair.second.insert(pair.second.end(), pair.first + prev_path_sum);
				forbidden_sums.insert(forbidden_sums.end(), pair.first + prev_path_sum);
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

