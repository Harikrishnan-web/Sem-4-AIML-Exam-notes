## 1A.Basics of Linux Commands

**Aim**
To explore and execute fundamental Linux commands for file management, directory navigation, and basic system interaction.

**Algorithm**

1. **Terminal Initialization:** Launch the terminal interface to begin the command-line session.
2. **Current Path Identification:** Use `pwd` to confirm the current active directory.
3. **Directory Navigation:** Use `cd` to enter specific folders or `cd ..` to retreat to the parent directory.
4. **Resource Creation:** Use `mkdir` to generate new directories and `touch` to create empty files.
5. **Content Listing:** Use `ls` to view all files and subdirectories in the current location.
6. **File Manipulation:** Use `cp` to duplicate files and `cat` to read their contents.
7. **Cleanup:** Use `rmdir` to remove directories that are no longer needed.

**Linux Commands**

* **pwd**
* **Function:** Displays the absolute path of the current working directory.
* **Step:** Type `pwd` and press Enter.


* **ls**
* **Function:** Lists the files and folders within the current directory.
* **Step:** Type `ls` to see the contents of your folder.


* **touch**
* **Function:** Creates a new, empty file.
* **Step:** Type `touch filename.txt` to create a file.


* **mkdir**
* **Function:** Creates a new directory (folder).
* **Step:** Type `mkdir directory_name` to create a new folder.


* **cd**
* **Function:** Changes the directory to a specified path.
* **Step:** Type `cd folder_name` to navigate into that folder.


* **cd ..**
* **Function:** Moves the user back to the parent directory.
* **Step:** Type `cd ..` to go one level up.


* **cat**
* **Function:** Displays the content of a text file.
* **Step:** Type `cat filename.txt` to read the file.


* **cp**
* **Function:** Copies a file from one location to another.
* **Step:** Type `cp source_file destination_file`.


* **rmdir**
* **Function:** Removes an empty directory.
* **Step:** Type `rmdir directory_name` to delete the folder.



**Sample Output**

```text
student@workstation:~$ pwd
/home/student
student@workstation:~$ touch part1.txt
student@workstation:~$ ls
part1.txt
student@workstation:~$ cat part1.txt
student@workstation:~$

```

---

## 1B.Writing and Editing Text Files Using VIM Editor

**Aim**
To demonstrate the ability to create and modify text files using the VIM editor's distinct operational modes.

**Algorithm**

1. **Open Editor:** Launch VIM with a new or existing filename; the editor starts in **Normal Mode**.
2. **Switch to Insert Mode:** Press `i` to enable text entry.
3. **Input Text:** Type the desired content into the file.
4. **Return to Normal Mode:** Press the `Esc` key to stop editing and enable commands.
5. **Enter Command Mode:** Type `:` to access the command line at the bottom of the screen.
6. **Save and Exit:** Use the command `wq` to write changes to the disk and quit the editor.

**VIM Steps and Commands**

* **Step 1: Start VIM**
* **Function:** Opens the file for editing.
* **Command:** `vim sample.txt`


* **Step 2: Enable Insert Mode**
* **Function:** Allows the user to type characters.
* **Command:** Press `i`


* **Step 3: Exit Insert Mode**
* **Function:** Returns the user to Normal Mode for navigation and commands.
* **Command:** Press `Esc`


* **Step 4: Save Changes**
* **Function:** Writes the text to the file.
* **Command:** Type `:w`


* **Step 5: Exit VIM**
* **Function:** Closes the editor.
* **Command:** Type `:wq` (Save and Exit) or `:q!` (Exit without saving).



**Sample Output**

```text
student@workstation:~$ vim sample.txt
[User types: Operating Systems Lab Learning VIM editor commands.]
student@workstation:~$ cat sample.txt
Operating Systems Lab Learning VIM editor commands.

```

---
## 2.Linux File System Hierarchic Commands

**Aim**
To implement and understand Linux commands used for managing the file system hierarchy, including moving, renaming, permission handling, and visualizing directory structures.

**Algorithm**

1. **File Management:** Use the `mv` command to either relocate files to different directories or rename them within the same directory.
2. **File Creation:** Generate new, empty files using the `touch` command to establish placeholders in the hierarchy.
3. **Permission Control:** Modify access levels using `chmod` to define who can read, write, or execute a file.
4. **Ownership Assignment:** Use `chown` to change the user ownership of specific files or directories.
5. **Storage Analysis:** Execute `df` to review the disk space usage across different mounted file systems.
6. **Structural Visualization:** Use the `tree` command to display a recursive, visual representation of directories and files.

**Linux Commands**

* **mv (Move/Rename)**
* **Function:** Moves files to a new location or renames them.
* **Step:** Type `mv` followed by the source filename and the destination filename/path.


* **touch (Create Empty File)**
* **Function:** Creates a new empty file if it doesn't exist.
* **Step:** Type `touch` followed by the desired filename.


* **chmod (Change Permissions)**
* **Function:** Changes the access permissions of a file using numeric or symbolic modes.
* **Step:** Type `chmod` followed by the permission code (e.g., 755) and the filename.


* **chown (Change Owner)**
* **Function:** Changes the owner of a file or directory.
* **Step:** Type `chown` followed by the username and the filename.


* **df (Disk Free)**
* **Function:** Displays the amount of available and used disk space on file systems.
* **Step:** Type `df -h` to see the space in a human-readable format (GB/MB).


* **tree**
* **Function:** Displays the directory structure in a visual tree format.
* **Step:** Type `tree` for the current folder or `tree directory_name` for a specific path.



**Sample Output**

```text
student@workstation:~$ mv copy.txt copy1.txt
student@workstation:~$ touch sample.txt
student@workstation:~$ chmod 755 sample.txt
student@workstation:~$ df -h
Filesystem      Size  Used  Avail Use% Mounted on
/dev/sda3        20G  6.6G    14G  34% /
student@workstation:~$ tree sample
sample
├── app
├── base
├── operating
└── system
1 directory, 4 files

```

---