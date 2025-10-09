/*
USE CASE EXAMPLE BELOW :

seven(times(five())); //  must return 35
four(plus(nine()));   //  must return 13
eight(minus(three()));  //  must return 5
six(divided_by(two())); //  must return 3

*/

#include <vector>

auto zero(std::vector<int> tuple){
  if(tuple[0] == 1){
     return 0 + tuple[1];
  }else if(tuple[0] == 2){
     return 0 - tuple[1];
  }else if(tuple[0] == 3){
     return 0 * tuple[1];
  }else if(tuple[0] == 4){
  }
  
  return 0;
}

auto one(std::vector<int> tuple){
  if(tuple[0] == 1){
     return 1 + tuple[1];
  }else if(tuple[0] == 2){
     return 1 - tuple[1];
  }else if(tuple[0] == 3){
     return 1 * tuple[1];
  }else if(tuple[0] == 4){
     return 1 / tuple[1];
  }
  return 0;
}

auto two(std::vector<int> tuple){
   if(tuple[0] == 1){
     return 2 + tuple[1];
  }else if(tuple[0] == 2){
     return 2 - tuple[1];
  }else if(tuple[0] == 3){
     return 2 * tuple[1];
  }else if(tuple[0] == 4){
     return 2 / tuple[1];
  }
  return 0;
}

auto three(std::vector<int> tuple){
  if(tuple[0] == 1){
     return 3 + tuple[1];
  }else if(tuple[0] == 2){
     return 3 - tuple[1];
  }else if(tuple[0] == 3){
     return 3 * tuple[1];
  }else if(tuple[0] == 4){
     return 3 / tuple[1];
  }
  return 0;
}

auto four(std::vector<int> tuple){
   if(tuple[0] == 1){
     return 4 + tuple[1];
  }else if(tuple[0] == 2){
     return 4 - tuple[1];
  }else if(tuple[0] == 3){
     return 4 * tuple[1];
  }else if(tuple[0] == 4){
     return 4 / tuple[1];
  }
  return 0;
}

auto five(std::vector<int> tuple){
  if(tuple[0] == 1){
     return 5 + tuple[1];
  }else if(tuple[0] == 2){
     return 5 - tuple[1];
  }else if(tuple[0] == 3){
     return 5 * tuple[1];
  }else if(tuple[0] == 4){
     return 5 / tuple[1];
  }
  return 0;
}

auto six(std::vector<int> tuple){
  if(tuple[0] == 1){
     return 6 + tuple[1];
  }else if(tuple[0] == 2){
     return 6 - tuple[1];
  }else if(tuple[0] == 3){
     return 6 * tuple[1];
  }else if(tuple[0] == 4){
     return 6 / tuple[1];
  }
  return 0;
}

auto seven(std::vector<int> tuple){
   if(tuple[0] == 1){
     return 7 + tuple[1];
  }else if(tuple[0] == 2){
     return 7 - tuple[1];
  }else if(tuple[0] == 3){
     return 7 * tuple[1];
  }else if(tuple[0] == 4){
     return 7 / tuple[1];
  }
  return 0;
}

auto eight(std::vector<int> tuple){
  if(tuple[0] == 1){
     return 8 + tuple[1];
  }else if(tuple[0] == 2){
     return 8 - tuple[1];
  }else if(tuple[0] == 3){
     return 8 * tuple[1];
  }else if(tuple[0] == 4){
     return 8 / tuple[1];
  }
  return 0;
}

auto nine(std::vector<int> tuple){
  if(tuple[0] == 1){
     return 9 + tuple[1];
  }else if(tuple[0] == 2){
     return 9 - tuple[1];
  }else if(tuple[0] == 3){
     return 9 * tuple[1];
  }else if(tuple[0] == 4){
     return 9 / tuple[1];
  }
  return 0;
}

auto zero(){return 0;}
auto one(){return 1;}
auto two(){return 2;}
auto three(){return 3;}
auto four(){return 4;}
auto five(){return 5;}
auto six(){return 6;}
auto seven(){return 7;}
auto eight(){return 8;}
auto nine(){return 9;}


std::vector<int> plus(int num){
  std::vector<int> number = {1,num};
  return number;
}

std::vector<int> minus(int num){
  std::vector<int> number = {2,num};
  return number;
}

std::vector<int> times(int num){
  std::vector<int> number = {3,num};
  return number;
}

std::vector<int> divided_by(int num){
  std::vector<int> number = {4,num};
  return number;
}
