# 🐚 Minishell2

> "This isn’t flying. This is falling with style!"  

Minishell2 is a simple Unix-like shell written in C.  
It replicates core features of modern shell environments like Bash, allowing users to run commands, chain them with pipes (`|`), separate them with semicolons (`;`), and use file redirections (`>`, `<`, `>>`, `<<`).

---

## ✨ Features

- Run basic shell commands (e.g. `ls`, `cat`, `cd`)
- Chain commands using:
  - Semicolons `;` (run one after another)
  - Pipes `|` (send output from one to the next)
- Use file redirections:
  - `>` write to a file
  - `>>` append to a file

---

## ⚙️ Installation

1. Clone the repository:
   ```bash
   git clone git@github.com:FloWindels/Minishell.git
   cd Minishell
   ```
2. Compile the project:
    ```bash
    make
    ```
3. Run the shell:
    ```bash
    ./mysh
    ```

## 🧪 Example Usage

```bash
$> ls -l ; echo "Hello world"
$> cat file.txt | grep error
$> echo "42" > answer.txt
```

## 💡 Why?
This project was created as part of the Epitech curriculum to understand how a shell works internally — from parsing input to handling system calls and process management.


## 🙋‍♀️ Author
Made with ❤️ by [@FloWindels](https://github.com/FloWindels)