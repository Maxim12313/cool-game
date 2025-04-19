#include "../include/bitops.hpp"
#include "../include/context.hpp"
#include "../include/ecs/component_array.hpp"
#include "../include/ecs/component_manager.hpp"
#include "../include/ecs/components.hpp"
#include "../include/ecs/entity_manager.hpp"
#include "../include/structs.hpp"
#include <iostream>

using std::cout;
void testComponentManager() {
    EntityManager entManager;
    Entity ent1 = entManager.createEntity();
    Entity ent2 = entManager.createEntity();

    ComponentManager manager;
    manager.registerComponent<Transform>();
    manager.insert(ent1, Transform(Vec2(9, 9)));
    Transform &val = manager.get<Transform>(ent1);
    cout << val.position.x << " " << val.position.y << "\n";

    manager.erase<Transform>(ent1);
    manager.insert(ent1, Transform(Vec2(10, 10)));
    val = manager.get<Transform>(ent1);
    cout << val.position.x << " " << val.position.y << "\n";

    manager.registerComponent<RigidBody>();
    manager.insert(ent1, RigidBody(Vec2(1, 2), Vec2(3, 4)));
    RigidBody &val2 = manager.get<RigidBody>(ent1);
    cout << val2.acceleration.x << " " << val2.acceleration.y << " "
         << val2.velocity.x << " " << val2.velocity.y << "\n";

    manager.insert(ent2, Transform(Vec2(11, 11)));
    val = manager.get<Transform>(ent2);
    cout << val.position.x << " " << val.position.y << "\n";
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

    Transform data = components.get(ent3);
    cout << data.position.x << " " << data.position.y << "\n";
    components.erase(ent2);

    data = components.get(ent1);
    cout << data.position.x << " " << data.position.y << "\n";

    data = components.get(ent4);
    cout << data.position.x << " " << data.position.y << "\n";
}

void testEntityManager() {
    EntityManager entManager;
    Entity ent = entManager.createEntity();
    printf("entity number: %d\n", ent);
    Signature sig = entManager.getSignature(ent);
    cout << "signature " << sig << "\n";
    // sig.flip(2);
    sig = setIthBit(sig, 2);
    entManager.setSignature(ent, sig);
    sig = entManager.getSignature(ent);
    cout << "signature " << sig << "\n";
    Entity ent2 = entManager.createEntity();
    // sig.flip(3);
    sig = setIthBit(sig, 3);
    entManager.setSignature(ent2, sig);
    cout << "signature " << sig << "\n";
    entManager.destroyEntity(ent);

    Entity ent3 = entManager.createEntity();
    cout << "entity: " << ent3 << "\n";
}
