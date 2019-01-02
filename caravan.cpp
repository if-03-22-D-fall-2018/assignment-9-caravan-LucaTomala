/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdlib.h>
#include "caravan.h"
#include "general.h"

#define COUNT_CARAVANS 5

struct CaravanImplementation
{
  int length;
  PackAnimal animal;
  struct CaravanImplementation* next;
};

Caravan head = (Caravan)malloc(sizeof(struct CaravanImplementation));

Caravan new_caravan()
{
    head->length = 0;
    head->animal = 0;
    head->next = 0;
    return head;
}

int get_length(Caravan caravan)
{
  return head->length;
}

void delete_caravan(Caravan caravan)
{
  Caravan current = head;
  while (current!=0)
  {
    if (caravan == head)
    {
      sfree(head);
      return;
    }
    else if (caravan == current->next)
    {
      current->next = caravan->next;
      sfree(caravan);
      return;
    }
    current = current->next;
  }
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
    if(animal != 0 && get_caravan(animal) == 0)
    {
        caravan->animal = animal;
        caravan->length++;
    }
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (caravan != 0) {
    caravan->length--;
    caravan->animal = 0;
  }
}

int get_caravan_load(Caravan caravan)
{
  return 0;
}

void unload(Caravan caravan)
{

}

int get_caravan_speed(Caravan caravan)
{
  return 0;
}

void optimize_load(Caravan caravan)
{

}
