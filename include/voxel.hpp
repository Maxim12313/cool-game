#ifndef VOXEL_HPP
#define VOXEL_HPP
#include "structs.hpp"
#include "vec2.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

struct Voxel {
    bool active = false;
};

struct VoxelChunk {
    Vec2 pos;
    std::vector<Voxel> voxels;

    VoxelChunk() : voxels(CHUNK_LENGTH * CHUNK_LENGTH) {}
    void readInput(int x1, int y1, size_t n, size_t m,
                   std::vector<std::string> &grid) {
        pos = Vec2(x1 * VOXEL_LENGTH, y1 * VOXEL_LENGTH);
        int idx = 0;
        for (int y2 = 0; y2 < CHUNK_LENGTH; y2++) {
            for (int x2 = 0; x2 < CHUNK_LENGTH; x2++) {
                int x = x1 + x2;
                int y = y1 + y2;
                if (y < n && x < m) {
                    bool show = grid[y][x] != '.';
                    voxels[idx] = Voxel(show);
                }
                idx++;
            }
        }
    }

    size_t addDraw(SDL_FRect *rects, size_t offsetIdx, Vec2 offsetPos) {
        size_t curr = 0;
        float posY = pos.y - offsetPos.y;
        for (int y = 0; y < CHUNK_LENGTH; y++) {
            float posX = pos.x - offsetPos.x;
            for (int x = 0; x < CHUNK_LENGTH; x++) {
                if (voxels[curr].active) {
                    rects[offsetIdx] =
                        SDL_FRect(posX, posY, VOXEL_LENGTH, VOXEL_LENGTH);
                    offsetIdx++;
                }
                curr++;
                posX += VOXEL_LENGTH;
            }
            posY += VOXEL_LENGTH;
        }
        return offsetIdx;
    }
};

struct VoxelRegion {
    std::vector<VoxelChunk> chunks;
    void readFromInput() {
        size_t n, m;
        std::cin >> n >> m;
        std::vector<std::string> grid(n);
        for (int i = 0; i < n; i++) {
            std::cin >> grid[i];
        }
        for (std::string &s : grid) {
            std::cout << s << "\n";
            assert(s.size() == m && "inconsistent column length");
        }

        for (int y1 = 0; y1 < n; y1 += CHUNK_LENGTH) {
            for (int x1 = 0; x1 < m; x1 += CHUNK_LENGTH) {
                chunks.emplace_back();
                chunks.back().readInput(x1, y1, n, m, grid);
            }
        }
    }
};

#endif
