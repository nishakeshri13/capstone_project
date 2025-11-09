#include <bits/stdc++.h>
#include <filesystem>
#include <chrono>
using namespace std;
namespace fs = std::filesystem;

// ---------- Existing Commands ----------
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

// ---------- New Day 3 Commands ----------
void cmd_cp(const string &src, const string &dest) {
    try {
        fs::copy(src, dest, fs::copy_options::overwrite_existing);
        cout << "Copied " << src << " to " << dest << "\n";
    } catch (...) {
        cout << "cp: failed to copy file\n";
    }
}

void cmd_mv(const string &src, const string &dest) {
    try {
        fs::rename(src, dest);
        cout << "Moved " << src << " to " << dest << "\n";
    } catch (...) {
        cout << "mv: failed to move/rename file\n";
    }
}

void cmd_rm(const string &target) {
    try {
        if (fs::remove(target))
            cout << "Removed: " << target << "\n";
        else
            cout << "rm: no such file or directory\n";
    } catch (...) {
        cout << "rm: failed to remove\n";
    }
}

void cmd_info(const string &file) {
    try {
        if (!fs::exists(file)) {
            cout << "info: file not found\n";
            return;
        }
        auto ftime = fs::last_write_time(file);
        auto sctp = chrono::time_point_cast<chrono::system_clock::duration>(
            ftime - fs::file_time_type::clock::now() + chrono::system_clock::now()
        );
        time_t cftime = chrono::system_clock::to_time_t(sctp);
        cout << "File: " << file << "\n";
        cout << "Type: " << (fs::is_directory(file) ? "Directory" : "File") << "\n";
        cout << "Size: " << fs::file_size(file) << " bytes\n";
        cout << "Last modified: " << ctime(&cftime);
    } catch (...) {
        cout << "info: error reading file details\n";
    }
}

// ---------- Main ----------
int main() {
    cout << "Simple File Explorer - Day 3\n";
    cout << "Commands: ls, pwd, cd, mkdir, touch, cp, mv, rm, info, exit\n";

    string line;
    while (true) {
        cout << fs::current_path().string() << " $ ";
        getline(cin, line);
        stringstream ss(line);
        string cmd, arg1, arg2;
        ss >> cmd >> arg1 >> arg2;

        if (cmd == "pwd") cmd_pwd();
        else if (cmd == "ls") cmd_ls();
        else if (cmd == "cd") cmd_cd(arg1);
        else if (cmd == "mkdir") cmd_mkdir(arg1);
        else if (cmd == "touch") cmd_touch(arg1);
        else if (cmd == "cp") cmd_cp(arg1, arg2);
        else if (cmd == "mv") cmd_mv(arg1, arg2);
        else if (cmd == "rm") cmd_rm(arg1);
        else if (cmd == "info") cmd_info(arg1);
        else if (cmd == "exit") break;
        else if (!cmd.empty()) cout << "Unknown command\n";
    }

    cout << "Exiting File Explorer\n";
    return 0;
}