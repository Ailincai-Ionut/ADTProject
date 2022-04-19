#pragma once
// DO NOT INCLUDE BAGITERATOR

// DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
typedef int TElem;
class BagIterator;

struct Node {
  Node *next;
  TElem element;
  unsigned int frequency;
};

class Bag {

private:
  // TODO - Representation
	//TODO: fix the memory leak problem and optimize the algorithms
  Node *head;
  int nr_elem;
  // DO NOT CHANGE THIS PART
  friend class BagIterator;

public:
  // constructor
  Bag();
  Bag(const Bag
          &b); // TODO: implement the copy constructor and assigment constructor
  Bag operator=(const Bag &b);

  // destructor
  ~Bag();

  // adds an element to the bag
  void add(TElem e);

  // removes one occurence of an element from a bag
  // returns true if an element was removed, false otherwise (if e was not part
  // of the bag)
  bool remove(TElem e);

  // checks if an element appearch is the bag
  bool search(TElem e) const;

  // returns the number of occurrences for an element in the bag
  int nrOccurrences(TElem e) const;

  // returns the number of elements from the bag
  int size() const;

  // returns an iterator for this bag
  BagIterator iterator() const;

  // checks if the bag is empty
  bool isEmpty() const;
};
