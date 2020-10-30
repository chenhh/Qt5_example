#include "runtimeobject.h"

bool RuntimeObject::isDerivedFrom(const RuntimeObject* pBaseClass) const
{
    const RuntimeObject* pClassThis = this;
    while(pClassThis)
    {
        // 判斷標識類的 RuntimeObject 的首地址是否相同
        if(pClassThis == pBaseClass)
        {
            return true;
        }
        // 如果地址不相同時，繼續往parent上去
        pClassThis = pClassThis->m_pBaseClass;
    }
    // 查詢到了繼承結構的頂層，沒有一個匹配
    return false;
}

const struct RuntimeObject MyObject::classMyObject
{
    "MyObject",
    sizeof(MyObject),
    nullptr
};

RuntimeObject* MyObject::runtimeObject() const
{
    return RUNTIME_OBJECT(MyObject);
}

bool MyObject::isKindOf(const RuntimeObject* pClass) const
{
    RuntimeObject* pClassThis = runtimeObject();
    return pClassThis->isDerivedFrom(pClass);
}
