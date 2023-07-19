#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include "judge.h"

namespace {
    
}
class Dir {
    std::string m_name = std::string("\0");
    Dir *m_parent = nullptr;
    std::map<std::string, Dir> m_subDirs = std::map<std::string, Dir>();
    std::map<std::string, Dir *> m_links = std::map<std::string, Dir *>();
    bool m_isSystemFile = false;

   public:
    Dir() {
    }

    Dir(std::string name, Dir *parent) : m_name(name), m_parent(parent) {
    }

    void addSubDir(std::string name) {
        m_subDirs[name] = Dir(name, this);
    }

    void addLink(Dir *adress, std::string name) {
        m_links[name] = adress;
    }

    Dir *getLink(std::string name) {
        return m_links[name];
    }

    std::string getName() {
        return m_name;
    }

    Dir &operator[](std::string name) {
        return m_subDirs[name];
    }

    std::string getPath() {
        std::vector<std::string> folders;
        Dir *curr = this;
        while (curr->m_parent != nullptr) {
            folders.push_back(curr->getName());
            curr = curr->m_parent;
        }
        std::string path = "/";
        while (!folders.empty()) {
            path.append(folders.back());
            folders.pop_back();
            path.append("/");
        }
        return path;
    }
    void makeSystemFile() {
        m_isSystemFile = true;
    }
    bool isSystemFile() {
        return m_isSystemFile;
    }

    std::map<std::string, Dir> *getSubdirs() {
        return &m_subDirs;
    }

    std::map<std::string, Dir *> *getLinks() {
        return &m_links;
    }
    Dir *getParent() {
        return m_parent;
    }
};

class MSD : public IMSD {
    Dir m_home;

   public:
    void init() {
        m_home = Dir();
    }

    void makeDir(char *path, char *name) {
        std::queue<std::string> folders;
        std::string buf;
        for (int i = 0; path[i] != '\0'; i++) {
            if (path[i] == '/' && i != 0) {
                folders.push(buf);
                buf.clear();
            } else if (i != 0)
                buf.push_back(path[i]);
        }

        if (folders.empty()) {
            m_home.addSubDir(std::string(name));
        } else {
            Dir *curr = &m_home;
            while (curr->getName() != folders.back()) {
                curr = &(*curr)[folders.front()];
                folders.pop();
            }
            curr->addSubDir(std::string(name));
        }
    }

    void makeLink(char *pathSrc, char *pathDst) {
        Dir *src = &m_home;
        Dir *dst = &m_home;

        std::string buf;
        for (int i = 0; pathSrc[i] != '\0'; i++) {
            if (pathSrc[i] == '/' && i != 0) {
                src = &(*src)[buf];
                buf.clear();
            } else if (i != 0)
                buf.push_back(pathSrc[i]);
        }
        for (int i = 0; pathDst[i] != '\0'; i++) {
            if (pathDst[i] == '/' && i != 0) {
                dst = &(*dst)[buf];
                buf.clear();
            } else if (i != 0)
                buf.push_back(pathDst[i]);
        }
        src->addLink(dst, pathDst);
    }

    void makeSystemFile(char *path) {
        Dir *curr = &m_home;

        std::string buf;
        for (int i = 0; path[i] != '\0'; i++) {
            if (path[i] == '/' && i != 0) {
                curr = &(*curr)[buf];
                buf.clear();
            } else if (i != 0)
                buf.push_back(path[i]);
        }
        curr->makeSystemFile();
    }

    void getMostSafeDir(char *result) {
        std::map<Dir *, int> security;
        std::queue<Dir *> queue;
        std::vector<Dir *> sysFiles;
        std::set<Dir *> seen;

        // SCAN FOR SYSTEM FILES
        queue.push(&m_home);
        while (!queue.empty()) {
            if (queue.front()->isSystemFile()) {
                sysFiles.push_back(queue.front());
            }

            std::map<std::string, Dir> *dirs = queue.front()->getSubdirs();
            for (auto it = dirs->begin(); it != dirs->end(); it++) {
                queue.push(&(it->second));
            }
            queue.pop();
        }

        // BFS FROM SYSTEM FILES TO SET SECURITY LEVELS
        for (auto i : sysFiles) {
            seen.clear();
            queue = std::queue<Dir *>();
            queue.push(i);
            std::queue<Dir *> new_queue;
            for (int security_level = 0; !queue.empty(); security_level++, new_queue = std::queue<Dir *>()) {
                while (!queue.empty()) {
                    if (seen.count(queue.front()) != 0) {
                        queue.pop();
                        continue;
                    }
                    seen.insert(queue.front());

                    if (security.count(queue.front()) == 0)
                        security[queue.front()] = security_level;
                    else {
                        if (security[queue.front()] > security_level)
                            security[queue.front()] = security_level;
                    }

                    auto dirs = queue.front()->getSubdirs();
                    for (auto &i : *dirs) {
                        new_queue.push(&i.second);
                    }
                    auto links = queue.front()->getLinks();
                    for (auto &i : *links) {
                        new_queue.push(i.second);
                    }
                    if (queue.front()->getParent() != nullptr)
                        new_queue.push(queue.front()->getParent());

                    queue.pop();
                }
                queue = new_queue;
            }
        }

        // Get most secure location
        int max = 0;
        for (auto i : security) {
            if (i.second > max) {
                max = i.second;
                strcpy(result, i.first->getPath().c_str());
            }
        }
    }
};

MSD solution;
int main() {
    freopen("in/MSD0c.in", "r", stdin);
    Judge::run(&solution);
    return 0;
}
