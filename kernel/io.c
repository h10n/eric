#ifndef _IO_C
#define _IO_C

#include <stdint.h>

static inline void outb(uint16_t port, uint8_t val) {
  __asm__ volatile ("outb %0, %1" : : "a"(val), "Nd"(port) );
}

static inline uint8_t inb(uint16_t port) {
  uint8_t ret;
  __asm__ volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
  return ret;
}

static inline void io_wait(void)
{
  /* TODO: This is probably fragile. */
  __asm__ volatile ( "jmp 1f\n\t"
                 "1:jmp 2f\n\t"
                 "2:" );
}

#endif
