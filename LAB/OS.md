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
## 3. CPU scheduling

**Aim**
To implement and analyze various CPU scheduling algorithms including FCFS, SJF, Priority, and Round Robin to determine process execution order and calculate waiting and turnaround times.

**Algorithm**

1. Start the program and read the total number of processes.
2. For each process, input the burst time. For Priority scheduling, input the priority level. For Round Robin, input the time quantum.
3. **FCFS:** Process tasks in the order they were entered. Waiting time is the sum of burst times of all preceding tasks.
4. **SJF:** Sort processes by their burst times in ascending order. Execute the shortest task first to minimize the average wait.
5. **Priority:** Sort processes based on priority values. Execute the highest priority task (lowest number) first.
6. **Round Robin:** Use a circular queue and execute each process for a fixed time quantum. If a process doesn't finish, move it to the end of the queue.
7. Calculate Turnaround Time as Burst Time + Waiting Time for every process.
8. Display the results for each algorithm in a table.

**C Program**

```c
#include <stdio.h>

void fcfs(int n, int bt[]) {
    int wt[20], tat[20], i;
    wt[0] = 0;
    for(i=1; i<n; i++) wt[i] = wt[i-1] + bt[i-1];
    for(i=0; i<n; i++) tat[i] = wt[i] + bt[i];
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i=0; i<n; i++) printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
}

void sjf(int n, int bt[]) {
    int wt[20], tat[20], p[20], i, j, temp;
    for(i=0; i<n; i++) p[i] = i+1;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(bt[i] > bt[j]) {
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
                temp=p[i]; p[i]=p[j]; p[j]=temp;
            }
        }
    }
    wt[0] = 0;
    for(i=1; i<n; i++) wt[i] = wt[i-1] + bt[i-1];
    for(i=0; i<n; i++) tat[i] = wt[i] + bt[i];
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i=0; i<n; i++) printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
}

void priority(int n, int bt[], int pr[]) {
    int wt[20], tat[20], p[20], i, j, temp;
    for(i=0; i<n; i++) p[i] = i+1;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(pr[i] > pr[j]) {
                temp=pr[i]; pr[i]=pr[j]; pr[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
                temp=p[i]; p[i]=p[j]; p[j]=temp;
            }
        }
    }
    wt[0] = 0;
    for(i=1; i<n; i++) wt[i] = wt[i-1] + bt[i-1];
    for(i=0; i<n; i++) tat[i] = wt[i] + bt[i];
    printf("\nProcess\tBT\tPR\tWT\tTAT\n");
    for(i=0; i<n; i++) printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
}

void rr(int n, int bt[], int tq) {
    int wt[20], tat[20], rem[20], i, time=0, done;
    for(i=0; i<n; i++) rem[i] = bt[i];
    do {
        done = 1;
        for(i=0; i<n; i++) {
            if(rem[i] > 0) {
                done = 0;
                if(rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }
    } while(!done);
    for(i=0; i<n; i++) tat[i] = bt[i] + wt[i];
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i=0; i<n; i++) printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
}

int main() {
    int n, bt[20], pr[20], tq, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);
    }
    printf("\n--- FCFS ---");
    fcfs(n, bt);
    printf("\n--- SJF ---");
    sjf(n, bt);
    printf("\n--- Priority ---");
    for(i=0; i<n; i++) {
        printf("Priority for P%d: ", i+1);
        scanf("%d", &pr[i]);
    }
    priority(n, bt, pr);
    printf("\n--- Round Robin ---");
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    rr(n, bt, tq);
    return 0;
}

```

**Sample Output**

**1. FCFS**

```text
Enter number of processes: 3
Enter Burst Time for P1: 5
Enter Burst Time for P2: 3
Enter Burst Time for P3: 8

Process BT WT TAT
P1      5  0  5
P2      3  5  8
P3      8  8  16

```

**2. SJF**

```text
Enter number of processes: 4
Enter Burst Time for P1: 6
Enter Burst Time for P2: 2
Enter Burst Time for P3: 8
Enter Burst Time for P4: 3

Process BT WT TAT
P2      2  0  2
P4      3  2  5
P1      6  5  11
P3      8  11 19

```

**3. Priority**

```text
Enter number of processes: 4
Burst time for P1: 5
Priority for P1: 2
Burst time for P2: 3
Priority for P2: 1
Burst time for P3: 8
Priority for P3: 4
Burst time for P4: 6
Priority for P4: 3

Process BT PR WT TAT
P2      3  1  0  3
P1      5  2  3  8
P4      6  3  8  14
P3      8  4  14 22

```

**4. Round Robin**

```text
Enter number of processes: 3
Burst time for P1: 5
Burst time for P2: 3
Burst time for P3: 1
Enter Time Quantum: 2

Process BT WT TAT
P1      5  4  9
P2      3  5  8
P3      1  4  5

```

---
## 4A.User and Permission Management: Create and manage users and groups 

**Aim**
To perform user and group management in Linux by creating accounts, setting passwords, managing home directories, and organizing users into groups using administrative commands.

**Algorithm**

1. **Gain Root Access:** Switch to the superuser or use administrative privileges to execute management commands.
2. **User Creation:** Create new user accounts with or without default home directories using specific flags.
3. **Security Setup:** Assign secure passwords to newly created users to enable account login.
4. **Group Management:** Create new groups to categorize users and delete them when no longer required.
5. **Account Modification:** Add users to secondary groups or change their primary group assignments.
6. **Verification:** Inspect system configuration files and use identity commands to verify that changes have been applied correctly.
7. **Cleanup:** Delete user accounts and their associated files to maintain system tidiness.

**Commands and Explanation**

1. **su root**
* **Function:** Switches the current session to the root user.
* **Step:** Run `su root` and enter the administrative password to gain full control.


2. **useradd user5**
* **Function:** Creates a new user account named "user5".
* **Step:** Run `useradd user5` to add the user to the system.


3. **useradd -m user6**
* **Function:** Creates a new user and automatically generates a home directory.
* **Step:** Use the `-m` flag to ensure the user has a personal space at `/home/user6`.


4. **passwd user6**
* **Function:** Sets or updates the password for the specified user.
* **Step:** Run `passwd user6` and type the new password twice when prompted.


5. **userdel -r user10**
* **Function:** Deletes the user and removes their home directory.
* **Step:** Use the `-r` flag to clean up all files associated with "user10".


6. **groupadd group11**
* **Function:** Creates a new system group.
* **Step:** Run `groupadd group11` to create a group for team organization.


7. **usermod -aG group1 user12**
* **Function:** Adds an existing user to a secondary (supplementary) group.
* **Step:** The `-aG` flag ensures the user stays in their current groups while joining "group1".


8. **id user12**
* **Function:** Displays the UID, GID, and group memberships for a user.
* **Step:** Run `id user12` to confirm the group addition was successful.


9. **cat /etc/passwd**
* **Function:** Lists all user accounts defined in the system.
* **Step:** View this file to see user IDs, home directories, and shell types.


10. **cat /etc/group**
* **Function:** Lists all groups and their members.
* **Step:** View this file to verify group creation and user assignments.


11. **whoami**
* **Function:** Displays the username of the current logged-in user.
* **Step:** Run `whoami` to confirm if you are operating as root or a standard user.



**Sample Input**

```text
su root
useradd user5
passwd user6
groupadd group1
usermod -aG group1 user12
id user12

```

**Sample Output**

```text
root@workstation:~# useradd user5
root@workstation:~# passwd user6
New password:
Retype new password:
passwd: password updated successfully
root@workstation:~# id user12
uid=1005(user12) gid=1005(user12) groups=1005(user12),1006(group1)
root@workstation:~# whoami
root

```
---
## 4B.User and Permission Management: Configure file permissions, ownership and group ownership
**Aim**
To manage and configure file security in Linux by modifying file permissions using numeric and symbolic modes, and changing user and group ownership of files and directories.

**Algorithm**

1. **Identify Attributes:** Use the long listing command to check current permissions and owners of a file.
2. **Permission Modification (Numeric):** Apply octal values (e.g., 755) to set absolute read, write, and execute permissions for owner, group, and others.
3. **Permission Modification (Symbolic):** Use specific symbols (u, g, o) and operators (+, -, =) to add or remove specific access rights.
4. **Ownership Transfer:** Change the specific user who owns the file to a different account.
5. **Group Assignment:** Assign the file to a specific group to manage team-based access.
6. **Recursive Application:** Apply permission or ownership changes to an entire directory tree including all sub-files and sub-folders.
7. **Special Bit Configuration:** Set advanced permissions like SUID, SGID, or the Sticky Bit for specialized execution and deletion behavior.

**Commands and Explanation**

1. **ls -l demo.txt**
* **Function:** Displays detailed information including permissions, owner, and group.
* **Step:** Run `ls -l` followed by the filename to view the current security metadata.


2. **chmod 755 demo.txt**
* **Function:** Changes permissions using numeric (octal) mode.
* **Step:** Run `chmod 755` where 7 is for owner (rwx), 5 for group (r-x), and 5 for others (r-x).


3. **chmod u+x demo.txt**
* **Function:** Adds execute permission for the user (owner) using symbolic mode.
* **Step:** Use `u+x` to grant execution rights without affecting other bits.


4. **chown user12 demo.txt**
* **Function:** Changes the owner of the file to "user12".
* **Step:** Type `chown` followed by the new username and the file name.


5. **chgrp group1 demo.txt**
* **Function:** Changes the group ownership of the file to "group1".
* **Step:** Type `chgrp` followed by the group name and the file name.


6. **chown user12:group1 demo.txt**
* **Function:** Changes both the owner and the group in a single command.
* **Step:** Use the `user:group` syntax to update both attributes simultaneously.


7. **chmod -R 755 /home/student/data**
* **Function:** Changes permissions recursively for a directory and all its contents.
* **Step:** Add the `-R` flag to ensure every file inside the folder is updated.


8. **chmod u+s filename**
* **Function:** Sets the SUID (Set User ID) bit.
* **Step:** Run `chmod u+s` so the file executes with the permissions of the owner.


9. **chmod g+s directory**
* **Function:** Sets the SGID (Set Group ID) bit on a directory.
* **Step:** Run `chmod g+s` so new files created inside inherit the directory's group.


10. **chmod +t directory**
* **Function:** Sets the Sticky Bit on a directory.
* **Step:** Run `chmod +t` to prevent users from deleting files owned by others in a shared folder.



**Sample Input**

```text
ls -l demo.txt
chmod 755 demo.txt
chown user12 demo.txt
chgrp group1 demo.txt
ls -l demo.txt

```

**Sample Output**

```text
root@workstation:~# ls -l demo.txt
-rw-r--r-- 1 root root Feb 22 10:31 demo.txt

root@workstation:~# chmod 755 demo.txt
root@workstation:~# chown user12 demo.txt
root@workstation:~# chgrp group1 demo.txt

root@workstation:~# ls -l demo.txt
-rwxr-xr-x 1 user12 group1 Feb 22 10:31 demo.txt

```
---
## 5A Job Scheduling in Linux using at