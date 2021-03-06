/*
 *  Copyright (c) 2014 Martin Glueck <martin@mangari.org>
 *  Copyright (c) 2020 Stefan Haller
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3 as
 *  published by the Free Software Foundation.
 */

#ifndef BOOT_DESCRIPTOR_BLOCK_H_
#define BOOT_DESCRIPTOR_BLOCK_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define BL_IDENTITY			 0x1043		// Version 0.43
#define FIRST_SECTOR		 0x3000		// where the application starts (BL size)
#define BOOT_BLOCK_DESC_SIZE 0x100		// 1 flash page
#define BOOT_BLOCK_PAGE   ((FIRST_SECTOR / BOOT_BLOCK_DESC_SIZE) - 1)

#ifdef DUMP_TELEGRAMS
	#define	BL_FEATURES  	 0x8100
#else
	#define BL_FEATURES		 0x0100		// Feature list of BL

#endif

typedef struct
{
    unsigned int startAddress;
    unsigned int endAddress;
    unsigned int crc;
    unsigned int appVersionAddress;
}__attribute__ ((aligned (256))) AppDescriptionBlock;

unsigned int checkApplication(AppDescriptionBlock * block);

unsigned char * getAppVersion(AppDescriptionBlock * block);

#ifdef __cplusplus
}
#endif

#endif /* BOOT_DESCRIPTOR_BLOCK_H_ */
