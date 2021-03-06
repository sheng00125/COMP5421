#ifndef MINIDB_H
#define MINIDB_H

#include <list>
#include <stdexcept>

template <class T>
class MiniDB
{
  std::list<T> db_store;
  typename std::list<T>::iterator current_position{db_store.begin()};

public:
  MiniDB() = default;
  MiniDB(const MiniDB &) = default;
  MiniDB &operator=(const MiniDB &) = default;

  std::size_t size() const
  {

    return db_store.size();
  }

  void insert(const T &item)
  {
    current_position = db_store.insert(current_position, item);
    
  }

  void append(const T &item)
  {
    current_position = db_store.insert(db_store.end(), item);
  }

  // the following operations must throw std::logic_error if the member list db.store is empty, leaving the invoking object unchanged.
  void prev()
  {
    if (size() == 0)
      throw std::logic_error("db is empty!");

    else
    {
      if (current_position != db_store.begin())
        current_position--;
      else
        throw std::logic_error("no previous element!");
    }
  }

  void next()
  {
    if (size() == 0)
      throw std::logic_error("db is empty!");

    else
    {
      if (current_position != --db_store.end())
        current_position++;
      else
        throw std::logic_error("no next element!");
    }
  }

  T remove()
  {
    if (size() != 0)
    {
      T removed = *current_position;

      current_position = db_store.erase(current_position);

      // if list is empty, db_store.begin() is db_store.end() and current_position will return them.
      if (current_position == db_store.end())
        current_position--;

      return removed;
    }
    else
      throw std::logic_error("db is empty!");
  }

  void moveToFirst()
  {
    if (size() != 0)
      current_position = db_store.begin();
    else
      throw std::logic_error("db is empty!");
  }

  void moveToLast()
  {
    if (size() != 0)
      current_position = --db_store.end();
    else
      throw std::logic_error("db is empty!");
  }

  std::size_t getCurrentIndex() const
  {
    std::size_t idx = std::distance<std::list<T>::const_iterator>(db_store.begin(), current_position);

    if (size() != 0)
      return idx;
    else
      throw std::logic_error("db is empty!");
  }

  void moveToIndex(std::size_t index)
  {
    if (size() != 0)
      current_position = std::next(db_store.begin(), index);
    else
      throw std::logic_error("db is empty!");
  }

  const T &getValue() const
  {
    if (size() != 0)
      return *current_position;
    else
      throw std::logic_error("db is empty!");
  }
};

#endif /* MINIDB_H */
