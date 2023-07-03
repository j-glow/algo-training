#include <malloc.h>

// #include <fstream>
#include "judge.h"

class Container : public IContainer {
    int size_of_int = 32;
    int m_values[200000000 / 32];
    int m_size = 200000000 / 32;

   public:
    void init(int size) {
        if (m_values) {
            for (int i = 0; i < m_size; i++)
                m_values[i] = 0;
        }
    }

    bool add(int a) {
        if (a >= m_size * size_of_int || a < 0) return false;

        if (!((m_values[a / size_of_int] & (1 << (a % size_of_int))))) {
            m_values[a / size_of_int] |= (1 << (a % size_of_int));
            return true;
        }
        return false;
    }

    bool contains(int a) {
        if (a >= m_size * size_of_int || a < 0) return false;

        return ((m_values[a / size_of_int]) & (1 << (a % size_of_int)));
    }

    bool remove(int a) {
        if (a >= m_size * size_of_int || a < 0) return false;

        if ((m_values[a / size_of_int]) & (1 << (a % size_of_int))) {
            m_values[a / size_of_int] &= ~(1 << (a % size_of_int));
            return true;
        }
        return false;
    }
};

int main() {
    // freopen("container0.in", "r", stdin);
    Container* container = new Container();
    Judge::run(container);
}
