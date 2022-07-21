#ifndef SINGLETON_BASE_HPP
#define SINGLETON_BASE_HPP

#include <memory>

namespace hrn_utils {

template<typename T>
class SingletonBase {
public:

    SingletonBase& operator=(const SingletonBase&) = delete;
    SingletonBase& operator=(SingletonBase&&) = delete;

    static std::shared_ptr<T> getInstance() {
        if(m_instance) {
            m_instance = std::make_shared<T>();
            return m_instance;
        }

        return m_instance;
    }

    template<typename ...ARGS>
    static std::shared_ptr<T> getInstance(const ARGS&... args) {
        return m_instance;
    }
protected:
    SingletonBase() = default;

private:
    static inline std::shared_ptr<T> m_instance{nullptr};
};

}
#endif // SINGLETON_BASE_HPP