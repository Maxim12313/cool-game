#ifndef COMPONENT_ARRAY_HPP
#define COMPONENT_ARRAY_HPP
#include "array"
#include "structs.hpp"
#include <cassert>
#include <cstdint>
#include <unordered_map>

// for each component data type
template <typename T> class ComponentArray {
public:
    ComponentArray() : usedLength(0) {}

    void insert(Entity ent, T &&component) {
        assert(ent < MAX_ENTITIES && "entity outside bounds");
        assert(!entToIdx.count(ent) && "entity component already exists");

        // forwarding, copies if lvalue reference and moves if temporary rvalue
        data[usedLength] = std::forward<T>(component);
        entToIdx[ent] = usedLength;
        idxToEnt[usedLength] = ent;
        usedLength++;
    }

    void erase(Entity ent) {
        assert(ent < MAX_ENTITIES && "entity outside bounds");
        assert(entToIdx.count(ent) && "entity is missing");

        size_t lastIdx = usedLength - 1;
        size_t currIdx = entToIdx[ent];
        std::swap(data[lastIdx], data[currIdx]);

        Entity lastEnt = idxToEnt[lastIdx];
        entToIdx.erase(ent);
        idxToEnt.erase(lastIdx);

        if (ent != lastEnt) {
            entToIdx[lastEnt] = currIdx;
            idxToEnt[currIdx] = lastEnt;
        }

        usedLength--;
    }

    T &operator[](Entity ent) {
        assert(ent < MAX_ENTITIES && "entity outside bounds");
        assert(entToIdx.count(ent) && "entity is missing");
        return data[entToIdx[ent]];
    }

private:
    // TODO: try hybrid approach with unordered map for sparse and allocated
    // array for high load and template
    std::array<T, MAX_ENTITIES> data;
    std::unordered_map<Entity, size_t> entToIdx;
    std::unordered_map<Entity, size_t> idxToEnt;
    size_t usedLength;
};

#endif
