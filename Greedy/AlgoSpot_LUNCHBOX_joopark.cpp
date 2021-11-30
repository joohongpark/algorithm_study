#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int comp(std::pair<int, int> left, std::pair<int, int> right) {
    return (left.second < right.second);
}

int solution(std::vector<std::pair<int, int> >& lunches) {
    std::sort(lunches.begin(), lunches.end(), comp);
    std::vector<std::pair<int, int> >::iterator iter = lunches.begin();
    int time = 0;
    while (iter != lunches.end()) {
        if (time < iter->second) {
            time = iter->second;
        }
        time += iter->first;
        iter++;
    }
    return (time);
}

int main(void) {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::vector<std::pair<int, int> > lunches;
        int c;
        std::cin >> c;
        for (int i = 0; i < c; i++) {
            std::pair<int, int> p;
            std::cin >> p.first;
            lunches.push_back(p);
        }
        for (int i = 0; i < c; i++) {
            std::cin >> lunches[i].second;
        }
        std::cout << solution(lunches) << std::endl;
    }
    return (0);
}