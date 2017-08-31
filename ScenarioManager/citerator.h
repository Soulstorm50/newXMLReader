#ifndef CITERATOR_H
#define CITERATOR_H

#include <Nfsm.h>
#include <vector>

using std::vector;
using namespace Nfsm;

template <typename T>
class CIterator
{
public:
    explicit CIterator(vector<T> &collection);
    bool nextItem();
    const T& first()const;
    const T& curretnItem()const;
    T& currentItem();
    void reset();

private:
    vector<T>& m_collection;
    size_t m_collectionIndex;
};

//------------------------------------------------------------------------------
template <typename T>
CIterator<T>::CIterator(vector<T> &collection) :
     m_collection(collection)
    ,m_collectionIndex(START_INDEX_OF_COLLECTION)
//------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------
template <typename T>
bool CIterator<T>::nextItem()
//------------------------------------------------------------------------------
{
    bool result = true;

    if((m_collection.size() - 1) == m_collectionIndex)
    {
        m_collectionIndex = -1;
        result = false;
    }
    else
    {
        ++m_collectionIndex;
    }

    return std::move(result);
}

template<typename T>
const T &CIterator<T>::first() const
{
    return m_collection[0];
}

template<typename T>
const T &CIterator<T>::curretnItem() const
{
    return m_collection[m_collectionIndex];
}

template<typename T>
T &CIterator<T>::currentItem()
{
    return m_collection[m_collectionIndex];
}

template<typename T>
void CIterator<T>::reset()
{
    m_collectionIndex = -1;
}
#endif // CITERATOR_H
