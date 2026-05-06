# Unit-4
---

### **MASS STORAGE STRUCTURE: OVERVIEW**

Main memory is typically too small to store all necessary programs and data permanently and is volatile, meaning it loses contents when power is lost. Therefore, computer systems use **secondary storage** as a permanent, high-capacity extension of main memory.



### **1. Magnetic Disks**
Magnetic disks provide the primary bulk of secondary storage for modern systems.
*   **Platters:** Each disk consists of flat circular platters (1.8 to 3.5 inches in diameter) coated with magnetic material. Information is stored by recording it magnetically on these surfaces.
*   **Read-Write Heads:** A head "flies" just above the surface of every platter. These heads are attached to a disk arm that moves all heads as a unit.
*   **Organization:** The surface of a platter is logically divided into circular **tracks**, which are further subdivided into **sectors**.
*   **Performance:** Disk speed is determined by the **transfer rate** (data flow speed) and **positioning time** (random-access time).





### **2. CYLINDER**
*   **Definition:** A cylinder is the set of all tracks that are at one specific arm position.
*   **Function:** Because the disk arm moves all read-write heads together, every head is positioned over the same track number on their respective platter surfaces simultaneously. This vertical "stack" of tracks forms the cylinder.

### **Disk speed has two parts.**
* The transfer rate is the rate at which data flow between the drive and the computer.
* The positioning time, or random-access time
* SEEK TIME: The time necessary to move the disk arm to the desired cylinder, is called the seek time.
* ROTATIONAL LATENCY: The time necessary for the desired sector to rotate to the disk head, called the
rotational latency.




### **3. HEAD CRASH**
*   **Definition:** A head crash occurs if the read-write head makes physical contact with the disk surface.
*   **Consequences:** Although platters have a thin protective layer, a crash usually damages the magnetic surface. This often leads to data loss or total drive failure.



### **4. Magnetic Tapes**
*   **Usage:** Tapes were early secondary-storage media but are now primarily used for **backup**, transferring information between systems, or storing infrequently used data.
*   **Access Speed:** Tapes are significantly slower than magnetic disks. Random access is roughly a thousand times slower, making them impractical for primary secondary storage.
*   **Capacity:** Like disks, they are permanent and can hold very large quantities of data.



### **5. Disk Structure**
*   **Logical Blocks:** Disk drives are addressed as large one-dimensional arrays of **logical blocks**, which are the smallest unit of data transfer.
*   **Mapping:** This array of blocks (usually 512 bytes each) is mapped onto the disk sectors sequentially. Sector 0 is the first sector of the first track on the outermost cylinder.
*   **Recording Techniques:**
    *   **Constant Linear Velocity (CLV):** The density of bits per track is uniform.
    *   **Constant Angular Velocity (CAV):** Bit density decreases from inner tracks to outer tracks to keep the data rate constant as the disk spins.



### **6. Disk Attachment**
Computers access disk storage through three primary architectures:
*   **Host-Attached Storage:** Accessed through local I/O ports using bus architectures like **SATA, USB, or Fibre Channel**. Data transfers are managed by a **host controller** at the computer end and a **disk controller** built into the drive.
*   **Network-Attached Storage (NAS):** A special-purpose storage system accessed remotely over a data network. Clients use remote-procedure-call interfaces such as **NFS** (UNIX) or **CIFS** (Windows).
*   **Storage Area Network (SAN):** A private, high-speed network that connects multiple servers to various storage units, allowing for flexible storage allocation across the enterprise.


### Disk Scheduling refer drive notes
---
## **DISK MANAGEMENT**

The operating system is responsible for several aspects of disk management, including preparing the drive for use, handling system startup, and managing physical defects in the media.



### **1. Disk Formatting**
A physical hard disk is just a blank slate of magnetic material and must be formatted before it can store files. This occurs in two distinct phases:

*   **Physical (Low-Level) Formatting:** This is the process of dividing the disk into the basic units that the hardware controller can read and write: **sectors**. The process creates a specific data structure for each sector that includes:
    *   **Header:** Contains the sector number for identification.
    *   **Data Area:** Usually 512 bytes where actual user data is stored.
    *   **Trailer:** Contains an **Error Correction Code (ECC)**. When data is written, the controller calculates a value based on the bits in the data area. When read back, if the recalculated ECC doesn't match the trailer, the controller knows the data is corrupted.
*   **Logical (High-Level) Formatting:** This is where the operating system creates the **file system**. The OS stores the initial data structures on the disk, such as maps of free and allocated space (like a File Allocation Table) and an initial empty directory.
    *   **Clusters:** To improve performance, the OS often groups several blocks together into "clusters." I/O is then performed in these larger chunks to reduce overhead.



### **2. Boot Block**
For a computer to start running, it needs to load its operating system into RAM. This procedure is known as **System Booting**.

*   **Bootstrap Program:** Computers have a tiny initial program called a bootstrap loader stored in **ROM (Read-Only Memory)**. Since ROM is non-volatile and cannot be easily changed, it typically only contains enough code to perform hardware checks and then find the "real" boot loader on the disk.
*   **Boot Block/Partition:** The more complex, full bootstrap code is stored at a fixed location on the disk called the **boot block**. A disk that contains this system-start partition is called a **boot disk** or **system disk**.
*   **Master Boot Record (MBR):** On many systems, the boot process begins by looking at the very first sector of the hard disk (the MBR). This sector contains a table indicating which partition is the "active" boot partition. The system then jumps to the boot block of that partition to finish loading the OS.





### **3. Bad Blocks**
Since disk platters are mechanical and have microscopic tolerances, it is common for some areas to be defective or wear out over time. These are known as **bad blocks**.

*   **Detection:** During formatting, the system scans the surface. If the ECC indicates a sector cannot hold data reliably, it is flagged as unusable so the file system never attempts to store data there.
*   **Sector Sparing (Forwarding):** Modern disks set aside a collection of "spare sectors" that the OS cannot see. If a block goes bad during the disk's life, the controller can be told to "spare" it. It maps the bad logical address to one of the healthy physical spare sectors. To the OS, the disk still appears to have its full capacity.
*   **Sector Slipping:** As an alternative, if a block (e.g., sector 17) goes bad, the controller can shift all subsequent sectors down by one position. Sector 18 becomes 17, 19 becomes 18, and so on, until a spare sector is used up at the end of the track. This keeps the logical blocks in a contiguous physical string for better performance.
---
### **FILE SYSTEM STORAGE**

The file system provides the mechanism for on-line storage and access to both data and programs of the operating system and all computer users. It consists of two distinct parts: a collection of files, each storing related data, and a directory structure which organizes and provides information about all files in the system.


### **1. FILE CONCEPTS**
A file is defined as a named collection of related information that is stored on a secondary storage device. It is an abstract data type.
*   **Nature:** Files can store various information types, including source or executable programs, numeric or text data, photos, music, and video.
*   **Structures:**
    *   **Text File:** A sequence of characters organized into lines.
    *   **Source File:** A sequence of functions, organized as declarations followed by executable statements.
    *   **Executable File:** A series of code sections that the loader can bring into memory and execute.



### **2. FILE ATTRIBUTES**
Attributes vary by operating system but typically include:
*   **Name:** Information kept in human-readable form.
*   **Identifier:** A unique tag (usually a number) that identifies the file within the file system.
*   **Type:** Needed for systems that support different file formats.
*   **Location:** A pointer to the device and the specific location of the file on that device.
*   **Size:** The current size of the file in bytes, words, or blocks.
*   **Protection:** Access-control information determining who can read, write, or execute the file.
*   **Time, Date, and User ID:** Kept for creation, last modification, and last use.

### **FILE OPERATIONS:**

*  A file is an abstract data type.

The operating system can provide system calls to create, write, read, reposition, delete, and truncate files. The
Basic Operations on a file includes
Creating a File
Writing a File
Reading a File
Repositioning within a File
Deleting a file
Truncating a file

1) Creating a file: OS first finds space in the file system for the file. Second, an entry for the new file must be made in
the directory.
2) Writing a file. To write a file, we make a system specifying both the name of the file and the information to be
written to the file. The system must keep a write pointer to the location in the file where the next write is to take place.
3) Reading a file. To read from a file, we use a system call that specifies the name of the file. The system needs to
keep a read pointer to the location in the file where the next read is to take place.
Current File Position Pointer: Because a process is usually either reading from or writing to a file, the current
operation location can be kept as a per-process current file- position pointer.
4) Repositioning within a file. The directory is searched for the appropriate entry, and the current-file-position pointer
is repositioned to a given value. This file operation is also known as files seek.
5) Deleting a file. To delete a file, we search the directory for the named file.
6) Truncating a file. The user may want to erase the contents of a file but keep its attributes

### **3. OPEN FILE TABLE**
To avoid the overhead of searching the directory for every file operation, the operating system uses internal tables to track active files.
*   **Mechanism:** When a file is opened, its entry is copied into the open-file table. Subsequent operations use an index into this table rather than the filename.
*   **Two-Level Structure:**
    *   **Per-Process Table:** Tracks files an individual process has open, including the current file-position pointer and access rights.
    *   **System-Wide Table:** Contains process-independent information, such as the location on disk, access dates, and file size.
*   **Open Count:** A counter tracks how many processes have the file open. When the count reaches zero, the entry is removed from the table.





### **4. FILE LOCKS**
File locks allow a process to restrict access to a file by other processes, which is essential for shared files.
*   **Shared Lock:** Similar to a reader lock; multiple processes can acquire it concurrently.
*   **Exclusive Lock:** Similar to a writer lock; only one process can hold it at a time.
*   **Types of Implementation:**
    *   **Mandatory:** The OS strictly prevents any other process from accessing a locked file.
    *   **Advisory:** The OS provides the lock status, but it is up to the processes to check the lock and decide whether to proceed.



### **5. FILE ACCESS METHODS**
Information in a file can be accessed in several ways depending on the application requirements.
*   **Sequential Access:** The simplest method. Information is processed in order, one record after the other. Operations include `read next()` and `write next()`.
*   **Direct Access (Random Access):** The file is viewed as a numbered sequence of blocks or records. Programs can read or write records rapidly in no particular order using a block number (e.g., `read(n)`).
*   **Indexed Access:** Involves building an index for the file. The index contains pointers to various blocks. To find a record, the system searches the index first and then uses the pointer to access the data directly.





### **6. FILE SYSTEM MOUNTING**
File system mounting is the process of attaching an additional file system to the currently accessible file structure of a computer.
*   **Mount Point:** This is the location within the file structure where the new file system is attached. It is typically an empty directory.
*   **Process:** The operating system is given the name of the device and the mount point. Once mounted, the directory structure of the new device becomes a subdirectory at that mount point.
*   **Example:** Mounting a volume containing user home directories under `/users` allows a file named `Jane` to be accessed via the path `/users/Jane`.
---
### **DIRECTORY AND DISK STRUCTURE**

The directory is a symbol table that translates file names into their directory entries. It is essential for organizing files across various disk partitions or volumes.

#### **Operations Performed on a Directory**
To manage files effectively, a directory must support several fundamental operations:
*   **Search for a file:** Finding a specific entry when a file is referenced by name.
*   **Create a file:** Adding a new entry to the directory.
*   **Delete a file:** Removing an entry when a file is no longer needed.
*   **List a directory:** Displaying all files and their attributes.
*   **Rename a file:** Changing the name of an existing entry.
*   **Traverse the file system:** Navigating through different directory levels to access files.


### **1. Single-Level Directory**
In this simplest structure, all files are contained in a single directory for all users.



*   **Advantages:**
    *   Extremely easy to implement and manage.
    *   Ideal for small systems with a limited number of files or a single user.
*   **Disadvantages:**
    *   **Naming Collisions:** Every file must have a unique name because they all share the same namespace.
    *   **Grouping Issues:** As the number of files grows, it becomes difficult for users to remember all names or organize related files together.



### **2. Two-Level Directory**
To solve naming conflicts between different users, each user is given their own **User File Directory (UFD)**. A **Master File Directory (MFD)** is used to index these UFDs by username or account number.



*   **Advantages:**
    *   **Solves Naming Collisions:** Two different users can have files with the exact same name (e.g., both can have a "test.doc") because they are stored in different UFDs.
    *   **Isolation:** Provides a basic level of privacy and organization by separating user files.
*   **Disadvantages:**
    *   **Isolation Obstacles:** It is difficult for users to cooperate on a project or share files because each user is effectively "locked" in their own directory.
    *   **Lack of Internal Grouping:** Users still cannot create subdirectories within their own UFD to organize their own files.



### **3. Tree-Structured Directory**
This is the most common directory structure. It extends the two-level approach into a tree of arbitrary height, allowing users to create their own subdirectories to organize files.



*   **Advantages:**
    *   **Efficient Searching:** Pathnames (Absolute or Relative) allow for very fast navigation to specific files.
    *   **Deep Organization:** Users can group files logically (e.g., a "Projects" folder containing "Math" and "Science" subfolders).
    *   **Namespace Flexibility:** The same filename can be used in different branches of the tree without conflict.
*   **Disadvantages:**
    *   **Complexity:** Managing the tree (especially deleting non-empty directories) requires more complex logic.
    *   **Access Overhead:** Accessing a file deep in the tree may require the system to follow multiple directory pointers, which can slightly increase I/O time if the directory levels are not cached.

### **4) Acyclic Graph Directories**

An acyclic graph is a directory structure that allows for no cycles, permitting directories to share subdirectories and files. This means the same file or subdirectory may appear in two or more different directories simultaneously. With a shared file, only one actual physical file exists; therefore, any changes made by one user are immediately visible to all others who share the file.

#### **Shared File Implementation**
Shared files and subdirectories are typically implemented in one of two ways:
*   **Links:** A new directory entry called a "link" is created, which serves as a pointer to the actual file or subdirectory. When a file is referenced, the system searches the directory; if it finds a link, it resolves the path name to locate the real file.
*   **Duplicate Entries:** All information about the shared file is duplicated in both sharing directories. However, this method faces major consistency problems if the file is modified.

#### **File Deletion**
Deleting files in an acyclic graph is more complex than in a tree structure:
*   **Dangling Pointers:** If a file is removed whenever any user deletes it, other users may be left with "dangling pointers" that point to a non-existent file.
*   **Link Removal:** One method is to only delete the link, leaving the original file intact for other users.
*   **Reference Counting:** The most robust approach is to preserve the file until all references to it are deleted. The system keeps a file-reference list or a counter; the file is only physically deleted when this list is empty or the count reaches zero.



### **5) General Graph Directory**

When links are added to a tree-structured directory, the tree nature is destroyed, resulting in a general graph structure. This allows for the possibility of cycles within the directory.

*   **Cycles:** If cycles are allowed, the system must be designed to avoid searching the same component twice to maintain performance.
*   **Reference Counts and Cycles:** In a general graph, a reference count of zero still means the file can be deleted. However, if cycles exist, the reference count may never reach zero even when the file is no longer accessible by any user.
*   **Garbage Collection:** To handle cycles, systems use garbage collection. This involves a two-pass process:
    *   **First Pass:** The system traverses the entire file structure and marks everything that can be accessed.
    *   **Second Pass:** The system collects everything that is not marked and adds it to a free-space list for reallocation.

---
### **FILE SHARING AND PROTECTION**

File sharing is a critical feature that allows users to collaborate, reduce redundancy, and achieve computing goals more efficiently. To support this, the operating system must manage access across multiple users and even remote systems.


### **1) File Sharing**

#### **I. Multiple Users**
*   **Default Access vs. Explicit Grant:** Systems with multiple users can either allow access to others' files by default or require the owner to specifically grant permissions.
*   **Owner and Group:** To implement sharing, the system uses "Owner" (the user with maximum control) and "Group" (a subset of users with shared access) attributes.
*   **Identification:** When an operation is requested, the system compares the requesting User ID against the owner and group IDs stored in the file's attributes to determine if the action is allowed.

#### **II. Remote File Systems**
Networking enables sharing across different physical locations.
*   **i) Client-Server Model:** A server declares resources as available, and clients seek access to them. A single server can support multiple clients, and a client can use multiple servers.
*   **ii) Distributed Information Systems:** Also known as distributed naming services (like DNS or LDAP), these provide unified access to the information needed for remote computing, such as user IDs and passwords across a network.
*   **iii) Failure Modes:** Remote systems are complex and can fail due to network congestion, cable failure, or corruption. Recovery often requires both the client and server to maintain "state" information about open files and current activities.



### **2) Consistency Semantics**

Consistency semantics specify how multiple users access a shared file simultaneously and when modifications by one user become visible to others.

#### **i) Unix Semantics**
The UNIX file system follows these rules:
*   **Immediate Visibility:** Writes to an open file by a user are visible immediately to all other users who have that same file open.
*   **Shared Pointers:** Users can share the "current location pointer." If one user advances the pointer, it affects all other users sharing that pointer.

#### **ii) Session Semantics**
Used by the Andrew File System (AFS):
*   **Delayed Visibility:** Writes to an open file are **not** visible immediately to other users with the same file open.
*   **Completion Visibility:** Changes only become visible in sessions that start **after** the file has been closed. Currently open instances do not reflect these new changes.

#### **iii) Immutable Shared File Semantics**
*   **No Modifications:** Once a creator declares a file as shared, it cannot be modified.
*   **Fixed Properties:** An immutable file's name cannot be reused, and its contents cannot be altered.
*   **Fixed Contents:** This signifies that the file's data is permanent and unchangeable.



### **3) Protection**

Protection mechanisms provide controlled access by limiting the types of operations users can perform on a file.

#### **Goals of Protection**
*   **Prevention of Misuse:** To stop malicious users or programs from intentionally damaging the system.
*   **Policy Enforcement:** To ensure resources are used only in ways that align with system administrator or designer policies.
*   **Damage Control:** To ensure that "errant" (buggy) programs cause the minimum amount of damage possible to the rest of the system.



#### **Types of Access**
Operations that can be controlled include:
*   **Read:** Reading from the file.
*   **Write:** Writing or rewriting the file.
*   **Execute:** Loading the file into memory and running it.
*   **Append:** Adding new information only to the end of the file.
*   **Delete:** Removing the file and freeing its space.
*   **List:** Listing the name and attributes of the file.

### **PROTECTION: ACCESS TYPES AND CONTROL**

The necessity for file protection arises directly from the ability of users to access files. Systems that prohibit access to other users' files do not require these protection mechanisms.

---

### **1. Types of Access**
Operating systems control several different types of operations to ensure data integrity and security:
*   **Read:** Allows reading the contents of the file.
*   **Write:** Allows writing to or rewriting the file.
*   **Execute:** Allows loading the file into memory and running it as a program.
*   **Append:** Allows adding new information to the end of the existing file.
*   **Delete:** Allows removing the file and freeing its disk space for reuse.
*   **List:** Allows viewing the name and attributes of the file within a directory.

These higher-level functions are often implemented by system programs that trigger lower-level system calls.



### **2. Access Control Methods**

#### **Access-Control List (ACL)**
The most common approach to protection is making access dependent on user identity.
*   **Mechanism:** An ACL is associated with each file and directory, specifying which usernames are allowed and what specific types of access they have.
*   **Verification:** When a user requests access, the operating system checks the ACL. If the user and the requested access type are listed, access is granted; otherwise, a protection violation occurs.
*   **Challenges:** 
    *   Constructing long lists can be tedious.
    *   Directory entries become variable in size, complicating space management.

#### **User Classifications**
To simplify ACLs, many systems categorize users into three groups:
1.  **Owner:** The user who created the file.
2.  **Group:** A specific set of users who share access and require similar permissions.
3.  **Universe (Other):** All remaining users in the system.





### **3. Protection in UNIX Systems**
UNIX uses a condensed scheme of **9 bits** to record protection information, divided into three fields of 3 bits each (**rwx**):
*   **r (Read):** Permission to read.
*   **w (Write):** Permission to write.
*   **x (Execute):** Permission to execute.

These fields are applied to the **Owner**, the **Group**, and the **Universe**.

**Example (book.tex):**
*   **Owner (Sara):** Needs full control. Permissions: **rwx** (111).
*   **Group (Students):** Need to read and write. Permissions: **rw-** (110).
*   **Universe (Others):** Need only to read. Permissions: **r--** (100).


### **4. Alternative: Password Protection**
Another method involves associating a unique password with every file.
*   **Effectiveness:** This can be highly effective if passwords are random and changed frequently.
*   **Disadvantages:**
    *   Users may have to remember an overwhelming number of passwords.
    *   If a single password is used for all files, discovering it grants access to everything (all-or-none protection).



### **5. Directory Protection**
In multilevel directory structures, protection must extend beyond individual files to include subdirectories.
*   **Mechanism:** Special mechanisms are required to control who can create or delete files within a specific directory.
*   **Difference:** Directory protection operations differ from file operations because they manage the "container" rather than the data itself.
---
### **FILE SYSTEM STRUCTURE**

The file system provides the mechanism for on-line storage and access to file contents, including data and programs. It resides permanently on secondary storage (disks), which allow for data to be rewritten in place and accessed directly.

#### **Layered File System Architecture**
To manage the complexity of mapping logical files to physical disk blocks, file systems are organized into layers:

*   **I/O Control:** The lowest level, consisting of device drivers and interrupt handlers that transfer information between main memory and the disk system.
*   **Basic File System:** Issues generic commands to device drivers to read and write physical blocks. It also manages memory buffers and caches for metadata to improve performance.
*   **File Organization Module:** Translates logical block addresses (the file's internal numbering) into physical block addresses (the disk's numbering) and tracks free space.
*   **Logical File System:** Manages the directory structure and metadata. It maintains file structure via **File Control Blocks (FCB)**.

**Advantages of Layering:** 
*   **Minimal Code Duplication:** Shared layers (like I/O control) can serve multiple file systems.
*   **Modularity:** Different file system types can be supported on the same hardware by changing only the upper layers.

**Disadvantages:**
*   **Complexity:** Deciding the number and function of layers is a significant design challenge.
*   **Performance Overhead:** Data must pass through multiple software layers, which can add latency.

#### **Example File Systems**
*   **UNIX:** Uses the UNIX File System (UFS), based on the Fast File System (FFS).
*   **Windows:** Supports FAT, FAT32, and NTFS (Windows NT File System).
*   **Linux:** Supports over 40 file systems, standardizing on the Extended File System (ext3, ext4).

### **ON-DISK & IN-MEMORY STRUCTURES**

#### **Key On-Disk Structures**
*   **Boot Control Block:** Contains information needed to boot the operating system from a volume (e.g., the MBR or partition boot sector).
*   **Volume Control Block:** Contains partition details, such as block size, block count, and pointers to free blocks (e.g., the superblock).
*   **Directory Structure:** Organizes the files (e.g., inode numbers in UFS).
*   **File Control Block (FCB):** Stores file permissions, size, dates, and data block pointers.



#### **Key In-Memory Structures**
*   **Mount Table:** Information about each mounted volume.
*   **Directory-Structure Cache:** Stores recently accessed directory info.
*   **System-Wide Open-File Table:** Contains a copy of the FCB for every file currently open by any process.
*   **Per-Process Open-File Table:** A pointer to the system-wide table for files open by a specific process, along with the process's current file pointer.



### **PARTITIONING AND MOUNTING**
*   **Partitioning:** A disk can be sliced into multiple partitions (raw or cooked). **Raw disks** have no file system (used for swap space or databases), while **cooked disks** contain a file system.
*   **Mounting:** The root partition is mounted at boot. Other file systems are attached to the hierarchy at a **mount point** (an empty directory). Windows mounts volumes to drive letters (e.g., C:), while UNIX integrates them into a single tree.


### **VIRTUAL FILE SYSTEMS (VFS)**
Modern OSs use a VFS layer to allow different file system types (local and remote) to appear the same to application programs.
*   **Interface Layer:** Provides standard calls like `open()` and `read()`.
*   **VFS Layer:** Separates generic operations from specific implementations and uses **vnodes** to uniquely represent files across a network.





### **FILE / DISK ALLOCATION TECHNIQUES**

#### **1. Contiguous Allocation**
Each file occupies a set of contiguous blocks on the disk.
*   **Advantage:** Minimal seek time; easy to implement.
*   **Disadvantage:** **External Fragmentation** (free space becomes fragmented over time) and difficulty in predicting file growth.

#### **2. Linked Allocation**
Files are stored as a linked list of disk blocks.
*   **Advantage:** No external fragmentation; files can grow easily.
*   **Disadvantage:** Inefficient for direct (random) access; pointers take up space. 
*   **Variation:** **File-Allocation Table (FAT)** stores all pointers in one table at the start of the disk to improve performance.

#### **3. Indexed Allocation**
Each file has its own **index block**, which contains pointers to all its data blocks.
*   **Advantage:** Supports efficient direct access without fragmentation.
*   **Mechanisms for Large Files:**
    *   **Linked Scheme:** Linking multiple index blocks together.
    *   **Multilevel Index:** A first-level index points to second-level index blocks.
    *   **Combined Scheme (UNIX Inode):** Uses direct pointers for small files and indirect/double-indirect pointers for large files.





### **FREE SPACE MANAGEMENT**
To reuse deleted file space, the system tracks free blocks using:
*   **Bit Vector:** 1 bit per block (1 = free, 0 = allocated). Simple and efficient.
*   **Linked List:** Linking free blocks together. Slow to traverse but easy to manage.
*   **Grouping/Counting:** Storing addresses of groups of free blocks or a starting address plus a count of contiguous free blocks.
---
### **FREE SPACE MANAGEMENT**

Because disk space is limited, the operating system must reuse the space from deleted files to accommodate new ones. To track available areas, the system maintains a **free-space list**, which records all blocks not currently allocated to a file or directory.



#### **1. Bit Vector (Bit Map)**
The free-space list is represented as a series of bits where each bit corresponds to a specific disk block.
*   **Mechanism:** A bit is set to **1** if the block is free and **0** if it is allocated.
*   **Example:** For a disk where blocks 2–5 and 8–13 are free, the bit map would start with bits representing those free positions as 1s.
*   **Calculation:** To find the first free block, the system checks for the first non-zero word. The block number is calculated as: $(number\ of\ bits\ per\ word) \times (number\ of\ 0\text{-}value\ words) + offset\ of\ first\ 1\ bit$.
*   **Pros/Cons:** It is simple and efficient for finding contiguous free blocks but becomes inefficient unless the entire vector is kept in main memory.

#### **2. Linked List**
This method links all free disk blocks together, keeping a pointer to the first free block in a special disk location.
*   **Mechanism:** The first free block contains a pointer to the next free disk block, and so on.
*   **Example:** If block 2 is the first free block, it points to block 3, which then points to block 4.
*   **Pros/Cons:** This scheme is generally inefficient because traversing the list requires reading each block, which requires substantial I/O time.



#### **3. Grouping**
A modification of the linked list approach designed to find the addresses of a large number of free blocks quickly.
*   **Mechanism:** The first free block stores the addresses of $n$ free blocks. 
*   **Structure:** The first $n-1$ of these addresses are actually free blocks. The $n$-th address points to another block that contains the addresses of the next $n$ free blocks.

#### **4. Counting**
This method takes advantage of the fact that multiple contiguous blocks are often freed or allocated at the same time.
*   **Mechanism:** Instead of listing every individual block, the system stores the address of the first free block and the number ($n$) of free contiguous blocks that follow it.
*   **Structure:** Each entry in the list consists of a **disk address** and a **count**.
*   **Storage:** For efficiency, these entries are often stored in a balanced tree rather than a simple linked list to allow for fast lookup and insertion.

#### **5. Space Maps**
Used by advanced systems like Oracle’s ZFS, space maps manage massive amounts of data by dividing devices into chunks called **Metaslabs**.
*   **Mechanism:** Each Metaslab has an associated space map which uses log-structured techniques to record all block activity (allocating and freeing) in time order.
*   **Operation:** When the system needs to allocate or free space, it loads the space map into a balanced-tree structure in memory and "replays" the log to find the current state.
*   **Result:** This provides an extremely accurate and fast in-memory representation of available space for that specific Metaslab.
---
### **I/O SYSTEMS: HARDWARE AND KERNEL SUBSYSTEM**

The role of the operating system in computer I/O is to manage and control I/O operations and devices. This is achieved through a combination of hardware device controllers and software device driver techniques.



### **1. I/O Hardware**
Computers interact with a vast array of devices, categorized into storage (disks), transmission (network cards), and human interface (keyboard, mouse).

#### **Key Hardware Components**
*   **Port:** The connection point through which a device communicates with the machine.
*   **Bus:** A common set of wires and a rigidly defined protocol that allows multiple devices to communicate.
    *   **PCI Bus:** Connects high-speed devices like the processor and memory.
    *   **Expansion Bus:** Connects slower devices like keyboards and USB ports.
*   **Controller:** A collection of electronics that operates a port, bus, or device. It contains registers (Status, Control, Data-in, Data-out) that the CPU manipulates to perform I/O.
*   **Memory-Mapped I/O:** A technique where the CPU interacts with device registers by reading or writing to specific physical memory addresses.

#### **I/O Communication Methods**
*   **Polling (Busy Waiting):** The host repeatedly reads the "busy bit" in the status register until it is clear. While simple, it wastes CPU cycles.
*   **Interrupts:** A device controller raises a signal on the "interrupt-request line." The CPU catches this, saves its state, and dispatches an **Interrupt Handler** (or Interrupt Service Routine) to deal with the device.
    *   **Interrupt Vector:** A table of addresses for specific interrupt handlers to speed up the dispatching process.
*   **Direct Memory Access (DMA):** Offloads data transfer tasks from the CPU to a special-purpose processor. 
    *   The CPU provides the DMA controller with the source, destination, and byte count. 
    *   The DMA controller transfers data directly between the device and memory, "stealing" bus cycles from the CPU (Cycle Stealing).




### **2. Application I/O Interface**
The OS abstracts the diversity of I/O devices into a few interface types to simplify application development.

*   **Block Devices:** Access data in fixed-sized blocks (e.g., hard drives). They support `read()`, `write()`, and `seek()`.
*   **Character Devices:** Access data as a stream of bytes (e.g., keyboards, mice). They use `get()` and `put()` operations.
*   **Network Devices:** Use a socket interface (different from read/write) to manage performance and addressing characteristics of remote data.
*   **Clocks and Timers:** Provide current time, elapsed time, and the ability to trigger operations at a specific future time (Programmable Interval Timer).

#### **I/O Variations**
*   **Blocking I/O:** The application is suspended (moved to a wait queue) until the I/O completes.
*   **Non-blocking I/O:** The system call returns immediately with whatever data is available.
*   **Asynchronous I/O:** The call returns immediately, and the I/O runs to completion in the background, notifying the application later.



### **3. Kernel I/O Subsystem**
The kernel provides a suite of services to manage I/O efficiently and protect the system from malicious or errant processes.

#### **Core Services**
*   **I/O Scheduling:** Reordering I/O requests (e.g., disk arm scheduling) to reduce waiting time and improve overall system throughput.
*   **Buffering:** Using a memory area to store data being transferred. This copes with speed mismatches between producers and consumers and supports "copy semantics" (ensuring data doesn't change during the write process).
*   **Caching:** Keeping copies of data in fast memory (RAM) to speed up subsequent accesses to the same data.
*   **Spooling:** Managing a buffer for devices that cannot accept interleaved data streams, such as printers. Each application's output is sent to a separate disk file and printed one at a time.
*   **Error Handling:** The OS compensates for transient failures (like a disk read retry) and returns error codes (e.g., `errno` in UNIX) to the application.
*   **I/O Protection:** All I/O instructions are "privileged." Users must issue a system call, allowing the kernel to verify the request before executing it in monitor mode.



#### **Kernel Data Structures**
The kernel tracks the state of I/O components via internal tables:
*   **System-wide Open File Table:** Tracks all files currently open in the system.
*   **Device-Status Table:** Tracks the state (idle or busy) of each device and maintains a queue of pending requests for busy devices.
---
### **FILE AND DIRECTORY PERMISSIONS**

In multi-user operating systems, permissions are essential to protect data and ensure that users can only access or modify files for which they have authorization.

#### **1. The UNIX Permission Model**
UNIX-based systems (including Linux) use a condensed 9-bit scheme to define access. These bits are divided into three fields of three bits each, representing three classes of users:
*   **Owner:** The user who created the file.
*   **Group:** A set of users sharing access to the file.
*   **Universe (Others):** All other users in the system.

Each field consists of the **rwx** bits:
*   **r (Read):** Permission to read the file contents or list a directory.
*   **w (Write):** Permission to modify the file or create/delete files within a directory.
*   **x (Execute):** Permission to run a file as a program or "enter" (traverse) a directory.



#### **2. Access Control Lists (ACLs)**
While the 9-bit scheme is efficient, it is limited. Many modern systems use **Access Control Lists (ACLs)** for finer granularity:
*   **Identity Dependent:** ACLs associate a specific list of usernames and their allowed access types with each file or directory.
*   **Verification:** When a user requests access, the OS checks the ACL for that specific user’s entry.
*   **Management:** In Windows, these lists are typically managed through the Security tab in a file’s properties window.



### **JOB SCHEDULING (CONCEPTUAL)**

Job scheduling allows the operating system to execute commands or scripts automatically at specified times or intervals. This is primarily handled by two utilities in UNIX-like environments: **cron** and **at**.

#### **1. cron (Recurring Tasks)**
The `cron` daemon is used for tasks that need to run repeatedly (e.g., daily backups or weekly system updates).
*   **Crontab:** A configuration file (cron table) where users specify the timing and the command to be executed.
*   **Fields:** A standard cron entry consists of five fields representing Minute, Hour, Day of Month, Month, and Day of Week.
*   **Usage:** It is the standard for system maintenance, such as log rotation or periodic report generation.



#### **2. at (One-Time Tasks)**
The `at` utility is designed for "fire and forget" tasks that only need to run once at a specific point in the future.
*   **Execution:** Once the specified time arrives, the task is executed, and the job is removed from the queue.
*   **Flexibility:** It accepts various time formats, such as "midnight," "noon," or specific offsets like "now + 30 minutes."
*   **Usage:** Commonly used for one-off maintenance tasks or running resource-heavy scripts during off-peak hours.
---