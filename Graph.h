#ifndef GRAPH_H_
#define GRAPH_H_

#include "Vector/Vector.h"
#include <set>

template <typename T>
struct Node
{
    T data_;
    Vector<Node<T> *> neighbors_;

    Node(T data) : data_(data) {}
    Node(T data, std::initializer_list<Node<T> *> neighbors) : data_(data), neighbors_(neighbors)
    {
        for (auto neighbor : neighbors)
        {
            neighbor->neighbors_.PushBack(this);
        }
    }
    Node(T data, Vector<Node<T> *> neighbors) : data_(data), neighbors_(neighbors)
    {
        for (auto neighbor : neighbors)
        {
            neighbor->neighbors_.PushBack(this);
        }
    }

    void AddNeighbor(Node<T> *neighbor)
    {
        neighbors_.PushBack(neighbor);
        neighbor->neighbors_.PushBack(this);
    }

    void Print()
    {
        std::cout << data_ << std::endl;
    }
};

template <typename T, typename NodeType = Node<T>>
class GraphDFSIterator
{
public:
    GraphDFSIterator(NodeType *node) : node_(node)
    {
        if (node_ == nullptr)
        {
            return;
        }

        for (auto neighbor : node_->neighbors_)
        {
            stack_.PushBack(neighbor);
        }
        visited_.insert(node_);
    }

    GraphDFSIterator &operator++()
    {
        if (stack_.Size() == 0)
        {
            node_ = nullptr;
            return *this;
        }
        NodeType *head = stack_.Back();
        stack_.Pop();
        visited_.insert(head);
        for (auto neighbor : head->neighbors_)
        {
            if (visited_.find(neighbor) == visited_.end())
            {
                stack_.PushBack(neighbor);
            }
        }
        node_ = head;
        return *this;
    }

    GraphDFSIterator operator++(int)
    {
        GraphDFSIterator tmp = *this;
        ++*this;
        return tmp;
    }

    bool operator!=(const GraphDFSIterator &other) const
    {
        return node_ != other.node_;
    }

    bool operator==(const GraphDFSIterator &other) const
    {
        return node_ == other.node_;
    }

    NodeType &operator*()
    {
        return *node_;
    }

private:
    NodeType *node_;
    std::set<NodeType *> visited_;
    Vector<NodeType *> stack_;
};

template <typename T>
class Graph
{
public:
    using iterator = GraphDFSIterator<T>;

    Graph() {}

    void AddNode(Node<T> *node)
    {
        nodes_.PushBack(node);
    }

    iterator begin()
    {
        return iterator(nodes_[0]);
    }

    iterator end()
    {
        return iterator(nullptr);
    }

    void Print()
    {
        for (auto node : nodes_)
        {
            node->Print();
        }
    }

    ~Graph() = default;

private:
    Vector<Node<T> *> nodes_;
};

#endif // GRAPH_H_