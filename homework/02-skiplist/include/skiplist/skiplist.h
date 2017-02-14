#ifndef __SKIPLIST_H
#define __SKIPLIST_H
#include <functional>

// Forward declaration
template <class K, class V> class Node;

// Forward declaration
template <class K, class V> class Iterator;

/**
 * Skiplist interface
 */
template<class Key, class Value, class Compare = std::less<Key>>
class SkipList {
public:

  /**
   * Creates new empty skiplist
   *
   * @param maxHeight maximum tower height in the skiplist
   */
  SkipList(int maxHeight);

  /**
   * Destructor
   */
  virtual ~SkipList();

  /**
   * Assign new value for the key. If a such key already has
   * assosiation then old value returns, otherwise nullptr
   *
   * @param key key to be assigned with value
   * @param value to be added
   * @return old value for the given key or nullptr
   */
  virtual Value Put(const Key& key, const Value& value) = 0;

  /**
   * Put value only if there is no assosiation with key in
   * the list and returns nullptr
   *
   * If there is an established assosiation with the key already
   * method doesn't nothing and returns existing value
   *
   * @param key key to be assigned with value
   * @param value to be added
   * @return existing value for the given key or nullptr
   */
  virtual Value PutIfAbsent(const Key& key, const Value& value) = 0;

  /**
   * Returns value assigned for the given key or nullptr
   * if there is no established assosiation with the given key
   *
   * @param key to find
   * @return value assosiated with given key or nullptr
   */
  virtual Value Get(const Key& key) const = 0;

  /**
   * Remove given key from the skpiplist and returns value
   * it has or nullptr in case if key wasn't assosiated with
   * any value
   *
   * @param key to be added
   * @return value for the removed key or nullptr
   */
  virtual Value Delete(const Key& key) = 0;

  /**
   * Same as Get
   */
  virtual const Value& operator[](const Key& key)  = 0;

  /**
   * Return iterator onto very first key in the skiplist
   */
  virtual Iterator<Key, Value> begin() const = 0;

  /**
   * Returns iterator to the first key that is greater or equals to
   * the given key
   */
  virtual Iterator<Key, Value> find(const Key &min) const = 0;

  /**
   * Returns iterator on the skiplist tail
   */
  virtual Iterator<Key, Value> end() const = 0;
};

#endif // __SKIPLIST_H
