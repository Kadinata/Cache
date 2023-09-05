#ifndef __LRU_CACHE_H__
#define __LRU_CACHE_H__

#include <unordered_map>
#include "LinkNode.h"

/**
 * This class implements a least-recently-used (LRU) cache
 * using a combination of doubly-linked list and a hash map
 * to achieve O(1) time put and get operations.
 */
template<class K, class V>
class LRUCache {

private:
  int capacity;
  int node_count;
  LinkNode<K, V>* dummy_head;
  LinkNode<K, V>* link_head;
  LinkNode<K, V>* link_tail;
  std::unordered_map<K, LinkNode<K, V>*> node_map;

  void move_node_to_tail(LinkNode<K, V>* node);

public:
  LRUCache(int capacity);   /* Constructor to initialize the cache and set its capacity */
  int get(K key);           /* Retrieve an item from the cache based on the provided key */
  void put(K key, V value); /* Store an item into the cache */

};

#endif