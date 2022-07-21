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
        if(!m_instance) {
            m_instance = std::shared_ptr<T>(new T());
        }

        return m_instance;
    }

    template<typename ...ARGS>
    static std::shared_ptr<T> getInstance(ARGS&&... args) {
        if(!m_instance){
            m_instance = std::shared_ptr<T>( new T(std::forward<ARGS>(args)...));
        }
        return m_instance;
    }
protected:
    SingletonBase() = default;
    ~SingletonBase() = default;

private:
    static inline std::shared_ptr<T> m_instance{nullptr};
};

}
#endif // SINGLETON_BASE_HPP