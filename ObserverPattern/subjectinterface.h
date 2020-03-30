#ifndef SUBJECTINTERFACE_H
#define SUBJECTINTERFACE_H

#include "observerinterface.h"

class ObserverInterface;

class SubjectInterface {
public:
    virtual void attach(std::shared_ptr<ObserverInterface> o) = 0;
    virtual void detach(std::shared_ptr<ObserverInterface> o) = 0;
    virtual void notify() = 0;
    virtual size_t observers_count() = 0;
    virtual ~SubjectInterface();
};

using SubjectInterfaceShPtr = std::shared_ptr<SubjectInterface> ;

#endif // SUBJECTINTERFACE_H
