//============================================================================
// Name        : Future.cpp
// Author      : Harshita
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<future>
#include<thread>
#include<iostream>
#include<vector>
#include<cstdio>
#include<chrono>

using namespace std;

int add(vector<future<int>> &FutureObj) {
    int a = FutureObj[0].get();
    int b = FutureObj[1].get();
    return a+b;
}
int main() {
    int k = 2;
    vector<promise<int>> PromiseObj(k);
    vector<future<int>> FutureObj(k);

    FutureObj[0] = PromiseObj[0].get_future();
    FutureObj[1] = PromiseObj[1].get_future();

    future<int> res = std::async(std::launch::async, add, std::ref(FutureObj));
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    PromiseObj[0].set_value(28);
    PromiseObj[1].set_value(17);

    int output = res.get();
    cout << "Sum = "<< output << endl;

    return 0;
}
