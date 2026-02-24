/*
Pete likes to bake some cakes. He has some recipes and ingredients.
Unfortunately he is not good in maths. Can you help him to find out,
how many cakes he could bake considering his recipes?

Write a function cakes(), which takes the recipe (unordered_map<string, int>) and 
the available ingredients (also an unordered_map<string, int>) and 
returns the maximum number of cakes Pete can bake (integer). 

For simplicity there are no units for the amounts (e.g. 1 lb of flour or 200 g of sugar are simply 1 or 200). 
Ingredients that are not present in the objects, can be considered as 0.

Examples:

// must return 2
cakes({{"flour", 500}, {"sugar", 200}, {"eggs", 1}}, {{"flour", 1200}, {"sugar", 1200}, {"eggs", 5}, {"milk", 200}});
// must return 0
cakes({{"apples", 3}, {"flour", 300}, {"sugar", 150}, {"milk", 100}, {"oil", 100}}, {{"sugar", 500}, {"flour", 2000}, {"milk", 2000}});
*/


#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

using Ingredients = std::unordered_map<std::string, int>;

int cakes(const Ingredients& recipe, const Ingredients& available){
  vector<string> keys;

  for(auto &r : recipe){
    for(auto &a : available){
       if(r.first == a.first){
         keys.push_back(r.first);
         break;
       }
    }
  }

  int r_size = recipe.size();
  int k_size = keys.size();

  if(r_size != k_size){
     return 0;
  }

  int value = available.at(keys[0]) / recipe.at(keys[0]);

  for(int a = 0;a < k_size;a++){
    if(available.at(keys[a]) < recipe.at(keys[a])){
       return 0;
    }

    if(
      (available.at(keys[a]) / recipe.at(keys[a]))
       < 
      value){
      value = available.at(keys[a]) / recipe.at(keys[a]);
    }
  }
  return value;
}
