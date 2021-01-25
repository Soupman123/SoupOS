#include "cpu.h"

inline void CPU::cpuid(uint32_t reg, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx)
{
    __asm__ volatile("cpuid"
        : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx)
        : "0" (reg));
}

char vendor[128];
char* CPU::getName() {
    cpuid(0x80000002, (uint32_t *)(vendor +  0), (uint32_t *)(vendor +  4), (uint32_t *)(vendor +  8), (uint32_t *)(vendor + 12));
    cpuid(0x80000003, (uint32_t *)(vendor + 16), (uint32_t *)(vendor + 20), (uint32_t *)(vendor + 24), (uint32_t *)(vendor + 28));
    cpuid(0x80000004, (uint32_t *)(vendor + 32), (uint32_t *)(vendor + 36), (uint32_t *)(vendor + 40), (uint32_t *)(vendor + 44));
    vendor[127] = 0;
    return vendor;
}

char vendor2[13];
char* CPU::getVendor() {
    uint32_t standardfunc;
    cpuid(0, &standardfunc, (uint32_t *)(vendor2 + 0), (uint32_t *)(vendor2 + 8), (uint32_t *)(vendor2 + 4));
    vendor[12] = 0;
    return vendor2;
}

void CPU::addSupported(const char* sup) {
    features[cpuFeatures] = (char*)sup;
}

void CPU::addParsedSuported(const char* sup) {
    parsedFeatures[cpuFeatures] = (char*)sup;
    cpuFeatures++;
}


char** CPU::getFeatures() {
    uint32_t eax, ebx, ecx, edx, standardfunc;
    char* tmp[13];
    cpuid(0, &standardfunc, (uint32_t *)(tmp + 0), (uint32_t *)(tmp + 8), (uint32_t *)(tmp + 4));
    
    if(standardfunc >= 1) {
        cpuid(1,&eax,&ebx,&ecx,&edx);

        if(ecx & ECX_SSE3) {addSupported("SSE3");addParsedSuported("Streaming SIMD Extensions 3");}
        if(ecx & ECX_PCLMULQDQ) {addSupported("PCLMULQDQ");addParsedSuported("PCLMULQDQ Instruction");}
        if(ecx & ECX_DTES64) {addSupported("DTES64");addParsedSuported("64-Bit Debug Store Area");}
        if(ecx & ECX_MONITOR) {addSupported("MONITOR");addParsedSuported("MONITOR/MWAIT");}
        if(ecx & ECX_DS_CPL) {addSupported("DS_CPL");addParsedSuported("CPL Qualified Debug Store");}
        if(ecx & ECX_VMX) {addSupported("VMX");addParsedSuported("Virtual Machine Extensions");}
        if(ecx & ECX_SMX) {addSupported("SMX");addParsedSuported("Safer Mode Extensions");}
        if(ecx & ECX_EST) {addSupported("EST");addParsedSuported("Enhanced SpeedStep Technology");}
        if(ecx & ECX_TM2) {addSupported("TM2");addParsedSuported("Thermal Monitor 2");}
        if(ecx & ECX_SSSE3) {addSupported("SSSE3");addParsedSuported("Supplemental Streaming SIMD Extensions 3");}
        if(ecx & ECX_CNXT_ID) {addSupported("CNXT_ID");addParsedSuported("L1 Context ID");}
        if(ecx & ECX_FMA) {addSupported("FMA");addParsedSuported("Fused Multiply Add");}
        if(ecx & ECX_CX16) {addSupported("CX16");addParsedSuported("CMPXCHG16B Instruction");}
        if(ecx & ECX_XTPR) {addSupported("XTPR");addParsedSuported("xTPR Update Control");}
        if(ecx & ECX_PDCM) {addSupported("PDCM");addParsedSuported("Perf/Debug Capability MSR");}
        if(ecx & ECX_PCID) {addSupported("PCID");addParsedSuported("Process-context Identifiers");}
        if(ecx & ECX_DCA) {addSupported("DCA");addParsedSuported("Direct Cache Access");}
        if(ecx & ECX_SSE41) {addSupported("SSE41");addParsedSuported("Streaming SIMD Extensions 4.1");}
        if(ecx & ECX_SSE42) {addSupported("SSE42");addParsedSuported("Streaming SIMD Extensions 4.2");}
        if(ecx & ECX_X2APIC) {addSupported("X2APIC");addParsedSuported("Extended xAPIC Support");}
        if(ecx & ECX_MOVBE) {addSupported("MOVBE");addParsedSuported("MOVBE Instruction");}
        if(ecx & ECX_POPCNT) {addSupported("POPCNT");addParsedSuported("POPCNT Instruction");}
        if(ecx & ECX_TSC) {addSupported("TSC");addParsedSuported("Local APIC supports TSC Deadline");}
        if(ecx & ECX_AESNI) {addSupported("AESNI");addParsedSuported("AESNI Instruction");}
        if(ecx & ECX_XSAVE) {addSupported("XSAVE");addParsedSuported("XSAVE/XSTOR States");}
        if(ecx & ECX_OSXSAVE) {addSupported("OSXSAVE");addParsedSuported("OS Enabled Extended State Management");}
        if(ecx & ECX_AVX) {addSupported("AVX");addParsedSuported("AVX Instructions");}
        if(ecx & ECX_F16C) {addSupported("F16C");addParsedSuported("16-bit Floating Point Instructions");}
        if(ecx & ECX_RDRAND) {addSupported("RDRAND");addParsedSuported("RDRAND Instruction");}
        if(edx & EDX_FPU) {addSupported("FPU");addParsedSuported("Floating-Point Unit On-Chip");}
        if(edx & EDX_VME) {addSupported("VME");addParsedSuported("Virtual 8086 Mode Extensions");}
        if(edx & EDX_DE) {addSupported("DE");addParsedSuported("Debugging Extensions");}
        if(edx & EDX_PSE) {addSupported("PSE");addParsedSuported("Page Size Extension");}
        if(edx & EDX_TSC) {addSupported("TSC");addParsedSuported("Time Stamp Counter");}
        if(edx & EDX_MSR) {addSupported("MSR");addParsedSuported("Model Specific Registers");}
        if(edx & EDX_PAE) {addSupported("PAE");addParsedSuported("Physical Address Extension");}
        if(edx & EDX_MCE) {addSupported("MCE");addParsedSuported("Machine-Check Exception");}
        if(edx & EDX_CX8) {addSupported("CX8");addParsedSuported("CMPXCHG8 Instruction");}
        if(edx & EDX_APIC) {addSupported("APIC");addParsedSuported("APIC On-Chip");}
        if(edx & EDX_SEP) {addSupported("SEP");addParsedSuported("SYSENTER/SYSEXIT instructions");}
        if(edx & EDX_MTRR) {addSupported("MTRR");addParsedSuported("Memory Type Range Registers");}
        if(edx & EDX_PGE) {addSupported("PGE");addParsedSuported("Page Global Bit");}
        if(edx & EDX_MCA) {addSupported("MCA");addParsedSuported("Machine-Check Architecture");}
        if(edx & EDX_CMOV) {addSupported("CMOV");addParsedSuported("Conditional Move Instruction");}
        if(edx & EDX_PAT) {addSupported("PAT");addParsedSuported("Page Attribute Table");}
        if(edx & EDX_PSE36) {addSupported("PSE36");addParsedSuported("36-bit Page Size Extension");}
        if(edx & EDX_PSN) {addSupported("PSN");addParsedSuported("Processor Serial Number");}
        if(edx & EDX_CLFLUSH) {addSupported("CLFLUSH");addParsedSuported("CLFLUSH Instruction");}
        if(edx & EDX_DS) {addSupported("DS");addParsedSuported("Debug Store");}
        if(edx & EDX_ACPI) {addSupported("ACPI");addParsedSuported("Thermal Monitor and Software Clock Facilities");}
        if(edx & EDX_MMX) {addSupported("MMX");addParsedSuported("MMX Technology");}
        if(edx & EDX_FXSR) {addSupported("FXSR");addParsedSuported("FXSAVE and FXSTOR Instructions");}
        if(edx & EDX_SSE) {addSupported("SSE");addParsedSuported("Streaming SIMD Extensions");}
        if(edx & EDX_SSE2) {addSupported("SSE2");addParsedSuported("Streaming SIMD Extensions 2");}
        if(edx & EDX_SS) {addSupported("SS");addParsedSuported("Self Snoop");}
        if(edx & EDX_HTT) {addSupported("HTT");addParsedSuported("Multi-Threading");}
        if(edx & EDX_TM) {addSupported("TM");addParsedSuported("Thermal Monitor");}
        if(edx & EDX_PBE) {addSupported("PBE");addParsedSuported("Pending Break Enable");}
    } 
    
    return features;
}