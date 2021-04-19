#include "SinglyLinkedOrderedList.h"

SinglyLinkedOrderedList::SinglyLinkedOrderedList():
    head_(nullptr)
{}

SinglyLinkedOrderedList::SinglyLinkedOrderedList(const SinglyLinkedOrderedList& src)
{
  if (src.head_ != nullptr)
  {
    head_ = new Node(src.head_->item_);
    Node* current1 = head_;
    Node* current2 = src.head_->next_;
    while (current2 != nullptr)
    {
      current1->next_ = new Node(current2->item_);
      current1 = current1->next_;
      current2 = current2->next_;
    }
  }
  else
  {
    head_ = nullptr;
  }
}

SinglyLinkedOrderedList::SinglyLinkedOrderedList(SinglyLinkedOrderedList&& src) noexcept:
    head_(src.head_)
{
  src.head_ = nullptr;
}

SinglyLinkedOrderedList& SinglyLinkedOrderedList::operator=(const SinglyLinkedOrderedList& src)
{
  if (this == &src)
  {
    return *this;
  }
  SinglyLinkedOrderedList temp(src);
  swap(temp);
  return *this;
}

SinglyLinkedOrderedList& SinglyLinkedOrderedList::operator=(SinglyLinkedOrderedList&& crs) noexcept
{
  swap(crs);
  return *this;
}

SinglyLinkedOrderedList::~SinglyLinkedOrderedList()
{
  Node* current = nullptr;
  Node* next = head_;
  while (next != nullptr)
  {
    current = next;
    next = next->next_;
    delete current;
  }
}


SinglyLinkedOrderedList::Node* SinglyLinkedOrderedList::searchNode(int item)
{
  Node* x = head_;
  while (x != nullptr && x->item_ != item)
  {
    x = x->next_;
  }
  return x;
}


bool SinglyLinkedOrderedList::searchItem(int item)
{
  return (searchNode(item) != nullptr);
}


bool SinglyLinkedOrderedList::insert(int item)
{
  Node* current = nullptr;
  Node* next = head_;
  while (next != nullptr && next->item_ <= item)
  {
    current = next;
    next = next->next_;
  }
  if (current == nullptr)
  {
    Node* x = new Node(item);
    x->next_ = head_;
    head_ = x;
    return true;
  }
  else
  {
    if (current->item_ == item)
    {
      return false;
    }
    Node* x = new Node(item);
    current->next_ = x;
    x->next_ = next;
    return true;
  }
}


bool SinglyLinkedOrderedList::deleteItem(int item)
{
  Node* current = nullptr;
  Node* next = head_;
  while (next != nullptr && next->item_ != item)
  {
    current = next;
    next = next->next_;
  }
  if (next != nullptr)
  {
    if (current == nullptr)
    {
      head_ = next->next_;
    }
    else
    {
      current->next_ = next->next_;
    }
    delete next;
    return true;
  }
  return false;
}

//обьединение эл-тов
void SinglyLinkedOrderedList::mergeLists(SinglyLinkedOrderedList& list)
{
  if (this == &list)
  {
    throw std::invalid_argument("Trying to merge a list with itself!");
  }
  if (list.head_ == nullptr)
  {
    return;
  }
  if (head_ == nullptr)
  {
    swap(list);
    return;
  }
  Node* current = nullptr;
  Node* next = head_;
  Node* current2 = nullptr;
  Node* next2 = list.head_;
  while (next2 != nullptr)
  {
    if (next->item_ == next2->item_)
    {
      current2 = next2;
      next2 = next2->next_;
      delete current2;
    }
    else
    {
      if (next2->item_ < next->item_)
      {
        current2 = next2;
        next2 = next2->next_;
        if (current != nullptr)
        {
          current->next_ = current2;
          current2->next_ = next;
        }
        else
        {
          head_ = current2;
          current = head_;
          current2->next_ = next;
        }
      }
      else
      {
        current = next;
        next = next->next_;
        if (next == nullptr)
        {
          current->next_ = next2;
          next2 = nullptr;
        }
      }
    }
  }
  list.head_ = nullptr;
}

//-
void SinglyLinkedOrderedList::subtractLists(const SinglyLinkedOrderedList& list)
{
  if (this == &list)
  {
    throw std::invalid_argument("Trying to subtract a list with itself");
  }
  if ((list.head_ == nullptr) || (head_ == nullptr))
  {
    return;
  }
  Node* current = nullptr;
  Node* next = head_;
  Node* current2 = list.head_;
  while (current2 != nullptr)
  {
    if (next->item_ == current2->item_)
    {
      if (current != nullptr)
      {
        current->next_ = next->next_;
        delete next;
        next = current->next_;
        if (next == nullptr)
        {
          current2 = nullptr;
        }
        else
        {
          current2 = current2->next_;
        }
      }
      else
      {
        head_ = next->next_;
        delete next;
        next = head_;
        if (next == nullptr)
        {
          current2 = nullptr;
        }
        else //если не конец
        {
          current2 = current2->next_;
        }
      }
    }
    else
    {
      if (current2->item_ < next->item_)
      {
        current2 = current2->next_;
      }
      else
      {
        current = next;
        next = next->next_;
        if (next == nullptr)
        {
          current2 = nullptr;
        }
      }
    }
  }
}

//пересечение эл-тов
SinglyLinkedOrderedList SinglyLinkedOrderedList::getCommonElements(const SinglyLinkedOrderedList& list)
{
  if(this == &list)
  {
    throw std::invalid_argument("Trying to use a list with itself!");
  }
  if (list.head_ == nullptr)
  {
    return *this;
  }
  if (head_ == nullptr)
  {
    return list;
  }
  SinglyLinkedOrderedList result;
  Node* currentResult = nullptr;
  Node* next = head_;
  Node* current2 = list.head_;
  while (current2 != nullptr)
  {
    if (next->item_ == current2->item_)
    {
      if (currentResult != nullptr)
      {
        currentResult->next_ = new Node(next->item_);
        currentResult = currentResult->next_;
        next = next->next_;
        if (next == nullptr)
        {
          current2 = nullptr;
        }
        else //если не конец
        {
          current2 = current2->next_;
        }
      }
      else
      {
        result.head_ = new Node(next->item_);
        currentResult = result.head_;
        next = next->next_;
        if (next == nullptr)
        {
          current2 = nullptr;
        }
        else
        {
          current2 = current2->next_;
        }
      }
    }
    else
    {
      if (current2->item_ < next->item_)
      {
        current2 = current2->next_;
      }
      else
      {
        next = next->next_;
        if (next == nullptr)
        {
          current2 = nullptr;
        }
      }
    }
  }
  return result;
}


std::ostream& operator<<(std::ostream& out, const SinglyLinkedOrderedList& src)
{
  SinglyLinkedOrderedList::Node* current = src.head_;
  while (current != nullptr)
  {
    out << current->item_ << ' ';
    current = current->next_;
  }
  out << std::endl;
  return (out);
}


void SinglyLinkedOrderedList::swap(SinglyLinkedOrderedList& src)
{
  Node* temp = this->head_;
  this->head_ = src.head_;
  src.head_ = temp;
}
