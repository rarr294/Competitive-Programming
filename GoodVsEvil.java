/*

Description

Middle Earth is about to go to war. The forces of good will have many battles with the forces of evil. Different races will certainly be involved. 
Each race has a certain worth when battling against others. 

On the side of good we have the following races, with their associated worth:

Hobbits: 1
Men: 2
Elves: 3
Dwarves: 3
Eagles: 4
Wizards: 10

On the side of evil we have:

Orcs: 1
Men: 2
Wargs: 2
Goblins: 2
Uruk Hai: 3
Trolls: 5
Wizards: 10

Although weather, location, supplies and valor play a part in any battle, if you add up the worth of the side of good and compare it with the worth of the side of evil, 
the side with the larger worth will tend to win.

Thus, given the count of each of the races on the side of good, followed by the count of each of the races on the side of evil, determine which side wins.
Input:

The function will be given two parameters. Each parameter will be a string of multiple integers separated by a single space. 
Each string will contain the count of each race on the side of good and evil.

The first parameter will contain the count of each race on the side of good in the following order:

Hobbits, Men, Elves, Dwarves, Eagles, Wizards.

The second parameter will contain the count of each race on the side of evil in the following order:

Orcs, Men, Wargs, Goblins, Uruk Hai, Trolls, Wizards.

All values are non-negative integers. The resulting sum of the worth for each side will not exceed the limit of a 32-bit integer.
Output:

Return "Battle Result: Good triumphs over Evil" if good wins
Return "Battle Result: Evil eradicates all trace of Good" if evil wins 
Return "Battle Result: No victor on this battle field" if it ends in a tie.

*/


class GoodVsEvil {
  public static String battle(String goodAmounts, String evilAmounts) {
    goodAmounts += " ";
    evilAmounts += " ";
    int g_size = goodAmounts.length();
    int e_size = evilAmounts.length();
    int good_sum = 0;
    int evil_sum = 0;

    int monster_counter = 1;
    for(int a = 0;a < g_size;a++){
       String number = "";
       while(goodAmounts.charAt(a) != ' '){
         number += goodAmounts.charAt(a);
         a++;
       }
       if(monster_counter == 1){
          good_sum += Integer.parseInt(number);
       }else if(monster_counter == 2){
          good_sum += (Integer.parseInt(number) * 2);
       }else if(monster_counter == 3 || monster_counter == 4){
          good_sum += (Integer.parseInt(number) * 3);
       }else if(monster_counter == 5){
          good_sum += (Integer.parseInt(number) * 4);
       }else if(monster_counter == 6){
          good_sum += (Integer.parseInt(number) * 10);
       }
       monster_counter++;
    }
    monster_counter = 1;
    for(int a = 0;a < e_size;a++){
      String number = "";
      while(evilAmounts.charAt(a) != ' '){
         number += evilAmounts.charAt(a);
         a++;
      }
      if(monster_counter == 1){
         evil_sum += Integer.parseInt(number);
      }else if(monster_counter == 2 || monster_counter == 3 || monster_counter == 4){
         evil_sum += (Integer.parseInt(number) * 2);
      }else if(monster_counter == 5){
         evil_sum += (Integer.parseInt(number) * 3);
      }else if(monster_counter == 6){
         evil_sum += (Integer.parseInt(number) * 5);
      }else if(monster_counter == 7){
         evil_sum += (Integer.parseInt(number) * 10);
      }
      monster_counter++;
    }
    if(good_sum > evil_sum){
      return "Battle Result: Good triumphs over Evil";
    }else if(evil_sum > good_sum){
      return "Battle Result: Evil eradicates all trace of Good";
    }
    return "Battle Result: No victor on this battle field";
  }
}
