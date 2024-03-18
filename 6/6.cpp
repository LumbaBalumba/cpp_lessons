#include <iostream>
#include <string>

template<class Key, class Value>
class Node
{
private:
    Node *left, *right;

public:
    Key key;
    Value value;

    Node(Key key = Key{}, Value value = Value{})
    {
        this->key = key;
        this->value = value;
        left = right = nullptr;
    }

    ~Node() noexcept
    {
        delete left;
        delete right;
    }

    Node *
    add(Key key, Value value)
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
    contains(Value value)
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
    find(Key key)
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

    [[deprecated]] void
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

    friend std::ostream &
    operator<<(std::ostream &out, const Node &node)
    {
        if (node.left) {
            out << *(node.left);
        }
        out << " {" << node.key << " : " << node.value << "} ";

        if (node.right) {
            out << *(node.right);
        }
        return out;
    }
};

template<class Key, class Value>
class Dict
{
private:
    Node<Key, Value> *node;

public:
    Dict()
    {
        node = nullptr;
    }

    ~Dict()
    {
        delete node;
    }

    Value &
    operator[](Key key)
    {
        if (empty()) {
            node = new Node(key, Value{});
            return node->value;
        }
        Node<Key, Value> *node = this->node->find(key);
        if (node == nullptr) {
            return this->node->add(key, Value{})->value;
        } else {
            return node->value;
        }
    }


    bool
    empty()
    {
        return node == nullptr;
    }


    friend std::ostream &
    operator<<(std::ostream &out, const Dict &dict)
    {
        return out << "{ " << *(dict.node) << " }";
    }
};


int
main(int argc, char *argv[])
{
    Dict<std::string, double> dict;
    dict["a"] = 5.0;
    dict["bdc"] = 3.0;
    dict["   "] = 1.0;
    std::cout << dict << std::endl;
    Dict<double, int> dict2;
    dict2[3.0] = 0;
    return 0;
}
