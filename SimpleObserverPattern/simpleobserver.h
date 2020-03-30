#ifndef SIMPLEOBSERVER_H
#define SIMPLEOBSERVER_H

#include "ObserverPattern/observerinterface.h"
#include <mutex>

class SimpleObserver : public ObserverInterface,
        public std::enable_shared_from_this<SimpleObserver> {
public:
    SimpleObserver();
    uint count() override;
    void update() override;
    void register_in_subject(SubjectInterfaceShPtr s) override;
    void unregister_from_subject(SubjectInterfaceShPtr s) override;
    ~SimpleObserver() override;

private:
    std::mutex mutex_;
    static uint count_;
};

#endif // SIMPLEOBSERVER_H
