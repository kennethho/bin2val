#ifndef BIN2VAL_HPP
#define BIN2VAL_HPP

#include <cstring>

template <typename T>
T bin2val_cast(const void* from)
{
  T val;
  memcpy(&val, from, sizeof(T));
  return val;
}

struct auto_bin2val
{
  const void* from_;

  auto_bin2val(const void* from)
  : from_(from) {}

  template <typename T>
  operator T () const
  {
    return bin2val_cast<T>(from_);
  }
};


inline auto_bin2val bin2val_cast(const void* from)
{
  return auto_bin2val(from);
}

#endif // BIN2VAL_HPP
