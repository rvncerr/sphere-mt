#include <coroutine/engine.h>

#include <setjmp.h>

namespace Coroutine {

void Engine::Store(context& ctx) {
    // TODO: implements
}

void Engine::Restore(context& ctx) {
    // TODO: implements
}

void Engine::Enter(context& ctx) {
    // TODO: implements
}

void Engine::yield() {
    // TODO: implements
    // setjmp, longjmp...
}

void Engine::sched(int routine) {
    // TODO: implements
    // setjmp, longjmp...
}

} // namespace Coroutine
