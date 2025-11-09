#include <bits/stdc++.h>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void cmd_pwd() {
    cout << fs::current_path().string() << "\n";
}

void cmd_ls() {
    for (auto &entry : fs::directory_iterator(fs::current_path())) {
        cout << entry.path().filename().string();
        if (entry.is_directory()) cout << "/"; // mark directories
        cout << "\n";
    }
}

int main() {
    cout << "Simple File Explorer - Day 1\n";
    cout << "Commands: ls, pwd, exit\n";

    string cmd;
    while (true) {
        cout << fs::current_path().string() << " $ ";
        getline(cin, cmd);

        if (cmd == "pwd") cmd_pwd();
        else if (cmd == "ls") cmd_ls();
        else if (cmd == "exit") break;
        else if (!cmd.empty()) cout << "Unknown command\n";
    }

    cout << "Exiting File Explorer\n";
    return 0;
}