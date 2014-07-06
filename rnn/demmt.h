#ifndef DEMMT_H
#define DEMMT_H

#include "demmt_pushbuf.h"

#define MMT_DEBUG 0
extern int find_ib_buffer;
extern int quiet;

#define mmt_debug(fmt, ...)        do { if (MMT_DEBUG)                 fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#define mmt_log(fmt, ...)          do { if (!find_ib_buffer && !quiet) fprintf(stdout, "%64s" fmt, " ", __VA_ARGS__); } while (0)
#define mmt_log_cont(fmt, ...)     do { if (!find_ib_buffer && !quiet) fprintf(stdout, fmt, __VA_ARGS__); } while (0)
#define mmt_error(fmt, ...)        do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)

struct region
{
	struct region *prev;
	uint32_t start;
	uint32_t end;
	struct region *next;
};

struct buffer
{
	int id;
	unsigned char *data;
	int length;
	uint64_t mmap_offset;
	uint64_t cpu_start;
	uint64_t data1;
	uint64_t data2;
	uint64_t gpu_start;
	enum BUFTYPE { PUSH, IB } type;
	union
	{
		struct pushbuf_decode_state pushbuf;
		struct ib_decode_state ib;
	} state;
	struct region *written_regions;
	struct region *written_region_last;
	struct buffer *prev, *next;
};

extern struct buffer *buffers_list;

extern struct rnndomain *domain;
extern struct rnndb *rnndb;
extern int chipset;
extern int guess_invalid_pushbuf;

#endif
