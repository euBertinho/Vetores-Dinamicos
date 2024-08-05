#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__
#include <stdexcept> // Para std::out_of_range

class linked_list {
private:
    struct int_node {
        int value;
        int_node* next, * prev;
    int_node(int v = 0) : value(v), next(nullptr), prev(nullptr) {}
    };
    int_node* head, * tail;
    unsigned int size_;
    unsigned int max_capacity;
public:
    linked_list() {
        this->head = 0;
        this->tail = 0;
        this->size_ = 0;
    }

    ~linked_list() {
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
    }

    bool pop_back() {
        if (tail == nullptr) return false; // List is empty
        int_node* to_remove = tail;
        if (head == tail) { // List has only one element
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete to_remove;
        --size_;
        return true;
    }

    bool pop_front() {
        if (head == nullptr) return false; // List is empty
        int_node* to_remove = head;
        if (head == tail) { // List has only one element
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete to_remove;
        --size_;
        return true;
    }

    int front() {
        if (head == nullptr) throw std::runtime_error("List is empty");
        return head->value;
    }

    int back() {
        if (tail == nullptr) throw std::runtime_error("List is empty");
        return tail->value;
    }

    bool remove(int value) {
        int_node* current = head;
        while (current != nullptr) {
            if (current->value == value) {
                if (current == head) {
                    pop_front();
                } else if (current == tail) {
                    pop_back();
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    --size_;
                }
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool remove_at(unsigned int index) {
        if (index >= this->size_)
            return false; // Não removeu
        int_node* to_remove = this->head;
        for (unsigned int i = 0; i < index; ++i)
            to_remove = to_remove->next;
        if (to_remove->prev != nullptr)
            to_remove->prev->next = to_remove->next;
        if (to_remove->next != nullptr)
            to_remove->next->prev = to_remove->prev;
        delete to_remove;
        return true; // Removeu
    }

    int find(int value) {
        int index = 0;
        int_node* current = head;
        while (current != nullptr) {
            if (current->value == value) return index;
            current = current->next;
            ++index;
        }
        return -1; // Not found
    }

    int count(int value) {
        int count = 0;
        int_node* current = head;
        while (current != nullptr) {
            if (current->value == value) ++count;
            current = current->next;
        }
        return count;
    }

    int sum() {
        int total = 0;
        int_node* current = head;
        while (current != nullptr) {
            total += current->value;
            current = current->next;
        }
        return total;
    }

    int get_at(unsigned int index) {
        if (index >= size_) throw std::out_of_range("Index out of bounds");
        int_node* current = head;
        for (unsigned int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    void clear() {
        while (pop_front()) {
            // pop_front handles deletion and adjustment
        }
    }

    void push_back(int value) {
        if (size_ >= max_capacity && max_capacity > 0) throw std::runtime_error("List has reached its maximum capacity");

        int_node* new_node = new int_node(value);
        if (tail == nullptr) { // Empty list
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        ++size_;
    }

    void push_front(int value) {        // o(n)
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = this->head;
        new_node->prev = nullptr;
        if (this->head == nullptr)
            this->tail = new_node;
        else
        this->head->prev = new_node;
        this->head = new_node;
        ++size_;
    }

    unsigned int size() const {
        return size_;
    }

    unsigned int capacity() const {
        return max_capacity;
    }

    double percent_occupied() const {
        if (max_capacity == 0) return 0.0; // Infinite capacity or undefined
        return (static_cast<double>(size_) / max_capacity) * 100.0;
    }
};

#endif // __LINKED_LIST_IFRN__
