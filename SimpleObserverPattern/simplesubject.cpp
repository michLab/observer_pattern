#include "simplesubject.h"
#include <iostream>
#include <algorithm>

void SimpleSubject::attach(ObserverInterfaceShPtr o) {
    std::unique_lock<std::mutex> lock(mutex_);
    std::cout << "[Subject] Attach observer" << std::endl;
    observers_.push_back(o);
}

void SimpleSubject::detach(ObserverInterfaceShPtr o) {
    std::unique_lock<std::mutex> lock(mutex_);
    std::cout << "[Subject] Detach observer" << std::endl;
    auto end = std::remove_if(observers_.begin(), observers_.end(),
                              [&o](const ObserverInterfaceShPtr i) {return i == o;});
    observers_.erase(end, observers_.end());
}

void SimpleSubject::notify() {
    std::unique_lock<std::mutex> lock(mutex_);
    for (auto& o : observers_) {
        o->update();
        std::cout << "[Subject] Notify observer" << std::endl;
    }
}

size_t SimpleSubject::observers_count() {
    std::unique_lock<std::mutex> lock(mutex_);
    std::cout << "[Subject] Observers count: " << observers_.size() << std::endl;
    return observers_.size();
}

SimpleSubject::~SimpleSubject(){

}
