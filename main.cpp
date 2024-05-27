//Tyler Evans 
//practice for mutexes in c++
//mutal exclusion two threads
//do not choose two piecs of data.
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
std::mutex functionMutex;

//this is the first action working
void firstAction(string words){
    functionMutex.lock();
    std::cout << words << " is functioning" << std::endl;
    this_thread::sleep_for(chrono::seconds(2));
    std::cout << words << " is done \n";
    functionMutex.unlock();
}

int main(void) {
    std::cout << "Mutex \n" << std::endl;
    //create the threads
    std::thread t1(firstAction, "one");
    std::thread t2(firstAction, "two");
    //join to the main resources
    t1.join();
    t2.join();
    return 0;
}
