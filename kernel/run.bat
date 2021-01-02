@echo off
set OSNAME=CustomOS
set BUILDDIR=%0/../bin
set OVMFDIR=%0/../../OVMFbin
@set path=C:\Program Files\qemu
@pushd %~dp0
color 0a
echo Starting QEMU....
qemu-system-x86_64 -drive format=raw,file=Z:\home\soupman\SoupOSUEFI\kernel\bin\CustomOS.img -m 256M -cpu qemu64 -drive if=pflash,format=raw,unit=0,file=..\OVMFbin\OVMF_CODE-pure-efi.fd,readonly=on -drive if=pflash,format=raw,unit=1,file=..\OVMFbin\OVMF_VARS-pure-efi.fd -net none
@popd
