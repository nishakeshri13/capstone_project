#  File Explorer – Linux Capstone Project (C++)

###  Overview
The **File Explorer Capstone Project** is a Linux-based, terminal-driven file management system developed using **C++17**.  
It replicates the functionality of a Linux shell — allowing users to **navigate**, **create**, **move**, **copy**, and **analyze files and directories** through command-line commands.

Built and tested on **Ubuntu (via WSL2)** using **VS Code**, this project demonstrates expertise in **Linux System Programming**, **C++ STL**, and **filesystem operations**.

---

##  Objective
To design and implement a **simple command-line File Explorer** that performs fundamental file and directory operations in Linux — while reinforcing system-level programming concepts in C++.

---

##  Technologies Used

| Tool / Technology | Purpose |
|-------------------|----------|
| **C++17 STL** | Core programming language |
| **Filesystem Library** | File and directory handling |
| **WSL2 (Ubuntu)** | Linux runtime environment |
| **VS Code** | Code editor & build environment |
| **Makefile** | Build automation |
| **Git & GitHub** | Version control and documentation |

---

##  Day-wise Progress

###  **Day 1 – Basic Setup & Commands**
**Implemented Commands:**  
- `pwd` → Print working directory  
- `ls` → List files/folders  
- `exit` → Exit the program  

**Highlights:**  
- Project setup and environment configuration  
- Tested basic shell commands in C++  
- Implemented Makefile for compilation  

---

###  **Day 2 – Directory Navigation & File Creation**
**Implemented Commands:**  
- `cd <dir>` → Change directory  
- `mkdir <dir>` → Create directory  
- `touch <file>` → Create a new file  

**Highlights:**  
- Introduced `std::filesystem::current_path()`  
- Added exception handling for invalid directories  
- Practiced argument parsing and validation  

---

###  **Day 3 – File Manipulation & Information Retrieval**
**Implemented Commands:**  
- `cp <src> <dest>` → Copy file  
- `mv <src> <dest>` → Move or rename file  
- `rm <file>` → Remove file  
- `info <file>` → Display file information  

**Highlights:**  
- Used `std::filesystem::copy`, `rename`, `remove`  
- Implemented `chrono` for last modified time  
- Improved error handling and input validation  

---

###  **Day 4 – Search, Tree & Help**
**Implemented Commands:**  
- `find <name>` → Search recursively for file/folder  
- `tree` → Display directory structure  
- `help` → Show command guide  

**Highlights:**  
- Recursive directory traversal  
- Implemented visual `tree` command output  
- Added in-terminal help menu  

---

###  **Day 5 – History, Clear & Exit Confirmation**
**Implemented Commands:**  
- `history` → Show executed commands  
- `clear` → Clear terminal screen  
- `exit` → With user confirmation  

**Highlights:**  
- Implemented command history vector  
- Enhanced UI/UX with clear screen feature  
- Final testing and code optimization  

---

##  Project Screenshots

| Day | Description | Screenshot |
|:---:|:-------------|:------------|
| **Day 1** | Basic setup – `pwd`, `ls`, `exit` |
| **Day 2** | Navigation – `cd`, `mkdir`, `touch'|
| **Day 3** | File management – `cp`, `mv`, `rm`, `info` |
| **Day 4** | Search & tree view – `find`, `tree`, `help` |
| **Day 5** | Final version – `history`, `clear`, `exit` | 

---

##  Project Structure

```
file-explorer-capstone/
├── Day1/
│   └── file_explorer.cpp
├── Day2/
│   └── file_explorer.cpp
├── Day3/
│   └── file_explorer.cpp
├── Day4/
│   └── file_explorer.cpp
├── Day5/
│   └── file_explorer.cpp
├── src/
│   └── file_explorer.cpp     # Final version (Day 5)
├── screenshots/
│   ├── day1.png
│   ├── day2.png
│   ├── day3.png
│   ├── day4.png
│   └── day5.png
├── Makefile
├── README.md
└── .gitignore
```

---

##  Build & Run Instructions

###  Build
```bash
make
```

###  Run
```bash
./file_explorer
```

###  Clean
```bash
make clean
```

---

##  Example Session

```bash
pwd
ls
mkdir test
cd test
touch file.txt
info file.txt
cp file.txt backup.txt
mv backup.txt ../
find file.txt
tree
history
exit
```

---

##  Author

**NISHA KESHRI**  
🎓 Linux System Programming | C++ Developer | Automation Enthusiast  
📧 [nishakeshri967@gmail.com]
🌐 [GitHub Profile](https://github.com/nishakeshri13)

---

## Conclusion

This project demonstrates a practical understanding of:
- Linux filesystem operations  
- Command-line interface development  
- Modern C++17 features and STL  
- Structured software design and documentation  



