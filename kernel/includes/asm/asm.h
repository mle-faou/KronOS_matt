/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:06:51 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/12/09 22:33:54 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H

/*******************************************************************************
 *                                GET ASM FLAGS                                *
 ******************************************************************************/

#define GET_ESP(x) asm volatile("mov %%esp, %0" \
								: "=r"(x)::)
#define GET_EBP(x) asm volatile("mov %%ebp, %0" \
								: "=r"(x)::)
#define GET_EIP(x) asm volatile("mov %%eip, %0" \
								: "=r"(x)::)
#define GET_ECX(x) asm volatile("mov %%ecx, %0" \
								: "=r"(x)::)
#define GET_EDX(x) asm volatile("mov %%edx, %0" \
								: "=r"(x)::)
#define GET_EBX(x) asm volatile("mov %%ebx, %0" \
								: "=r"(x)::)
#define GET_EAX(x) asm volatile("mov %%eax, %0" \
								: "=r"(x)::)
#define GET_ESI(x) asm volatile("mov %%esi, %0" \
								: "=r"(x)::)
#define GET_EDI(x) asm volatile("mov %%edi, %0" \
								: "=r"(x)::)

/*******************************************************************************
 *                                   EFLAGS                                    *
 ******************************************************************************/

#define GET_EFLAGS(x) asm volatile("pushf\n\t" \
								   "pop %0"    \
								   : "=r"(x)::)
#define SET_EFLAGS(x) asm volatile("push %0\n\t" \
								   "popf" ::     \
									   : "r"(x))

/*******************************************************************************
 *                                SET ASM FLAGS                                *
 ******************************************************************************/

#define SET_EIP(x) asm volatile("mov %0, %%eip" :: \
									: "r"(x))
#define SET_ESP(x) asm volatile("mov %0, %%esp" :: \
									: "r"(x))
#define SET_EBP(x) asm volatile("mov %0, %%ebp" :: \
									: "r"(x))
#define SET_ECX(x) asm volatile("mov %0, %%ecx" :: \
									: "r"(x))
#define SET_EDX(x) asm volatile("mov %0, %%edx" :: \
									: "r"(x))
#define SET_EBX(x) asm volatile("mov %0, %%ebx" :: \
									: "r"(x))
#define SET_EAX(x) asm volatile("mov %0, %%eax" :: \
									: "r"(x))
#define SET_ESI(x) asm volatile("mov %0, %%esi" :: \
									: "r"(x))
#define SET_EDI(x) asm volatile("mov %0, %%edi" :: \
									: "r"(x))

/*******************************************************************************
 *                              SET ASM REGISTER                               *
 ******************************************************************************/

#define SET_CR4(x) asm volatile("mov %0, %%cr4" :: \
									: "r"(x))

/*******************************************************************************
 *                                    CPUID                                    *
 ******************************************************************************/

#define CPUID(eax, ebx, ecx, edx) asm volatile("cpuid"                                          \
											   : "=a"(*eax), "=b"(*ebx), "=c"(*ecx), "=d"(*edx) \
											   : "a"(*eax), "c"(*ecx))

/*******************************************************************************
 *                               INTERRUPT FLAG                                *
 ******************************************************************************/

#define ASM_STI() __asm__ volatile("sti") // Set Interrupt Flag
#define ASM_CLI() __asm__ volatile("cli") // Clear Interrupt Flag

#endif /* !ASM_H */