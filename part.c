#include "componentPart.h"
#include <stdio.h>
#include <string.h>

int computePrice(ComponentPart compart[], int index)
{
  if (compart[index].numComponent == 0)
    return compart[index].price;

  int price = 0;
  for (int i = 0; i < compart[index].numComponent; i++)
    price += computePrice(compart, compart[index].componentPartList[i]);
  return price;
}

void printPrice(int N, ComponentPart list[])
{
  for (int i = 0; i < N; i++) {
    printf("%s %d\n", list[i].name, list[i].price);
  }  
}

void sortPrice(int N, ComponentPart list[])
{
  for (int i = N - 2; i >= 0; i--)
    for (int j = 0; j <= i; j++) 
      if (strcmp(list[j].name, list[j + 1].name) > 0) {
	ComponentPart temp = list[j];
	list[j] = list[j + 1];
	list[j + 1] = temp;
      }
}

void findPrice(int N, ComponentPart list[])
{
  for (int i = 0; i < N; i++)
    list[i].price = computePrice(list, i);

  sortPrice(N, list);
  printPrice(N, list);
}

