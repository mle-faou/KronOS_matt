/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:53:31 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/09/30 18:19:26 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory/memory.h>

// __MemorySystem *__mem_root;
// PageDirectory __page_directory;
// uint32_t __page_directory[PAGE_TABLE_SIZE];
// size_t __nb_pages;

void init_kernel_memory(void)
{
 
    return;
    
    // poweroff();
    // init_paging();
    // return;

    // __mem_root = (__MemorySystem *)kmalloc(sizeof(__MemorySystem));
    // __mem_root->value = (void *)MEMORY_START;
    // __mem_root->next = NULL;
    // __mem_root->prev = NULL;
    // __nb_pages = 0;

    /*

    __mem_root = NULL;
    __nb_pages = 0;

    for (size_t i = 0; i < PAGE_TABLE_SIZE; i++)
    {
        // This sets the following flags to the pages:
        // Supervisor: Only kernel-mode can access them
        // Write Enabled: It can be both read from and written to
        // Not Present: The page table is not present
        __page_directory[i] = 0x00000002;
    }

    uint32_t page_table[PAGE_TABLE_SIZE] __attribute__((aligned(PAGE_SIZE)));
    for (size_t i = 0; i < PAGE_TABLE_SIZE; i++)
    {
        // As the address is page aligned, it will always leave 12 bits zeroed.
        // Those bits are used by the attributes ;)
        page_table[i] = (i * 0x1000) | 3; // 0x3 = Supervisor + Write Enabled + Not Present
    }
    __page_directory[0] = ((unsigned int)page_table) | 3;

    // __enable_large_pages();
    kprintf("Load New Page Directory\n");
    __load_page_directory(__page_directory);
    kprintf("Enable paging\n");
    __enable_paging();
    // poweroff();
    // __flush_tlb();
    */
}