// Linked_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iomanip>
#include <iostream>
#include <memory>

template <typename D>
struct Node {
    Node() :value{} {};
    Node(D _value) : value{ _value }, next_node{ nullptr }{};
    D value{};
    std::shared_ptr<Node<D>> next_node{ nullptr };
};

template <typename D>
class Linked_List {
    
public:
    int Size{0};
    size_t count{ 1 };
    std::shared_ptr<Node<D>> head_ptr{ nullptr };
    Linked_List() = default;
    Linked_List(std::shared_ptr<Node<D>> new_node) :head_ptr(new_node), Size{ 1 }, count{ 1 } {
    }
    
    bool insert(std::shared_ptr<Node<D>>& head, const D& value) {
        
        static int num{ 1 };
        if (!head) {
            head = std::make_shared<Node<D>>(value);
            ++Size;
            return true;
        }
        insert(head->next_node, value);
        return false;
    }

    bool insert(int& index, const D& value) {
        std::shared_ptr<Node<D>> new_node = std::make_shared<Node<D>>(value);
        if (index == 1) {
            new_node->next_node = head_ptr;
            head_ptr = new_node;
            Size++;
            return true;
        }
        if ((index == Size) & (index != 1)) {
            std::shared_ptr<Node<D>> temp (find(head_ptr, index));
            temp->next_node = new_node;
            Size++;
            return true;
        }

        std::shared_ptr<Node<D>> temp (find(head_ptr, index));
        std::shared_ptr<Node<D>> previous(find(head_ptr, index-1));
       
        previous->next_node = new_node;
        new_node->next_node = temp;
        Size++;
        return true;
    }
    bool remove(size_t index) {
        std::shared_ptr<Node<D>> temp = find(head_ptr, index);
        if (temp) {
            if (Size != 1) {
                if (index == Size) {
                    std::shared_ptr<Node<D>> temp1 = find(head_ptr, index - 1);
                    temp1->next_node = nullptr;
                    temp = nullptr;
                    --Size;
                    return true;
                }
                if (index == 1) {
                    std::shared_ptr<Node<D>> temp2 = find(head_ptr, index + 1);
                    head_ptr = temp2;
                    temp = nullptr;
                    --Size;
                    return true;
                }
                
                std::shared_ptr<Node<D>> temp1 = find(head_ptr, index - 1);
                std::shared_ptr<Node<D>> temp2 = find(head_ptr, index + 1);
                temp1->next_node = temp2;
                temp = nullptr;
                --Size;
                return true;
            }
            else {
                --Size;
                temp = nullptr;
            }
                
        }
        std::cout << " The element you want to remove does not exist" << std::endl;
        return false;
    }

    std::shared_ptr<Node<D>>& find(std::shared_ptr<Node<D>>& head, const int index) {
        if (index <= Size && index > 0) {
            if (head != nullptr && count == index) {

                reset();
                std::shared_ptr<Node<D>> temp;
                temp = head;
                return temp;
            }
            if (!head) {
                std::cout << "|" << std::setw(100) << std::setfill('-') << "|" << std::endl;
                std::cout << "Element at index does not exist" << std::endl;
                std::cout << "|" << std::setw(100) << std::setfill('-') << "|" << std::endl;
                reset();
            }

            ++count;
            find(head->next_node, index);
        }
        else if(index > Size){
            std::shared_ptr<Node<D>> temp = nullptr;
            return temp;
        }
           
    }
    void reset() {
        count = 1;
    }

    //int Length(std::shared_ptr<Node<D>>& head) {
    //    static int num{ 0 };
    //    if (head) {
    //        num++;
    //        Length(head->next_node);
    //    }
    //    return num;
    //}
    ~Linked_List() {};
};

int main()
{
    std::cout << "|" << std::setw(100) << std::setfill('-') << "|" << std::endl;
    std::cout <<"Emmanuel's C++ version of a Singly Linked List. Improvement: elements accesible by index" << std::endl;
    int num1{ 1 };
    int num3{ 3 };
    int num5{ 5 };
    
    std::shared_ptr<Node<int>> Head = std::make_shared<Node<int>>(3);
    Linked_List<int> list(Head);
    std::cout << std::boolalpha;
    std::cout << "|" << std::setw(100) << std::setfill('-') << "|" << std::endl;
    list.insert(Head, 2);//index, value/head, value
    list.insert(Head, 4);
    list.insert(num1, 5);
    list.insert(num3, 6);
    list.insert(num5, 7);
    /*list.remove(1);
    list.remove(5);
    list.remove(2);*/

    std::shared_ptr<Node<int>> temp;
    std::shared_ptr<Node<int>> temp2;
    std::shared_ptr<Node<int>> temp3;
    std::shared_ptr<Node<int>> temp4;
    std::shared_ptr<Node<int>> tempend;
  
    temp = list.head_ptr->next_node;
    temp2 = temp->next_node;
    temp3 = temp2->next_node;
    temp4 = temp3->next_node;
    tempend = temp4->next_node;
    
    std::cout << "|" << std::setw(100) << std::setfill('-') << "|" << std::endl;
    std::cout << "This List is " << list.Size <<" elements long" << std::endl;
 
    std::cout << "|"<<std::setw(100) << std::setfill('-') << "|" << std::endl;
    std::cout << "Current List:" << std::endl;
    std::cout << list.head_ptr->value << std::endl;
    std::cout << temp->value << std::endl;
    std::cout << temp2->value << std::endl;
    std::cout << temp3->value << std::endl;
    std::cout << temp4->value << std::endl;
    std::cout << tempend->value << std::endl;
    std::cout << "|" << std::setw(100) << std::setfill('-') << "|" << std::endl;
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
