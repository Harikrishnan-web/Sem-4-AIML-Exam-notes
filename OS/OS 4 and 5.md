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