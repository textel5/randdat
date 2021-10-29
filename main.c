/*
    randdat generate a list of random birthdays
    Copyright (C) 2021  Sergey Tokarev
....
    This file is part of randdat.
    randdat is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    listint is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with listint.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <stdio.h>

#include "../strtodigit/strtodigit.h"
#include "randdat.h"

int main(int argc, char **argv)
{
  int value;
  if (argc < 2) {
    fprintf(stderr, "main.c:error: enter a value\n");
    return 1;
  }
  value = strtodigit(argv[1]);
  randdat_print(value);
  return 0;
}