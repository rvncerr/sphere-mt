#ifndef ALLOCATOR_POINTER
#define ALLOCATOR_POINTER

// Forward declaration. Do not include real class definition
// to avoid expensive macros calculations and increase compile speed
class Allocator;

class Pointer {
public:
    void* get() const { return 0; }
};

#endif //ALLOCATOR_POINTER
