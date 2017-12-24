.section ".text.startup"

.global _start
.global _get_stack_pointer

.equ    CPSR_MODE_USER,         0x10
.equ    CPSR_MODE_FIQ,          0x11
.equ    CPSR_MODE_IRQ,          0x12
.equ    CPSR_MODE_SVR,          0x13
.equ    CPSR_MODE_ABORT,        0x17
.equ    CPSR_MODE_UNDEFINED,    0x1B
.equ    CPSR_MODE_SYSTEM,       0x1F

.equ    CPSR_IRQ_INHIBIT,       0x80
.equ    CPSR_FIQ_INHIBIT,       0x40
.equ    CPSR_THUMB,             0x20

_start:
	// Set the vector table
	ldr pc, _reset_h
	ldr pc, _undefined_instruction_vector_h
	ldr pc, _software_interrupt_vector_h
	ldr pc, _prefetch_abort_vector_h
	ldr pc, _data_abort_vector_h
	ldr pc, _unused_handler_h
	ldr pc, _interrupt_vector_h
	ldr pc, _fast_interrupt_vector_h

_reset_h:                           .word   _reset_
_undefined_instruction_vector_h:    .word   undefined_instruction_vector
_software_interrupt_vector_h:       .word   software_interrupt_vector
_prefetch_abort_vector_h:           .word   prefetch_abort_vector
_data_abort_vector_h:               .word   data_abort_vector
_unused_handler_h:                  .word   _reset_
_interrupt_vector_h:                .word   interrupt_vector
_fast_interrupt_vector_h:           .word   fast_interrupt_vector

_reset_:

	// Move instructions that for jumping vector table's handlers
	// to address 0x0000.(instructions are placed in the head of Code section(0x8000))
	mov		r0, #0x8000
	mov		r1, #0x0000

	// Instructions are 8 * 2 words.
	// So we need to ldmia and stmia twice.
	ldmia r0!,{r2, r3, r4, r5, r6, r7, r8, r9}
	stmia	r1!,{r2, r3, r4, r5, r6, r7, r8, r9}
	ldmia r0!,{r2, r3, r4, r5, r6, r7, r8, r9}
	stmia	r1!,{r2, r3, r4, r5, r6, r7, r8, r9}
	
	// Set interrupt mode stack pointer.
	mov r0, #(CPSR_MODE_IRQ | CPSR_IRQ_INHIBIT | CPSR_FIQ_INHIBIT )
	msr cpsr_c, r0
	mov sp, #(63 * 1024 * 1024)
	
	// Set application stack pointer.
	mov r0, #(CPSR_MODE_SVR | CPSR_IRQ_INHIBIT | CPSR_FIQ_INHIBIT )
	msr cpsr_c, r0
	mov sp, #(64 * 1024 * 1024) // 64MB
	
	// Run the c startup function.
	bl _cstartup

// safety trap
_inf_loop:
	b _inf_loop

_get_stack_pointer:
	// Return the stack pointer value
	str sp, [sp]
	ldr r0, [sp]
	
	// Return from the function
	mov pc, lr


