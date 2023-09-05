#ifndef __LINK_NODE_H__
#define __LINK_NODE_H__

template<class K, class V>
class LinkNode
{
public:
  LinkNode(K key, V value);
  LinkNode();
  void link(LinkNode<K, V>* node);
  void unlink();

public:
  const K key = key;
  const V value = value;
  const LinkNode<K, V>* prev;
  const LinkNode<K, V>* next;
};

#endif
