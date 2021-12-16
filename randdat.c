/*
    randdat generate a list of random birthdays
    Copyright (C) 2021  Sergey Tokarev
....
    This file is part of randdat.
    randdat is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    randdat is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with randdat.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../make_rand_in_range_function/make_rand_in_range_function.h"
#include "randdat.h"

MAKE_RAND_IN_RANGE_FUNCTION(int)

enum randdat_datelims {
  minday = 1,
  maxday = 31,
  maxdayfeb = 28,
  maxdayfebleap = 29,
  minmonth = 1,
  maxmonth = 12,
  minyear = 1900,
  maxyear = 2000
};

enum randdat_month_name {
JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, NOV, DES
};

struct randdat_date {
  int day;
  int month;
  int year;
};

static int isyearleap(const int year)
{
  if (year % 4 || year % 100 || year % 400) {
    return 0;
  } else {
    return 1;
  }
}

void randdat_print(int count)
{
  int i;
  srand(time(NULL));
  for (i = 0; i < count; i++) {
    struct randdat_date date;
    char done = 0;
    while (!done) {
      date.day = int_rand_in_range(minday, maxday);
      date.month = int_rand_in_range(minmonth, maxmonth);
      date.year = int_rand_in_range(minyear, maxyear);
      if (date.month == FEB) {
        if (isyearleap(date.year)) {
          if (date.day <= maxdayfebleap)
            done = 1;
        } else {
          if (date.day <= maxdayfeb)
            done = 1;
        }
      } else {
        done = 1;
      }
    }
    printf("%02d.%02d.%d\n", date.day, date.month, date.year);
  }
}