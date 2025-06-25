#include "list.hpp"
#include <cassert>
#include <iostream>

using namespace blgt;

void test_empty_list() {
    list l;
    assert(l.empty());
    assert(l.size() == 0);
    std::cout << "test_empty_list passed\n";
}

void test_insert_front() {
    list l;
    l.insert_front(42);
    assert(!l.empty());
    assert(l.size() == 1);
    auto it = l.begin();
    assert(*it == 42);
    std::cout << "test_insert_front passed\n";
}

void test_insert_back() {
    list l;
    l.insert_back(99);
    assert(!l.empty());
    assert(l.size() == 1);
    auto it = l.begin();
    assert(*it == 99);
    std::cout << "test_insert_back passed\n";
}

void test_insert_front_and_back() {
    list l;
    l.insert_front(1);
    l.insert_back(2);
    assert(l.size() == 2);
    auto it = l.begin();
    assert(*it == 1);
    ++it;
    assert(*it == 2);
    std::cout << "test_insert_front_and_back passed\n";
}

void test_erase_front() {
    list l;
    l.insert_front(100);
    l.insert_back(200);
    l.erase_front();
    assert(l.size() == 1);
    auto it = l.begin();
    assert(*it == 200);
    std::cout << "test_erase_front passed\n";
}

void test_erase_back() {
    list l;
    l.insert_front(100);
    l.insert_back(200);
    l.erase_back();
    assert(l.size() == 1);
    auto it = l.begin();
    assert(*it == 100);
    std::cout << "test_erase_back passed\n";
}

void test_iterator_increment() {
    list l;
    l.insert_back(10);
    l.insert_back(20);
    auto it = l.begin();
    assert(*it == 10);
    ++it;
    assert(*it == 20);
    std::cout << "test_iterator_increment passed\n";
}

void test_iterator_comparison() {
    list l;
    l.insert_back(1);
    l.insert_back(2);
    auto it1 = l.begin();
    auto it2 = l.begin();
    assert(it1 == it2);
    ++it2;
    assert(it1 != it2);
    std::cout << "test_iterator_comparison passed\n";
}

void test_iteration_all_elements() {
    list l;
    for (int i = 0; i < 5; ++i)
        l.insert_back(i);

    int sum = 0, cnt = 0;
    for (auto it = l.begin(); it != l.end(); ++it) {
        sum += *it;
        cnt++;
    }
    assert(sum == 0 + 1 + 2 + 3 + 4);
    assert(cnt == 5);
    std::cout << "test_iteration_all_elements passed\n";
}

void test_erase_until_empty() {
    list l;
    l.insert_back(1);
    l.insert_back(2);
    l.erase_front();
    l.erase_front();
    assert(l.empty());
    std::cout << "test_erase_until_empty passed\n";
}

int main() {
    test_empty_list();
    test_insert_front();
    test_insert_back();
    test_insert_front_and_back();
    test_erase_front();
    test_erase_back();
    test_iterator_increment();
    test_iterator_comparison();
    test_iteration_all_elements();
    test_erase_until_empty();
    std::cout << "All tests passed!\n";
    return 0;
}