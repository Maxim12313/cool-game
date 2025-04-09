#ifndef STRUCTS_HPP
#define STRUCTS_HPP
#include <SDL3/SDL.h>
#include <bitset>
#include <cstdint>

using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;

using Component = std::uint8_t;
const Component MAX_COMPONENTS = 32;

// TODO: must ensure can hold all components
using Signature = std::uint32_t;

const float VOXEL_LENGTH = 50;
const size_t CHUNK_LENGTH = 15;
const size_t REGION_LENGTH = 20;
const size_t MAX_ACTIVE_VOXELS = 1000;

struct Color {
    int r, g, b, a;
};

#endif
