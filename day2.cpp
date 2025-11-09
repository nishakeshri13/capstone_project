#include <bits/stdc++.h>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

// ----------- Existing Commands -----------
void cmd_pwd() {
    cout << fs::current_path().string() << "\n";
}

void cmd_ls() {
    for (auto &entry : fs::directory_iterator(fs::current_path())) {
        cout << entry.path().filename().string();
        if (entry.is_directory()) cout << "/";
        cout << "\n";
    }
}

// ----------- New Day 2 Commands -----------
void cmd_cd(const string &path) {
    try {
        fs::current_path(path);
    } catch (...) {
        cout << "cd: no such directory\n";
    }
}

void cmd_mkdir(const string &dir) {
    try {
        if (fs::create_directory(dir))
            cout << "Directory created: " << dir << "\n";
        else
            cout << "mkdir: directory already exists or failed\n";
    } catch (...) {
        cout << "mkdir: failed to create directory\n";
    }
}

void cmd_touch(const string &file) {
    ofstream f(file);
    if (f)
        cout << "File created: " << file << "\n";
    else
        cout << "touch: failed to create file\n";
    f.close();
}

// ----------- Main Loop -----------
int main() {
    cout << "Simple File Explorer - Day 2\n";
    cout << "Commands: ls, pwd, cd, mkdir, touch, exit\n";

    string line;
    while (true) {
        cout << fs::current_path().string() << " $ ";
        getline(cin, line);
        stringstream ss(line);
        string cmd, arg;
        ss >> cmd >> arg;

        if (cmd == "pwd") cmd_pwd();
        else if (cmd == "ls") cmd_ls();
        else if (cmd == "cd") cmd_cd(arg);
        else if (cmd == "mkdir") cmd_mkdir(arg);
        else if (cmd == "touch") cmd_touch(arg);
        else if (cmd == "exit") break;
        else if (!cmd.empty()) cout << "Unknown command\n";
    }

    cout << "Exiting File Explorer\n";
    return 0;
}