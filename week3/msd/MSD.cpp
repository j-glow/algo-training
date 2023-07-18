#include <set>
#include <string>
#include <ranges>

#include <iomanip>
#include <iostream>
#include <ranges>
#include <string_view>

#include "judge.h"

class Dir {
    std::string m_name;
    Dir *m_parent;
    std::set<Dir> m_subDirs;
    std::set<Dir*> m_links;

   public:
    Dir() {
        m_name = std::string("");
        m_parent = nullptr;
        m_subDirs = std::set<Dir>();
    }
    Dir(std::string name, Dir *parent) {
        m_name = name;
        m_parent = parent;
        m_subDirs = std::set<Dir>();
    }
    void addSubDir(std::string name) {
        m_subDirs.insert(Dir(name, this));
    }
    void addLink(Dir *linkChild) {
		m_links.insert(linkChild);
    }
	void findSubFolder(){}
};

class MSD : public IMSD {
    Dir home;

   public:
    void init() {
        home = Dir();
    }

    void makeDir(char *path, char *name) {
		std::string parent = path;
		std::string child = name;
		for ();
    }

    void makeLink(char *pathSrc, char *pathDst) {
    }

    void makeSystemFile(char *path) {
    }

    void getMostSafeDir(char *result) {
    }
};

MSD solution;
int main() {
    Judge::run(&solution);
    return 0;
}
