#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include "structs.hpp"
#include "systems.hpp"
#include <cassert>
#include <memory>
#include <typeindex>
#include <unordered_map>

class SystemManager {
public:
    template <typename T>
    T &registerSystem(Signature &signature) {
        auto idx = std::type_index(typeid(T));
        assert(!systems.count(idx) && "system already registered");
        Data data(std::unique_ptr<T>());
        systems[idx] = data;
        return data.system;
    }

    void checkAddEntity(Entity ent, Signature signature) {
        for (const auto &[key, data] : systems) {
            auto &[system, systemSignature] = data;
            if ((signature & systemSignature) == signature) {
                system->entities.insert(ent);
            } else {
                system->entities.erase(ent);
            }
        }
    };

private:
    struct Data {
        std::unique_ptr<System> system;
        Signature signature;
    };

    std::unordered_map<std::type_index, Data> systems;
};
#endif
