#pragma once

#include <cstdint>
#include <cstdlib>

namespace blgt {

    class list {
    private:
        struct node {
            node* _next;
            std::int32_t* _data;
        };

    public:
        struct iterator {
            iterator& operator++();
            iterator operator++(int);
            std::int32_t& operator*();
            node* _data;
        };

        list();
        ~list();

        iterator begin();
        iterator end();

        void insert_front(std::int32_t value);
        void insert_back(std::int32_t value);
        void erase_front();
        void erase_back();

        bool empty() const;
        std::size_t size() const;

    private:
        node* _head;
    };

    bool operator==(const list::iterator& lhs, const list::iterator& rhs);
    bool operator!=(const list::iterator& lhs, const list::iterator& rhs);

}