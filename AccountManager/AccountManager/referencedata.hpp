#pragma once

#include <QList>

class ReferenceData
{
public:
    // Constructor
    ReferenceData()
    {
        _name = "";
        _childrenList.clear();
    }
    ReferenceData(const QString& pName)
    {
        _name = pName;
        _childrenList.clear();
    }

    // Getter
    const QString& get_name() const
    { return _name; }
    const QList<ReferenceData>& get_children() const
    { return _childrenList; }

    // Setter
    bool add_children(const QString& pChildrenName)
    {
        // Search if children not already exist
        QListIterator<ReferenceData> i(_childrenList);
        for(int i=0; i<_childrenList.size(); i++)
        {
            if(_childrenList[i]._name == pChildrenName)
            { return false; }
        }
        return true;
    }

private:
    QString _name;
    QList<ReferenceData> _childrenList;
};
