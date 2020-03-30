#include "simpleobserver.h"
#include <iostream>
#include <memory>

uint SimpleObserver::count_ = 0;

SimpleObserver::SimpleObserver() {
    std::unique_lock<std::mutex> lock(mutex_);
    ++count_;
}
uint SimpleObserver::count() {
    std::unique_lock<std::mutex> lock(mutex_);
    return count_;
}
void SimpleObserver::update() {
    std::unique_lock<std::mutex> lock(mutex_);
    std::cout << "[Observer] Update";
}

void SimpleObserver::register_in_subject(SubjectInterfaceShPtr s) {
    std::unique_lock<std::mutex> lock(mutex_);
    std::cout << "[Observer] Send register request to Subject" << std::endl;
    s->attach(shared_from_this());
}

void SimpleObserver::unregister_from_subject(SubjectInterfaceShPtr s) {
    std::unique_lock<std::mutex> lock(mutex_);
    std::cout << "[Observer] Send unregister request to Subject" << std::endl;
    s->detach(shared_from_this());
}

SimpleObserver::~SimpleObserver() {

}
