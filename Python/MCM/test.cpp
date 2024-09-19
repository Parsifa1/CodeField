#include <bits/stdc++.h>
using namespace std;
struct Leaf {};
struct Node;
using Tree = variant<Leaf, Node*>;
using var_t = std::variant<int, long, double, std::string>;
struct Node {
    Tree left;
    Tree right;
};
template <class... Ts>
struct overload : Ts... {
    using Ts::operator()...;
};
// explicit deduction guide (not needed as of C++20)
template <class... Ts>
overload(Ts...) -> overload<Ts...>;

int num_leaves(Tree const& tree) {
    return visit(
        overload(
            [](Leaf const&) { return 1; },
            [](this auto const& self, Node* n) -> int {  //
                return visit(self, n->left) + visit(self, n->right);
            }
        ),
        tree
    );
}

int main() {
    Node n{Leaf{}, new Node{Leaf{}, Leaf{}}};
    cout << num_leaves(&n) << endl;
}
