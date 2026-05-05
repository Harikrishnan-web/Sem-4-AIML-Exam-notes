### **MASS STORAGE STRUCTURE: OVERVIEW**

Main memory is typically too small to store all necessary programs and data permanently and is volatile, meaning it loses contents when power is lost[cite: 1]. Therefore, computer systems use **secondary storage** as a permanent, high-capacity extension of main memory[cite: 1].

---

### **1. Magnetic Disks**
Magnetic disks provide the primary bulk of secondary storage for modern systems[cite: 1].
*   **Platters:** Each disk consists of flat circular platters (1.8 to 3.5 inches in diameter) coated with magnetic material[cite: 1]. Information is stored by recording it magnetically on these surfaces[cite: 1].
*   **Read-Write Heads:** A head "flies" just above the surface of every platter[cite: 1]. These heads are attached to a **disk arm** that moves all heads as a single unit[cite: 1].
*   **Organization:** The surface is logically divided into circular **tracks**, which are further subdivided into **sectors**[cite: 1].
*   **Performance:** Disk speed is determined by the **transfer rate** (data flow speed) and **positioning time** (random-access time)[cite: 1].



---

### **2. CYLINDER**
*   **Definition:** A cylinder is the set of all tracks that are at one specific arm position[cite: 1].
*   **Function:** Because the disk arm moves all read-write heads together, every head is positioned over the same track number on their respective platter surfaces simultaneously[cite: 1]. This vertical "stack" of tracks forms the cylinder[cite: 1].

---

### **3. HEAD CRASH**
*   **Definition:** A head crash occurs if the read-write head makes physical contact with the disk surface[cite: 1].
*   **Consequences:** Although platters have a thin protective layer, a crash usually damages the magnetic surface, leading to data loss or total drive failure[cite: 1].

---

### **4. Magnetic Tapes**
*   **Usage:** Tapes were early secondary-storage media but are now primarily used for **backup**, transferring information between systems, or storing infrequently used data[cite: 1].
*   **Access Speed:** Tapes are significantly slower than magnetic disks[cite: 1]. Random access is roughly a thousand times slower, making them impractical for primary secondary storage[cite: 1].
*   **Capacity:** Like disks, they are permanent and can hold very large quantities of data[cite: 1].

---

### **5. Disk Structure**
*   **Logical Blocks:** Disk drives are addressed as large one-dimensional arrays of **logical blocks**, which are the smallest unit of data transfer[cite: 1].
*   **Mapping:** This array of blocks (usually 512 bytes each) is mapped onto the disk sectors sequentially[cite: 1]. Sector 0 is the first sector of the first track on the outermost cylinder[cite: 1].
*   **Formatting Types:**
    *   **Constant Linear Velocity (CLV):** The density of bits per track is uniform[cite: 1].
    *   **Constant Angular Velocity (CAV):** Bit density decreases from inner tracks to outer tracks to maintain a constant data rate as the disk spins[cite: 1].

---

### **6. Disk Attachment**
Computers access disk storage through three primary architectures:
*   **Host-Attached Storage:** Accessed through local I/O ports using bus architectures like **SATA, USB, or Fibre Channel**[cite: 1]. Data transfers are managed by a **host controller** at the computer end and a **disk controller** built into the drive[cite: 1].
*   **Network-Attached Storage (NAS):** A special-purpose storage system accessed remotely over a data network[cite: 1]. Clients use remote-procedure-call interfaces such as **NFS** (UNIX) or **CIFS** (Windows)[cite: 1].
*   **Storage Area Network (SAN):** A private, high-speed network that connects multiple servers to various storage units, allowing for flexible storage allocation[cite: 1].