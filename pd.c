#include <string.h>
#include <stdlib.h>
#include <unistd.h>


//data example
const char *s =
"/+1-541-754-3010erd 156 Alphand_St. ard<J Steeve>\n"
" 133, Green, Rd. <E Kustur> NY-56423 ;+1-541-914-3010\n"
"+1-541-984-3012 <P Reed> /PO Box 530; Pollocksville, NC-28573\n"
" :+1-321-512-2222 <Paul Dive> Sequoia Alley PQ-67209\n"
"+1-741-984-3090 <Peter Reedgrave> _Chicago\n"
" :+1-921-333-2222 <Anna Stevens> Haramburu_Street AA-67209\n"
"+1-111-544-8973 <Peter Pan> LA\n"
" +1-921-512-2222 <Wilfrid Stevens> Wild Street AA-67209\n"
"aere<M Abrar> LA ?+1-121-544-8974 \n"
" <R Steell> Quora Street AB-47209 +1-481-512-2222\n"
"<Arthur Clarke> San Antonio $+1-121-504-8974 TT-45120\n"
" <Ray Chandler> Teliman Pk. !+1-681-512-2222! AB-47209,\n"
"<Sophia Loren> +1-421-674-8974 Bern TP-46017\n"
" <Peter O'Brien> High Street +1-908-512-2222; CC-47209\n"
"<Anastasia> +48-421-674-8974 Via Quirinal Roma\n"
" <P Salinger> Main Street, +1-098-512-2222, Denver\n"
"<Abrar> *+19-421-674-8974 Chateau des Fosses Strasbourg F-68000\n"
" <Bernard Deltheil> +1-498-512-2222; Mount Av.  Eldorado\n"
"+1-099-500-8000 <Peter Crush> Labrador Bd.\n"
"+1-931-512-4855 <William Saurin> Bison Street CQ-23071\n"
"<P Salinge> Main Street, +1-098-512-2222, Denve\n"
"<P Salinge> Main Street, +1-098-512-2222, Denve\n"
"/+5-541-754-3010 156 Alphandria_Street. <Jr Part>\n 1333, Green, Road <F Fulgur> NW-46423 ;+6-541-914-3010!\n"
"+5-541-984-3012 <Peter Reeves> /PO Box 5300; Albertville, SC-28573\n :+5-321-512-2222 <Paulo Divino> Boulder Alley ZQ-87209\n"
"+3-741-984-3090 <F Flanaghan> _Chicago Av.\n :+3-921-333-2222 <Roland Scorsini> Bellevue_Street DA-67209\n"
"+8-111-544-8973 <Laurence Pantow> SA\n +8-921-512-2222 <Raymond Stevenson> Joly Street EE-67209\n"
"<John Freeland> Mantow ?+2-121-544-8974 \n <Robert Mitch> Eleonore Street QB-87209 +2-481-512-2222?\n"
"<Arthur Paternos> San Antonio $+7-121-504-8974 TT-45121\n <Ray Charles> Stevenson Pk. !+7-681-512-2222! CB-47209,\n"
"<JP Gorce> +9-421-674-8974 New-Bern TP-16017\n <P McDon> Revolution Street +2-908-512-2222; PP-47209\n"
"<Elizabeth Corber> +8-421-674-8974 Via Papa Roma\n <C Saborn> Main Street, +15-098-512-2222, Boulder\n"
"<Colin Marshall> *+9-421-674-8974 Edinburgh UK\n <Bernard Povit> +3-498-512-2222; Hill Av.  Cameron\n"
"+12-099-500-8000 <Pete Highman> Ontario Bd.\n +8-931-512-4855 <W Mount> Oxford Street CQ-23071\n"
"<Donald Drinkaw> Moon Street, +3-098-512-2222, Peterville\n";
//

const char *not_found = "Error => Not found: ";
const char *many = "Error => Too many people: ";

const char *name  = "Name => ";
const char *phone = "Phone => ";
const char *addr  = "Address => ";

char *phone_directory(const char *p,const char *num){

  int total_num = 0;
  int n_size = strlen(num);

  int line_size;

  char *rest;
  const char *cp = p;
  const char *n_offset;
  const char *num_offset;

  while(*p){
     const char *offset = p;

     p = strchr(p,43) + 1;

     if(total_num == 2){
       rest = malloc(27 + n_size);
       memcpy(rest,many,26);
       memcpy(rest + 26,num,n_size + 1);
       return rest;
     }

     if(!memcmp(p,num,n_size)){
       total_num++;
       n_offset = p;
       num_offset = offset;
       line_size = strchr(offset,10) - offset;
     }

     p = strchr(p,10) + 1;
  }

  if(total_num == 0){
    rest = malloc(21 + n_size);
    memcpy(rest,not_found,20);
    memcpy(rest + 20,num,n_size + 1);
    return rest;
  }

  line_size += 34 + n_size;
  rest = malloc(line_size + 1);

  //Phone => num, Name => name, Address => adress
  int offset = 0;

  memcpy(rest + offset,phone,9);
  offset += 9;

  memcpy(rest + offset,num,n_size);
  offset += n_size;

  *(rest + offset++) = 44;
  *(rest + offset++) = 32;

  memcpy(rest + offset,name,8);
  offset += 8;

  const char *name_ = strchr(num_offset,60);
  const char *name_ub = strchr(name_,62);  //name up bound

  int size = name_ub - (name_ + 1);

  memcpy(rest + offset,name_ + 1,size);
  offset += size;

  *(rest + offset++) = 44;
  *(rest + offset++) = 32;

  memcpy(rest + offset,addr,11);
  offset += 11;

  //name up bound
  while(*name_ub != 32 && *name_ub != 10){
    name_ub++;
  }
  name_ub -= 1;
  //

  //name low bound
  char flag = 0;
  while(name_ != cp){
    if(*name_ == 32 || *name_ == 10){
      flag = 1;
      break;
    }
    name_--;
  }
  (flag == 1) ? (name_ += 1) : 0;
  //

  //phone up bound
  const char *n_cp = n_offset + n_size;
  while(*n_cp != 32 && *n_cp != 10){n_cp++;}
  n_cp -= 1;
  //

  //phone low bound
  flag = 0;
  while(n_offset != cp){
    if(*n_offset == 32 || *n_offset == 10){
      flag = 1;
      break;
    }
    n_offset--;
  }

  (flag == 1) ? (n_offset += 1) : 0;
  //

  while(*num_offset != 10){
    while(*num_offset == 32){ num_offset++; }

    if(num_offset == name_){
      num_offset = name_ub + 1;
      continue;
    }

    if(num_offset == n_offset){
      num_offset = n_cp + 1;
      continue;
    }

    while(*num_offset != 32 && *num_offset != 10){
       (!(
         (*num_offset >= 65 && *num_offset <= 90)  ||
         (*num_offset >= 97 && *num_offset <= 122) ||
         (*num_offset >= 48 && *num_offset <= 57)  ||
         (*num_offset == 45)
       )) ? 0 : (*(rest + offset++) = *num_offset);
       num_offset++;
    }

    *(rest + offset++) = 32;
  }

  *(rest + offset - 1) = 0;
  return rest;
}
