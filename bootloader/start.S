.global _start
.section .text

_start:
    /* Set up stack */
    ldr sp, =0x30000000   /* Example: Stack at 0x30000000 */

    /* Jump to kernel */
    ldr r0, =kernel_main
    blx r0

    /* Infinite loop */
    b .
