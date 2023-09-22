# DDMA
Disk based DMA for ATA and SCSI
 
## Credits
[btbd](https://github.com/btbd/ddma) for his disk DMA for ATA disks.

## Brief
The repo showcases a c++ interface for using DMA to r/w arbitrary virtual addresses.
It can be adapted to hijack type-1 hypervisors like Hyper-V at runtime,
and in general circumvent SLAT.
