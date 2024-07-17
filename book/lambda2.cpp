#include <iostream>

int main(){
    int id = 0;
    auto f = [id] mutable{
        printf("id: %d\n", id);
        ++id;
    };
    id = 43;
    f();
    f();
    f();
}