#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <ranges>
#include <string>
#include <vector>

#include "judge.h"

class Dir {
    std::string m_name = std::string("");
    Dir *m_parent = nullptr;
    std::map<std::string, Dir> m_subDirs = std::map<std::string, Dir>();
    std::map<std::string, Dir *> m_links = std::map<std::string, Dir *>();
    bool m_isSystemFile = false;

   public:
    Dir() {
    }

    Dir(std::string name, Dir *parent) : 
    m_name(name), m_parent(parent) {
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
        Dir curr = *this;
        while (curr.m_parent != nullptr) {
            folders.push_back(curr.getName());
            curr = *m_parent;
        }
        std::string path = "/";
        while (!folders.empty()) {
            path.append(folders.back());
            folders.pop_back();
            path.append("/");
        }
        return path;
    }
    void makeSystemFile(){
        m_isSystemFile = true;
    }
};

class MSD : public IMSD {
    Dir home;

   public:
    void init() {
        home = Dir();
    }

    void makeDir(char *path, char *name) {
        std::queue<std::string> pathfolders;
        std::string buf;
        for (int i = 0; path[i] != '\0'; i++) {
            if (path[i] == '/' && i != 0) {
                pathfolders.push(buf);
                buf.clear();
            } else
                buf.push_back(path[i]);
        }

        std::string child = name;
        if (pathfolders.empty()) {
            home.addSubDir(name);
        } else {
            Dir curr;
            while (curr.getName() != pathfolders.back()) {
                curr = curr[pathfolders.front()];
                pathfolders.pop();
            }
            curr.addSubDir(name);
        }
    }

    void makeLink(char *pathSrc, char *pathDst) {
        Dir src = home;
        Dir dst = home;

        std::string buf;
        for (int i = 0; pathSrc[i] != '\0'; i++) {
            if (pathSrc[i] == '/' && i != 0) {
                src = home[buf];
                buf.clear();
            } else
                buf.push_back(pathSrc[i]);
        }
        for (int i = 0; pathDst[i] != '\0'; i++) {
            if (pathDst[i] == '/' && i != 0) {
                dst = home[buf];
                buf.clear();
            } else
                buf.push_back(pathDst[i]);
        }
        src.addLink(&dst,pathDst);
    }

    void makeSystemFile(char *path) {
        Dir curr = home;

        std::string buf;
        for (int i = 0; path[i] != '\0'; i++) {
            if (path[i] == '/' && i != 0) {
                curr = home[buf];
                buf.clear();
            } else
                buf.push_back(path[i]);
        }
        curr.makeSystemFile();
    }

    void getMostSafeDir(char *result) {
    }
};

MSD solution;
int main() {
    freopen("in/MSD0a.in", "r", stdin);
    Judge::run(&solution);
    return 0;
}
