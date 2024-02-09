#include <cstdlib>
#include <ctime>
#include <iostream>

class Node
{
private:
    Node *left, *right;

public:
    int key, value;

    Node(int key, int value)
    {
        this->value = value;
        left = right = nullptr;
    }

    ~Node() noexcept
    {
        delete left;
        delete right;
    }

    Node *
    add(int key, int value)
    {
        if (this->key > key) {
            if (left == nullptr) {
                left = new Node(key, value);
                return left;
            } else {
                return left->add(key, value);
            }
        } else if (this->key < key) {
            if (right == nullptr) {
                right = new Node(key, value);
                return right;
            } else {
                return right->add(key, value);
            }
        } else {
            this->value = value;
            return this;
        }
    }

    [[deprecated]] bool
    contains(int value)
    {
        if (this->value == value) {
            return true;
        } else if (this->value < value) {
            if (right == nullptr) {
                return false;
            } else {
                return right->contains(value);
            }
        } else {
            if (left == nullptr) {
                return false;
            } else {
                return left->contains(value);
            }
        }
    }

    Node *
    find(int key)
    {
        if (this->key == key) {
            return this;
        } else if (key > this->key) {
            if (right == nullptr) {
                return nullptr;
            } else {
                return right->find(key);
            }
        } else {
            if (left == nullptr) {
                return nullptr;
            } else {
                return left->find(key);
            }
        }
    }

    void
    print()
    {
        if (left != nullptr) {
            left->print();
        }
        std::cout << value << " ";
        if (right != nullptr) {
            right->print();
        }
    }
};


class Dict
{
private:
    Node *node;

public:
    Dict()
    {
        node = nullptr;
    }

    ~Dict()
    {
        delete node;
    }

    int &
    operator[](int key)
    {
        if (empty()) {
            node = new Node(key, 0);
            return node->value;
        }
        Node *node = this->node->find(key);
        if (node == nullptr) {
            return this->node->add(key, 0)->value;
        } else {
            return node->value;
        }
    }


    bool
    empty()
    {
        return node == nullptr;
    }
};


int
main(int argc, char *argv[])
{
    Dict dict;
    dict[0] = 1;
    dict[1] = 2;
    dict[2] = 3;
    dict[3] = 4;
    dict[4] = 5;
    return 0;
}
