#include "LinkNode.h"

template<class K, class V>
LinkNode<K, V>::LinkNode(K key, V value) {
  this->key = key;
  this->value = value;
  this->next = NULL;
  this->prev = NULL;
}

template<class K, class V>
LinkNode<K, V>::LinkNode() {
  this->next = NULL;
  this->prev = NULL;
}

template<class K, class V>
void LinkNode<K, V>::link(LinkNode<K, V>* node) {
  if (this == node) {
    return;
  }

  if (node == NULL) {
      this->next = NULL;
      return;
  }

  this->next = node;
  node->prev = this;
}

template<class K, class V>
void LinkNode<K, V>::unlink() {

  if (this->prev && this->next) {
    this->prev->next = this->next;
    this->next->prev = this->prev;
  }
  else if (!this->prev && this->next) {
    this->next->prev = NULL;
  }
  else if (this->prev && !this->next) {
    this->prev->next = NULL;
  }

  this->next = NULL;
  this->prev = NULL;
}