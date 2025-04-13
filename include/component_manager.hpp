#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP
#include "component_array.hpp"
#include "structs.hpp"
#include <cassert>
#include <iostream>
#include <memory>
#include <typeindex>

// manage all different types of components arrays together
class ComponentManager {
public:
    template <typename T>
    void registerComponent() {
        auto key = std::type_index(typeid(T));
        assert(!components.count(key) && "component already registered");
        Data data(std::make_unique<ComponentArray<T>>(),
                  Component(components.size()));
        components[key] = std::move(data);
    }

    template <typename T>
    void erase(Entity ent) {
        auto key = std::type_index(typeid(T));
        assert(components.count(key) && "component not registered");
        ComponentArray<T> *ptr = getComponentArray<T>();
        ptr->erase(ent);
    }

    template <typename T>
    void insert(Entity ent, T component) {
        auto key = std::type_index(typeid(T));
        assert(components.count(key) && "component not registered");
        ComponentArray<T> *ptr = getComponentArray<T>();
        ptr->insert(ent, component);
    }

    template <typename T>
    T &get(Entity ent) {
        auto key = std::type_index(typeid(T));
        assert(components.count(key) && "component not registered");
        ComponentArray<T> *ptr = getComponentArray<T>();
        return ptr->get(ent);
    }

    template <typename T>
    Component getComponentType(T component) {
        auto key = std::type_index(typeid(T));
        assert(components.count(key) && "component not registered");
        return components[key].type;
    }

private:
    template <typename T>
    ComponentArray<T> *getComponentArray() {
        auto key = std::type_index(typeid(T));
        assert(components.count(key) && "component not registered");
        return static_cast<ComponentArray<T> *>(components[key].array.get());
    }

private:
    struct Data {
        std::unique_ptr<IComponentArray> array;
        Component type;
    };

    std::unordered_map<std::type_index, Data> components;
};

#endif
