# 🚀 PROCview – Custom Linux Process Viewer (my_ps)

## 📌 Project Overview

PROCview is a custom Linux command-line tool written in C.
It creates a user-defined command called `my_ps` that merges the output of:

- ps aux
- ps -eLf

The merged output is stored in merged.txt and displayed on the terminal.

---

## 🎯 Objective

This project demonstrates:

- Linux process monitoring
- System call usage (system())
- File handling in C
- Command-line tool creation
- Shell output redirection

---

## 🧠 Concepts Used

- system()
- fopen(), fclose()
- fgets(), fprintf()
- Shell redirection (>)
- Linux process commands

---

## ⚙️ How It Works

1. Executes:
   ps aux > x1.txt
   ps -eLf > x2.txt

2. Opens both files in C.
3. Merges their contents into merged.txt.
4. Displays merged.txt in terminal.

---

## 🛠 Compilation

gcc project3_AI.c -o my_ps

---

## ▶️ Execution

./my_ps

---

## 💻 Install As Custom Command

sudo cp my_ps /usr/local/bin/
my_ps

---

## 📂 Files Generated

- x1.txt
- x2.txt
- merged.txt
- my_ps

---

## 👨‍💻 Author

Md Rehan Ansari  
B.Tech CSE  
NIT Durgapur

