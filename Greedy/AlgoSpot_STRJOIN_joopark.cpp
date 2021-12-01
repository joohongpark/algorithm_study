#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int solution(std::list<int>& lunches) {
    int rtn = 0;
    while (lunches.size() > 1) {
        int a, b;
        a = lunches.front();
        lunches.pop_front();
        if (lunches.size() == 1) {
            lunches.front() += a;
            rtn += lunches.front();
            break ;
        } else {
            b = lunches.front();
            lunches.pop_front();
        }
        int sum = a + b;
        rtn += sum;
        std::list<int>::iterator iter = lunches.begin();
        while (true) {
            if (iter == lunches.end()) {
                lunches.push_back(sum);
                break ;
            }
            if (*iter >= sum) {
                lunches.insert(iter, sum);
                break ;
            }
            iter++;
        }
    }
    
    return (rtn);
}

int main(void) {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::vector<int> strings_tmp;
        int c;
        std::cin >> c;
        for (int i = 0; i < c; i++) {
            int tmp;
            std::cin >> tmp;
            strings_tmp.push_back(tmp);
        }
        std::sort(strings_tmp.begin(), strings_tmp.end());
        std::list<int> strings(strings_tmp.begin(), strings_tmp.end());
        std::cout << solution(strings) << std::endl;
    }
    return (0);
}