#include "../Vector/Vector.h"

#include "../Graph/Graph.h"

#include <string>

int main()
{
    utilities::Vector<int> my_vector(10);
    utilities::Vector<int> my_vector2(10);
    my_vector2 = my_vector;
    // Node<char> a('a');
    // Node<char> b('b');
    // Node<char> c('c');
    // Node<char> d('d');
    // Node<char> e('e');
    // Node<char> f('f');
    // Node<char> g('g');
    // Node<char> h('h');
    // Node<char> i('i');

    // a.AddNeighbor(&b);
    // a.AddNeighbor(&c);
    // b.AddNeighbor(&d);
    // b.AddNeighbor(&e);
    // c.AddNeighbor(&f);
    // c.AddNeighbor(&g);
    // d.AddNeighbor(&h);
    // e.AddNeighbor(&i);

    // Graph<char> graph;
    // graph.AddNode(&a);
    // graph.AddNode(&b);
    // graph.AddNode(&c);
    // graph.AddNode(&d);
    // graph.AddNode(&e);
    // graph.AddNode(&f);
    // graph.AddNode(&g);
    // graph.AddNode(&h);
    // graph.AddNode(&i);

    // for (auto &node : graph)
    // {
    //     node.Print();
    // }
    return 0;
}