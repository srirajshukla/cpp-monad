#include <iostream>
#include <fmt/format.h>

using namespace std;

int main(){
    fmt::print("hello, {} {}", 32, "world");
    int x = 30;

    fmt::print("{}", x);

    cout << "hello";
}