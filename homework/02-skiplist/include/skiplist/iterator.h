#ifndef __ITERATOR_H
#define __ITERATOR_H

// Forward declaration
template <class K, class V> class Node;

/**
 * Skiplist iterator
 */
template<class Key, class Value>
class Iterator {
private:
  Node<Key, Value> *pCurrent;

public:
  Iterator(Node<Key,Value> *p) : pCurrent(p) {}
  virtual ~Iterator() {}

  virtual Key& key() = 0;
  virtual Value& value() = 0;

  virtual Iterator& operator=(const Iterator &) = 0;

  virtual bool operator==(const Iterator &) = 0;
  virtual bool operator!=(const Iterator &) = 0;

  virtual Iterator& operator++() = 0;
  virtual Iterator& operator++(int) = 0;

  virtual Value& operator*() = 0;
  virtual Value* operator->() = 0;
};

#endif // __ITERATOR_H
