#include "Ejercicio01.h"
#include <queue>

struct compare {
    bool operator()(const Node<int>* a, const Node<int>* b) {
        return a->value < b->value;
    }
};

Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists) {
    std::priority_queue<Node<int>*, std::vector<Node<int>*>, compare> pq;
    Node<int>* dummy = new Node<int>();
    Node<int>* tail = dummy;

    while (lists != nullptr) {
        if (lists->value != nullptr) {
            pq.push(lists->value);
            lists->value = lists->value->next;
        }
        lists = lists->next;
    }
    while (!pq.empty()) {
        tail->next = pq.top();
        pq.pop();
        tail = tail->next;

        if (tail->next != nullptr) {
            pq.push(tail->next);
        }
    }

    return dummy->next;
}

