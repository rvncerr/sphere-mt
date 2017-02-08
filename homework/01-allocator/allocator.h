#include <stdexcept>
#include <string>

enum class AllocErrorType {
    InvalidFree,
    NoMemory,
};

class AllocError: std::runtime_error {
private:
    AllocErrorType type;

public:
    AllocError(AllocErrorType _type, std::string message):
            runtime_error(message),
            type(_type)
    {}

    AllocErrorType getType() const { return type; }
};

class Allocator;

class Pointer {
public:
    void *get() const { return 0; } 
};

class Allocator {
public:
    Allocator(void *base, size_t size) {}
    
    Pointer alloc(size_t N) { return Pointer(); }
    void realloc(Pointer &p, size_t N) {}
    void free(Pointer &p) {}

    void defrag() {}
    std::string dump() { return ""; }
};

