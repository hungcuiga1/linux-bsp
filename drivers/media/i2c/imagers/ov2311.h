/*
 * OmniVision ov2311 sensor camera setup 1600x130@30/GREY8/MIPI
 *
 * Copyright (C) 2015-2020 Cogent Embedded, Inc.
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 */

//#define OV2311_DISPLAY_PATTERN
//#define OV2311_FSIN_ENABLE

#define OV2311_MAX_WIDTH	1600
#define OV2311_MAX_HEIGHT	1300

#define OV2311_DELAY		0xffff

#define OV2311_SENSOR_WIDTH	1616
#define OV2311_SENSOR_HEIGHT	1316

#define OV2311_X_START		((OV2311_SENSOR_WIDTH - OV2311_MAX_WIDTH) / 2)
#define OV2311_Y_START		((OV2311_SENSOR_HEIGHT - OV2311_MAX_HEIGHT) / 2)
#define OV2311_X_END		(OV2311_X_START + OV2311_MAX_WIDTH - 1)
#define OV2311_Y_END		(OV2311_Y_START + OV2311_MAX_HEIGHT - 1)

struct ov2311_reg {
	u16	reg;
	u8	val;
};

/* R1600x1300 RAW8 MIPI 60fps */
static const struct ov2311_reg ov2311_regs_r1c[] = {
{0x0103, 0x01},
{0x0100, 0x00},
{0x010c, 0x02},
{0x010b, 0x01},
{0x0300, 0x01},
{0x0302, 0x32},
{0x0303, 0x00},
{0x0304, 0x03},
{0x0305, 0x02},
{0x0306, 0x01},
{0x030d, 0x5a},
{0x030e, 0x04},
{0x3001, 0x02},
{0x3004, 0x00},
{0x3005, 0x00},
{0x3006, 0x0a},
{0x3011, 0x0d},
{0x3014, 0x04},
{0x301c, 0xf0},
{0x3020, 0x20},
{0x302c, 0x00},
{0x302d, 0x00},
{0x302e, 0x00},
{0x302f, 0x03},
{0x3030, 0x10},
{0x303f, 0x03},
{0x3103, 0x00},
{0x3106, 0x08},
{0x31ff, 0x01},
{0x3501, 0x05},
{0x3502, 0x7c},
{0x3506, 0x00},
{0x3507, 0x00},
{0x3620, 0x67},
{0x3633, 0x78},
{0x3662, 0x65},
{0x3664, 0xb0},
{0x3666, 0x70},
{0x3670, 0x68},
{0x3674, 0x10},
{0x3675, 0x00},
{0x367e, 0x90},
{0x3680, 0x84},
{0x36a2, 0x04},
{0x36a3, 0x80},
{0x36b0, 0x00},
{0x3700, 0x35},
{0x3704, 0x39},
{0x370a, 0x50},
{0x3712, 0x00},
{0x3713, 0x02},
{0x3778, 0x00},
{0x379b, 0x01},
{0x379c, 0x10},
{0x3800, 0x00},
{0x3801, 0x00},
{0x3802, 0x00},
{0x3803, 0x00},
{0x3804, 0x06},
{0x3805, 0x4f},
{0x3806, 0x05},
{0x3807, 0x23},
{0x3808, OV2311_MAX_WIDTH >> 8},
{0x3809, OV2311_MAX_WIDTH & 0xff},
{0x380a, OV2311_MAX_HEIGHT >> 8},
{0x380b, OV2311_MAX_HEIGHT & 0xff},
{0x380c, 0x03},
{0x380d, 0xa8},
{0x380e, 0x05},
{0x380f, 0x88},
{0x3810, OV2311_X_START >> 8},
{0x3811, OV2311_X_START & 0xff},
{0x3812, OV2311_Y_START >> 8},
{0x3813, OV2311_X_START & 0xff},
{0x3814, 0x11},
{0x3815, 0x11},
{0x3816, 0x00},
{0x3817, 0x01},
{0x3818, 0x00},
{0x3819, 0x05},
{0x3820, 0x00},
{0x3821, 0x00},
{0x382b, 0x5a},
{0x382c, 0x0a},
{0x382d, 0xf8},
{0x3881, 0x44},
{0x3882, 0x02},
{0x3883, 0x8c},
{0x3885, 0x07},
{0x389d, 0x03},
{0x38a6, 0x00},
{0x38a7, 0x01},
{0x38b3, 0x07},
{0x38b1, 0x00},
{0x38e5, 0x02},
{0x38e7, 0x00},
{0x38e8, 0x00},
{0x3910, 0xff},
{0x3911, 0xff},
{0x3912, 0x08},
{0x3913, 0x00},
{0x3914, 0x00},
{0x3915, 0x00},
{0x391c, 0x00},
{0x3920, 0xff},
{0x3921, 0x80},
{0x3922, 0x00},
{0x3923, 0x00},
{0x3924, 0x05},
{0x3925, 0x00},
{0x3926, 0x00},
{0x3927, 0x00},
{0x3928, 0x1a},
{0x392d, 0x03},
{0x392e, 0xa8},
{0x392f, 0x08},
{0x4001, 0x00},
{0x4003, 0x40},
{0x4008, 0x04},
{0x4009, 0x1b},
{0x400c, 0x04},
{0x400d, 0x1b},
{0x4010, 0xf4},
{0x4011, 0x00},
{0x4016, 0x00},
{0x4017, 0x04},
{0x4042, 0x11},
{0x4043, 0x70},
{0x4045, 0x00},
{0x4409, 0x5f},
{0x4509, 0x00},
{0x450b, 0x00},
{0x4600, 0x00},
{0x4601, 0xa0},
{0x4708, 0x09},
{0x470c, 0x81},
{0x4710, 0x06},
{0x4711, 0x00},
{0x4800, 0x00},
{0x481f, 0x30},
{0x4837, 0x14},
{0x4f00, 0x00},
{0x4f07, 0x00},
{0x4f08, 0x03},
{0x4f09, 0x08},
{0x4f0c, 0x05},
{0x4f0d, 0xb4},
{0x4f10, 0x00},
{0x4f11, 0x00},
{0x4f12, 0x07},
{0x4f13, 0xe2},
{0x5000, 0x9f},
{0x5001, 0x20},
{0x5026, 0x00},
{0x5c00, 0x00},
{0x5c01, 0x2c},
{0x5c02, 0x00},
{0x5c03, 0x7f},
{0x5e00, 0x00},
{0x5e01, 0x41},
{0x38b1, 0x02},
{0x3880, 0x00},

#if 1  /* Y8 mode */
{0x3016, 0xF1},
{0x0100, 0x01},
{0x4814, 0x6A}, //; dt_man en, both embed/image data type are 0x2A
{0x3218, 0x32},
{0x3216, 0x01},
{0x3208, 0x04},
{0x3D81, 0x01},
{0x4605, 0x02},
{0x4816, 0x0A},
{0x3208, 0x14},
{0x3662, 0x67}, //; [1] raw8
{0x366F, 0x1A}, //; [6] MSB
//{0x3674, 0x11}, //; [0] embed_en, add embed data before normal image
{0x3674, 0x10}, //; [0] embed_dis, add embed data before normal image
{0x3016, 0xF0},
#endif

{0x0100, 0x01},
};
