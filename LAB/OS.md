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
**Aim**
To schedule and manage non-recurring one-time tasks in the Linux environment using the `at` utility and to manage the scheduled job queue.

**Algorithm**

1. **Tool Installation:** Install the `at` package if it is not already present on the system.
2. **Service Initialization:** Start the background daemon `atd` and enable it to ensure it runs automatically on system boot.
3. **Execution Time Specification:** Define the specific time or date for the task execution using the `at` command.
4. **Command Input:** Enter the desired shell commands to be executed at the scheduled time within the interactive `at` prompt.
5. **Job Commitment:** Save the job using the termination sequence (Ctrl+D) to place it in the execution queue.
6. **Queue Monitoring:** Verify the status and job ID of scheduled tasks using the queue listing command.
7. **Cleanup:** If a task is no longer required, remove it from the queue using its specific job ID.

**Commands and Explanation**

1. **sudo apt install at**
* **Function:** Downloads and installs the `at` utility from the repository.
* **Step:** Run this command to ensure the software is available on your Linux distribution.


2. **sudo systemctl start atd**
* **Function:** Starts the `at` daemon, which is the background process responsible for running scheduled jobs.
* **Step:** Execute this to activate the scheduling service immediately.


3. **sudo systemctl enable atd**
* **Function:** Configures the `atd` service to start automatically whenever the system boots up.
* **Step:** This is a crucial step to ensure scheduled jobs are not missed after a system restart.


4. **at 17:30**
* **Function:** Opens an interactive prompt to schedule a task for 5:30 PM.
* **Step:** Type the time and press Enter; you will see the `at>` prompt.


5. **echo "Job Executed" > output.txt**
* **Function:** The actual task to be performed at the scheduled time.
* **Step:** Type the command at the `at>` prompt and press Enter.


6. **Ctrl + D**
* **Function:** Signals the end of input (EOF) and saves the job.
* **Step:** Press this key combination to submit the task to the queue.


7. **atq**
* **Function:** Lists all pending jobs in the queue.
* **Step:** Run this to see your Job ID, scheduled time, and user.


8. **atrm 3**
* **Function:** Removes a specific job from the queue.
* **Step:** Use `atrm` followed by the Job ID (e.g., 3) to cancel a scheduled task.



**Sample Input**

```text
at 17:30
warning: commands will be executed using /bin/sh
at> echo "Hello, this is a scheduled job" > ~/job_output.txt
at> <EOT>

```

**Sample Output**

```text
job 3 at Fri Apr 17 17:30:00 2026

student@workstation:~$ cat ~/job_output.txt
Hello, this is a scheduled job

```
---
## 5B Job Scheduling in Linux using CRON Job
**Aim**
To automate and schedule recurring tasks in the Linux environment by configuring the Cron table (Crontab) with specific time intervals and shell commands.

**Algorithm**

1. **Initialize Editor:** Access the user-specific crontab configuration file using the editing command.
2. **Define Schedule:** Understand the five-field time format (Minute, Hour, Day of Month, Month, Day of Week) to set the repetition frequency.
3. **Draft Command:** Write the full path or script command that needs to be executed automatically at the set intervals.
4. **Append Entry:** Insert the cron expression into the configuration file to register the background task.
5. **Commit Changes:** Save the file and exit the editor to trigger the Cron daemon to reload the schedule.
6. **Verification:** List the active cron jobs to ensure the entry was successfully recorded.
7. **Execution Check:** Monitor the output destination file to verify that the task runs automatically at the scheduled time.

**Commands and Explanation**

1. **crontab -e**
* **Function:** Opens the current user's crontab file for editing.
* **Step:** Run this command. If it is the first time, select an editor (like nano) to proceed.


2. *** * * * * command**
* **Function:** This is the standard syntax for a cron entry.
* **Step:** The five stars represent: Minute (0-59), Hour (0-23), Day of Month (1-31), Month (1-12), and Day of Week (0-7).


3. **30 17 * * * echo "Hello, this is a cron job" > ~/cron_output.txt**
* **Function:** Schedules a task to run daily at 5:30 PM (17:30).
* **Step:** Add this specific line at the very bottom of the crontab file opened in Step 1.


4. **Ctrl + O followed by Enter, then Ctrl + X**
* **Function:** Saves the changes and exits the nano editor.
* **Step:** Use these key combinations to confirm your new schedule.


5. **crontab -l**
* **Function:** Lists all scheduled cron jobs for the current user.
* **Step:** Run this command to verify that your daily task is now active in the system.


6. **sudo systemctl status cron**
* **Function:** Checks if the cron service is active and running in the background.
* **Step:** Ensure the service is "active (running)" otherwise scheduled tasks will not execute.



**Sample Input**

```text
crontab -e
[Add the following line]:
30 17 * * * echo "Hello, this is a cron job" > ~/cron_output.txt

```

**Sample Output**

```text
crontab: installing new crontab

[After 17:30, check file]:
student@workstation:~$ cat ~/cron_output.txt
Hello, this is a cron job

```
---
## 6.Implement Banker’s Algorithm for Deadlock Avoidance
## Implement Banker's Algorithm for Deadlock Avoidance

**Aim**
To implement the Banker’s Algorithm to maintain the system in a safe state and avoid deadlocks by simulating resource allocation and checking for a safe sequence.

**Algorithm**

1. **Initialization:** Define matrices for **Allocation** (resources currently held by processes), **Max** (maximum resources a process may need), and **Available** (resources currently free in the system).
2. **Calculate Need:** For every process, calculate the remaining resource requirement: $Need[i][j] = Max[i][j] - Allocation[i][j]$.
3. **Safety Status:** Create a `Work` array (initialized to `Available`) and a `Finish` boolean array (all initialized to false).
4. **Find Process:** Search for an index $i$ such that `Finish[i]` is false and $Need[i] \leq Work$.
5. **Resource Release:** If such a process is found, assume it completes its task. Add its `Allocation` back to the `Work` array ($Work = Work + Allocation$), set `Finish[i]` to true, and add the process to the **Safe Sequence**.
6. **Iteration:** Repeat steps 4 and 5 until either all processes are finished or no more processes can be satisfied.
7. **Conclusion:** If all processes have `Finish[i] = true`, the system is in a **Safe State**. Otherwise, it is **Unsafe**.

**C Program**

```c
#include <stdio.h>
int main() {
    int p, r, i, j, count = 0;
    printf("Enter number of processes and resources: ");
    scanf("%d %d", &p, &r);
    int allocation[10][10], max[10][10], need[10][10];
    int available[10], safe[10], done[10];

    printf("Enter allocation matrix:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter max matrix:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter available resources:\n");
    for(i = 0; i < r; i++)
        scanf("%d", &available[i]);

    printf("\nNeed Matrix:\n");
    for(i = 0; i < p; i++) {
        for(j = 0; j < r; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < p; i++)
        done[i] = 0;

    while(count < p) {
        int found = 0;
        for(i = 0; i < p; i++) {
            if(done[i] == 0) {
                int flag = 1;
                for(j = 0; j < r; j++) {
                    if(need[i][j] > available[j]) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    safe[count] = i;
                    done[i] = 1;
                    for(j = 0; j < r; j++)
                        available[j] += allocation[i][j];
                    count++;
                    found = 1;
                }
            }
        }
        if(!found) {
            printf("\nSystem is in Unsafe State\n");
            return 0;
        }
    }

    printf("\nSafe Sequence: ");
    for(i = 0; i < p; i++)
        printf("P%d ", safe[i]);
    printf("\nSystem is in Safe State\n");
    return 0;
}

```

**Sample Output**

```text
Enter number of processes and resources: 3 3
Enter allocation matrix:
0 1 0
2 0 0
3 0 2
Enter max matrix:
7 5 3
3 2 2
9 0 2
Enter available resources:
3 3 2

Need Matrix:
7 4 3 
1 2 2 
6 0 0 

Safe Sequence: P1 P2 P0 
System is in Safe State

```
---
## 7.Implement an Algorithm for Deadlock Detection
## Implement an Algorithm for Deadlock Detection

**Aim**
To implement a deadlock detection algorithm that identifies processes currently involved in a deadlock by analyzing resource allocation and outstanding requests.

**Algorithm**

1. **Initialize Matrices:** Define an **Allocation** matrix for currently held resources and a **Request** matrix for resources each process is waiting for.
2. **Tracking Setup:** Initialize a `Work` vector equal to the `Available` resources and a `Finish` boolean array set to false for all processes.
3. **Search for Executable Process:** Find a process $i$ where `Finish[i]` is false and its `Request` is less than or equal to the `Work` vector.
4. **Reclaim Resources:** If such a process is found, assume it completes its task, add its `Allocation` back to the `Work` vector, and set `Finish[i]` to true.
5. **Iteration:** Repeat steps 3 and 4 until no more such processes can be found.
6. **Deadlock Identification:** Any process $i$ where `Finish[i]` remains false after the loop is concluded to be in a state of deadlock.

**C Program**

```c
#include <stdio.h>
int main() {
int n, m, i, j;
printf("Enter number of processes: ");
scanf("%d", &n);
printf("Enter number of resources: ");
scanf("%d", &m);
int allocation[n][m], request[n][m], available[m];
int finish[n], work[m];
printf("Enter Allocation Matrix:\n");
for(i = 0; i < n; i++)
for(j = 0; j < m; j++)
scanf("%d", &allocation[i][j]);
printf("Enter Request Matrix:\n");
for(i = 0; i < n; i++)
for(j = 0; j < m; j++)
scanf("%d", &request[i][j]);
printf("Enter Available Resources:\n");
for(i = 0; i < m; i++) {
scanf("%d", &available[i]);
work[i] = available[i];
}
for(i = 0; i < n; i++)
finish[i] = 0;
int found;
do {
found = 0;
for(i = 0; i < n; i++) {
if(!finish[i]) {
int possible = 1;
for(j = 0; j < m; j++) {
if(request[i][j] > work[j]) {
possible = 0;
break;
}
}
if(possible) {
for(j = 0; j < m; j++)
work[j] += allocation[i][j];
finish[i] = 1;
found = 1;
}
}
}
} while(found);
int deadlock = 0;
for(i = 0; i < n; i++) {
if(!finish[i]) {
deadlock = 1;
printf("Process P%d is in deadlock\n", i);
}
}
if(!deadlock)
printf("No Deadlock Detected\n");
return 0;
}

```

**Sample Output**

```text
Enter number of processes: 3
Enter number of resources: 3
Enter Allocation Matrix:
0 1 0
2 0 0
3 0 3
Enter Request Matrix:
0 0 0
2 0 2
0 0 1
Enter Available Resources:
0 0 0
Process P1 is in deadlock
Process P2 is in deadlock

```
---
## 8.Installation of VMware on Linux Host and Adding Guest Operating System
**Aim**
To download, install, and configure VMware Workstation Player on a Linux host and successfully set up a Guest Operating System.

**Algorithm**

1. **Download:** Obtain the official VMware Linux bundle file from the VMware website.
2. **Permission:** Use the terminal to grant executable permissions to the downloaded installer.
3. **Installation:** Execute the installer with root privileges to launch the installation wizard.
4. **Configuration:** Complete the wizard by accepting license agreements and following the setup prompts.
5. **Virtual Machine Creation:** Open VMware and initiate the "Create New Virtual Machine" process by selecting an ISO image for the Guest OS.
6. **Resource Allocation:** Define the VM name, specify the storage location, and allocate hardware resources like RAM and Disk size.
7. **Execution:** Finalize settings and power on the virtual machine to begin the Guest OS installation.

**Linux Commands**

* **cd Downloads**
* **Function:** Navigates to the directory where the installer was saved.


* **chmod +x VMware-Player-Full-*.bundle**
* **Function:** Changes the file mode to allow the bundle file to be executed as a program.


* **sudo ./VMware-Player-Full-*.bundle**
* **Function:** Runs the installer script with administrative (root) privileges.



**Step-by-Step Installation**

1. **Download Bundle:** Visit the VMware website and download the Workstation Player Linux bundle (e.g., `VMware-Player-Full-17.x.x.bundle`).
2. **Open Terminal:** Press `Ctrl+Alt+T` to open your command-line interface.
3. **Make Executable:** Navigate to your folder and run `chmod +x` on the bundle file to unlock installation.
4. **Run Installer:** Execute the file using `sudo ./[filename]`. Enter your root password when prompted to start the graphical wizard.
5. **Follow Wizard:** Accept the End User License Agreement (EULA) and choose whether to join the Customer Experience Improvement Program (CEIP).
6. **Create VM:** Once installed, launch VMware from your Application Menu and click "Create a New Virtual Machine".
7. **Select ISO:** Browse your local files to select the ISO image of the OS you wish to install (e.g., Ubuntu).
8. **Set Hardware:** Allocate at least 2GB of RAM, 2 CPU cores, and 20GB of disk space for stable performance.
9. **Finish & Boot:** Click "Finish" and select "Power on this virtual machine" to start the Guest OS setup.

**Sample Input**

```text
cd Downloads
chmod +x VMware-Player-Full-17.0.0.bundle
sudo ./VMware-Player-Full-17.0.0.bundle

```

**Sample Output**

```text
Extracting VMware Installer...done.
Installing VMware Player 17.0.0
Configuring...
Installation was successful.

```
---
## 9.Implement Paging Technique of Memory Management

**Aim**
To implement the paging technique of memory management to calculate the physical address from a given logical address based on page table mapping.

**Algorithm**

1. **Memory Setup:** Input the total physical memory size and the fixed page size to calculate the total number of available frames (memory slots).
2. **Process Allocation:** Enter the number of processes and the specific number of pages required for each process.
3. **Availability Check:** Verify if the required pages for a process can fit into the remaining free frames; if not, terminate allocation with a "Memory is Full" message.
4. **Page Table Entry:** For each process, manually input the frame numbers where its pages are stored to build the Page Table.
5. **Address Request:** Input a logical address consisting of the process ID, the page number within that process, and the offset (displacement).
6. **Validation:** Ensure the process ID, page number, and offset are within the bounds of the allocated memory.
7. **Address Translation:** Locate the Frame Number from the Page Table using the process ID and page number.
8. **Physical Address Calculation:** Compute the final address using the formula: $Physical\ Address = (Frame\ Number \times Page\ Size) + Offset$.
9. **Output:** Display the resulting physical address.

**C Program**

```c
#include <stdio.h>
int main() {
    int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
    int s[10], fno[10][20];
    printf("\nEnter the memory size -- ");
    scanf("%d", &ms);
    printf("\nEnter the page size -- ");
    scanf("%d", &ps);
    nop = ms / ps;
    printf("\nThe no. of pages available in memory are %d", nop);
    printf("\nEnter number of processes -- ");
    scanf("%d", &np);
    rempages = nop;
    for(i = 1; i <= np; i++) {
        printf("\nEnter no. of pages required for p[%d]-- ", i);
        scanf("%d", &s[i]);
        if(s[i] > rempages) {
            printf("\nMemory is Full");
            break;
        }
        rempages = rempages - s[i];
        printf("\nEnter pagetable for p[%d] -- ", i);
        for(j = 0; j < s[i]; j++)
            scanf("%d", &fno[i][j]);
    }
    printf("\nEnter Logical Address to find Physical Address ");
    printf("\nEnter process no. and pagenumber and offset -- ");
    scanf("%d %d %d", &x, &y, &offset);
    if(x > np || y >= s[x] || offset >= ps)
        printf("\nInvalid Process or Page Number or offset");
    else {
        pa = fno[x][y] * ps + offset;
        printf("\nThe Physical Address is -- %d", pa);
    }
    return 0;
}

```

**Sample Output**

```text
Enter the memory size -- 100
Enter the page size -- 10
The no. of pages available in memory are 10
Enter number of processes -- 2

Enter no. of pages required for p[1]-- 3
Enter pagetable for p[1] -- 5 6 7

Enter no. of pages required for p[2]-- 2
Enter pagetable for p[2] -- 2 4

Enter Logical Address to find Physical Address 
Enter process no. and pagenumber and offset -- 1 2 3
The Physical Address is -- 73

```
---
## 10B.Implement Page Replacement Algorithms: LRU

**Aim**
To implement the Least Recently Used (LRU) page replacement algorithm to simulate memory management and calculate the total number of page faults.

**Algorithm**

1. **Initialize Memory:** Input the number of frames available in physical memory and the total number of pages in the reference string.
2. **Input Reference String:** Enter the sequence of page requests (reference string) made by the processor.
3. **Frame Tracking:** Maintain an array for frames (initialized to -1) and a counter or timestamp array to track when each page was last used.
4. **Page Check:** For each page in the reference string:
* If the page is already present in a frame (**Page Hit**), update its timestamp to the current counter value.
* If the page is not present (**Page Fault**):
* If there is an empty frame, place the page there and record the timestamp.
* If all frames are full, identify the page that has the oldest timestamp (least recently used).
* Replace that oldest page with the new page and update the timestamp.




5. **Fault Counting:** Increment the fault counter every time a page is not found in the frames.
6. **Display Status:** After each request, display the current state of the frames.
7. **Output Results:** Print the total number of page faults occurred during the simulation.

**C Program**

```c
#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int no_of_frames, no_of_pages, frames[10], pages[30];
    int counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    printf("Enter reference string: ");
    for (i = 0; i < no_of_pages; ++i)
        scanf("%d", &pages[i]);

    for (i = 0; i < no_of_frames; ++i)
        frames[i] = -1;

    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0) {
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        printf("\n");
        for (j = 0; j < no_of_frames; ++j)
            printf("%d\t", frames[j]);
    }
    printf("\n\nTotal Page Faults = %d\n", faults);
    return 0;
}

```

**Sample Output**

```text
Enter number of frames: 3
Enter number of pages: 7
Enter reference string: 1 2 3 1 4 5 2

1	-1	-1	
1	2	-1	
1	2	3	
1	2	3	
1	4	3	
5	4	3	
5	4	2	

Total Page Faults = 6

```
---
## 10.A Implement Page Replacement Algorithms: FIFO

**Aim**
To implement the First-In, First-Out (FIFO) page replacement algorithm to simulate how the operating system manages memory pages and to calculate the total number of page faults.

**Algorithm**

1. **Initialize Memory:** Input the total number of frames available in the physical memory and the total number of pages in the reference string.
2. **Input Reference String:** Enter the sequence of pages requested by the CPU.
3. **Setup Tracking:** Create an array for frames (initialized to -1 to indicate they are empty) and a pointer/index (initially at 0) to track which frame was filled first.
4. **Process Requests:** For each page in the reference string:
* **Check Availability:** Search the current frames to see if the page is already present.
* **Page Hit:** If the page is found, move to the next request (no action needed).
* **Page Fault:** If the page is not found:
* Increment the page fault counter.
* Replace the page at the current pointer position with the new page.
* Increment the pointer using the formula: $Pointer = (Pointer + 1)\ \%\ Number\ of\ Frames$.




5. **Output Results:** After processing the entire string, display the total count of page faults.

**C Program**

```c
#include <stdio.h>
#include <stdlib.h>

int pagefault(int a[], int frame[], int n, int no) {
    int i, j = 0, count = 0, k;
    for (i = 0; i < no; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++) {
        int avail = 0;
        for (k = 0; k < no; k++) {
            if (frame[k] == a[i])
                avail = 1;
        }
        if (avail == 0) {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;
        }
    }
    return count;
}

int main() {
    int n, no, fault, i;
    int *a, *frame;
    printf("ENTER THE NUMBER OF PAGES: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    printf("ENTER THE PAGE NUMBER: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("ENTER THE NUMBER OF FRAMES: ");
    scanf("%d", &no);
    frame = (int*)malloc(no * sizeof(int));
    fault = pagefault(a, frame, n, no);
    printf("Page Faults: %d\n", fault);
    return 0;
}

```

**Sample Output**

```text
ENTER THE NUMBER OF PAGES: 7
ENTER THE PAGE NUMBER: 1 2 3 1 4 5 2
ENTER THE NUMBER OF FRAMES: 3
Page Faults: 6

```
---
## 10.C Implement Page Replacement Algorithms: LFU

**Aim**
To implement the Least Frequently Used (LFU) page replacement algorithm to simulate memory management and calculate the total number of page faults.

**Algorithm**

1. **Initialize Memory:** Input the number of frames available in physical memory and the total number of pages in the reference string.
2. **Input Reference String:** Enter the sequence of page requests made by the processor.
3. **Frame Tracking:** Maintain an array for frames (initialized to -1) and a frequency counter array to track how many times each page currently in a frame has been accessed.
4. **Process Requests:** For each page in the reference string:
* **Check Availability:** Search the current frames to see if the page is already present.
* **Page Hit:** If the page is found, increment its specific frequency counter.
* **Page Fault:** If the page is not found:
* Increment the total page fault counter.
* **Empty Frame:** If there is an empty frame, place the page there and set its frequency to 1.
* **Replacement:** If all frames are full, identify the page with the lowest frequency. If multiple pages have the same lowest frequency, use the one that arrived earliest (FIFO).
* Replace the identified page with the new page and reset its frequency to 1.




5. **Output Results:** After processing all requests, display the total count of page faults.

**C Program**

```c
#include <stdio.h>

int main() {
    int i, j, k, n, frameno, page[50], frame[10], flag, count = 0, count1[10] = {0};

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frameno);

    for (i = 0; i < frameno; i++)
        frame[i] = -1;

    printf("Page reference string\tFrames\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t\t", page[i]);
        flag = 0;

        for (j = 0; j < frameno; j++) {
            if (page[i] == frame[j]) {
                flag = 1;
                count1[j]++;
                break;
            }
        }

        if (flag == 0) {
            for (j = 0; j < frameno; j++) {
                if (frame[j] == -1) {
                    frame[j] = page[i];
                    count1[j]++;
                    count++;
                    break;
                }
            }

            if (j == frameno) {
                int min = 0;
                for (k = 1; k < frameno; k++) {
                    if (count1[k] < count1[min])
                        min = k;
                }
                frame[min] = page[i];
                count1[min] = 1;
                count++;
            }
        }

        for (j = 0; j < frameno; j++)
            printf("%d\t", frame[j]);
        printf("\n");
    }

    printf("Total Page Faults: %d\n", count);
    return 0;
}

```

**Sample Output**

```text
Enter number of pages: 7
Enter page reference string: 1 2 3 1 4 5 2
Enter number of frames: 3

Page reference string   Frames
1                       1       -1      -1
2                       1       2       -1
3                       1       2       3
1                       1       2       3
4                       1       4       3
5                       1       4       5
2                       2       4       5

Total Page Faults: 6

```
---
## 11A.Create and Activate a Swap Partition

**Aim**
To create a dedicated swap partition on a storage device, format it appropriately, and activate it to extend the system's virtual memory capacity.

**Algorithm**

1. **Identify Disk:** List all available block devices to identify the target disk for the swap partition.
2. **Partitioning:** Use a partitioning tool to create a new partition and set its type to "Linux swap".
3. **Kernel Update:** Inform the operating system of the changes made to the partition table.
4. **Formatting:** Apply the swap signature to the newly created partition using the specialized swap formatting tool.
5. **Activation:** Enable the partition so the system can begin using it for paging.
6. **Verification:** Check the system memory statistics to confirm the swap space has increased.
7. **Persistence:** Append the partition details to the filesystem table to ensure the swap is activated automatically upon every reboot.

**Linux Commands**

1. **lsblk**
* **Function:** Lists information about all available block devices (disks and partitions).
* **Step:** Use this to find your disk name (e.g., `/dev/sdb`).


2. **sudo fdisk /dev/sdb**
* **Function:** Opens the disk manipulator for the specified drive.
* **Step:** Inside `fdisk`:
* Press `n` to create a new partition.
* Press `t` and enter code `82` (Linux swap) to set the type.
* Press `w` to write changes and exit.




3. **sudo partprobe**
* **Function:** Informs the OS kernel of partition table changes.
* **Step:** Run this so the system recognizes the new `/dev/sdb1` without a reboot.


4. **sudo mkswap /dev/sdb1**
* **Function:** Sets up a Linux swap area on the device.
* **Step:** This "formats" the partition specifically for swap usage.


5. **sudo swapon /dev/sdb1**
* **Function:** Enables the device for paging and swapping.
* **Step:** This makes the swap active immediately.


6. **swapon --show**
* **Function:** Displays active swap devices and their sizes.
* **Step:** Use this to verify the partition is being used.


7. **free -h**
* **Function:** Shows the amount of free and used memory in the system.
* **Step:** Check the "Swap" row to see the updated total capacity.



**Step-by-Step Execution**

1. **Create Partition:** Run `sudo fdisk /dev/sdb`, follow the prompts to create a partition, change the type to `82`, and save.
2. **Format Swap:** Run `sudo mkswap /dev/sdb1` (replace `sdb1` with your actual partition name).
3. **Activate:** Execute `sudo swapon /dev/sdb1`.
4. **Permanent Mount:** Open the fstab file using `sudo nano /etc/fstab` and add the line:
`/dev/sdb1  none  swap  sw  0  0`

**Sample Input**

```text
lsblk
sudo fdisk /dev/sdb
[Inside fdisk: n, p, 1, default, default, t, 82, w]
sudo mkswap /dev/sdb1
sudo swapon /dev/sdb1
free -h

```

**Sample Output**

```text
Setting up swapspace version 1, size = 2 GiB (2147479552 bytes)
no label, UUID=550e8400-e29b-41d4-a716-446655440000

              total        used        free      shared  buff/cache   available
Mem:          7.7Gi       1.2Gi       4.5Gi       120Mi       2.0Gi       6.1Gi
Swap:         2.0Gi          0B       2.0Gi

```
---
## 11B.Configure Logical Volume Management (LVM)

**Aim**
To create and manage a flexible storage structure using Logical Volume Management (LVM) by initializing physical volumes, grouping them into volume groups, and carving out logical volumes.

**Algorithm**

1. **Preparation:** Identify the raw disks or partitions available for LVM.
2. **Physical Volume (PV) Creation:** Initialize the raw disks so the LVM driver can recognize them as usable building blocks.
3. **Volume Group (VG) Creation:** Combine one or more Physical Volumes into a single storage pool.
4. **Logical Volume (LV) Creation:** Slice the Volume Group into specific logical partitions that can be formatted with a filesystem.
5. **Filesystem Formatting:** Apply a filesystem (like ext4) to the Logical Volume to make it ready for data storage.
6. **Mounting:** Attach the formatted Logical Volume to a directory in the Linux file tree.
7. **Verification:** Check the status and size of the PVs, VGs, and LVs to ensure the configuration is correct.

**Linux Commands**

1. **sudo pvcreate /dev/sdb /dev/sdc**
* **Function:** Initializes disks as Physical Volumes.
* **Step:** Run this first to mark your raw disks for LVM use.


2. **sudo vgcreate vg_data /dev/sdb /dev/sdc**
* **Function:** Creates a Volume Group named `vg_data` using the initialized PVs.
* **Step:** This pools the capacity of both disks into one group.


3. **sudo lvcreate -L 10G -n lv_storage vg_data**
* **Function:** Creates a 10GB Logical Volume named `lv_storage` inside the `vg_data` group.
* **Step:** Use the `-L` flag for size and `-n` for the name.


4. **sudo mkfs.ext4 /dev/vg_data/lv_storage**
* **Function:** Formats the new logical volume with the ext4 filesystem.
* **Step:** This makes the volume usable for storing files.


5. **sudo mkdir /mnt/lvm_disk**
* **Function:** Creates a mount point directory.
* **Step:** You need a folder to "hook" the disk into the system.


6. **sudo mount /dev/vg_data/lv_storage /mnt/lvm_disk**
* **Function:** Mounts the logical volume to the created directory.
* **Step:** Run this to start using the disk space.


7. **pvs, vgs, lvs**
* **Function:** Displays summary reports for Physical Volumes, Volume Groups, and Logical Volumes respectively.
* **Step:** Use these commands to verify your setup.



**Step-by-Step Execution**

1. **Initialize Disks:** Identify disks using `lsblk`, then run `pvcreate`.
2. **Build Pool:** Group the disks using `vgcreate`.
3. **Create Volume:** Slice the pool into the desired size using `lvcreate`.
4. **Format and Use:** Run `mkfs.ext4`, create a folder, and `mount` the volume.

**Sample Input**

```text
sudo pvcreate /dev/sdb
sudo vgcreate my_vg /dev/sdb
sudo lvcreate -L 5G -n my_lv my_vg
sudo mkfs.ext4 /dev/my_vg/my_lv
sudo mount /dev/my_vg/my_lv /mnt
lvs

```

**Sample Output**

```text
Physical volume "/dev/sdb" successfully created.
Volume group "my_vg" successfully created.
Logical volume "my_lv" created.
mke2fs 1.46.5 (30-Dec-2021)
Creating filesystem with 1310720 4k blocks...

  LV    VG    Attr       LSize Pool Origin Data%  Meta%  Move Log Cpy%Sync Convert
  my_lv my_vg -wi-a----- 5.00g                                                    

```
---
## 12A.Configure Basic Network Settings (IP, DNS, Gateway)

**Aim**
To manually configure and verify essential network parameters including the IP address, subnet mask, default gateway, and DNS servers on a Linux system.

**Algorithm**

1. **Identify Interface:** Determine the name of the active network interface (e.g., eth0, ens33) currently recognized by the system.
2. **Assign IP Address:** Set a specific static IP address and subnet mask to the identified network interface.
3. **Set Default Gateway:** Define the router's IP address that the system will use to access external networks.
4. **Configure DNS:** Update the name server configuration file to ensure the system can resolve domain names into IP addresses.
5. **Apply Changes:** Restart the networking service or bring the interface up/down to commit the new settings.
6. **Verification:** Test connectivity using tools like ping and check the current routing table.

**Linux Commands**

1. **ip addr show**
* **Function:** Displays all network interfaces and their currently assigned IP addresses.
* **Step:** Run this first to find your interface name.


2. **sudo ip addr add 192.168.1.50/24 dev eth0**
* **Function:** Assigns the static IP `192.168.1.50` with a 24-bit subnet mask to interface `eth0`.
* **Step:** Replace `eth0` with your actual interface name found in step 1.


3. **sudo ip route add default via 192.168.1.1**
* **Function:** Sets the default gateway to `192.168.1.1`.
* **Step:** This allows the system to communicate with devices outside the local network.


4. **sudo nano /etc/resolv.conf**
* **Function:** Opens the DNS resolver configuration file for editing.
* **Step:** Add `nameserver 8.8.8.8` to this file to use Google’s DNS.


5. **ping -c 4 google.com**
* **Function:** Sends 4 packets to a domain to test internet connectivity and DNS resolution.
* **Step:** Final check to ensure the configuration is working.



**Step-by-Step Execution**

1. **View Interface:** Run `ip addr` to see names like `enp0s3`.
2. **Set Static IP:** Use `sudo ip addr add [IP/Mask] dev [Interface]`.
3. **Set Route:** Run `sudo ip route add default via [Gateway_IP]`.
4. **Edit DNS:** Type `sudo nano /etc/resolv.conf`, enter `nameserver 8.8.8.8`, and save (Ctrl+O, Enter, Ctrl+X).
5. **Check Status:** Use `ip route show` to confirm the gateway and `ping` to confirm the connection.

**Sample Input**

```text
ip addr show
sudo ip addr add 192.168.1.100/24 dev ens33
sudo ip route add default via 192.168.1.1
sudo nano /etc/resolv.conf
[Add line: nameserver 8.8.8.8]
ping -c 3 8.8.8.8

```

**Sample Output**

```text
2: ens33: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500
    inet 192.168.1.100/24 scope global ens33

default via 192.168.1.1 dev ens33 proto static 

PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=117 time=14.2 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=117 time=13.5 ms

--- 8.8.8.8 ping statistics ---
2 packets transmitted, 2 received, 0% packet loss, time 1001ms

```
---
## 12B.Configure and Verify NFS Server and Client

**Aim**
To install, configure, and verify a Network File System (NFS) to allow a client machine to access and share directories across a network as if they were local.

**Algorithm**

1. **Host Setup:** Install the NFS kernel server package on the host machine and create a dedicated directory for sharing.
2. **Export Configuration:** Modify the exports file to define which client IPs have access and set specific permissions (Read/Write, Sync).
3. **Service Initialization:** Export the shared directories and restart the NFS service to apply the configuration.
4. **Firewall Adjustment:** Configure the host firewall to allow NFS traffic from the client.
5. **Client Setup:** Install the NFS common utilities on the client machine and create a local mount point.
6. **Mounting:** Execute the mount command to link the remote server directory to the local client folder.
7. **Verification:** Create a file on the client side and verify its presence on the server to confirm successful bi-directional synchronization.

**Linux Commands**

**On the NFS Server:**

1. **sudo apt install nfs-kernel-server**
* **Function:** Installs the necessary server-side software for NFS.


2. **sudo mkdir -p /mnt/nfs_share**
* **Function:** Creates a directory that will be shared across the network.


3. **sudo chown nobody:nogroup /mnt/nfs_share**
* **Function:** Adjusts permissions so that any client can access the folder.


4. **sudo nano /etc/exports**
* **Function:** Opens the configuration file where sharing rules are defined.
* **Step:** Add the line: `/mnt/nfs_share [Client_IP](rw,sync,no_subtree_check)`


5. **sudo exportfs -a && sudo systemctl restart nfs-kernel-server**
* **Function:** Makes the shared directory available and restarts the service.



**On the NFS Client:**

1. **sudo apt install nfs-common**
* **Function:** Installs client-side tools to recognize and mount NFS shares.


2. **sudo mkdir -p /mnt/nfs_client**
* **Function:** Creates a local folder where the remote share will appear.


3. **sudo mount [Server_IP]:/mnt/nfs_share /mnt/nfs_client**
* **Function:** Connects the remote server directory to the local mount point.


4. **df -h**
* **Function:** Displays disk usage; used here to verify the NFS mount is active.



**Step-by-Step Execution**

1. **Server side:** Install the server package, create `/var/nfs/general`, and edit `/etc/exports` to grant your client IP `rw` access.
2. **Apply on Server:** Run `sudo exportfs -ra` to update the share list without rebooting.
3. **Client side:** Install `nfs-common`, create a mount folder, and use the `mount` command with the server's IP.
4. **Test:** Create a file using `touch /mnt/nfs_client/test.txt` and check if it appears on the server in `/mnt/nfs_share`.

**Sample Input**

```text
[Server] sudo exportfs -v
[Client] sudo mount 192.168.1.10:/mnt/nfs_share /mnt/nfs_client
[Client] touch /mnt/nfs_client/hello_server.txt

```

**Sample Output**

```text
/mnt/nfs_share  192.168.1.50(rw,wdelay,root_squash,no_subtree_check)

student@client:~$ df -h | grep nfs
192.168.1.10:/mnt/nfs_share   50G   2G   48G   5% /mnt/nfs_client

student@server:~$ ls /mnt/nfs_share
hello_server.txt

```
---
## 13A.Perform Root Password Recovery Using Rescue/Emergency Mode

**Aim**
To regain administrative access to a Linux system by bypassing the standard login process using emergency/rescue modes to reset a lost or forgotten root password.

**Algorithm**

1. **Interrupt Boot:** Restart the system and access the GRUB bootloader menu during the initial startup phase.
2. **Modify Boot Parameters:** Edit the boot entry to change the kernel's behavior, directing it to a shell environment instead of the standard graphical or multi-user login.
3. **Initiate Emergency Mode:** Instruct the kernel to mount the root filesystem and launch a privileged shell (`/bin/sh` or `/bin/bash`).
4. **Remount Filesystem:** Change the status of the root partition from "read-only" to "read-write" to allow modifications to system files.
5. **Password Reset:** Execute the password utility to define a new credential for the root account.
6. **SELinux Context (Optional):** Update security labels if the system uses SELinux to ensure the new password file is accepted upon reboot.
7. **System Resumption:** Flush changes to the disk and restart the system to login with the new password.

**Linux Commands**

1. **rw init=/bin/bash**
* **Function:** Kernel parameters added to the boot line to mount the system as read-write and launch a shell.
* **Step:** Append this to the end of the line starting with `linux` or `linux16` in the GRUB editor.


2. **mount -o remount,rw /**
* **Function:** Remounts the root directory with write permissions.
* **Step:** Run this immediately after the bash shell appears if the drive is still read-only.


3. **passwd root**
* **Function:** Invokes the password reset utility for the root user.
* **Step:** Enter your new password twice when prompted.


4. **touch /.autorelabel**
* **Function:** Triggers an SELinux file system relabel on the next boot.
* **Step:** Essential for systems like RHEL, CentOS, or Fedora to prevent login failures after a reset.


5. **exec /sbin/init**
* **Function:** Resumes the normal boot process.
* **Step:** Run this or use `reboot -f` to exit the emergency shell.



**Step-by-Step Execution**

1. **Enter GRUB:** Reboot and tap `Shift` or `Esc` to see the menu. Highlight the kernel and press `e`.
2. **Edit Line:** Find the line starting with `linux`. Go to the end, remove `rhgb quiet` (if present), and type `rd.break` (for RHEL) or `init=/bin/bash` (for Ubuntu/Debian).
3. **Boot:** Press `Ctrl+X` or `F10` to boot with these temporary settings.
4. **Write Access:** At the prompt, type `mount -o remount,rw /`.
5. **Change Pass:** Type `passwd root`, enter the new password, and confirm.
6. **Finalize:** Type `touch /.autorelabel` (if required), then `exit` and reboot.

**Sample Input**

```text
[At GRUB Edit Screen]: linux /vmlinuz... root=UUID... rw init=/bin/bash
[At Shell Prompt]:
passwd root
Enter new UNIX password: 
Retype new UNIX password: 
reboot -f

```

**Sample Output**

```text
passwd: password updated successfully
Rebooting...
[System boots to login screen, root accepts new password]

```
---
## 13B.Deploy an Application by Cloning a GitHub Repository

**Aim**
To download an application's source code from a remote GitHub repository to a local Linux environment and prepare it for execution.

**Algorithm**

1. **Environment Check:** Verify that Git is installed on the host system.
2. **Repository Identification:** Locate the target repository on GitHub and obtain its HTTPS or SSH clone URL.
3. **Authentication (Optional):** Set up credentials or SSH keys if the repository is private.
4. **Cloning:** Execute the clone command to pull a complete copy of the remote repository, including its history and branches.
5. **Navigation:** Enter the newly created directory containing the application files.
6. **Dependency Installation:** Run the specific package manager (like `npm` or `pip`) to install the required libraries listed in the source.
7. **Execution:** Launch the application using the appropriate runtime command.

**Linux Commands**

1. **git --version**
* **Function:** Checks if the Git version control system is installed.
* **Step:** Run this first; if not found, install it using `sudo apt install git`.


2. **git clone [https://github.com/user/repository.git**](https://github.com/user/repository.git)
* **Function:** Creates a local copy of the remote repository.
* **Step:** Copy the URL from the "Code" button on GitHub and paste it after the clone command.


3. **cd repository**
* **Function:** Changes the current working directory to the application folder.
* **Step:** Use the name of the folder created by the clone command.


4. **ls -a**
* **Function:** Lists all files, including hidden configuration files (like `.env` or `.git`).
* **Step:** Verify that all project files were successfully downloaded.


5. **git pull origin main**
* **Function:** Fetches and integrates changes from the remote server.
* **Step:** Use this if the local code needs to be updated to the latest version.



**Step-by-Step Execution**

1. **Install Git:** Use `sudo apt update && sudo apt install git -y`.
2. **Get Code:** Run `git clone [URL]`. For example: `git clone https://github.com/octocat/Spoon-Knife`.
3. **Enter Project:** Type `cd Spoon-Knife`.
4. **Install Dependencies:** Depending on the project, run commands like `npm install` (for Node.js) or `pip install -r requirements.txt` (for Python).
5. **Run:** Start the app using `python3 app.py` or `npm start`.

**Sample Input**

```text
git clone https://github.com/example/web-app.git
cd web-app
ls
cat README.md

```

**Sample Output**

```text
Cloning into 'web-app'...
remote: Enumerating objects: 45, done.
remote: Total 45 (delta 0), reused 0 (delta 0), pack-reused 45
Unpacking objects: 100% (45/45), 12.35 KiB | 1.23 MiB/s, done.

[File List]:
app.py  requirements.txt  static/  templates/  README.md

```
---