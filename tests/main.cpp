#include "../include/component_array.hpp"
#include "../include/entity_manager.hpp"
#include <iostream>

using std::cout;

int main() {
}

void testComponentArray() {
    EntityManager entManager;
    Entity ent1 = entManager.createEntity();
    Entity ent2 = entManager.createEntity();
    Entity ent3 = entManager.createEntity();
    Entity ent4 = entManager.createEntity();
    ComponentArray<Transform> components;
    components.insert(ent1, Transform(Vec2(0, 1)));
    components.insert(ent2, Transform(Vec2(0, 2)));
    components.insert(ent3, Transform(Vec2(0, 3)));
    components.insert(ent4, Transform(Vec2(0, 4)));

    Transform data = components[ent3];
    cout << data.position.x << " " << data.position.y << "\n";
    components.erase(ent2);

    data = components[ent1];
    cout << data.position.x << " " << data.position.y << "\n";

    data = components[ent4];
    cout << data.position.x << " " << data.position.y << "\n";
}

void testEntityManager() {
    EntityManager entManager;
    Entity ent = entManager.createEntity();
    printf("entity number: %d\n", ent);
    Signature sig = entManager.getSignature(ent);
    cout << "signature " << sig << "\n";
    sig.flip(2);
    entManager.setSignature(ent, sig);
    sig = entManager.getSignature(ent);
    cout << "signature " << sig << "\n";
    Entity ent2 = entManager.createEntity();
    sig.flip(3);
    entManager.setSignature(ent2, sig);
    cout << "signature " << sig << "\n";
    entManager.destroyEntity(ent);

    Entity ent3 = entManager.createEntity();
    cout << "entity: " << ent3 << "\n";
}
