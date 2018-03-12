#include <iostream>
#include "Checkbook.h"
// Function definitions of the class template
using namespace std;

template<class Datatype>
void Checkbook<Datatype>::setBalance(float amount)
{
  balance = amount;
}
template<class Datatype>
bool Checkbook<Datatype>::writeCheck(Datatype amount) //
{
  if(amount > balance)
    return false;
  balance -= amount;
  lastCheck = amount;
  return true;
}
template<class Datatype>
void Checkbook<Datatype>::deposit(float amount)
{
  balance += amount;
  lastDeposit = amount;
}
template<class Datatype>
float Checkbook<Datatype>::getBalance()
{
  return balance;
}
template<class Datatype>
Datatype Checkbook<Datatype>::getLastCheck() //
{
  return lastCheck;
}
template<class Datatype>
float Checkbook<Datatype>::getLastDeposit()
{
  return lastDeposit;
}
