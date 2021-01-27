#include "clock.h"

int Clock::getUpdateInProgress() {
    outb(0x70, 0x0A);
    return (inb(0x71) & 0x80);
}

unsigned char Clock::getRegister(int reg) {
    outb(0x70, reg);
    return inb(0x71);
}

uint32_t Clock::readSeconds() {
    while(getUpdateInProgress());
    int second = getRegister(0x0);
    return (second & 0x0F) + ((second / 16) * 10);
}

uint32_t Clock::readHours() {
    while(getUpdateInProgress());
    int second = getRegister(0x4);
    return (second & 0x0F) + ((second / 16) * 10);
}

uint32_t Clock::readMinutes() {
    while(getUpdateInProgress());
    int second = getRegister(0x2);
    return (second & 0x0F) + ((second / 16) * 10);
}

uint32_t Clock::readDay() {
    while(getUpdateInProgress());
    int second = getRegister(0x7);
    return (second & 0x0F) + ((second / 16) * 10);
}

uint32_t Clock::readMonth() {
    while(getUpdateInProgress());
    int second = getRegister(0x8);
    return (second & 0x0F) + ((second / 16) * 10);
}

uint32_t Clock::readYear() {
    while(getUpdateInProgress());
    int second = getRegister(0x9);
    return (second & 0x0F) + ((second / 16) * 10);
}

uint32_t Clock::readTime() {
    return readHours()*3600+readMinutes()*60+readSeconds();
}

void Clock::waitSeconds(uint32_t secs) {
    int lastsec = readTime()+secs;
    while(lastsec != readTime()){}
}