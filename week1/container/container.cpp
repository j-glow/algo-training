#include <malloc.h>

#include "judge.h"

class Container : public IContainer {
    bool* m_values;
    int m_size = 0;

   public:
    void init(int size) {
        m_size = size;
        if (m_size > 0)
            m_values = (bool*)malloc(m_size * sizeof(bool));
        for(int i = 0; i<m_size; i++)
            m_values[i]=false;
    }

    bool add(int a) {
        if (a >= m_size || a < 0 || m_values == NULL) return true;

        if (!m_values[a]) {
            m_values[a] = true;
            return true;
        }
        return false;
    }

    bool contains(int a) {
        if (a >= m_size || a < 0 || m_values == NULL) return true;

        return m_values[a];
    }

    bool remove(int a) {
        if (a >= m_size || a < 0 || m_values == NULL) return true;

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
