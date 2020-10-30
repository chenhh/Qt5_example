#ifndef RUNTIMEOBJECT_H
#define RUNTIMEOBJECT_H
#include <QString>
#include <cstddef>

struct RuntimeObject
{
    // 從現在的class往BaseClass找類別是否有相符者
    bool isDerivedFrom(const RuntimeObject* pBaseClass) const;

    QString m_className; // 類的名字
    size_t     m_classSize; // 類的大小
    RuntimeObject* m_pBaseClass; // 其基類中 RuntimeObject 結構的地址
};


class MyObject
{
public:
    virtual RuntimeObject* runtimeObject() const;
    virtual ~MyObject();
    // 如果現在的class是繼承自pClass, 則回傳true, 否則為false
    bool isKindOf(const RuntimeObject* pClass) const;

public:
    static const RuntimeObject classMyObject; // 標識類的靜態成員
};
inline MyObject::~MyObject() { }

// 下面是一系列的巨集定義
// RUNTIME_OBJECT 巨集用來取得 class_name 類中 RuntimeObject 結構的地址
#define RUNTIME_OBJECT(class_name) ((RuntimeObject*)&class_name::class##class_name)


#endif // RUNTIMEOBJECT_H
