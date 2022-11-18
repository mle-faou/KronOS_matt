/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paging.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:34:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/18 01:03:05 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory/paging.h>
#include <memory/frames.h>
#include <memory/kheap.h>

page_directory_t *kernel_directory = NULL;
page_directory_t *current_directory = NULL;
bool paging_enabled = false;

static page_t *create_page(uint32_t address, page_directory_t *dir)
{
    uint32_t table_idx = address / 1024;
    if (!dir->tables[table_idx])
    {
        dir->tables[table_idx] = (page_table_t *)kmalloc_ap(sizeof(page_table_t), &dir->tablesPhysical[table_idx]);
        kmemset(dir->tables[table_idx], 0, PAGE_SIZE);
        dir->tablesPhysical[table_idx] |= 0x7;
        return (&dir->tables[table_idx]->pages[address % 1024]);
    }
    else
    {
        dir->tablesPhysical[table_idx] |= 0x7;
        return (&dir->tables[table_idx]->pages[address % 1024]);
    }
}

#include <system/pit.h>

page_t *get_page(uint32_t address, page_directory_t *dir)
{
    address /= PAGE_SIZE;
    uint32_t table_idx = address / 1024;
    if (dir->tables[table_idx])
    {
        return (&dir->tables[table_idx]->pages[address % 1024]);
    }
}

static void switch_page_directory(page_directory_t *dir)
{
    current_directory = dir;
    enable_paging((page_directory_t *)&dir->tablesPhysical);
}

void init_paging(void)
{
    init_frames();

    kernel_directory = (page_directory_t *)kmalloc_a(sizeof(page_directory_t));
    kmemset(kernel_directory, 0, sizeof(page_directory_t));
    kernel_directory->physicalAddr = (uint32_t)kernel_directory->tablesPhysical;
    current_directory = kernel_directory;

    /* Map Kernel Heap Area */
    for (uint32_t i = KHEAP_START; i < KHEAP_START + KHEAP_INITIAL_SIZE; i += PAGE_SIZE)
    {
        create_page(i, kernel_directory);
    }

    /* ALlocate Frames */
    for (uint32_t i = 0; i < placement_addr + PAGE_SIZE; i += PAGE_SIZE)
    {
        const page_t *page = get_page(i, kernel_directory);
        if (!page)
            page = create_page(i, kernel_directory);
        alloc_frame((page_t *)page, 0, 0);
    }

    /* Allocate Frames for Kernel Heap */
    for (uint32_t i = KHEAP_START; i < KHEAP_START + KHEAP_INITIAL_SIZE; i += PAGE_SIZE)
    {
        const page_t *page = get_page(i, kernel_directory);
        if (!page)
            page = create_page(i, kernel_directory);
        alloc_frame((page_t *)page, 0, 0);
    }

    isr_register_interrupt_handler(14, page_fault);

    switch_page_directory(kernel_directory);
    init_heap(KHEAP_START, KHEAP_START + KHEAP_INITIAL_SIZE, KHEAP_MAX_SIZE, 0, 0);
    current_directory = kernel_directory;
    switch_page_directory(current_directory);
    paging_enabled = true;
}