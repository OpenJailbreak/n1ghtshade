#ifndef IMAGE_H
#define IMAGE_H

#define DEVICE_TREE_TAG 'dtre'
#define LOGO_TAG 'logo'

struct bdev6_t {
    struct bdev6_t *next;
    unsigned field_4;
    unsigned field_8;
    unsigned field_C;
    unsigned field_10;
    unsigned size_lo;
    unsigned size_hi;
    int (*bdev_read)(void *bdev, void *buf, long long offset, long long size);
    unsigned block_read;
    unsigned bdev_write;
    unsigned block_write;
    unsigned field_34;
    char name[16];
} /*__attribute__((packed))*/;

struct bdev_t {
    struct bdev_t *next;
    unsigned field_4;
    unsigned field_8;
    unsigned field_C;
    unsigned field_10;
    unsigned size_lo;
    unsigned size_hi;
    unsigned field_1C;
    unsigned field_20;
    int (*bdev_read)(void *bdev, void *buf, long long offset, long long size);
    unsigned block_read;
    unsigned bdev_write;
    unsigned block_write;
    unsigned field_34;
    char name[16];
    unsigned field_48;
    unsigned field_4C;
    unsigned field_50;
    unsigned field_54;
} /*__attribute__((packed))*/;

struct firmware_image;

struct firmware_image_info {
    unsigned total_length;
    unsigned size;
    unsigned type;
    unsigned magic;
    unsigned flags;
    struct firmware_image *super;
} /*__attribute__((packed))*/;

typedef struct firmware_image {
    struct firmware_image *prev;
    struct firmware_image *next;
    struct bdev6_t *bdev;
    unsigned offset_lo;
    unsigned offset_hi;
    unsigned field_14;
    struct firmware_image_info info;
} firmware_image/*__attribute__((packed))*/;


typedef struct img3_root {
    unsigned int magic;
    unsigned int size;
    unsigned int dataSize;
    unsigned int shshOffset;
    unsigned int name;
} img3_root;

int bdev_read(void *bdev, void *buf, long long offset, long long size);
int load_image_from_bdev(char* address, uint32_t tag, size_t* len);

#endif