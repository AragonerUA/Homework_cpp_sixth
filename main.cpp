#include <iostream>
#include <vector>
#include "need.h"

//forward iterator
template <class Iter, class Type>
bool allOf(Iter first, const Iter& last, const Type& value) {
    while (first != last) {
        if (*first == value) {
            first++;
        }
        else {
            return false;
        }
    }
    return true;
}

template <class Iter, class Predicat>
bool isSorted(Iter first, Iter last, Predicat p) {
    for (auto i = first; i < last; i++) {
        if (!p(*i, *(i + 1))) {
            return false;
        }
    }
    return true;
}

template <class Iter, class Predicate>
bool isPalindrome(Iter first, Iter last, Predicate p) {
    last--;
    while (first != last) {
        if(!p(*first, *last))
            return false;
        first++;
        if(!(first != last))
            break;
        last--;
    }
    return true;
}

template <class Type, int N>
class Predicate {

public:
    bool operator() (const Type a) {
        return a % N == 0;
    }
};

template <class Type>
class SecondPredicate {

public:
    bool operator() (const Type a, const Type b) {
        return a == b;
    }
};

template <class Type>
class IsLess {
public:
    bool operator() (const Type a, const Type b) {
        return a < b;
    }
};

template <class Type>
class IsMore {
public:
    bool operator() (const Type a, const Type b) {
        return a > b;
    }
};


int main() {
    //AllOf
    std::vector<CPoint> v;
    CPoint point;
    point.x = 4.0;
    point.y = 5.0;
    v.push_back(point);
    point.x = 4.0;
    point.y = 5.0;
    v.push_back(point);
    point.x = 4.0;
    point.y = 5.0;
    v.push_back(point);
    std::cout << "AllOf Check:
";
    point.x = 4.0;
    point.y = 89.991;
//    point.x = 4.0;
//    point.y = 5.0;
    std::cout << allOf(v.begin(), v.end(), point) << std::endl; //Might be 1
    std::vector<CPoint> vect;
    CPoint need;
    need.x = 1.0;
    need.y = 5.2;
    vect.push_back(need);
    need.x = 3.1;
    need.y = 3.1;
    vect.push_back(need);
    need.x = 3.1;
    need.y = 3.1;
    vect.push_back(need);
    std::cout << "Another AllOf Check:
";
    std::cout << allOf(vect.begin(), vect.end(), need) << std::endl; //Might be 0

    //Sorted
    std::vector<int> vector = {1, 5, 8};
    std::cout << "is_Sorted Check:
";
    std::cout << isSorted(vector.begin(), vector.end(), IsLess<int>()) << std::endl;
    std::cout << "Another is_Sorted Check:
";
    std::cout << isSorted(vector.begin(), vector.end(), IsMore<int>()) << std::endl;

    //isPalindrome
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    std::cout << "isPalindrome Check:
";
    std::cout << isPalindrome(vec.begin(), vec.end(), SecondPredicate<int>()) << std::endl;

}
