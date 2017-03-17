#include <fmo/algorithm.hpp>
#include <map>

namespace fmo {
    using AlgorithmRegistry = std::map<std::string, Algorithm::Factory>;

    AlgorithmRegistry& getRegistry() {
        static AlgorithmRegistry registry;
        return registry;
    }

    void registerExplorerV1();

    void registerBuiltInFactories() {
        static bool registered = false;
        if (registered) return;
        registered = true;

        registerExplorerV1();
    }

    std::unique_ptr<Algorithm> fmo::Algorithm::make(const Config& config) {
        registerBuiltInFactories();
        auto& registry = getRegistry();
        auto it = registry.find(config.name);
        if (it == registry.end()) { throw std::runtime_error("unknown algorithm name"); }
        return it->second(config);
    }

    void Algorithm::registerFactory(const std::string& name, const Factory& factory) {
        auto& registry = getRegistry();
        auto it = registry.find(name);
        if (it != registry.end()) { throw std::runtime_error("duplicate algorithm name"); }
        registry.emplace(name, factory);
    }
}