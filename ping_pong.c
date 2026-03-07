/*

While Mrs Pong is away visiting her sister, Mr Pong has foolishly set up a ping pong table in his lounge room, 
and invites his neighbour Mr Ping over for a friendly ping pong session.

When Mr Ping hits the ping pong ball, the ping pong ball goes ping.

When Mr Pong hits the ping pong ball, the ping pong ball goes pong.

Unfortunately, not every hit goes where it was meant to...

Sometimes the ping pong ball hits the net, or bounces off a wall, or it ricochets off Mrs Pong's rather expensive porcelain collection, 
a light fitting, or various pieces of lounge furniture, before finally coming to rest on the floor. When that happens there are all kinds of bad noises.

Example

A typical rally may sound like this:

ping-pong-ping-pong-ping-pong-ping-pong-dong-tang-bing-tink-donk-donk-donk

Mr Ping served
here were several good returns
Mr Pong hits a bad shot which broke the handle off his wife's 2nd favourite teacup. Oops.

Task :

Who scored the most points?
Input

The sounds of one or more rallies.
Output

The name of the winning player: ping or pong
Notes

To score a point the same player must both serve and win the rally.
Whoever picks the ball off the floor will serve next. It's random.
A bad noise is anything other than ping or pong.
A bad noise means whoever hit the ball last hit a bad shot.
For some unknown reason all noises are 4 lowercase characters, and delimited by -
If scores are even, then the winner is the player who did NOT hit the final bad shot.
There are no double hits.
The final rally always ends with the ball on the floor.
All input is valid.

*/


#include <string.h>
#include <stdio.h>

char cmp(char *s1,char *s2){
  for(char a = 0;a <= 3;a++){
     if(*(s1 + a) != *(s2 + a)){
       return 0;
     }
  }
  return 1;
}

char isPing(char *s){
  char flag = (
   *s == 'p' &&
   *(s + 1) == 'i' &&
   *(s + 2) == 'n' &&
   *(s + 3) == 'g'
  ) ? 1 : 0;

  return flag;
}

char notPingOrPong(char *s){
  char ping_flag = (
   s[0] == 'p' &&
   s[1] == 'i' &&
   s[2] == 'n' &&
   s[3] == 'g'
  ) ? 1 : 0;

  char pong_flag = (
   s[0] == 'p' &&
   s[1] == 'o' &&
   s[2] == 'n' &&
   s[3] == 'g'
  ) ? 1 : 0;

  return (ping_flag == 0 && pong_flag == 0) ? 0 : 1;
}

const char *ping_pong(char *sounds){
  int ping = 0;
  int pong = 0;
  int size = strlen(sounds);

  int a = 0;
  char *lost = sounds;
  int total_nonBadNoise = 1;
  while(a < size){
    char *serve = sounds + a;

    if(notPingOrPong(serve) == 0){
      a += 5;
      continue;
    }

    while(a += 5,notPingOrPong(sounds + a)){
      total_nonBadNoise++;
    }

    lost = sounds + a - 5;
    if(cmp(serve,sounds + a - 5) == 0){
      if(isPing(serve) == 1){
        ping++;
        goto gohere;
      }
      pong++;
    }
    gohere:
    a += 5;
  }
  
  if(total_nonBadNoise == 1){
     if(isPing(sounds)){
       return "pong";
     }
     return "ping";
  }else if(ping == pong){
    if(isPing(lost)){
      return "pong";
    }
    return "ping";
  }else if(ping > pong){
    return "ping";
  }
  return "pong";
}
