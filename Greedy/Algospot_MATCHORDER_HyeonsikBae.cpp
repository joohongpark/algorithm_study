#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test_case;
int player;

void	init(vector<int>& point_russian, vector<int>& point_korean) {
	cin >> player;
	int temp;
	for (int i = 0; i < player; i++) {
		cin >> temp;
		point_russian.push_back(temp);
	}
	for (int i = 0; i < player; i++) {
		cin >> temp;
		point_korean.push_back(temp);
	}
	sort(point_korean.begin(), point_korean.end());
	return ;
}

int	matchOrder(vector<int>& point_russian, vector<int>& point_korean) {
	int rtn = 0;
	for (int i = 0; i < player; i++) {
		int max_korean = point_korean.at(point_korean.size() - 1);
		if (point_russian.at(i) > max_korean) {
			point_korean.erase(point_korean.begin());
			continue;
		}
		point_korean.erase(lower_bound(point_korean.begin(), point_korean.end(), point_russian.at(i)));
		rtn++;
	}
	return (rtn);
}

int main(void) {
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		vector<int> point_korean;
		vector<int> point_russian;
		init(point_russian, point_korean);
		cout << matchOrder(point_russian, point_korean) << endl;
	}
	return (0);
}