// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <memory>

template <class V, class K>
struct Node {
    Node() = default;
    Node(K _key, V _value) : key{ _key }, value{ _value } {};
    K key{};
    V value{};
    std::shared_ptr<Node<V, K>> left_ptr{ nullptr };
    std::shared_ptr<Node<V, K>> right_ptr{ nullptr };
    ~Node() {};
};

template <class V, class K>
class Binary_Search_Tree {
public:
    Binary_Search_Tree() = default;
    ~Binary_Search_Tree() {};
    Binary_Search_Tree(std::shared_ptr<Node<V, K>>& new_node) : root_node{ new_node } {
    }
    std::shared_ptr<Node<V, K>> root_node;
    bool add(std::shared_ptr<Node<V, K>>& new_node, K key, V value) {
        if (!new_node) 
            new_node = std::make_shared<Node<V, K>>(key, value);
        
        else {
            if (key < new_node->key) 
                add(new_node->left_ptr, key, value);
            
            else if (key > new_node->key) 
                add(new_node->right_ptr, key, value);
        }
        return true;
    }

    template <class V, class K>
    bool find(std::shared_ptr<Node<V , K>>& root, K key_param) {
 
        if (!root) 
            std::cout << "Key does not exist"; 
            
            else {
                
                if (key_param == root->key) {
                    std::cout << "Found, the value at " << key_param << " is " << root->value << std::endl;
                    return true;
                }
                
                else if (key_param != root->key) {
                    if (key_param < root->key)
                        find(root->left_ptr, key_param);
                    else
                        find(root->right_ptr, key_param);
                }
            }
        return false;
    }

    void remove(std::shared_ptr<Node<V, K>>& root, K key_param) {
        if (!root)
            std::cout << "Key does not exist";

        else {

            if (key_param == root->key) {
                root = nullptr;
            }

            else if (key_param != root->key) {
                if (key_param < root->key)
                    remove(root->left_ptr, key_param);
                else
                    remove(root->right_ptr, key_param);
            }
        }
    }
};


int main()
{
    
    std::shared_ptr<Node<int, int>> n = std::make_shared<Node<int,int>>(4,3) ;
    Binary_Search_Tree<int, int> b(n);
    std::cout << std::boolalpha;
    b.add(n, 2, 4);
    b.add(n, 5, 7);
    b.add(n, 8, 9);
    b.find(n, 8);
    b.find(n, 2);
    b.remove(n, 2);
    b.find(n, 2);
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
