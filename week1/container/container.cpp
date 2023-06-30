#include <malloc.h>

#include "judge.h"

class Container : public IContainer {
    bool* m_values;
    int m_size;

   public:
    void init(int size) {
        m_values = (bool*)calloc(size, sizeof(int));
        m_size = size;
    }
    bool add(int a) {
        if (a > m_size) return false;
        
        if (!m_values[a]) {
            return m_values[a] = true;
        }
        return false;
    }
    bool contains(int a) {
        if (a > m_size) return false;

        return m_values[a];
    }
    bool remove(int a) {
        if (a > m_size) return false;

        if (m_values[a]) {
            m_values[a] = false;
            return true;
        }
        return false;
    }
};

int main() {
    Container* container = new Container();
    Judge::run(container);
}
