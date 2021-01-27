#pragma once
#include <stdint.h>
#include <stddef.h>
#include "cstr.h"
#include "Bitmap.h"
#include "paging/PageFrameAllocator.h"
#include "paging/PageMapIndexer.h"
#include "paging/paging.h"
#include "paging/PageTableManager.h"
#include "gdt/gdt.h"
#include "interrupts/IDT.h"
#include "interrupts/interrupts.h"
#include "IO.h"
#include "drivers/display/Framebuffer.h"
#include "drivers/display/Rendering.h"
#include "drivers/mouse/mouse.h"
#include "drivers/cpu/cpu.h"

struct BootInfo{
	Framebuffer* framebuffer;
	PSF1_FONT* psf1_Font;
	EFI_MEMORY_DESCRIPTOR* mMap;
	uint64_t mMapSize;
	uint64_t mMapDescSize;
};

extern uint64_t _KernelStart;
extern uint64_t _KernelEnd;

struct KernelInfo {
    PageTableManager* pageTableManager;
};

//CPU cpu;
//char** CPUFeatures = cpu.getFeatures();

KernelInfo InitializeKernel(BootInfo* bootInfo);