#!/bin/bash
# Build the NeuroOS pieces (needs gcc and nasm)
echo "Building bootloader..."
nasm -f bin boot.asm -o neuroos.img
echo "Building kernel demo...";  gcc kernel.c scheduler.c -o kernel_demo
echo "Building memory demo...";  gcc memory.c -o memory_demo
echo "Building shell demo...";   gcc shell.c -o shell_demo
echo "Done. Run: ./kernel_demo  ./memory_demo  ./shell_demo"
echo "Boot in emulator: qemu-system-x86_64 -drive format=raw,file=neuroos.img"
