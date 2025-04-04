#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP
#include <typeindex>

// manage all different types of components arrays together
class ComponentManager {
public:
    template <typename T>
    void registerComponent() {
        auto key = std::type_index(typeid(int));
        // can hash from type_index to component array efficiently
    }

private:
};

#endif
