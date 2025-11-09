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
        if (fs::remove_all(target))
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
        if (!fs::is_directory(file))
            cout << "Size: " << fs::file_size(file) << " bytes\n";
        cout << "Last modified: " << ctime(&cftime);
    } catch (...) {
        cout << "info: error reading file details\n";
    }
}

// ---------- New Day 4 Commands ----------
void search_recursive(const fs::path &path, const string &target) {
    try {
        for (auto &entry : fs::recursive_directory_iterator(path)) {
            if (entry.path().filename().string().find(target) != string::npos) {
                cout << entry.path().string() << "\n";
            }
        }
    } catch (...) {
        cout << "find: error during search\n";
    }
}

void cmd_find(const string &target) {
    if (target.empty()) {
        cout << "Usage: find <name>\n";
        return;
    }
    cout << "Searching for '" << target << "'...\n";
    search_recursive(fs::current_path(), target);
}

void print_tree(const fs::path &path, string prefix = "") {
    try {
        for (auto &entry : fs::directory_iterator(path)) {
            cout << prefix << "|-- " << entry.path().filename().string();
            if (entry.is_directory()) {
                cout << "/" << "\n";
                print_tree(entry.path(), prefix + "    ");
            } else {
                cout << "\n";
            }
        }
    } catch (...) {
        cout << "tree: error reading directory\n";
    }
}

void cmd_tree() {
    cout << fs::current_path().string() << "\n";
    print_tree(fs::current_path());
}

void cmd_help() {
    cout << "\nAvailable Commands:\n";
    cout << "------------------------------------------\n";
    cout << "pwd                - Show current directory\n";
    cout << "ls                 - List files and folders\n";
    cout << "cd <dir>           - Change directory\n";
    cout << "mkdir <dir>        - Create a directory\n";
    cout << "touch <file>       - Create a file\n";
    cout << "cp <src> <dest>    - Copy file\n";
    cout << "mv <src> <dest>    - Move or rename file\n";
    cout << "rm <target>        - Delete file or folder\n";
    cout << "info <file>        - Show file info\n";
    cout << "find <name>        - Search by filename\n";
    cout << "tree               - Display folder tree\n";
    cout << "help               - Show this help message\n";
    cout << "exit               - Exit the explorer\n";
    cout << "------------------------------------------\n\n";
}

// ---------- Main ----------
int main() {
    cout << "Simple File Explorer - Day 4\n";
    cout << "Type 'help' for list of commands.\n";

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
        else if (cmd == "find") cmd_find(arg1);
        else if (cmd == "tree") cmd_tree();
        else if (cmd == "help") cmd_help();
        else if (cmd == "exit") break;
        else if (!cmd.empty()) cout << "Unknown command\n";
    }

    cout << "Exiting File Explorer\n";
    return 0;
}