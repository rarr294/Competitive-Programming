/*

Greed is a dice game played with five six-sided dice. 
Your mission,should you choose to accept it, 
is to score a throw according to these rules.
You will always be given an array with five six-sided dice values.

Three 1's => 1000 points
Three 6's =>  600 points
Three 5's =>  500 points
Three 4's =>  400 points
Three 3's =>  300 points
Three 2's =>  200 points
One   1   =>  100 points
One   5   =>   50 point
Each of 5 dice can only be counted once in each roll. 
For example, a given "5" can only count as part of a triplet(contributing to the 500 points) 
or as a single 50 points, but not both in the same roll.

Example scoring

5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)
*/

int score(const int dice[5]){
  char bucket[7] = {0};

  //filling the bucket
  for(int a = 0;a <= 4;a++){
    bucket[dice[a]]++;
  }
  //

  //counting
  int score = 0;
  for(int a = 1;a <= 6;a++){
    if(bucket[a] == 3){
      score += (
        (a == 1) ? 1000 : (a * 100)
      );
    }else if(bucket[a] < 3){
      score += (
      (a == 1) ? (bucket[a] * 100) :
      ((a == 5) ? (bucket[a] * 50) : 0
      ));
    }else if(bucket[a] > 3){
      score += (
        (a == 1) ? 1000 : (a * 100)
      );
      bucket[a] -= 3;
      score += (
        (a == 1) ? (bucket[a] * 100) :
        ((a == 5) ? (bucket[a] * 50) : 0
      ));
    }
  }
  //
  return score;
}
