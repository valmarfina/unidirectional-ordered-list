#include "SinglyLinkedOrderedList.h"

int main()
{
  SinglyLinkedOrderedList list;
  list.insert(1);
  list.insert(3);
  list.insert(2);
  list.insert(2);
  list.insert(2);
  list.insert(2);
  list.insert(0);
  list.insert(4);
  std::cout << list;
  list.deleteItem(3);
  std::cout << list;
  list.deleteItem(5);
  std::cout << list;
  if (list.searchItem(5))
  {
    std::cout << "Yes\n";
  }
  else
  {
    std::cout << "No\n";
  }
  if (list.searchItem(4))
  {
    std::cout << "Yes\n";
  }
  else
  {
    std::cout << "No\n";
  }
  SinglyLinkedOrderedList list2;
  list2.insert(-2);
  list2.insert(-1);
  list2.insert(1);
  list2.insert(2);
  list2.insert(3);
  list2.insert(7);
  list2.insert(9);

  //обьединение эл-тов
  std::cout << "\n-----------------------------------\n" << "List = " << list;
  std::cout << "List2 = " << list2;
  list.mergeLists(list2);
  list.mergeLists(list2);
  list2.mergeLists(list);
  list.mergeLists(list2);
  std::cout << "Merging...\n";
  std::cout << "List = " << list;
  std::cout << "List2 = " << list2;
  std::cout << "-----------------------------------\n";
  list2.insert(-3);
  list2.insert(-2);
  list2.insert(0);
  list2.insert(2);
  list2.insert(3);
  list2.insert(5);
  list2.insert(7);
  list2.insert(9);
  list2.insert(10);

  //пересечение эл-тов
  std::cout << "\n-----------------------------------\n" << "List = " << list;
  std::cout << "List2 = " << list2;
  std::cout << "Getting common...\n";
  std::cout << "ListResult = " << list.getCommonElements(list2);
  std::cout << "List = " << list;
  std::cout << "List2 = " << list2;
  std::cout << "-----------------------------------\n";

  //-
  std::cout << "\n-----------------------------------\n" << "List = " << list;   //-
  std::cout << "List2 = " << list2;
  list.subtractLists(list2);
  std::cout << "Subtracting...\n";
  std::cout << "List = " << list;
  std::cout << "List2 = " << list2;
  std::cout << "-----------------------------------\n";

  SinglyLinkedOrderedList list3;
  list3.insert(1);
  std::cout << "\n-----------------------------------\n" << "List = " << list;
  std::cout << "List3 = " << list3;
  std::cout << "Getting common...\n";
  try
  {
    std::cout << "ListResult = " << list3.getCommonElements(list);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
  }
  std::cout << "List = " << list;
  std::cout << "List3 = " << list3;
  std::cout << "-----------------------------------\n";

  return 0;
}
