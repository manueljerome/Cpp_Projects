// Insertion_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <memory>

class I_sort {
    friend std::ostream& operator<<(std::ostream& os, std::shared_ptr<std::vector<int>>& v); 
 
       
    
public:
    std::shared_ptr<std::vector<int>> sort(std::shared_ptr<std::vector<int>>& source) {
        
        for (size_t i{ 0 }; i < (source->size()); i++) {
            if (i != 0) {
                if (source->at(i) < source->at(i - 1)) {
                    for (auto j{ i }; j > 0; j--) {
                        if (source->at(j) < source->at(j - 1)) {
                            int temp = source->at(j - 1);
                            source->at(j - 1) = source->at(j);
                            source->at(j) = temp;
                        }
                    }
                }
            }
        }
        std::shared_ptr<std::vector<int>> temp(source);
        return  source;
    }
    
};
std::ostream& operator<<(std::ostream& os, std::shared_ptr<std::vector<int>>& v) {
    std::cout << "[";
    for (auto i : *v) {
        os <<" " << i;
    }
    std::cout << "]";
    return os;
}

int main()
{
    std::vector<int> r {1, 2, 4, 3, 6, 7};
    std::shared_ptr<std::vector<int>> test = std::make_shared<std::vector<int>> (r);
    std::shared_ptr<std::vector<int>> receiver;
    I_sort s;
    receiver = s.sort(test);
    //std::cout << "Working" <<std::endl;
    std::cout << receiver;
   // std::cout << "Working" << std::endl;
}


