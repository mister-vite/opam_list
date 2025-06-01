#include "list.hpp"
#include <iostream>

namespace blgt {

    list::iterator& list::iterator::operator++() {
        if (_data) _data = _data->_next;
        return *this;
    }

    list::iterator list::iterator::operator++(int) {
        iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    std::int32_t& list::iterator::operator*() {
        return *(_data->_data);
    }

    list::list() : _head(nullptr) {}

    list::~list() {
        while (_head) erase_front();
    }

    list::iterator list::begin() { return { _head }; }
    list::iterator list::end() { return { nullptr }; }

    void list::insert_front(std::int32_t value) {
        _head = new node{ _head, new std::int32_t(value) };
    }

    void list::insert_back(std::int32_t value) {
        if (!_head) return insert_front(value);

        node* current = _head;
        while (current->_next) current = current->_next;
        current->_next = new node{ nullptr, new std::int32_t(value) };
    }

    void list::erase_front() {
        if (!_head) return;

        node* tmp = _head;
        _head = _head->_next;
        delete tmp->_data;
        delete tmp;
    }

    void list::erase_back() {
        if (!_head) return;

        if (!_head->_next) {
            erase_front();
            return;
        }

        node* prev = nullptr;
        node* curr = _head;
        while (curr->_next) {
            prev = curr;
            curr = curr->_next;
        }

        delete curr->_data;
        delete curr;
        prev->_next = nullptr;
    }

    bool list::empty() const { return !_head; }

    std::size_t list::size() const {
        std::size_t count = 0;
        for (node* n = _head; n; n = n->_next) ++count;
        return count;
    }

    bool operator==(const list::iterator& lhs, const list::iterator& rhs) {
        return lhs._data == rhs._data;
    }

    bool operator!=(const list::iterator& lhs, const list::iterator& rhs) {
        return !(lhs == rhs);
    }

}

void test_list() {
    blgt::list lst;

    std::cout << "Test 1: " << (lst.empty() ? "PASS" : "FAIL") << "\n";

    lst.insert_front(10);
    std::cout << "Test 2: " << (lst.size() == 1 ? "PASS" : "FAIL") << "\n";

    lst.insert_back(20);
    std::cout << "Test 3: " << (lst.size() == 2 ? "PASS" : "FAIL") << "\n";

    auto it = lst.begin();
    std::cout << "Test 4: " << (*it == 10 ? "PASS" : "FAIL") << " ";
    ++it;
    std::cout << (*it == 20 ? "PASS" : "FAIL") << "\n";

    lst.erase_front();
    lst.erase_back();
    std::cout << "Test 5: " << (lst.empty() ? "PASS" : "FAIL") << "\n";
}

int main() {
    test_list();
    return 0;
}