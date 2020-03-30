#ifndef SIMPLESUBJECT_H
#define SIMPLESUBJECT_H

#include "ObserverPattern/subjectinterface.h"
#include <mutex>
#include <vector>

class SimpleSubject : public SubjectInterface {
public:
    virtual void attach(ObserverInterfaceShPtr o) override;
    virtual void detach(ObserverInterfaceShPtr o) override;
    virtual void notify() override;
    virtual size_t observers_count() override;
    virtual ~SimpleSubject() override;
private:
    std::mutex mutex_;
    std::vector<ObserverInterfaceShPtr> observers_;
};

#endif // SIMPLESUBJECT_H
