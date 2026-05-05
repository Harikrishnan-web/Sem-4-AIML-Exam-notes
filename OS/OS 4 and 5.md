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