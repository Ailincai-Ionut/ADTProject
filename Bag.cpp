#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

Bag::Bag() {
  head = new Node;
  head->element = NULL_TELEM;
  head->frequency = 0;
  head->next = nullptr;
  nr_elem = 0;
}

Bag::~Bag() {
  Node *curr = head->next;
  Node *prev;
  while (curr != nullptr) {
    prev = curr;
    curr = curr->next;
    delete prev;
  }
}

void Bag::add(TElem elem) {
  Node *curr = head->next;
  Node *prev = head;
  while (curr != nullptr && curr->element != elem) {
    prev = curr;
    curr = curr->next;
  }
  if (curr != nullptr) {
    curr->frequency += 1;
  } else {
    Node *new_node = new Node;
    new_node->element = elem;
    new_node->frequency = 1;
    new_node->next = nullptr;
    prev->next = new_node;
  }
  nr_elem += 1;
}

bool Bag::remove(TElem elem) {
  Node *curr = head->next;
  Node *prev = head;
  while (curr != nullptr && curr->element != elem) {
    prev = curr;
    curr = curr->next;
  }
  if (curr != nullptr) {
    curr->frequency -= 1;
    if (curr->frequency <= 0) {
      prev->next = curr->next;
      delete curr;
    }
    nr_elem -= 1;
    return true;
  } else {
    return false;
  }
}

bool Bag::search(TElem elem) const {
  Node *curr = head->next;
  while (curr != nullptr && curr->element != elem) {
    curr = curr->next;
  }
  if (curr != nullptr)
    return true;
  else
    return false;
}

int Bag::nrOccurrences(TElem elem) const {
  Node *curr = head->next;
  while (curr != nullptr && curr->element != elem) {
    curr = curr->next;
  }
  if (curr != nullptr)
    return curr->frequency;
  else
    return 0;
}

int Bag::size() const { return nr_elem; }

bool Bag::isEmpty() const {
  if (head->next == nullptr)
    return true;
  else
    return false;
}

BagIterator Bag::iterator() const { return BagIterator(*this); }
