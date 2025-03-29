#ifndef CONFIG_H
#define CONFIG_H

#include <random>

namespace Config {
constexpr int windowWidth = 1920;
constexpr int windowHeight = 1080;
constexpr int fpsDelay = 16;
constexpr int chunkSize = 1000;

// inline so all files get separate rand
inline std::mt19937 rng{std::random_device{}()};
inline int randInt(int lo, int hi) {
    std::uniform_int_distribution<int> rand(lo, hi);
    return rand(rng);
}

}; // namespace Config

#endif
