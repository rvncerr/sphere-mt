#ifndef __NODE_H
#define __NODE_H

/**
 * Skiplist Node
 */
template<class Key, class Value>
class Node {
private:
  Key *pKey;
  Value *pValue;
  Node *pNext;

public:
  Node() {}
  virtual ~Node() {}

  /**
   * Return key assosiated with the given node
   */
  virtual Key& key() const = 0;

  /**
   * Returns value assosiated with the given node
   */
  virtual Value& value() const = 0;

  /**
   * Returns next node in the sequence
   */
  virtual Node & next() const = 0;
};

#endif // __NODE_H
