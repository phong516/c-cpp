#include <list>
#include <algorithm>
#include <iostream>
#include "print.hpp"

using namespace std;

class AddValue{
    private:
        int theValue;
    public:
        AddValue(int v): theValue(v){}

        void operator() (int& elem) const{
            elem += theValue;
        }
};

int main(){
    list<int> coll;

    for (int i = 0; i < 9; i++){
        coll.push_back(i);
    }

    PRINT_ELEMENT(coll, "initialized:       ");

    for_each(coll.begin(), coll.end(),
            AddValue(10));

    PRINT_ELEMENT(coll, "after adding 10:       ");

    for_each(coll.begin(), coll.end(),
            AddValue(*coll.begin()));
    PRINT_ELEMENT(coll, "after adding first element: ");
}