#ifndef VOXEL_SYSTEM_HPP
#define VOXEL_SYSTEM_HPP

#include "vec2.hpp"
#include "voxel.hpp"

struct VoxelSystem {
public:
    VoxelSystem() {
        VoxelRegion region;
        region.readFromInput();
        for (VoxelChunk &chunk : region.chunks) {
            activeChunks.push_back(chunk);
        }
    }

    void draw(Vec2 offset, SDL_Renderer *renderer) {
        SDL_FRect rects[MAX_ACTIVE_VOXELS];
        size_t count = 0;
        for (VoxelChunk &chunk : activeChunks) {
            count = chunk.addDraw(rects, count, offset);
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderFillRects(renderer, rects, int(count));
    }

private:
    std::vector<VoxelChunk> activeChunks;
};
#endif
