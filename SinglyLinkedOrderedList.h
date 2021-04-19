#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

#include <iostream>

class SinglyLinkedOrderedList
{
public:
  SinglyLinkedOrderedList();
  SinglyLinkedOrderedList(const SinglyLinkedOrderedList&);
  SinglyLinkedOrderedList(SinglyLinkedOrderedList&&) noexcept;
  SinglyLinkedOrderedList& operator=(const SinglyLinkedOrderedList&);
  SinglyLinkedOrderedList& operator=(SinglyLinkedOrderedList&&) noexcept;
  ~SinglyLinkedOrderedList();

  bool searchItem(int);
  bool insert(int);
  bool deleteItem(int);

  void mergeLists(SinglyLinkedOrderedList&);
  void subtractLists(const SinglyLinkedOrderedList&);
  SinglyLinkedOrderedList getCommonElements(const SinglyLinkedOrderedList&);
private:
  struct Node
  {
      int item_;
      Node* next_;
      Node(int item, Node* next = nullptr):
          item_(item),
          next_(next)
      {}
  };
  Node* head_;

  Node* searchNode(int);
  void swap(SinglyLinkedOrderedList&);
  friend std::ostream& operator<<(std::ostream& out, const SinglyLinkedOrderedList&);
};
#endif
