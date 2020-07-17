#ifndef MINIDB_H
#define MINIDB_H

#include <list>
#include <stdexcept>

template <class T> class MiniDB
{
  std::list<T> db_store;
  typename std::list<T>::iterator current_position { db_store.begin() };
  
public:
  
  MiniDB() = default;
  MiniDB(const MiniDB&) = default;
  MiniDB& operator=(const MiniDB&) = default;

  std::size_t size() const {

    return db_store.size();
    
  }
  
  void insert(const T& item) {
    current_position = db_store.insert(current_position, item);
    current_position++;
  }
  
  void append(const T& item) {
    current_position = db_store.insert(db_store.end(), item);
  }

  // the following operations must throw std::logic_error if the member list db.store is empty, leaving the invoking object unchanged.
  void prev() {
    if (current_position == db_store.begin())
      throw std::logic_error("no previous element!");

    current_position--;
  }
  
  void next() {
    if (current_position == --db_store.end())
      throw std::logic_error("no next element!");

    current_position++;
  }
  
  T remove() {
    
    T removed = *current_position;

    current_position = db_store.erase(current_position);

    // if list is empty, db_store.begin() is db_store.end() and current_position will return them.
    if ( current_position == db_store.end() )
      current_position--;

    return removed;
  }
  
  void moveToFirst() {
    current_position = db_store.begin();
  }
  
  void moveToLast() {
    current_position = --db_store.end();
  }
  
  std::size_t getCurrentIndex() const {

    std::size_t idx = std::distance<std::list<T>::const_iterator>(db_store.begin(), current_position);

    return idx;
    
  }
  
  void moveToIndex(std::size_t index) {

    current_position = std::next(db_store.begin(), index);
    
  }

  const T& getValue() const {

    return *current_position;
  }
  
};

#endif /* MINIDB_H */
