#include <emscripten/bind.h>
#include <dushi.h>

using namespace emscripten;

bool init = false;

std::string bezem(std::string msg, int smileys, int aids){
    if(!init)
        dushi_load();
    return dushi_bezem(msg, smileys, aids);
}

EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("bezem", &bezem);
}
