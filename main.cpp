#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/binary-prefix-divisible-by-5/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> b(A.size());
        if (A.empty()) return b;
        unsigned long num = A[0];
        b[0] = (num == 0);
        int one = 1;
        for (int i = 1; i < A.size(); ++i) {
            num <<= 1;
            if (A[i] == 1) num |= one;
            if (num % 5 == 0) {
                b[i] = true;
                num = 0;
            }
        }
        return b;
    }
};

void test1() {
    vector<int> v1{0,1,1};

    cout << boolalpha;
    cout << "101 ? " << Solution().prefixesDivBy5(v1) << endl;

    // [0,1,1,1,1,1]
    vector<int> v2{0,1,1,1,1,1};

    cout << boolalpha;
    cout << "[true,false,false,false,true,false] ? " << Solution().prefixesDivBy5(v2) << endl;

    vector<int> v3{1,1,1,0,1};

    cout << boolalpha;
    cout << "[false,false,false,false,false] ? " << Solution().prefixesDivBy5(v3) << endl;

}

void test2() {

}

void test3() {

}