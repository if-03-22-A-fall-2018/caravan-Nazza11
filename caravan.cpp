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
 #include "caravan.h"
 #include "general.h"
 #include <stdlib.h>

 typedef struct _node{
   PackAnimal pack_animal;
   struct _node* next;
 }Node;

 struct CaravanImplementation{
   Node* head;
 };

 Caravan new_caravan()
 {
   Caravan caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
   caravan->head = 0;
   return caravan;
 }

 int get_length(Caravan caravan)
 {
   int count=0;
   Node* currentNode=caravan->head;

   while(currentNode!=0)
   {
     count++;
     currentNode=currentNode->next;
   }
   return count;
 }

 void delete_caravan(Caravan caravan)
 {
   Node* head=caravan->head;

   while(caravan->head!=0)
   {
     head=caravan->head;
     caravan->head=head->next;
     sfree(head);
   }

   sfree(caravan);
 }

 void add_pack_animal(Caravan caravan, PackAnimal animal)
 {
   if((animal == 0) || (get_caravan(animal) == caravan)){
     return;
   }

   if(get_caravan(animal) != 0){
     remove_pack_animal(get_caravan(animal), animal);
   }

   add_to_caravan(animal, caravan);
   Node* node= (Node*)malloc(sizeof(Node));
   node->pack_animal = animal;
   node->next = caravan->head;
   caravan->head = node;

 }

 void remove_pack_animal(Caravan caravan, PackAnimal animal)
 {
      
 }

 int get_caravan_load(Caravan caravan)
 {
   int length = get_length(caravan);
   int load_count = 0;

   Node* currentNode = caravan->head;

   for(int i = 0; i < length; i++){
     load_count += get_load(currentNode->pack_animal);
     currentNode = currentNode->next;
   }

   return load_count;
 }

 void unload(Caravan caravan)
 {
   int length = get_length(caravan);

   Node* currentNode = caravan->head;

   for(int i = 0; i < length; i++){
     unload(currentNode->pack_animal);
     currentNode = currentNode->next;
   }

 }

 int get_caravan_speed(Caravan caravan)
 {
   return 0;
 }
