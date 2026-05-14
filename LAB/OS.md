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

## Implement Paging Technique of Memory Management

**Aim**
To implement the paging technique of memory management to calculate the physical address from a given logical address based on page table mapping.

**Algorithm**

1. 
**Input Memory Configuration:** Enter the total physical memory size and the fixed page size.


2. 
**Calculate Availability:** Divide the total memory by the page size to determine the total number of available pages (frames) in memory.


3. 
**Process Definition:** Input the number of processes and the specific number of pages required for each process.


4. 
**Capacity Check:** For each process, ensure the required pages do not exceed the remaining available frames; if they do, indicate that memory is full.


5. 
**Page Table Entry:** Input the frame numbers for each process to map where its logical pages reside in physical memory.


6. 
**Address Request:** Input a logical address consisting of the process number, page number, and offset.


7. 
**Input Validation:** Check if the requested process, page, or offset is within the valid allocated range.


8. 
**Compute Address:** Calculate the physical address using the formula: $Physical\ Address = (Frame\ Number \times Page\ Size) + Offset$.


9. 
**Output Results:** Display the final calculated physical address.



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
