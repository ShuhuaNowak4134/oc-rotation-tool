// main.cpp — entry point. Wires config and subsystems together.

#include "ocrotationtool/settings.h"
#include "ocrotationtool/pool.h"
#include "ocrotationtool/rotate.h"
#include "ocrotationtool/inject.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    ocrotationtool::Settings settings = ocrotationtool::Settings::load_default();
    ocrotationtool::Pool pool(settings.store_path);
    ocrotationtool::Rotate rotate(settings.store_path);
    ocrotationtool::Inject inject(settings.store_path);
    std::fprintf(stderr, "[oc-rotation-tool] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
