#include <iostream>
#include <list>
int main()
{
  std::list<int> l(10,1);
  l.insert(l.begin(), 5);
  for(auto i : l)
  {
    std::cout << i << " ";
  }
  return 0;
}
