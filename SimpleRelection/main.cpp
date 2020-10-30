#include <iostream>
#include "runtimeobject.h"
using namespace std;

class MyStudent : public MyObject
{
public:
    virtual RuntimeObject* runtimeObject() const
    {
        return (RuntimeObject*)&classMyStudent;
    }
    static const RuntimeObject classMyStudent;
};

const RuntimeObject MyStudent::classMyStudent
{
    "MyStudent",
    sizeof(MyStudent),
    (RuntimeObject*)&MyObject::classMyObject
};


int main()
{
    MyObject* pMyObject = new MyStudent;

    if(pMyObject->isKindOf(RUNTIME_OBJECT(MyStudent)))
    {
        MyStudent* pMyStudent = (MyStudent*)pMyObject;
        cout << " a student! \n";
        delete pMyStudent;
    }
    else
    {
        cout << "not a student! \n";
        delete pMyObject;
    }

    return 0;
}
