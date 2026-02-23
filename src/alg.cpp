// Copyright 2022 NNTU-CS
#include <cstdint>
#include <vector>
#include <algorithm>

bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2 || value == 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;
  for (uint64_t i = 5; i <= value / i; i += 6) {
    if (value % i == 0 || value % (i + 2) == 0)
      return false;
  }
  return true;
}
uint64_t nPrime(uint64_t n) {
  if (n == 1) return 2;
  uint64_t count = 1;     
  uint64_t number = 3;
  while (count < n) {
    if (checkPrime(number))
      ++count;
    number += 2;      
  }
  return number - 2;
}
uint64_t nextPrime(uint64_t value) {
  if (value < 2) return 2;
  uint64_t candidate = value + 1;
  if (candidate % 2 == 0)
    ++candidate;
  while (!checkPrime(candidate)) {
    candidate += 2;
  }
  return candidate;
}
uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;
  std::vector<bool> prime(hbound, true);
  prime[0] = prime[1] = false;
  for (uint64_t i = 2; i <= hbound / i; ++i) {
    if (prime[i]) {
      for (uint64_t j = i * i; j < hbound; j += i)
        prime[j] = false;
    }
  }
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (prime[i])
      sum += i;
  }
  return sum;
}
uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound <= 3 || hbound <= lbound + 2)
    return 0;
  std::vector<bool> prime(hbound, true);
  prime[0] = prime[1] = false;
  for (uint64_t i = 2; i <= hbound / i; ++i) {
    if (prime[i]) {
      for (uint64_t j = i * i; j < hbound; j += i)
        prime[j] = false;
    }
  }
  uint64_t count = 0;
  uint64_t start = std::max<uint64_t>(lbound, 2);
  for (uint64_t i = start; i + 2 < hbound; ++i) {
    if (prime[i] && prime[i + 2] && i >= lbound)
      ++count;
  }
  return count;
}
