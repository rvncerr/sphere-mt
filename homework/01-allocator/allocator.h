#ifndef ALLOCATOR
#define ALLOCATOR
#include <string>

// Forward declaration. Do not include real class definition
// to avoid expensive macros calculations and increase compile speed
class Pointer;

/**
 * Wraps given memory area and provides defagmentation allocator interface on
 * the top of it.
 *
 *
 */
class Allocator {
public:
    Allocator(void* base, size_t size) {}

    /**
     * TODO: semantics
     * @param N size_t
     */
    Pointer alloc(size_t N);

    /**
     * TODO: semantics
     * @param p Pointer
     * @param N size_t
     */
    void realloc(Pointer& p, size_t N) {}

    /**
     * TODO: semantics
     * @param p Pointer
     */
    void free(Pointer& p) {}

    /**
     * TODO: semantics
     */
    void defrag() {}

    /**
     * TODO: semantics
     */
    std::string dump() const { return ""; }
};

#endif // ALLOCATOR
