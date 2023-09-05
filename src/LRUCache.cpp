#include "LRUCache.h"
#include "LinkNode.h"


template<class K, class V>
LRUCache<K, V>::LRUCache(int capacity) {
  this->capacity = capacity;
  this->node_count = 0;
  this->dummy_head = new LinkNode<K, V>();
  this->link_head = dummy_head;
  this->link_tail = dummy_head;
}

template<class K, class V>
int LRUCache<K, V>:: get(K key) {
  if (!this->node_map.count(key)) return -1;
  move_node_to_tail(this->node_map[key]);
  return this->node_map[key]->value;
}

template<class K, class V>
void LRUCache<K, V>::put(K key, V value){
  if (this->node_map.count(key)) {
      this->node_map[key]->value = value;
      move_node_to_tail(this->node_map[key]);
  }
  else if (this->node_count < this->capacity) {
      move_node_to_tail(new LinkNode<K, V>(key, value));
      this->node_count++;
  }
  else {
      this->node_map.erase(this->link_head->key);
      this->link_head->key = key;
      this->link_head->value = value;
      move_node_to_tail(this->link_head);
  }
  this->node_map[key] = this->link_tail;
}

template<class K, class V>
void LRUCache<K, V>::move_node_to_tail(LinkNode<K, V>* node)
{
  if (node != this->link_tail) {
    node->unlink();
    this->link_tail->link(node);
    this->link_tail = node;
    this->link_tail->link(NULL);
  }

  this->link_head = this->dummy_head->next;
}