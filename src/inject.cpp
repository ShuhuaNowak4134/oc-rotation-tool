// inject.cpp — part of oc-rotation-tool.

#include "ocrotationtool/inject.h"

#include <cstdio>

namespace ocrotationtool {

Inject::Inject(const std::string& config_path)
    : config_path_(config_path) {}

void Inject::configure(const std::string& key, const std::string& value) {
    if (key == "verbose") verbose_ = (value == "true");
}

bool Inject::run() {
    if (verbose_) std::fprintf(stderr, "[oc-rotation-tool] inject: run\n");
    // core logic lives here
    return true;
}

}  // namespace ocrotationtool
