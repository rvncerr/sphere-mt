#ifndef COROUTINE_ENGINE_H
#define COROUTINE_ENGINE_H

#include <map>
#include <setjmp.h>

namespace Coroutine {

/**
 * # Entry point of coroutine library
 * Allows to run coroutine and schedule its execution. Not threadsafe
 */
class Engine final {
private:
    /**
     * A single coroutine instance which could be scheduled for execution
     * should be allocated on heap
     */
    typedef struct {
        // Begin of routine stack
        char* Low;

        // End of routine stack
        char* High;

        // routine stack copy
        char* StackBuffer;
        size_t BufferSize;

        // Saved routine context
        jmp_buf Environment;

        // routine that start this one
        struct routine* caller;

        // routine called by this one
        struct routine* callee;
    } context;

    /**
     * Where coroutines stack begins
     */
    char* StackBottom;

    /**
     * Current coroutine
     */
    context* cur_routine;

    /**
     * Main coroutine
     */
    context* main_routine;

    /**
     * Sequence to enumerate coroutines
     */
    int context_seq;

    /**
     * All alive routines keyed by id
     */
    std::map<int, context*> alive;

protected:
    /**
     * Save state (stack & env) of the current coroutine in the given context
     */
    void Store(context& ctx);

    /**
     * Restore state (stack &env) in the c++ runtime from the given context
     */
    void Restore(context& ctx);

    /**
     * Suspend current coroutine execution and execute given context
     */
    void Enter(context& ctx);

public:
    Engine()
        : StackBottom(0) {}
    Engine(Engine&&) = delete;
    Engine(const Engine&) = delete;

    /**
     * Entry point into the engine. Prepare all internal mechanics and starts given function which is
     * considered as main.
     *
     * Once control returns back to caller of start all coroutines are done execution
     *
     * @param arguments to be passed to the main coroutine
     * @return result of coroutine execution
     */
    template <typename R, typename... Ta, typename... Tv>
    R start(R (*main)(Ta...), Tv... args) {
        // To acquire stack begin, create variable on stack and remember its address. Just before it, store pointer
        // to the Engine
        char StackStartsHere;
        this->StackBottom = &StackStartsHere;

        // Start routine execution
        R result = main(std::forward<Tv>(args)...);

        // Shutdown runtime
        this->StackBottom = 0;
        return result;
    }

    /**
     * Register new coroutine. It won't receive control until scheduled explicitely or implicitely. In case of some
     * errors function returns -1
     */
    template <typename... Ta, typename... Tv>
    int run(void (*main)(Ta...), Tv... args) {
        return -1;
    }

    /**
     * Gives up current routine execution and let engine to schedule other routine. It is not defined when
     * routine will get execution back, for example if there are no other coroutines then execution could
     * be trasferred back immediately or yeiled turns to be noop.
     *
     * Also there are no guarantee what routine will get execution, it could be caller of the current one or
     * any other which is ready to run
     */
    void yield();

    /**
     * Suspend current routine and transfers control to the given one, resumes its execution from the point
     * when it has been suspended previously.
     *
     * If routine to pass execution to is not specified runtime will try to transfer execution back to caller
     * of the current routine, if there is no caller then this method has same semantics as yield
     */
    void sched(int routine);
};

} // namespace Coroutine

#endif // COROUTINE_ENGINE_H
