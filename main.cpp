#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <mutex>

#include "ObserverPattern/observerinterface.h"
#include "ObserverPattern/subjectinterface.h"
#include "SimpleObserverPattern/simpleobserver.h"
#include "SimpleObserverPattern/simplesubject.h"

using namespace std;

int main()
{
    cout << "Observer Pattern" << endl;
    ObserverInterfaceShPtr observer_1 = std::make_shared<SimpleObserver>();
    ObserverInterfaceShPtr observer_2 = std::make_shared<SimpleObserver>();
    SubjectInterfaceShPtr subject = std::make_shared<SimpleSubject>();
//    subject->attach(observer_1);
//    subject->attach(observer_2);
    observer_1->register_in_subject(subject);
    subject->observers_count();
    observer_1->unregister_from_subject(subject);
    subject->observers_count();
    return 0;
}















