#include "bin2val.hpp"

#include <cassert>

int f(int)
{
  return 0;
}
int f(double)
{
  return 1;
}

void example()
{
  const int n = 0;
  const float m = 1.0;

  const size_t offset = 1;
  unsigned char buf1[sizeof(n) + offset];
  unsigned char buf2[sizeof(m) + offset];

  memcpy(buf1 + offset, &n, sizeof(n));
  memcpy(buf2 + offset, &m, sizeof(m));
  const unsigned char* x = buf1 + offset;
  const unsigned char* y = buf2 + offset;

  int a = (bin2val_cast(x));
  assert(a == n);
  float b = bin2val_cast(y);
  assert(b == m);

#if(CPP11)
  auto c = bin2val_cast<int>(x);
  assert(c == n);
  auto d = bin2val_cast<float>(y);
  assert(d == m);
#else
  int c = bin2val_cast<int>(x);
  assert(c == n);
  float d = bin2val_cast<float>(y);
  assert(d == m);
#endif

  assert(f(bin2val_cast<int>(x)) == 0);
  assert(f(bin2val_cast<float>(y)) == 1);
}

int main()
{
  example();
  return 0;
}
