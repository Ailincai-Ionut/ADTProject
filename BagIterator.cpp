#include "BagIterator.h"
#include "Bag.h"
#include <exception>

#include <stdexcept>

using namespace std;

// TODO: you might need to declare a custom exception

BagIterator::BagIterator(const Bag &c) : bag(c) {
  curr = c.head->next;
  if (curr != nullptr)
    currFreq = curr->frequency;
  else
    currFreq = 0;
}

void BagIterator::first() {
  curr = bag.head->next;
  if (curr != nullptr)
    currFreq = curr->frequency;
  else
    currFreq = 0;
}

void BagIterator::next() {
  if (curr == nullptr) {
    throw runtime_error("Fuck!");
    return;
  }
  if (currFreq <= 1) {
    if (curr != nullptr) {
      curr = curr->next;
      if (curr != nullptr)
        currFreq = curr->frequency;
    }

  } else {
    currFreq--;
  }
}

bool BagIterator::valid() const {
  if (curr == nullptr)
    return false;
  else
    return true;
}

TElem BagIterator::getCurrent() const {
  if (curr != nullptr)
    return curr->element;
  else
    throw runtime_error("Fuck!");
}
