	.cpu cortex-m0plus
	.arch armv6s-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"add.c"
	.text
	.global	acc
	.bss
	.align	2
	.type	acc, %object
	.size	acc, 4
acc:
	.space	4
	.text
	.align	1
	.global	mac
	.syntax unified
	.code	16
	.thumb_func
	.type	mac, %function
mac:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	str	r0, [r7, #4]
	str	r1, [r7]
	ldr	r1, [r7]
	ldr	r0, [r7, #4]
	bl	__aeabi_fmul
	adds	r3, r0, #0
	adds	r2, r3, #0
	ldr	r3, .L3
	ldr	r3, [r3]
	adds	r1, r3, #0
	adds	r0, r2, #0
	bl	__aeabi_fadd
	adds	r3, r0, #0
	adds	r0, r3, #0
	mov	sp, r7
	add	sp, sp, #8
	@ sp needed
	pop	{r7, pc}
.L4:
	.align	2
.L3:
	.word	acc
	.size	mac, .-mac
	.section	.init,"ax",%progbits
	.align	1
	.global	mac_init
	.syntax unified
	.code	16
	.thumb_func
	.type	mac_init, %function
mac_init:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r3, .L6
	ldr	r2, .L6+4
	str	r2, [r3]
	nop
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L7:
	.align	2
.L6:
	.word	acc
	.word	-1068955284
	.size	mac_init, .-mac_init
	.global	__aeabi_fadd
	.global	__aeabi_fmul
	.ident	"GCC: (Arm GNU Toolchain 15.2.Rel1 (Build arm-15.86)) 15.2.1 20251203"
