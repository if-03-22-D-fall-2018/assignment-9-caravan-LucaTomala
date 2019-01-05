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

typedef struct NodeImplementation* Node;

struct NodeImplementation
{
    PackAnimal animal;
    struct NodeImplementation* next;
};

struct CaravanImplementation{
    int length;
    Node head = (Node)malloc(sizeof(struct NodeImplementation));
};

Caravan new_caravan()
{
  Caravan caravan =(Caravan)malloc(sizeof(struct CaravanImplementation));
  caravan->length = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  Node current = caravan->head;
  while(current != 0)
  {
        delete_animal(current->animal);
        current = current->next;
  }
  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal == 0) return;
  Node current = caravan->head;
  Node new_node = (Node)malloc(sizeof(struct NodeImplementation));
  new_node->animal = animal;
  new_node->next = 0;

  if (caravan->head == 0) {
    caravan->head = new_node;
    add_to_caravan(animal, caravan);
    caravan->length++;
  }

  else{
    while (current->next != 0 && animal != current->animal) {
      current = current->next;
    }
    if (animal == current->animal) return;
      current->next = new_node;
      add_to_caravan(animal, caravan);
      caravan->length++;
}
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal != 0)
  {
    Node current = caravan->head;
    Node prev;
    if (current != 0 && current->animal == animal) {
      caravan->head = current->next;
      sfree(current);
      remove_from_caravan(animal, caravan);
      caravan->length--;
      return;
    }

    while (current != 0 && current->animal != animal ) {
      prev = current;
      current=current->next;
    }

    if (current==0) return;
      prev->next = current->next;
      sfree(current);
      remove_from_caravan(animal, caravan);
      caravan->length --;
  }
}

int get_caravan_load(Caravan caravan)
{
  Node current = caravan->head;
  int load = 0;
  while (current!=0)
  {
    load = load + get_load(current->animal);
    current = current->next;
  }
  return load;
}

void unload(Caravan caravan)
{
  Node current = caravan->head;
  while (current!= 0)
  {
    unload(current->animal);
    current = current->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  return 0;
}

void optimize_load(Caravan caravan)
{

}
