#include <iostream>
#include <thread>
#include <future>

using namespace std;

void compute(std::promise<int> prom, int x, int y) {
    cout<<"Compute threads goes to sleep, before it sets a value in promise"<<endl;
    this_thread::sleep_for(chrono::seconds(5));
    
    cout<<"Setting value in promise\n";
    prom.set_value(x + y);
}

int main() {
    std::promise<int> prom;
    std::future<int> result = prom.get_future();

    cout<<"Starting a thread, which sets value on promise\n";
    std::thread t(compute, std::move(prom), 10, 20);

    cout<<"Main threads calls get on future\n";
    int var = result.get();
    cout<<"Main threads gets value from future:"<<var<<"\n";

    t.join();

    return 0;
}