#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include "judge.h"

#define MAX_DIRS 6000

class Dir {
    std::string m_path = std::string("/");
    int m_parent = -1;
    std::set<int> m_subDirs;
    bool m_isSystemFile = false;

   public:
    Dir() {
    }

    Dir(std::string path, int parent) : m_path(path), m_parent(parent) {
    }

    void addSubDir(int subdir) {
        m_subDirs.insert(subdir);
    }

    std::string getPath() {
        return m_path;
    }

    void makeSystemFile() {
        m_isSystemFile = true;
    }
    bool isSystemFile() {
        return m_isSystemFile;
    }

    std::set<int> &getSubdirs() {
        return m_subDirs;
    }

    int getParent() {
        return m_parent;
    }
};

class MSD : public IMSD {
    std::vector<Dir> dirs;
    std::map<std::string, int> dir_ptrs;
    int ID;

   public:
    void init() {
        dirs.reserve(MAX_DIRS);
        dirs.clear();
        ID = 1;
        dirs.push_back(Dir());
        dir_ptrs["/"] = 0;
    }

    void makeDir(char *path, char *name) {
        std::string s_path = path;
        std::string s_name = name;
        std::string fullpath = s_path + s_name + "/";

        dirs[dir_ptrs[s_path]].addSubDir(ID);

        dirs.push_back(Dir(std::string(fullpath), dir_ptrs[s_path]));
        dir_ptrs[fullpath] = ID;

        ID++;
    }

    void makeLink(char *pathSrc, char *pathDst) {
        dirs[dir_ptrs[pathSrc]].addSubDir(dir_ptrs[pathDst]);
    }

    void makeSystemFile(char *path) {
        dirs[dir_ptrs[path]].makeSystemFile();
    }

    void getMostSafeDir(char *result) {
        std::vector<int> security;
        std::queue<int> queue;
        std::vector<int> sources;
        std::vector<bool> seen;

        sources.reserve(MAX_DIRS);

        sources.clear();
        security = std::vector<int>(ID, 0);
        seen = std::vector<bool>(ID, false);

        // SCAN FOR SOURCE FILES
        queue.push(0);
        seen[0] = true;
        while (!queue.empty()) {
            if (!dirs[queue.front()].isSystemFile()) {
                sources.push_back(queue.front());
            }

            for (auto i : dirs[queue.front()].getSubdirs()) {
                if (seen[i] == false)
                    queue.push(i);
                seen[i] = true;
            }
            queue.pop();
        }

        // BFS FROM SOURCE FILES TO FIND CLOSEST SYSFILE
        for (auto i : sources) {
            seen = std::vector<bool>(ID, false);

            queue = std::queue<int>();
            queue.push(i);
            std::queue<int> new_queue;
            int security_level = 0;
            while (!queue.empty()) {
                while (!queue.empty()) {
                    seen[queue.front()] = true;

                    if (dirs[queue.front()].isSystemFile()) {
                        security[i] = security_level;
                        new_queue = std::queue<int>();
                        break;
                    }
                    for (auto j : dirs[queue.front()].getSubdirs()) {
                        if (!seen[j]) new_queue.push(j);
                        seen[j] = true;
                    }
                    if (dirs[queue.front()].getParent() != -1 && !seen[dirs[queue.front()].getParent()])
                        new_queue.push(dirs[queue.front()].getParent());

                    queue.pop();
                }
                if(security[i] != 0) break;
                security_level++;
                queue = new_queue;
                new_queue = std::queue<int>();
            }
        }

        // Get most secure location
        int max = 0;
        for (int i = 0; i < ID; i++) {
            if (security[i] > max) {
                max = security[i];
                strcpy(result, dirs[i].getPath().c_str());
            }
        }
    }
};

MSD solution;
int main() {
    freopen("in/MSD0e.in", "r", stdin);
    Judge::run(&solution);
    return 0;
}
