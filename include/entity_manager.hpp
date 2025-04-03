#include "structs.hpp"
#include <array>
#include <cassert>
#include <cstdint>
#include <stack>

class EntityManager {
public:
    EntityManager() {
        // load all available ents
        for (int i = MAX_ENTITIES - 1; i >= 0; i--) {
            availableEnts.push(i);
        }
    }

    Entity createEntity() {
        assert(countEntity() < MAX_ENTITIES && "too many entities\n");
        Entity ent = availableEnts.top();
        availableEnts.pop();
        used[ent] = 1;
        return ent;
    }

    void destroyEntity(Entity ent) {
        assert(ent < MAX_ENTITIES && "entity out of range\n");
        assert(isUsed(ent) && "entity is mising");
        signatures[ent].reset();
        used[ent] = 0;
        availableEnts.push(ent);
    }

    Signature getSignature(Entity ent) const {
        assert(ent < MAX_ENTITIES && "entity out of range\n");
        assert(isUsed(ent) && "entity is missing");
        return signatures[ent];
    }

    void setSignature(Entity ent, Signature signature) {
        assert(ent < MAX_ENTITIES && "entity out of range\n");
        assert(isUsed(ent) && "entity is missing");
        signatures[ent] = signature;
    }

    bool isUsed(Entity ent) const { return used[ent]; }

    uint32_t countEntity() const { return MAX_ENTITIES - availableEnts.size(); }

private:
    std::stack<Entity> availableEnts;
    std::array<Signature, MAX_ENTITIES> signatures;
    std::bitset<MAX_ENTITIES> used;
};
