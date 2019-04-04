# C++ Random sort

This is a simple implementation of a random sorting algorithm (also: Bogosort)
written in C++.

## Implementation

The Sorter does not actually touch the array to be sorted ('data array'),
but rather shuffles an internal 'index array', which can then be used to address
the data array in a sorted fashion.

The Sorter class is implemented as a template and can sort arrays of any
data type/class that has the < operator implemented.

### Example

```c++
uint8_t len = 6;
int array[len] = {4, 5, 7, 1, 8, 2};
Sorter<int> *s = new Sorter<int>(len);

uint64_t iterations = s->sort(array);
const uint8_t *index = s->getIndex();

printf("Sorted array after %ld iterations:\n", iterations);
for (size_t i = 0; i < len; i++) {
  printf("%d\n", array[index[i]]);
}
```

So far only tested with integers and doubles.
