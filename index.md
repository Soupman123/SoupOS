<script>
var myDiv = document.createElement("div");
myDiv.id = 'menu';
myDiv.innerHTML = '<div id="menu" style="position: absolute; left: 0; margin-left: 30px; top: 285px;"><h2>{{ site.data.list.docs_list_title }}</h2><ul>{% for item in site.data.list.toc %}<h4>{{ item.title }}</h4>{% for entry in item.subfolderitems %}<li><a href="https://soupman123.github.io/SoupOS{{ entry.url }}">{{ entry.page }}</a></li>{% endfor %}{% endfor %}</ul></div>';
document.body.appendChild(myDiv);
</script>

## Introduction

### What is SoupOS?
[SoupOS](http://github.com) is a computer operating system currently maintained & written by [Soupman123](https://github.com/Soupman123/). SoupOS is a hobby operating system not written to compete with other operating systems, and is currently just a small project.

### What can SoupOS do?
Some of the main features inlude but are not limmited to at this moment:
```
PS/2 Mouse
Basic Keyboard
Simple text rendering
PCI Devices
*Temporary Double Buffering System
(subject to major performance improvement in near future!)
```

### How can I get involved / started?
To get involved you can download the source code [here](https://github.com/Soupman123/SoupOS/archive/master.zip), or download the compiled operating system image [here](https://github.com/Soupman123/SoupOS/raw/master/kernel/bin/SoupOS.img). There are also some great resources over at [@Absurdponcho](https://github.com/Absurdponcho)['s operating system](https://github.com/Absurdponcho/PonchoOS) if you would like to learn more about operating system development. You can also support this project over in [support](#support).

## Internals
The bootloader is an efi application and can be found [here](https://github.com/Soupman123/SoupOS/blob/master/gnu-efi/bootloader/main.c). It passes all the nessasary values to the [kernel](https://github.com/Soupman123/SoupOS/blob/master/kernel/src/kernel.cpp). These valuse include (but not limited to):
```
Primary Framebuffer information and location
RSDP
Memory Map
```
The kernel has many tasks it has to complete on startup in order to run. These tasks are important such as defining a global memory table, and paging.

### GDT
The first task the kernel starts is to start the "Global Descriptor Table" or GDT for short. This is needed in order to define the characteristics of the various memory areas used during program execution, including the base address, the size, and access privileges like executability and writability.

### Preparing the memory
The next task the kernel completes is the memory preparation. To prepare the memory, the kenel first will lock all the pages dedicated to the kernel memory so that the global memory allocator will not give any kernel memory for other programs to write over. After the kernel memory is locked, the kernel requests a page (4096 bytes of free memory) from the global memory allocator, and completely clears it of residual bytes. This page will become the global page table. Then the kernel loops through memory and maps the memory saving the map to the page table previously described. Next, the kernel will also map the framebuffer and lock those pages so that the framebuffer will never overwritten by a program. The last step is to tell the computer that that page is the page table and after this is complete the kenel can move onto the next step.

### Graphics
After we have completed some basics, we can add extras, such as the ability to write to the screen. The kernel now will give the framebuffer sent by the bootloader to the rendering handler. There are many algorithms the renderer has to write shapes and other graphics, so I will not describe them here. The render also has one other mode called "double buffering". Double buffering is where the renderer will write to an auxilary section in memory first, then the rendering loop will copy the buffer to the screen memory. This will prevent artifacting, and enable screen clearing. The issue with double buffering is it is very slow to copy the memory, which is the cause that it comes disabled by default. The buffering will be modified once a new graphics output protocol is written for SoupOS that will allow where the screen memory is read from. If we could move the screen memory, we could switch between the 2 buffers instead of moving the actual bytes. This feature is sadly still in development though. 

### Interrupts
Next the kernel initializes i/o. Interrupts are the first to be initalized, this allows the PS/2 keyboard & mouse to work and be handled.

### PCI
Now we can initialize ACPI to finally interact with pci, which can support things like graphics cards or usb controllers.

### RTC
After all this the kernel sets up a RTC (real time clock) to have a system clock and other time functions.

## Miscellaneous

### Credits 
Thanks to [@Absurdponcho](https://github.com/Absurdponcho) for helping me get started with operating system development & always providing great educational resources.
[Soup#9370](https://discord.com/users/698622052059316285/).

### Support
Currently you can support this project via staring this project on [github](https://github.com/Soupman123/SoupOS/), but more support options are coming soon.
You can support [@Absurdponcho](https://github.com/Absurdponcho) via his [patreon](https://www.patreon.com/PonchoYT).

### Legal
```
“Soupman” License Condition v1.0, derived from the “Commons Clause” 
License Condition v1.0

The Software is provided to you by the Licensor under the License, 
as defined below, subject to the following conditions.

Without limiting other conditions in the License, the grant of 
rights under the License will not include, and the License does not
grant to you, the right to Sell the Software, or modify the license
for commercial use.

For purposes of the foregoing, “Sell” means practicing any or all 
of the rights granted to you under the License to provide to third
parties, for a fee or other consideration (including without 
limitation fees for hosting or consulting/ support services related
to the Software), a product or service whose value derives, entirely
or substantially, from the functionality of the Software. Any license 
notice or attribution required by the License must also include this
Soupman License Condition notice.

Software: SoupOS
License: “Soupman” License Condition v1.0
Licensor: Soupman123
```
<a href="#top">Back to top.</a>
