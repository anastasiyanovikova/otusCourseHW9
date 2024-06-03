#include <iostream>
#include "async.h"

int main(int argc, char const *argv[])
{
  long N = 3;
  if(argc > 1)
    N = atoi (argv [1]);
  
  auto context = connect(N);
  std::string firstCom = "vfdkl";
  receive(firstCom.c_str(), firstCom.size(), context);
  firstCom = "1c";
  receive(firstCom.c_str(), firstCom.size(), context);
  firstCom = "2d";
  receive(firstCom.c_str(), firstCom.size(), context);
  firstCom = "3frdes";
  receive(firstCom.c_str(), firstCom.size(), context);
  firstCom = "4vfd";
  receive(firstCom.c_str(), firstCom.size(), context);
  firstCom = "5bvfd";
  receive(firstCom.c_str(), firstCom.size(), context);
  disconnect(context);
  
  return 0;
}
