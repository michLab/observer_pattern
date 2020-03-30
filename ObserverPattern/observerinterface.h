#ifndef OBSERVERINTREFACE_H
#define OBSERVERINTREFACE_H

#include <memory>
#include "subjectinterface.h"

class SubjectInterface;

class ObserverInterface {
public:
    virtual void update() = 0;
    virtual uint count() = 0;
    virtual void register_in_subject(std::shared_ptr<SubjectInterface> s) = 0;
    virtual void unregister_from_subject(std::shared_ptr<SubjectInterface> s) = 0;
    virtual ~ObserverInterface();
};

using ObserverInterfaceShPtr = std::shared_ptr<ObserverInterface>;

#endif // OBSERVERINTREFACE_H
