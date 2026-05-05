# Unit-4
---

### **MASS STORAGE STRUCTURE: OVERVIEW**

Main memory is typically too small to store all necessary programs and data permanently and is volatile, meaning it loses contents when power is lost. Therefore, computer systems use **secondary storage** as a permanent, high-capacity extension of main memory.

---

### **1. Magnetic Disks**
Magnetic disks provide the primary bulk of secondary storage for modern systems.
*   **Platters:** Each disk consists of flat circular platters (1.8 to 3.5 inches in diameter) coated with magnetic material. Information is stored by recording it magnetically on these surfaces.
*   **Read-Write Heads:** A head "flies" just above the surface of every platter. These heads are attached to a disk arm that moves all heads as a unit.
*   **Organization:** The surface of a platter is logically divided into circular **tracks**, which are further subdivided into **sectors**.
*   **Performance:** Disk speed is determined by the **transfer rate** (data flow speed) and **positioning time** (random-access time).



---

### **2. CYLINDER**
*   **Definition:** A cylinder is the set of all tracks that are at one specific arm position.
*   **Function:** Because the disk arm moves all read-write heads together, every head is positioned over the same track number on their respective platter surfaces simultaneously. This vertical "stack" of tracks forms the cylinder.



---

### **3. HEAD CRASH**
*   **Definition:** A head crash occurs if the read-write head makes physical contact with the disk surface.
*   **Consequences:** Although platters have a thin protective layer, a crash usually damages the magnetic surface. This often leads to data loss or total drive failure.

---

### **4. Magnetic Tapes**
*   **Usage:** Tapes were early secondary-storage media but are now primarily used for **backup**, transferring information between systems, or storing infrequently used data.
*   **Access Speed:** Tapes are significantly slower than magnetic disks. Random access is roughly a thousand times slower, making them impractical for primary secondary storage.
*   **Capacity:** Like disks, they are permanent and can hold very large quantities of data.

---

### **5. Disk Structure**
*   **Logical Blocks:** Disk drives are addressed as large one-dimensional arrays of **logical blocks**, which are the smallest unit of data transfer.
*   **Mapping:** This array of blocks (usually 512 bytes each) is mapped onto the disk sectors sequentially. Sector 0 is the first sector of the first track on the outermost cylinder.
*   **Recording Techniques:**
    *   **Constant Linear Velocity (CLV):** The density of bits per track is uniform.
    *   **Constant Angular Velocity (CAV):** Bit density decreases from inner tracks to outer tracks to keep the data rate constant as the disk spins.

---

### **6. Disk Attachment**
Computers access disk storage through three primary architectures:
*   **Host-Attached Storage:** Accessed through local I/O ports using bus architectures like **SATA, USB, or Fibre Channel**. Data transfers are managed by a **host controller** at the computer end and a **disk controller** built into the drive.
*   **Network-Attached Storage (NAS):** A special-purpose storage system accessed remotely over a data network. Clients use remote-procedure-call interfaces such as **NFS** (UNIX) or **CIFS** (Windows).
*   **Storage Area Network (SAN):** A private, high-speed network that connects multiple servers to various storage units, allowing for flexible storage allocation across the enterprise.