#pragma once

#include <cigol/base/non-copyable.hpp>

#include <cigol/ecs/system.hpp>
#include <cigol/ecs/entity.hpp>

#include <cigol/base/iterable-to-optional.hpp>
#include <cigol/base/parameter-pack-type-unicity.hpp>

#include <coro/shared_generator.h>

#include <range/v3/view/map.hpp>

#include <tuple>
#include <chrono>
#include <memory>
#include <vector>
#include <optional>

namespace cigol::ecs {
    class Scene: private cigol::base::NonCopyable {
        private:
            /*
            * Encapsulating entities/systems here will allow me to refactor entity
            * storage to a less naive solution later.
            */
            std::vector<std::shared_ptr<Entity>>    entities;
            std::vector<System>                     systems;

        public:
            Scene() = default;

            Scene(
                Scene&& scene
            );

            void
            process(
                std::chrono::milliseconds Δt
            );

            void
            addEntity(
                std::shared_ptr<Entity>   entity
            );

            void
            addSystem(
                System                    system
            );

            template <typename ComponentType>
            shared_generator<std::pair<std::shared_ptr<Entity>, std::shared_ptr<ComponentType>>>
            findEntitiesWithComponent() {
                for (auto entity: this->entities) {
                    auto componentsGenerator = entity->findComponents<ComponentType>();

                    for (auto component: componentsGenerator) {
                        co_yield { entity, component };
                    }
                }
            }

            template <typename... ComponentTypes>
            requires cigol::base::ParameterPackTypeUnicity<ComponentTypes...>
            shared_generator<std::tuple<std::shared_ptr<Entity>, std::shared_ptr<ComponentTypes>...>>
            findEntitiesWithComponents() {
                for (auto entity: this->entities) {
                    auto components = std::apply([&entity] (auto... tupleElements) {
                        return std::make_tuple(
                            entity
                            ->findFirstComponent<std::decay_t<decltype(*tupleElements)>>()
                            .value_or(nullptr)
                            ...
                        );
                    }, std::tuple<std::shared_ptr<ComponentTypes>...> {});

                    const bool isComplete = std::apply([] (auto&... components) {
                        return ((components != nullptr) && ...);
                    }, components);

                    if (isComplete) {
                        co_yield std::tuple_cat(std::make_tuple(entity), components);
                    }
                }
            }

            template <typename ComponentType>
            std::optional<std::shared_ptr<ComponentType>>
            getFirstComponent() {
                return findEntitiesWithComponent<ComponentType>()
                | ranges::views::values
                | cigol::base::toOptional();
            }
    };
}
