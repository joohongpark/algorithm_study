#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int test_case;
int lunch_box;
int m[10000];
int e[10000];

vector<pair<int, int> >	init(void) {
	vector<pair<int, int> >	lunch;
	cin >> lunch_box;
	for (int i = 0; i < lunch_box; i++)
		cin >> m[i];
	for (int i = 0; i < lunch_box; i++)
		cin >> e[i];
	for (int i = 0; i < lunch_box; i++)
		lunch.push_back(make_pair(e[i], m[i]));
	sort(lunch.begin(), lunch.end());
	return (lunch);
}

int	lunchBox(vector<pair<int, int> > lunch) {
	int	rtn = 0;
	int m = 0;
	for (int i = lunch_box - 1; i >= 0; i--) {
		m += lunch.at(i).second;
		rtn = max(rtn, m + lunch.at(i).first);
	}
	return (rtn);
}

int main(void) {
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
		cout << lunchBox(init()) << endl;
	return (0);
}