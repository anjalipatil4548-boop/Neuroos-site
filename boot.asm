; NeuroOS bootloader (16-bit real mode, NASM)
; Build: nasm -f bin boot.asm -o neuroos.img
[org 0x7c00]

start:
    mov si, message        ; point SI to the text
    call print             ; print it
    jmp $                  ; stop here forever

print:
    mov ah, 0x0e           ; BIOS teletype function
.next:
    lodsb                  ; load next character into AL
    or al, al              ; end of string?
    jz .done
    int 0x10               ; print character
    jmp .next
.done:
    ret

message db 'NeuroOS booting... AI core ready.', 0

times 510 - ($ - $$) db 0  ; pad to 512 bytes
dw 0xAA55                  ; boot signature
